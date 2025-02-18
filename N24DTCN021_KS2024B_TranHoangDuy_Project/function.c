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

#include "class.h"

#include "datatypes.h"

#include "student.h"

#include "teacher.h"



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
			c;
			
			printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Input exceeds maximum length ( '%d' characters ), try again!\033[0m\n", maxLength);
            
			continue;
		}


        if(strlen(str) == 0) 
        {
            c;
			
			printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Input data cannot be empty, try again!\033[0m\n");
            
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



void loginAdminMenu()
{
	printf("\n\t\t\t\t\t      \033[1m*** STUDENT MANAGEMENT SYSTEM USING C ***\033[0m");

    printf("\n\n\t\t\t\t\t\t\t\033[1m*  ADMIN LOGIN UI:  *\033[0m");
    
    printf("\n\n\t\t\t\t\t\t+----------------------------------+");
}



void loginUserMenu()
{
	printf("\n\t\t\t\t\t      \033[1m*** STUDENT MANAGEMENT SYSTEM USING C ***\033[0m");

    printf("\n\n\t\t\t\t\t\t\t\033[1m*  USER LOGIN UI:  *\033[0m");
    
    printf("\n\n\t\t\t\t\t\t+----------------------------------+");
}



void loginTeacherMenu()
{
	printf("\n\t\t\t\t\t      \033[1m*** STUDENT MANAGEMENT SYSTEM USING C ***\033[0m");

    printf("\n\n\t\t\t\t\t\t\t\033[1m*  TEACHER LOGIN UI:  *\033[0m");
    
    printf("\n\n\t\t\t\t\t\t+------------------------------------+");
}



void userAndPassword(Admin *admin) 
{
    do 
	{		
		loginAdminMenu();
		
		printf("\033[1m\n\n\t\t\t\t\t\t-> Enter admin email:\033[0m ");
        
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

    printf("\033[1m\n\n\t\t\t\t\t\t-> Enter admin password:\033[0m ");
    
	encryptPassword(admin->password, sizeof(admin->password));
}




void userAndPassword1(User *user) 
{
    do 
	{		
		loginUserMenu();
		
		printf("\033[1m\n\n\t\t\t\t\t\t-> Enter user email:\033[0m ");
        
		scanf(" %[^\n]s", user->userName);

        if(strstr(user->userName, "@email.com") == NULL) 
		{
            c; 
			
			printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Your email must contain string '@email.com'!\033[0m\n");
			
			s;
			
			c;
        }   
	} 
	
	while(strstr(user->userName, "@email.com") == NULL);
	
	printf("\n\t\t\t\t\t\t+----------------------------------+");

    printf("\033[1m\n\n\t\t\t\t\t\t-> Enter user password:\033[0m ");
    
	encryptPassword(user->password, sizeof(user->password));
}



void userAndPassword2(Teacher *teacher) 
{
    do 
	{		
		loginTeacherMenu();
		
		printf("\033[1m\n\n\t\t\t\t\t\t-> Enter teacher email:\033[0m ");
        
		scanf(" %[^\n]s", teacher->userName);

        if(strstr(teacher->userName, "@email.com") == NULL) 
		{
            c; 
			
			printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Your email must contain string '@email.com'!\033[0m\n");
			
			s;
			
			c;
        }   
	} 
	
	while(strstr(teacher->userName, "@email.com") == NULL);
	
	printf("\n\t\t\t\t\t\t+------------------------------------+");

    printf("\033[1m\n\n\t\t\t\t\t\t-> Enter teacher password:\033[0m ");
    
	encryptPassword(teacher->password, sizeof(teacher->password));
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
	


/*
void saveAccount() 
{
    FILE *file;
	
	file = fopen("teacherAccount.bin", "wb");
	
	if(file == NULL) 
	{   
		c;
		
		printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Cannot write data into file 'teacherAccount.bin'!\033[0m\n");
		
		s;
		
		exit(0);
    }
	
	f;

    //loginUserMenu();
    
    Teacher teacher;
    
    userAndPassword2(&teacher);
	
	fwrite(&teacher, sizeof(Teacher), 1, file);
  
	fclose(file);   
}
*/



void exit()
{									
	printf("\n\n\t\t\t\t\t\t");
								
	p;
								
	c;
}


			
void adminMenu(Student students[], int *studentCount, Class classes[], int *classCount, Admin *admin, Teacher teachers[], int *teacherCount)
{
	printf("\n\t\t\t\t\t\t  \033[1m*** STUDENT MANAGEMENT SYSTEM USING C ***\033[0m\n");
	
	printf("\n\t\t\t\t\t\t+--------------|\033[1m ADMIN MENU\033[0m |--------------+\n");
		
	printf("\t\t\t\t\t\t|%-42s|\n\t\t\t\t\t\t", "[1] Students Management.");
		
	printf("|%-42s|\n\t\t\t\t\t\t", "[2] Classrooms Management.");
		
	printf("|%-42s|\n\t\t\t\t\t\t", "[3] Teachers Management.");
		
	printf("|%-42s|\n\t\t\t\t\t\t", "[4] User Guidelines.");
		
	printf("|%-42s|\n\t\t\t\t\t\t", "[5] About Us.");
		
	printf("|%-42s|\n\t\t\t\t\t\t", "[0] Exit The Program.");
	
	printf("+------------------------------------------+");
	
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
		
		exit(0);
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



void checkAccountUser(Student students[], int *studentCount, Class classes[], int *classCount, User *user) 
{
    User userFromFile, userInput;
    
	FILE *file;

    file = fopen("userAccount.bin", "rb");
    
	if(file == NULL) 
	{              
		c;
		
		printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Cannot read data from file 'userAccount.bin'!\033[0m\n");
		
		s;
		
		exit(0);
    }

    userAndPassword1(&userInput);

    fread(&userFromFile, sizeof(User), 1, file);
    	
	fclose(file);

    if(strcmp(userInput.userName, userFromFile.userName) == 0 && strcmp(userInput.password, userFromFile.password) == 0) 
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
        	
        	userAndPassword1(&userInput);
        	
        	if(strcmp(userInput.userName, userFromFile.userName) == 0 && strcmp(userInput.password, userFromFile.password) == 0) 
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
        	
        			userAndPassword1(&userInput);
   				}
   		}
}




void checkAccountTeacher(Student students[], int *studentCount, Class classes[], int *classCount, Teacher *teacher) 
{
    Teacher teacherFromFile, teacherInput;
    
	FILE *file;

    file = fopen("teacherAccount.bin", "rb");
    
	if(file == NULL) 
	{              
		c;
		
		printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Cannot read data from file 'teacherAccount.bin'!\033[0m\n");
		
		s;
		
		exit(0);
    }

    userAndPassword2(&teacherInput);

    fread(&teacherFromFile, sizeof(Teacher), 1, file);
    	
	fclose(file);

    if(strcmp(teacherInput.userName, teacherFromFile.userName) == 0 && strcmp(teacherInput.password, teacherFromFile.password) == 0) 
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
        	
        	userAndPassword2(&teacherInput);
        	
        	if(strcmp(teacherInput.userName, teacherFromFile.userName) == 0 && strcmp(teacherInput.password, teacherFromFile.password) == 0) 
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
        	
        			userAndPassword2(&teacherInput);
   				}
   		}
}
