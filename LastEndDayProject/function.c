#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <windows.h>

#include <conio.h> // getch library

#define c system("cls")

#define p system("pause")

#define f fflush(stdin)

#define s Sleep(2000)

#define MAX_STUDENTS 50

#include "datatypes.h"



int loadTeachers(Teacher teachers[], int *teacherCount) 
{
    FILE *file2 = fopen("teacherData.bin", "rb");
    
	if(file2 == NULL) 
	{
        c;
		
		printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Cannot read data from file 'teacherData.bin'!\033[0m\n");
		
		s;
        
		exit(0);
    }

    *teacherCount = 0;  
    
	while(fread(&teachers[*teacherCount], sizeof(Teacher), 1, file2)) 
	{
        (*teacherCount)++;
    }

    fclose(file2);
    
	return *teacherCount;
}



void saveTeachers(Teacher teachers[], int teacherCount) 
{
    FILE *file2 = fopen("teacherData.bin", "wb");
    
	if(file2 == NULL) 
	{
        c;
		
		printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Cannot write data into file 'teacherData.bin'!\033[0m\n");
		
		s;
        
		exit(0);
    }

    fwrite(teachers, sizeof(Teacher), teacherCount, file2);

    fclose(file2);
    
	printf("\033[32m\n\n\t\t\t\t\t\t[*] Successfully saved '%d' classes to file 'teacherData.bin'!\033[0m\n", teacherCount);
}




int loadClasses(Class classes[], int *classCount) 
{
    FILE *file1 = fopen("classData.bin", "rb");
    
	if(file1 == NULL) 
	{
        c;
		
		printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Cannot read data from file 'classData.bin'!\033[0m\n");
		
		s;
        
		exit(0);
    }

    *classCount = 0;  
    
	while(fread(&classes[*classCount], sizeof(Class), 1, file1)) 
	{
        (*classCount)++;
    }

    fclose(file1);
    
	return *classCount;
}



void saveClasses(Class classes[], int classCount) 
{
    FILE *file1 = fopen("classData.bin", "wb");
    
	if(file1 == NULL) 
	{
        c;
		
		printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Cannot write data into file 'classData.bin'!\033[0m\n");
		
		s;
        
		exit(0);
    }

    fwrite(classes, sizeof(Class), classCount, file1);

    fclose(file1);
    
	printf("\033[32m\n\n\t\t\t\t\t\t[*] Successfully saved '%d' classes to file 'studentData.bin'!\033[0m\n", classCount);
}



int loadStudents(Student students[], int *studentCount) 
{
    FILE *file = fopen("studentData.bin", "rb");
    
	if(file == NULL) 
	{
        c;
		
		printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Cannot read data from file 'studentData.bin'!\033[0m\n");
		
		s;
        
		exit(0);
    }

    *studentCount = 0;  
    
	while(fread(&students[*studentCount], sizeof(Student), 1, file)) 
	{
        (*studentCount)++;
    }

    fclose(file);
    
	return *studentCount;
}




void saveStudents(Student students[], int studentCount) 
{
    FILE *file = fopen("studentData.bin", "wb");
    
	if(file == NULL) 
	{
        c;
		
		printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Cannot write data into file 'studentData.bin'!\033[0m\n");
		
		s;
        
		exit(0);
    }

    fwrite(students, sizeof(Student), studentCount, file);

    fclose(file);
    
	printf("\033[32m\n\n\t\t\t\t\t\t[*] Successfully saved '%d' students to file 'studentData.bin'!\033[0m\n", studentCount);
}




void inputString(char *str, int maxLength, const char *prompt) 
{
    int d;
    
    while(1) 
    {		
		s;
		
		c;
		
		f;
		
		printf("\n\n\t\t\t\t\t\t-> %s ( max '%d' characters ): ", prompt, maxLength);
		
		scanf("%[^\n]s", str);

        if(strlen(str) > maxLength)
		{
			printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Input exceeds maximum length ( '%d' characters ), try again!\033[0m\n", maxLength);
            
			continue;
		}


        if(strlen(str) == 0) 
        {
            printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Input data cannot be empty! Try again.\033[0m\n");
            
			continue;
        }

        break; 
    }
}


void endProgram()
{
	printf("\n\t\t\t\t\t\t+---------x\033[1m THANK YOU!\033[0m x--------+");
	
	printf("\n\n\t\t\t\t\t\t+------x\033[1m SEE YOU SOON!\033[0m x--------+");
}



void goBackOrExit()
{
	char choice;
	
	do
	{
		printf("\033[33m\n\n\t\t\t\t\t\t-> Go back [b] or exit [e]:\033[0m ");
	
		scanf(" %c", &choice);
	
		choice = tolower(choice);
	
		if(choice == 'b')
		{	
			c;
			
			printf("\033[33m\n\n\t\t\t\t\t\t[*] Return to current menu!\033[0m");
			
			s;
			
			c;
		
			return;
		}
	
			else if(choice == 'e')
			{
				c;
			
				printf("\033[33m\n\n\t\t\t\t\t\t\t[*] Exit program!\033[0m\n");
			
				endProgram();
				
				s;
			
				exit(0);
			}
			
				else
				{
					c;
					
					printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");
					
					s;
					
					c;
				}
				
	}	
	
	while(1);
}


/*
void addStudentToClass()
{
    FILE *fs = fopen("studentData.bin", "rb");
    
	if(fs == NULL)
    {
        printf("\033[31m\n\t\t\t\t\t\t[x] Error: Cannot open 'studentData.bin'!\033[0m\n");
        
		exit(0);
    }

    Student students[50];
    
	int studentCount = 0;

    while(fread(&students[studentCount], sizeof(Student), 1, fs))
    {
        studentCount++;
    }
    
	fclose(fs);

    FILE *fc = fopen("classData.bin", "rb");
    
	if(fc == NULL)
    {
        printf("\033[31m\n\t\t\t\t\t\t[x] Error: Cannot open 'classData.bin'!\033[0m\n");
        
		exit(0);
    }

    Class classes[20];
    
	int classCount = 0;

    while(fread(&classes[classCount], sizeof(Class), 1, fc))
    {
        classCount++;
    }
    
	fclose(fc);

    char id10[10], id11[10];
    
    inputString(id10, 9, "Enter student code");
    
	Student *foundStudent = NULL;

    for (int i = 0; i < studentCount; i++)
    {
        if (strcmp(students[i].student_id, id10) == 0)
        {
            foundStudent = &students[i];
            
			break;
        }
    }

    if(foundStudent == NULL)
    {
        printf("\033[31m\n\t\t\t\t\t\t[x] Student code '%s' not found!\033[0m\n", id10);
        
		exit(0);
    }

    inputString(id11, 9, "Enter class code");
    
	Class *foundClass = NULL;

    for(int j = 0; j < classCount; j++)
    {
        if(strcmp(classes[j].class_id, id11) == 0)
        {
            foundClass = &classes[j];
            
			break;
        }
    }

    if(foundClass == NULL)
    {
        printf("\033[31m\n\t\t\t\t\t\t[x] Class code '%s' not found!\033[0m\n", id11);
        
		exit(0);
    }

    foundClass->students[foundClass->studentCount] = *foundStudent;
    
	foundClass->studentCount++;
	
	c;

    printf("\033[32m\n\t\t\t\t\t\t[*] Student '%s' added to class '%s' successfully!\033[0m\n", id10, id11);
    
    s;

    fc = fopen("classData.bin", "wb");
    
	if(fc == NULL)
    {
        printf("\033[31m\n\t\t\t\t\t\t[x] Error: Cannot update 'classData.bin'!\033[0m\n");
        
		exit(0);
    }

    fwrite(classes, sizeof(Class), classCount, fc);
    
	fclose(fc);
	
	c;
}
*/




void encryptPassword(char *password, int maxLength) 
{
    int i = 0;
    
	char ch;
    
    while(1) 
	{
        ch = getch(); 

        if(ch == '\r') 
		{ 
            password[i] = '\0';
            
			printf("\n"); 
            
			break;
        }
  
        else if(ch == 8 && i > 0) 
		{ 
            printf("\b \b"); 
            
			i--;
        }
   
        else if(i < maxLength - 1 && ch >= 32 && ch <= 126) 
		{ 
            password[i] = ch;
            
			i++;
            
			printf("*"); 
        }
    }
}



void loginMenu()
{
	printf("\n\t\t\t\t\t      \033[1m*** STUDENT MANAGEMENT SYSTEM USING C ***\033[0m");

    printf("\n\n\t\t\t\t\t\t\t\033[1m*  ADMIN LOGIN UI:  *\033[0m");
    
    printf("\n\n\t\t\t\t\t\t+----------------------------------+");
}



void userAndPassword(Admin *admin) 
{
    do 
	{		
		loginMenu();
		
		printf("\033[1m\n\n\t\t\t\t\t\t-> Enter email:\033[0m ");
        
		scanf(" %[^\n]s", admin->userName);

        if(strstr(admin->userName, "@email.com") == NULL) 
		{
            c;
			
			printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Your email must contain string '@email.com'!\033[0m\n");
			
			s;
			
			c;
        }   
	} 
	
	while(strstr(admin->userName, "@email.com") == NULL);
	
	printf("\n\t\t\t\t\t\t+----------------------------------+");

    printf("\033[1m\n\n\t\t\t\t\t\t-> Enter password:\033[0m ");
    
	encryptPassword(admin->password, sizeof(admin->password));
}



void showMainMenu()
{
	printf("\n\t\t\t\t\t        \033[1m*** STUDENT MANAGEMENT SYSTEM USING C ***\033[0m\n");
		
	printf("\n\t\t\t\t\t\t+---------|\033[1m CHOOSE YOUR ROLE:\033[0m |---------+\n");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[1] Admin.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[2] Student.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[3] Teacher.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[0] Exit The Program.");
		
	printf("\t\t\t\t\t\t+---------------------------------------+");
		
	printf("\n");
}
	


void showStudentMenu()	
{
	printf("\n\t\t\t\t\t      \033[1m*** STUDENT MANAGEMENT SYSTEM USING C ***\033[0m\n");
		
	printf("\n\t\t\t\t\t\t+----------|\033[1m STUDENT MENU\033[0m |---------+\n");
		
	printf("\t\t\t\t\t\t|%-35s|\n\t\t\t\t\t\t", "[1] Add A New Student.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[2] Show List Students.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[3] Search A Student.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[4] Edit A Student.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[5] Delete A Student.");
	
	printf("|%-35s|\n\t\t\t\t\t\t", "[6] Sort Students.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[0] Exit The Program.");
	
	printf("+-----------------------------------+");
}



void showClassMenu()
{
	printf("\n\t\t\t\t\t         \033[1m*** STUDENT MANAGEMENT SYSTEM USING C ***\033[0m\n");
		
	printf("\n\t\t\t\t\t\t+--------------|\033[1m CLASS\033[0m |-------------+\n");
		
	printf("\t\t\t\t\t\t|%-36s|\n\t\t\t\t\t\t", "[1] Show List Classes.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[2] Add A New Class.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[3] Edit A Class.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[4] Delete A Class.");
	
	printf("|%-36s|\n\t\t\t\t\t\t", "[5] Add Student To Class.");
				
	printf("|%-36s|\n\t\t\t\t\t\t", "[0] Exit The Program.");
		
	printf("+------------------------------------+");
}

	

void showTeacherMenu()
{
	printf("\n\t\t\t\t\t        \033[1m*** STUDENT MANAGEMENT SYSTEM USING C ***\033[0m\n");
		
	printf("\n\t\t\t\t\t\t+--------------|\033[1m TEACHER\033[0m |-------------+\n");
		
	printf("\t\t\t\t\t\t|%-38s|\n\t\t\t\t\t\t", "[1] Show List Teachers.");
		
	printf("|%-38s|\n\t\t\t\t\t\t", "[2] Add A New Teacher.");
		
	printf("|%-38s|\n\t\t\t\t\t\t", "[3] Edit A Teacher.");
		
	printf("|%-38s|\n\t\t\t\t\t\t", "[4] Delete A Teacher.");
	
	printf("|%-38s|\n\t\t\t\t\t\t", "[5] Add Teacher To Class.");
	
	printf("|%-38s|\n\t\t\t\t\t\t", "[6] Search A Teacher.");
				
	printf("|%-38s|\n\t\t\t\t\t\t", "[0] Exit The Program.");
		
	printf("+--------------------------------------+");
}



/*
void saveAccountAdmin() 
{
    FILE *file;
	
	file = fopen("adminAccount.bin", "wb");
	
	if(file == NULL) 
	{   
		c;
		
		printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Cannot write data into file 'adminAccount.bin'!\033[0m\n");
		
		s;
		
		exit(1);
    }
	
	f;

    loginMenu();
    
    Admin admin;
    
    userAndPassword(&admin);
	
	fwrite(&admin, sizeof(Admin), 1, file);
  
	fclose(file);   
}
*/


void exit()
{									
	printf("\n\n\t\t\t\t\t\t");
								
	p;
								
	c;
}



void displayListTeachers()
{
    c;
    
    FILE *file5;
    
    file5 = fopen("teacherData.bin", "rb");
    
    if(file5 == NULL)
    {
    	c;
		
		printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Cannot read data from file 'teacherData.bin'!\033[0m\n");
		
		s;
		
		exit(0);
	}
	
	Teacher teachers;
	
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\033[1m*  ALL TEACHERS:  *\033[0m\n\n");

    printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
	printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Email", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
	
	while(fread(&teachers, sizeof(Teacher), 1, file5))
	{
		printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", teachers.teacher_id, teachers.name, teachers.gmail, teachers.phone, teachers.dateOfBirth.day, teachers.dateOfBirth.month, teachers.dateOfBirth.year, (teachers.gender == 0) ? "Male" : "Female", "NULL");
		
		printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
	}
    
    fclose(file5);
}

	

void addTeacher(Teacher teachers[], int *teacherCount, char id12[]) 
{	
    FILE *file3;
    
	Teacher tempTeacher, newTeacher;

    file3 = fopen("teacherData.bin", "rb");
    
	if(file3 != NULL) 
    {
        while(fread(&tempTeacher, sizeof(Teacher), 1, file3)) 
        {
            if(strcmp(tempTeacher.teacher_id, id12) == 0) 
            {
                printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Teacher code '%s' already exists!\033[0m\n", id12);
                
				fclose(file3);
				
				exit(0);
            }

            if(strcmp(tempTeacher.phone, newTeacher.phone) == 0 || strcmp(tempTeacher.gmail, newTeacher.gmail) == 0) 
            {
                printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Teacher information already exists!\033[0m\n");
                
				fclose(file3);
                
				exit(0);
            }
        }
        
		fclose(file3);
    }

    strcpy(newTeacher.teacher_id, id12);
       
	inputString(newTeacher.name, 24, "Enter teacher name");
	
	c;
    
	inputString(newTeacher.phone, 19, "Enter teacher phone number");
	
	c;
    
    inputString(newTeacher.gmail, 29, "Enter teacher gmail");
    
    c;
    
    do 
    {
        printf("\n\t\t\t\t\t\t-> Enter teacher gender ( 0: Male, 1: Female ): ");
        
		scanf("%d", &newTeacher.gender);
    } 
    
	while(newTeacher.gender != 0 && newTeacher.gender != 1);
	
	c;
    
    do 
    {
        printf("\n\t\t\t\t\t\t-> Enter teacher date of birth ( dd mm yyyy ): ");
        
		scanf("%d %d %d", &newTeacher.dateOfBirth.day, &newTeacher.dateOfBirth.month, &newTeacher.dateOfBirth.year);
        
        if(newTeacher.dateOfBirth.day < 1 || newTeacher.dateOfBirth.day > 31 || newTeacher.dateOfBirth.month < 1 || newTeacher.dateOfBirth.month > 12 || newTeacher.dateOfBirth.year < 1000 || newTeacher.dateOfBirth.year > 3000) 
        {          	
            printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Invalid date of birth, try again!\033[0m");
        } 
        
		else 
        {
            break;
        }
    } 
    
	while(1);

    file3 = fopen("teacherData.bin", "ab");
    
	if(file3 == NULL) 
    {       
        printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Cannot write data into file 'teacherData.bin'!\033[0m\n");
        
		exit(0);
    }

    fwrite(&newTeacher, sizeof(Teacher), 1, file3);
    
	fclose(file3);
	
	c;

    printf("\033[32m\n\t\t\t\t\t\t[*] Teacher added successfully and saved to file 'teacherData.bin'!\033[0m\n");
    
    s;
    
    teachers[*teacherCount] = newTeacher;
    
	(*teacherCount)++;
}



		
void addStudent(Student students[], int *studentCount, char id0[]) 
{	
    FILE *file;
    
	Student tempStudent, newStudent;

    file = fopen("studentData.bin", "rb");
    
	if(file != NULL) 
    {
        while(fread(&tempStudent, sizeof(Student), 1, file)) 
        {
            if(strcmp(tempStudent.student_id, id0) == 0) 
            {
                printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Student code '%s' already exists!\033[0m\n", id0);
                
				fclose(file);
				
				exit(0);
            }

            if(strcmp(tempStudent.phone, newStudent.phone) == 0 || strcmp(tempStudent.email, newStudent.email) == 0) 
            {
                printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Student information already exists!\033[0m\n");
                
				fclose(file);
                
				exit(0);
            }
        }
        
		fclose(file);
    }

    strcpy(newStudent.student_id, id0);
       
	inputString(newStudent.name, 24, "Enter student name");
	
	c;
    
	inputString(newStudent.phone, 19, "Enter student phone number");
	
	c;
    
    inputString(newStudent.email, 29, "Enter student email");
    
    c;
    
    do 
    {
        printf("\n\t\t\t\t\t\t-> Enter student gender ( 0: Male, 1: Female ): ");
        
		scanf("%d", &newStudent.gender);
    } 
    
	while(newStudent.gender != 0 && newStudent.gender != 1);
	
	c;
    
    do 
    {
        printf("\n\t\t\t\t\t\t-> Enter student date of birth ( dd mm yyyy ): ");
        
		scanf("%d %d %d", &newStudent.dateOfBirth.day, &newStudent.dateOfBirth.month, &newStudent.dateOfBirth.year);
        
        if(newStudent.dateOfBirth.day < 1 || newStudent.dateOfBirth.day > 31 || newStudent.dateOfBirth.month < 1 || newStudent.dateOfBirth.month > 12 || newStudent.dateOfBirth.year < 1000 || newStudent.dateOfBirth.year > 3000) 
        {          	
            printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Invalid date of birth, try again!\033[0m");
        } 
        
		else 
        {
            break;
        }
    } 
    
	while(1);

    file = fopen("studentData.bin", "ab");
    
	if(file == NULL) 
    {       
        printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Cannot write data into file 'studentData.bin'!\033[0m\n");
        
		exit(0);
    }

    fwrite(&newStudent, sizeof(Student), 1, file);
    
	fclose(file);
	
	c;

    printf("\033[32m\n\t\t\t\t\t\t[*] Student added successfully and saved to file 'studentData.bin'!\033[0m\n");
    
    s;
    
    students[*studentCount] = newStudent;
    
	(*studentCount)++;
}
	


void displayListStudents()
{
    c;
    
    FILE *file;
    
    file = fopen("studentData.bin", "rb");
    
    if(file == NULL)
    {
    	c;
		
		printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Cannot read data from file 'studentData.bin'!\033[0m\n");
		
		s;
		
		exit(0);
	}
	
	Student students;
	
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\033[1m*  ALL STUDENTS:  *\033[0m\n\n");

    printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
	printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Email", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
	
	while(fread(&students, sizeof(Student), 1, file))
	{
		printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", students.student_id, students.name, students.email, students.phone, students.dateOfBirth.day, students.dateOfBirth.month, students.dateOfBirth.year, (students.gender == 0) ? "Male" : "Female", "NULL");
		
		printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
	}
    
    fclose(file);
}



void searchTeachersByName(Teacher teachers[], int teacherCount, const char* name1)
{
    int found1 = 0;

    printf("\n\t\t\t\t\t\t\t\t\t\t\t*  LIST OF TEACHERS HAVE NAME '%s':  *", name1);
  
    printf("\n\n\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
	printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Gmail", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
	for(int i = 0; i < (teacherCount); i++)
    {
        if(strstr(teachers[i].name, name1) != NULL)
        {
            printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", teachers[i].teacher_id, teachers[i].name, teachers[i].gmail, teachers[i].phone, teachers[i].dateOfBirth.day, teachers[i].dateOfBirth.month, teachers[i].dateOfBirth.year, (teachers[i].gender == 0) ? "Male" : "Female", "NULL");

            printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
			
			found1 = 1;
        }
    }
   
    if(found1 != 1)
    {
        c;
		
		printf("\033[31m\n\t\t\t\t\t\t[x] Warning: No teachers found with the name '%s'!\033[0m\n", name1);
    }
}



void searchStudentsByName(Student students[], int studentCount, const char* name)
{
    int found = 0;

    printf("\n\t\t\t\t\t\t\t\t\t\t\t*  LIST OF STUDENTS HAVE NAME '%s':  *", name);
  
    printf("\n\n\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
	printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Email", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
	for(int i = 0; i < (studentCount); i++)
    {
        if(strstr(students[i].name, name) != NULL)
        {
            printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", students[i].student_id, students[i].name, students[i].email, students[i].phone, students[i].dateOfBirth.day, students[i].dateOfBirth.month, students[i].dateOfBirth.year, (students[i].gender == 0) ? "Male" : "Female", "NULL");

            printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
			
			found = 1;
        }
    }
   
    if(found != 1)
    {
        c;
		
		printf("\033[31m\n\t\t\t\t\t\t[x] Warning: No students found with the name '%s'!\033[0m\n", name);
    }
}

	
	
void addClass(Class classes[], int *classCount, char id7[])
{						
    FILE *f1;
    
	Class newClass, tempClass;

    f1 = fopen("classData.bin", "rb");
    
    if(f1 != NULL)
    {
        while(fread(&tempClass, sizeof(Class), 1, f1)) 
        {
            if(strcmp(tempClass.class_id, id7) == 0) 
            {
                printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Class code '%s' already exists!\033[0m\n", id7);
                
				fclose(f1);
				
				s;
                
				exit(0);  
            }

            if(strcmp(tempClass.class_name, newClass.class_name) == 0) 
            {
                printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Class name '%s' already exists!\033[0m\n", newClass.class_name);
                
				fclose(f1);
				
				s;
                
				exit(0);
            }
        }
        
		fclose(f1);	
    }
    
    newClass.studentCount = 0;
    
    strcpy(newClass.class_id, id7);
    
	inputString(newClass.class_name, 24, "Enter class name");   

    f1 = fopen("classData.bin", "ab");
    
	if(f1 == NULL)
    {
        c;
		
		printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Cannot write data into file 'classData.bin'!\033[0m\n");
		
		s;
    	
		exit(0);
    }

    fwrite(&newClass, sizeof(Class), 1, f1);
    
	fclose(f1);

    classes[*classCount] = newClass;
    
	(*classCount)++;
	
	c;

    printf("\033[32m\n\t\t\t\t\t\t[*] Class added successfully and saved to file 'classData.bin'!\033[0m\n");
}

	
	
void displayListClasses()
{
    FILE *f1 = fopen("classData.bin", "rb");
    
	if(f1 == NULL)
    {
        printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Cannot read data from file 'classData.bin'!\033[0m\n");
        
		exit(0);
    }

    Class classes[20];
    
	int classCount = 0;

    while(fread(&classes[classCount], sizeof(Class), 1, f1))
    {
        classCount++;
    }
    
	fclose(f1);

    printf("\n\t\t\t\t\t\t\t\t    \033[1m*  ALL CLASSES:  *\033[0m\n\n");
    
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+\n");
    
	printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|\n", "ID", "Name", "Students");
    
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+\n");

    for(int i = 0; i < classCount; i++)
    {
        printf("\t\t\t\t\t\t|%-6s|%-22s|", classes[i].class_id, classes[i].class_name);

        if(classes[i].studentCount == 0)
        {
            printf("%-30s|\n", "No Students In Class");
        }
    }
    
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+\n");
}


	


void manageClasses(Class classes[], int *classCount, Student students[], int studentCount)
{
	c;
	
	int choiceMenuClass;
		
	do
		{				
			showClassMenu();		
				
			printf("\033[1m\n\n\t\t\t\t\t\t-> Enter your choice:\033[0m ");
				
			scanf("%d", &choiceMenuClass);				
				
			switch(choiceMenuClass)
				{
					case 0:
						{
							c;
								
							printf("\033[33m\n\t\t\t\t\t\t[*] Exit program!\033[0m");
							
							endProgram();
								
							s;													
								
							exit(0);															
						}
							
					case 1:
						{							
							Class classes[20];
    							
							int classCount = loadClasses(classes, &classCount);
							
							if(classCount == 0)
							{
								c;
										
								printf("\033[31m\n\t\t\t\t\t\t[x] Warning: There are currently no classes in the list!\033[0m");
									
								s;
										
								exit();
							}
									
									else
										{
											c;
											
											displayListClasses();
											
											goBackOrExit();
										}
																
								break;
						}
							
						case 2:
							{								
								c;
								
								char id7[10];
								
								int found7 = -1;
								
								inputString(id7, 9, "Enter class code you want to add");					
								
								c;
								
								printf("\n\n\t\t\t\t\t\t");
								
								p;												
								
								for(int t = 0; t < (*classCount); t++)
								{
									if(strcmp(classes[t].class_id, id7) == 0)
									{	
										found7 = 1;
										
										c;
										
										printf("\033[31m\n\t\t\t\t\t\t[x] Warning: This class code is already exist, try different class code!\033[0m");
										
										exit();
									}
								}																
									
									if(found7 == -1)
									{																																																																																			
										c;
										
										f;
										
										addClass(classes, classCount, id7);
										
										c;
										
										printf("\033[32m\n\n\t\t\t\t\t\t[*] Add class successfully!\033[0m");																																			
											
										goBackOrExit();											
									}
								
								break;
							}
							
						case 3:
							{
								c;
								
								char id8[10];
								
								int found8 = -1;
								
								Class classes[20];
    							
								int classCount = loadClasses(classes, &classCount);						
								
								inputString(id8, 9, "Enter class code you want to edit");							
								
								for(int i = 0; i < (classCount); i++)
								{
									if(strcmp(classes[i].class_id, id8) == 0)
									{
										found8 = i;
												
										break;
									}
								}
									
								if(found8 == -1)
								{
									c;
									
									printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Class code '%s' not found!\033[0m", id8);
									
									s;
										
									exit();
								}
									
									else
										{
											c;
											
											printf("\033[32m\n\t\t\t\t\t\t[*] Found class with code: %s!\033[0m", id8);
											
											s;
											
											c;
											
											printf("\n\t\t\t\t\t\t\t\t *  CLASS CODE '%s' INFORMATION:  *\n\n", id8);
    
											printf("\t\t\t\t\t\t+------+----------------------+------------------------------+\n");
    
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|\n", "ID", "Name", "Students");
    
											printf("\t\t\t\t\t\t+------+----------------------+------------------------------+\n");
											
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|", classes[found8].class_id, classes[found8].class_name, "NULL");
											
											printf("\n\t\t\t\t\t\t+------+----------------------+------------------------------+\n");
											
											printf("\n\n\t\t\t\t\t\t");
											
											p;
											
											c;																															
											
											inputString(classes[found8].class_name, 9, "Enter new class name");
											
											saveClasses(classes, classCount);							
											
											c;
																						
											printf("\033[32m\n\t\t\t\t\t\t[*] Class information updated successfully!\033[0m");
											
											s;
											
											exit();
																						
										}
										
									break;
							}
							
						case 4:
							{
								c;
								
								char id9[10];
								
								int found9 = -1;
								
								Class classes[20];
    							
								int classCount = loadClasses(classes, &classCount);	
								
								inputString(id9, 9, "Enter class code you want to delete");
								
								for(int x = 0; x < (classCount); x++)
								{
									if(strcmp(classes[x].class_id, id9) == 0)
									{
										found9 = x;
												
										break;
									}
								}
									
								if(found9 == -1)
								{
									c;
									
									printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Class code '%s' not found!\033[0m", id9);
									
									s;
										
									exit();
								}																			
											
									else
										{											
											c;
											
											printf("\033[32m\n\t\t\t\t\t\t[*] Found class with code: %s!\033[0m", id9);
																																
											s;
											
											c;
											
											printf("\n\t\t\t\t\t\t\t\t *  CLASS CODE '%s' INFORMATION:  *\n\n", id9);
    
											printf("\t\t\t\t\t\t+------+----------------------+------------------------------+\n");
    
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|\n", "ID", "Name", "Students");
    
											printf("\t\t\t\t\t\t+------+----------------------+------------------------------+\n");
											
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|", classes[found9].class_id, classes[found9].class_name, "NULL");
											
											printf("\n\t\t\t\t\t\t+------+----------------------+------------------------------+\n");
											
											printf("\n\n\t\t\t\t\t\t");
											
											p;
											
											s;
											
											c;									
										}
											
											char yourChoice3;
	
											do
												{																										
													printf("\n\n\t\t\t\t\t\t-> Are you sure want to delete this class? ( y / n ): ");
	
													scanf(" %c", &yourChoice3);
	
													yourChoice3 = tolower(yourChoice3);
	
													if(yourChoice3 == 'y')
													{	
														for(int g = found9; g < (classCount) - 1; g++)
														{
															classes[g] = classes[g + 1];
														}
														
														(classCount)--;
														
														c;
														
														saveClasses(classes, classCount);
										
														printf("\033[32m\n\t\t\t\t\t\t[*] Delete this class successfully!\033[0m");
														
														s;
														
														c;
										
														break;
														
													}
	
														else if(yourChoice3 == 'n')
														{
															c;
															
															printf("\033[32m\n\t\t\t\t\t\t[*] You choose not delete this class!\033[0m");
															
															s;
													
															break;			
														}
			
															else
																{
																	c;
					
																	printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");
					
																	s;
					
																	c;
																}
												}
												
												while(1);
									
									break;							
							}
							
						default:
							{
								c;
								
								printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");
								
								exit();
							}
							
						case 5:
							{
								c;
								
								//addStudentToClass();
								
								break;															
							}
					}
			}
			
			while(choiceMenuClass != 0);						
	}
	

	
void manageStudents(Student students[], int *studentCount)
	{
		int choiceStudentMenu;
		
		do 
			{
				showStudentMenu();
				
				printf("\033[1m\n\n\t\t\t\t\t\t-> Enter your choice:\033[0m ");
				
				scanf("%d", &choiceStudentMenu);
				
				switch(choiceStudentMenu)
					{
						case 0:
							{
								c;
					
								printf("\033[33m\n\t\t\t\t\t\t\t[*] Exit program!\033[0m\n");
					
								endProgram();
								
								s;
								
								exit(0);								
							}
						
						case 2:
							{								
								Student students[50];
    							
								int studentCount = loadStudents(students, &studentCount);
								
								if(studentCount == 0)
								{
									c;
										
									printf("\033[31m\n\t\t\t\t\t\t[x] Warning: There are currently no students in the list!\033[0m");
									
									s;
										
									exit();
								}
									
									else
										{
											displayListStudents();
											
											goBackOrExit();
										}
																
								break;							
							}
							
						case 1:
							{
								c;
								
								char id0[10];

								int found0 = -1;
								
								inputString(id0, 9, "Enter student code you want to add");													
								
								c;
								
								printf("\n\n\t\t\t\t\t\t");
								
								p;												
								
								for(int t = 0; t < (*studentCount); t++)
								{
									if(strcmp(students[t].student_id, id0) == 0)
									{	
										found0 = 1;
										
										c;
										
										printf("\033[31m\n\t\t\t\t\t\t[x] Warning: This student code is already exist, try different student code!\033[0m");
										
										exit();
									}
								}																
									
									if(found0 == -1)
									{																																																																																			
										c;
										
										f;
										
										addStudent(students, studentCount, id0);										

										c;																		
											
										goBackOrExit();											
									}
								
								break;
							}
							
						case 4:
							{
								c;
								
								char id2[10];
								
								int found2 = -1;
								
								Student students[50];
    							
								int studentCount = loadStudents(students, &studentCount);
								
								printf("\n\t\t\t\t\t\t\t\t*  UPDATE THE NEW STUDENT:  *");						
								
								inputString(id2, 9, "Enter student code you want to edit");							
								
								for(int z = 0; z < (studentCount); z++)
								{
									if(strcmp(students[z].student_id, id2) == 0)
									{
										found2 = z;
												
										break;
									}									
								}
									
								
								if(found2 == -1)
								{
									c;
									
									printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Student code '%s 'not found!\033[0m", id2);
									
									s;
										
									exit();
								}
									
									else
										{											
											c;
											
											printf("\033[32m\n\t\t\t\t\t\t[*] Found student with code: %s!\033[0m", id2);
											
											s;
											
											c;
											
											printf("\n\t\t\t\t\t\t\t\t\t\t\t*  STUDENT CODE '%s' INFORMATION:  *", id2);
  
    										printf("\n\n\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Email", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
											printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
											
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", students[found2].student_id, students[found2].name, students[found2].email, students[found2].phone, students[found2].dateOfBirth.day, students[found2].dateOfBirth.month, students[found2].dateOfBirth.year, (students[found2].gender == 0) ? "Male" : "Female", "NULL");

            								printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");										
											
											printf("\n\n\t\t\t\t\t\t");
											
											p;
											
											c;
											
											inputString(students[found2].name, 24, "Enter new student name");
											
											inputString(students[found2].phone, 19, "Enter new student phone");																
											
											inputString(students[found2].email, 29, "Enter new student email");
											
											c;					
											
											do 
											{
        										printf("\n\t\t\t\t\t\t-> Enter new student date of birth ( dd mm YYYY ): ");
        
												scanf("%d %d %d", &students[found2].dateOfBirth.day, &students[found2].dateOfBirth.month, &students[found2].dateOfBirth.year);

        										if(students[found2].dateOfBirth.day < 1 || students[found2].dateOfBirth.day > 31 || students[found2].dateOfBirth.month < 1 || students[found2].dateOfBirth.month > 12 || students[found2].dateOfBirth.year < 1000 || students[found2].dateOfBirth.year > 2025)
        										{
            										printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Invalid date of birth, try again!\033[0m");
        										}
        
													else
        												{
            												break;
        												}
    										} 
	
											while(1);		
											
											printf("\n\t\t\t\t\t\t-> Enter new student gender ( 0: Male, 1: Female; 1 character ): ");
																					
											int tempGender1;
											
											f;
											
											do
												{
													printf("\n\t\t\t\t\t\t-> Enter new student gender ( 0: Male, 1: Female; 1 character ): ");
				
													scanf("%d", &tempGender1);
												}
			
											while(tempGender1 != 0 && tempGender1 != 1);
			
											students[found2].gender = (tempGender1 == 0) ? 0 : 1;
											
											saveStudents(students, studentCount);																																							
											
											c;
											
											printf("\033[32m\n\t\t\t\t\t\t[*] Student information updated successfully!\033[0m");																		
											
											goBackOrExit();
										}
									
									break;
							}
							
						case 3:
							{
								c;
								
								char name3[25];
								
								int found3 = -1;
								
								Student students[50];
    							
								int studentCount = loadStudents(students, &studentCount);
								
								inputString(name3, 24, "Enter student name you want to search");
								
								c;
								
								searchStudentsByName(students, studentCount, name3); 
								
								goBackOrExit();
										
								break;																
							}
							
						case 5:
							{
								c;
								
								char id4[10];
								
								int found4 = -1;
								
								Student students[50];
        							
								int studentCount = loadStudents(students, &studentCount);
								
								printf("\n\t\t\t\t\t\t\t\t*  DELETE A STUDENT:  *");
								
								inputString(id4, 9, "Enter student code you want to delete");

								for(int u = 0; u < (studentCount); u++)
								{
									if(strcmp(students[u].student_id, id4) == 0)
									{
										found4 = u;
												
										break;
									}
																					
								}
									
								if(found4 == -1)
								{
									c;
									
									printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Student code '%s 'not found!\033[0m", id4);
										
									exit();																				
								}
									
									else
										{
											c;
											
											printf("\033[32m\n\t\t\t\t\t\t[*] Found student with code: %s!\033[0m", id4);
																																
											s;
											
											c;																				
											
											printf("\n\t\t\t\t\t\t\t\t\t\t\t*  STUDENT CODE '%s' INFORMATION:  *", id4);
  
    										printf("\n\n\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Email", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
											printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
											
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", students[found4].student_id, students[found4].name, students[found4].email, students[found4].phone, students[found4].dateOfBirth.day, students[found4].dateOfBirth.month, students[found4].dateOfBirth.year, (students[found4].gender == 0) ? "Male" : "Female", "NULL");

            								printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");											
										}											
											char yourChoice1;
	
											do
												{
													printf("\n\t\t\t\t\t\t-> Are you sure want to delete this student? ( y / n ): ");
	
													scanf(" %c", &yourChoice1);
	
													yourChoice1 = tolower(yourChoice1);
	
													if(yourChoice1 == 'y')
													{	
														for(int r = found4; r < (studentCount) - 1; r++)
														{
															students[r] = students[r + 1];
														}
														
														(studentCount)--;
														
														saveStudents(students, studentCount);
														
														c;
										
														printf("\033[32m\n\t\t\t\t\t\t[*] Delete this student successfully!\033[0m");
														
														s;
										
														break;
														
													}
	
														else if(yourChoice1 == 'n')
														{
															c;
															
															printf("\033[32m\n\t\t\t\t\t\t[*] You choose not delete this student!\033[0m");
															
															s;
															
															c;
													
															break;			
														}
			
															else
																{
																	c;
					
																	printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");
					
																	s;
					
																	c;
																}
												}
												
												while(1);
																											
								break;
							}
							
						case 6:
							{
								c;
								
								int sortChoice;
								
								do
								{																
									printf("\n\t\t\t\t\t\t+------------x SORT MENU x-------------+\n");
		
									printf("\t\t\t\t\t\t|%-38s|\n\t\t\t\t\t\t", "[1] Sort Students By Name Ascending.");
		
									printf("|%-38s|\n\t\t\t\t\t\t", "[2] Sort Students By Name Descending.");
									
									printf("|%-38s|\n\t\t\t\t\t\t", "[0] Exit The Program.");

									printf("+--------------------------------------+");
								
									printf("\033[1m\n\n\t\t\t\t\t\t-> Enter your choice:\033[1m ");
								
									scanf("%d", &sortChoice);
								
									c;
									
									Student students[50];
        							
									int studentCount = loadStudents(students, &studentCount);
									
									if(sortChoice == 0)
									{
										c;
					
										printf("\033[33m\n\t\t\t\t\t\t\t[*] Exit program!\033[0m\n");
					
										endProgram();
								
										s;
								
										exit(0);
									}
								
									else if(sortChoice == 1)
									{
										for(int i = 0; i < (studentCount) - 1; i++)
										{
											for(int j = 0; j < (studentCount) - i - 1; j++)
											{
												if(strcmp(students[j].name, students[j + 1].name) < 0)
												{
													Student temp = students[j];
												
													students[j] = students[j + 1];
												
													students[j + 1] = temp;
												}
											}	
										}									
									
										displayListStudents();
										
										printf("\n\t\t\t\t\t\t*  Students after Ascending arrangement  *\n");
									}
									
										else if(sortChoice == 2)
										{
											for(int a = 0; a < (studentCount) - 1; a++)
											{
												for(int b = 0; b < (studentCount) - a - 1; b++)
												{
													if(strcmp(students[b].name, students[b + 1].name) > 0)
													{
														Student temp = students[b];
												
														students[b] = students[b + 1];
												
														students[b + 1] = temp;
													}
												}	
											}										
									
											displayListStudents();
											
											printf("\n\n\t\t\t\t\t\t*  Students after Descending arrangement  *\n");
										}
										
											else
												{
													printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");																										
												}
												
									saveStudents(students, studentCount);
									
									goBackOrExit();
										
								}
								
								while(sortChoice != 0 && sortChoice != 1 && sortChoice != 2);
								
								break;	
							}
							
						default:
						{
							printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");
								
							exit();
						}
					}
			}
			
			while(choiceStudentMenu != 0);				
	}
		
	

void manageTeachers(Teacher teachers[], int *teacherCount)
	{
		int choiceTeacherMenu;
		
		do 
			{
				showTeacherMenu();
				
				printf("\033[1m\n\n\t\t\t\t\t\t-> Enter your choice:\033[0m ");
				
				scanf("%d", &choiceTeacherMenu);
				
				switch(choiceTeacherMenu)
					{
						case 0:
							{
								c;
					
								printf("\033[33m\n\t\t\t\t\t\t\t[*] Exit program!\033[0m\n");
					
								endProgram();
								
								s;
								
								exit(0);								
							}
						
						case 1:
							{								
								Teacher teacher[10];
    							
								int teacherCount = loadTeachers(teachers, &teacherCount);
								
								if(teacherCount == 0)
								{
									c;
										
									printf("\033[31m\n\t\t\t\t\t\t[x] Warning: There are currently no teachers in the list!\033[0m");
									
									s;
										
									exit();
								}
									
									else
										{
											c;
											
											displayListTeachers();
											
											goBackOrExit();
										}
																
								break;							
							}
							
						case 2:
							{
								c;
								
								char id12[10];

								int found12 = -1;
								
								inputString(id12, 9, "Enter teacher code you want to add");													
								
								c;
								
								printf("\n\n\t\t\t\t\t\t");
								
								p;												
								
								for(int r = 0; r < (*teacherCount); r++)
								{
									if(strcmp(teachers[r].teacher_id, id12) == 0)
									{	
										found12 = 1;
										
										c;
										
										printf("\033[31m\n\t\t\t\t\t\t[x] Warning: This teacher code is already exist, try different teacher code!\033[0m");
										
										exit();
									}
								}																
									
									if(found12 == -1)
									{																																																																																			
										c;
										
										addTeacher(teachers, teacherCount, id12);										

										c;																		
											
										goBackOrExit();											
									}
								
								break;
							}
							
						case 3:
							{
								c;
								
								char id13[10];
								
								int found13 = -1;
								
								Teacher teachers[10];
    							
								int teacherCount = loadTeachers(teachers, &teacherCount);
								
								printf("\n\t\t\t\t\t\t\t\t*  UPDATE THE NEW TEACHER:  *");						
								
								inputString(id13, 9, "Enter teacher code you want to edit");							
								
								for(int v = 0; v < (teacherCount); v++)
								{
									if(strcmp(teachers[v].teacher_id, id13) == 0)
									{
										found13 = v;
												
										break;
									}									
								}
									
								
								if(found13 == -1)
								{
									c;
									
									printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Teacher code '%s 'not found!\033[0m", id13);
									
									s;
										
									exit();
								}
									
									else
										{											
											c;
											
											printf("\033[32m\n\t\t\t\t\t\t[*] Found teacher with code: %s!\033[0m", id13);
											
											s;
											
											c;
											
											printf("\n\t\t\t\t\t\t\t\t\t\t\t*  TEACHER CODE '%s' INFORMATION:  *", id13);
  
    										printf("\n\n\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Gmail", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
											printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
											
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", teachers[found13].teacher_id, teachers[found13].name, teachers[found13].gmail, teachers[found13].phone, teachers[found13].dateOfBirth.day, teachers[found13].dateOfBirth.month, teachers[found13].dateOfBirth.year, (teachers[found13].gender == 0) ? "Male" : "Female", "NULL");

            								printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");										
											
											printf("\n\n\t\t\t\t\t\t");
											
											p;
											
											c;
											
											inputString(teachers[found13].name, 24, "Enter new teacher name");
											
											c;
											
											inputString(teachers[found13].phone, 19, "Enter new teacher phone");
											
											c;																
											
											inputString(teachers[found13].gmail, 29, "Enter new teacher gmail");
											
											c;					
											
											do 
											{
        										printf("\n\t\t\t\t\t\t-> Enter new teacher date of birth ( dd mm YYYY ): ");
        
												scanf("%d %d %d", &teachers[found13].dateOfBirth.day, &teachers[found13].dateOfBirth.month, &teachers[found13].dateOfBirth.year);

        										if(teachers[found13].dateOfBirth.day < 1 || teachers[found13].dateOfBirth.day > 31 || teachers[found13].dateOfBirth.month < 1 || teachers[found13].dateOfBirth.month > 12 || teachers[found13].dateOfBirth.year < 1000 || teachers[found13].dateOfBirth.year > 2025)
        										{
            										printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Invalid date of birth, try again!\033[0m");
        										}
        
													else
        												{
            												break;
        												}
    										} 
	
											while(1);
											
											c;		
																					
											int tempGender2;
											
											do
												{
													printf("\n\t\t\t\t\t\t-> Enter new teacher gender ( 0: Male, 1: Female; 1 character ): ");
				
													scanf("%d", &tempGender2);
												}
			
											while(tempGender2 != 0 && tempGender2 != 1);
			
											teachers[found13].gender = (tempGender2 == 0) ? 0 : 1;
											
											saveTeachers(teachers, teacherCount);																																							
											
											c;
											
											printf("\033[32m\n\t\t\t\t\t\t[*] Teacher information updated successfully!\033[0m");																		
											
											goBackOrExit();
										}
									
									break;
							}
							
						case 6:
							{
								c;
								
								char name4[25];
								
								int found14 = -1;
								
								Teacher teachers[10];
    							
								int teacherCount = loadTeachers(teachers, &teacherCount);
								
								inputString(name4, 24, "Enter teacher name you want to search");
								
								c;
								
								searchTeachersByName(teachers, teacherCount, name4); 
								
								goBackOrExit();
										
								break;																
							}
							
						case 4:
							{
								c;
								
								char id14[10];
								
								int found14 = -1;
								
								Teacher teachers[10];
        							
								int teacherCount = loadTeachers(teachers, &teacherCount);
								
								printf("\n\t\t\t\t\t\t\t\t*  DELETE A TEACHER:  *");
								
								inputString(id14, 9, "Enter teacher code you want to delete");

								for(int o = 0; o < (teacherCount); o++)
								{
									if(strcmp(teachers[o].teacher_id, id14) == 0)
									{
										found14 = o;
												
										break;
									}
																					
								}
									
								if(found14 == -1)
								{
									c;
									
									printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Teacher code '%s 'not found!\033[0m", id14);
										
									exit();																				
								}
									
									else
										{
											c;
											
											printf("\033[32m\n\t\t\t\t\t\t[*] Found teacher with code: %s!\033[0m", id14);
																																
											s;
											
											c;																				
											
											printf("\n\t\t\t\t\t\t\t\t\t\t\t*  TEACHER CODE '%s' INFORMATION:  *", id14);
  
    										printf("\n\n\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Gmail", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
											printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
											
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", teachers[found14].teacher_id, teachers[found14].name, teachers[found14].gmail, teachers[found14].phone, teachers[found14].dateOfBirth.day, teachers[found14].dateOfBirth.month, teachers[found14].dateOfBirth.year, (teachers[found14].gender == 0) ? "Male" : "Female", "NULL");

            								printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");											
										}											
											char yourChoice2;
	
											do
												{
													printf("\n\t\t\t\t\t\t-> Are you sure want to delete this teacher? ( y / n ): ");
	
													scanf(" %c", &yourChoice2);
	
													yourChoice2 = tolower(yourChoice2);
	
													if(yourChoice2 == 'y')
													{	
														for(int l = found14; l < (teacherCount) - 1; l++)
														{
															teachers[l] = teachers[l + 1];
														}
														
														(teacherCount)--;
														
														saveTeachers(teachers, teacherCount);
														
														c;
										
														printf("\033[32m\n\t\t\t\t\t\t[*] Delete this teacher successfully!\033[0m");
														
														s;
														
														c;
										
														break;
														
													}
	
														else if(yourChoice2 == 'n')
														{
															c;
															
															printf("\033[32m\n\t\t\t\t\t\t[*] You choose not delete this teacher!\033[0m");
															
															s;
															
															c;
													
															break;			
														}
			
															else
																{
																	c;
					
																	printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");
					
																	s;
					
																	c;
																}
												}
												
												while(1);
																											
								break;
							}
							
							case 5:
								{
									
								}
							
						default:
						{
							printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");
								
							exit();
						}
					}
			}
			
			while(choiceTeacherMenu != 0);				
	}
	
	
		
void adminMenu(Student students[], int *studentCount, Class classes[], int *classCount, Admin *admin, Teacher teachers[], int *teacherCount)
{
	printf("\n\t\t\t\t\t       \033[1m*** STUDENT MANAGEMENT SYSTEM USING C ***\033[0m\n");
	
	printf("\n\t\t\t\t\t\t+--------------x\033[1m MENU\033[0m x--------------+\n");
		
	printf("\t\t\t\t\t\t|%-36s|\n\t\t\t\t\t\t", "[1] Students Management.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[2] Classrooms Management.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[3] Teachers Management.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[4] User Guidelines.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[5] About Us.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[0] Exit The Program.");
	
	printf("+------------------------------------+");
	
	int adminMenuChoice;
	
	printf("\033[1m\n\n\t\t\t\t\t\t-> Enter your choice:\033[0m ");
	
	scanf("%d", &adminMenuChoice);
	
	switch(adminMenuChoice)
		{
			case 0:
				{
					c;
					
					printf("\033[33m\n\t\t\t\t\t\t\t[*] Exit program!\033[0m\n");
					
					endProgram();
								
					s;
								
					exit(0);					
				}
				
			case 1:
				{
					c;
					
					manageStudents(students, studentCount);
					
					printf("\n\n\t\t\t\t\t\t");
					
					p;
					
					s;
					
					break;
				}
				
			case 2:
				{									
					manageClasses(classes, classCount, students, *studentCount);
					
					printf("\n\n\t\t\t\t\t\t");
					
					p;
					
					s;
					
					break;
				}
				
			case 3:
				{
					c;
					
					manageTeachers(teachers, teacherCount);
					
					printf("\n\n\t\t\t\t\t\t");
					
					p;
					
					s;
					
					break;
					
				}
				
			case 4:
				{
					c;
										
					printf("\n\t\t\t\t\t\t+---------------------------------------------------------------*\033[1m USER GUIDELINES:\033[0m *---------------------------------------------------------------+");
					
					printf("\n\n\t\t\t\t\t\t-> Use the number and letter keys on your keyboard to interact with different menus in the program.");
					
					printf("\n\n\t\t\t\t\t\t-> Requires correct data entry requirements, limits input data errors and when searching, it will take some time to perform the request.");
					
					printf("\n\n\t\t\t\t\t\t-> Runs on almost any IDE.");
					
					printf("\n\n\t\t\t\t\t\t-> The data of the managed user will be printed in each file with the extension .bin and different name in the same folder containing this program.");
					
					printf("\n\n\t\t\t\t\t\t+--------------------------------------------------------------------------------------------------------------------------------------------------+");
					
					printf("\n\n\n\t\t\t\t\t\t");
					
					p;
					
					c;
					
					break;
				}
				
			case 5:
				{
					c;
					
					printf("\n\t\t\t\t\t\t+----------------------------------------------------------*\033[1m ABOUT US:\033[0m *--------------------------------------------------------------+");
					
					printf("\n\n\t\t\t\t\t\t*  The program was created by N24DTCN021 to create a C program that can manage many different functions to help with managements.  *");
					
					printf("\n\n\t\t\t\t\t\t*  19/04/2006 By Tran Hoang Duy - N24DTCN021 - All rights reserved - No copyright!  *");
					
					printf("\n\n\t\t\t\t\t\t+-------------------------------------------------------------------------------------------------------------------------------------+");
					
					printf("\n\n\n\t\t\t\t\t\t");
					
					p;
					
					c;
					
					break;										
				}
				
			default:
				{
					c;
					
					printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");
					
					s;
					
					break;
				}
		}
		
}



void checkAccountAdmin(Student students[], int *studentCount, Class classes[], int *classCount, Admin *admin) 
{
    Admin adminFromFile, adminInput;
    
	FILE *file;

    file = fopen("adminAccount.bin", "rb");
    
	if(file == NULL) 
	{              
		c;
		
		printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Cannot read data from file 'adminAccount.bin'!\033[0m\n");
		
		s;
		
		exit(1);
    }

    userAndPassword(&adminInput);

    fread(&adminFromFile, sizeof(Admin), 1, file);
    	
	fclose(file);

    if(strcmp(adminInput.userName, adminFromFile.userName) == 0 && strcmp(adminInput.password, adminFromFile.password) == 0) 
		{
        	c;
			
			printf("\033[32m\n\n\t\t\t\t\t\t[*] Email and password match!\033[0m\n");
			
			s;
			
			c;
    	} 
		
		else 
		{
        	c;
			
			printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Email and password do not match, try again!\033[0m\n");
			
			s;
			
			c;
			
			goBackOrExit();
        	
        	userAndPassword(&adminInput);
        	
        	if(strcmp(adminInput.userName, adminFromFile.userName) == 0 && strcmp(adminInput.password, adminFromFile.password) == 0) 
			{
        		c;
			
				printf("\033[32m\n\n\t\t\t\t\t\t[*] Email and password match!\033[0m\n");
			
				s;
			
				c;
    		} 
		
				else 
				{
        			c;
			
					printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Email and password do not match, try again!\033[0m\n");
			
					s;
			
					c;
			
					goBackOrExit();
        	
        			userAndPassword(&adminInput);
   				}
   		}
}
