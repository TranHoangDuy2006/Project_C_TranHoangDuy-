#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <windows.h>

#include <conio.h> // getch library

#define c system("cls")

#define p system("pause")

#define f fflush(stdin)

#define s Sleep(2000)

#include "datatypes.h"


void checkStringLength(const char *str, int maxLength) 
{
    if(strlen(str) >= maxLength) 
	{ 
        c;
		
		printf("\n\t\t\t\t\t\t[x] Error: String exceeds the allowed character limit, try again!");
        
        s;
        
        exit(0);         
    }	
}


void showMainMenu()
{
	printf("\n\t\t\t\t\t        *** STUDENT MANAGEMENT SYSTEM USING C ***\n");
		
	printf("\n\t\t\t\t\t\t+---------x CHOOSE YOUR ROLE: x---------+\n");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[1] Admin.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[2] Student.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[3] Teacher.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[0] Exit The Program.");
		
	printf("\t\t\t\t\t\t+---------------------------------------+");
		
	printf("\n");
}
	


void showStudentMenu()	
{
	printf("\n\t\t\t\t\t      *** STUDENT MANAGEMENT SYSTEM USING C ***\n");
		
	printf("\n\t\t\t\t\t\t+----------x STUDENT MENU x---------+\n");
		
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
	printf("\n\t\t\t\t\t   *** STUDENT MANAGEMENT SYSTEM USING C ***\n");
		
	printf("\n\t\t\t\t\t\t+--------------x CLASS x-------------+\n");
		
	printf("\t\t\t\t\t\t|%-36s|\n\t\t\t\t\t\t", "[1] Show List Class.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[2] Add A New Class.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[3] Edit A Class.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[4] Delete A Class.");
				
	printf("|%-36s|\n\t\t\t\t\t\t", "[5] Exit The Program.");
		
	printf("+------------------------------------+");
}




		
	
	
void loginMenu()
{
	printf("\n\t\t\t\t\t      *** STUDENT MANAGEMENT SYSTEM USING C ***");
	
	printf("\n\n\t\t\t\t\t\t\t*  ADMIN LOGIN UI:  *");
	
	printf("\n\n\t\t\t\t\t\t##################################");
	
	printf("\n\n\t\t\t\t\t\tEmail:...........................");
	
	printf("\n\n\t\t\t\t\t\tPassword:........................");
	
	printf("\n\n\t\t\t\t\t\t##################################");
}
	


/*
void adminAccount(Admin admin[])
{
	FILE *f1 = fopen("adminAccount.bin", "wb");
	
	if(f1 == NULL)
	{
		perror("\n\t\t\t\t\t\tKhong the mo file 'adminAccount.bin'!");
		
		return;
	}
	
	fwrite(admin, sizeof(Admin), 1, f1);
	
	printf("\n\n\t\t\t\t\t\tDa ghi du lieu vao file 'adminAccount.bin' thanh cong!");	
	
	fclose(f1);
	
}


void readAdminAccount()
{
	FILE *f2 = fopen("adminAccount.bin", "rb");
	
	if(f2 == NULL)
	{
		perror("\nKhong the doc file 'adminAccount.txt'!");
		
		return 0;
	}
	
	char line[100];
	
	fread(&admin, sizeof(Admin), 1, f2);
	
	printf("\n\n\t\t\t\t\t\tDa doc du lieu tu file 'adminAccount.txt' thanh cong!");

	fclose(f2);

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



void endProgram()
{
	printf("\n\t\t\t\t\t\t+---------- THANK YOU ----------+");
	
	printf("\n\t\t\t\t\t\t+------- SEE YOU SOON ----------+");
}



void goBackOrExit()
{
	char choice;
	
	do
	{
		printf("\n\n\t\t\t\t\t\t-> Go back (b) or Exit (e): ");
	
		scanf(" %c", &choice);
	
		choice = tolower(choice);
	
		if(choice == 'b')
		{	
			c;
			
			printf("\n\n\t\t\t\t\t\tReturn to current menu!");
			
			c;
		
			return;
		}
	
			else if(choice == 'e')
			{
				c;
			
				printf("\n\n\t\t\t\t\t\t\tExit program!\n");
			
				endProgram();
				
				printf("\n\n\t\t\t\t\t\t");
				
				p;
			
				exit(0);
			}
			
				else
				{
					c;
					
					printf("\n\n\t\t\t\t\t\t[x] Error: Invalid choice, try again!");
					
					s;
					
					c;
				}
				
	}	
	
	while(1);
}



void saveAccountAdmin() 
{
    FILE *file;
    
	Admin admin;
	
	file = fopen("adminAccount.bin", "wb");
	
	if(file == NULL) 
	{   
		return;
    }
	
	f;
	
	printf("\n\n\n\t\t\t\t\t\t*  FIRST | CREATE ACCOUNT:  *");

    do 
	{
        printf("\n\n\t\t\t\t\t\t-> Enter email: ");
        
		fgets(admin.userName, sizeof(admin.userName), stdin);
        
		admin.userName[strcspn(admin.userName, "\n")] = '\0';

        if(strstr(admin.userName, "@gmail.com") == NULL) 
		{
            printf("\n\t\t\t\t\t\t[x] Error: Your email must contain string '@gmail.com'!\n");
        }
    } 
	
	while(strstr(admin.userName, "@gmail.com") == NULL); 

    printf("\n\t\t\t\t\t\t-> Enter password: ");
	
	encryptPassword(admin.password, sizeof(admin.password));
	
	fwrite(&admin, sizeof(Admin), 1, file);
  
	fclose(file);   
}



void exit()
{									
	printf("\n\n\t\t\t\t\t\t");
								
	p;
								
	c;
}

	
		
void addStudent(Student students[], int *studentCount, char id0[])
{
    FILE *file;
    
    file = fopen("studentData.bin", "wb");
    
    if(file == NULL)
    {
    	return;
	}
		
	Student newStudent;

    strcpy(newStudent.student_id, id0);

    printf("\n\t\t\t\t\t\t-> Enter student name ( max 24 characters ): ");
    
	scanf(" %[^\n]s", newStudent.name);
    
	checkStringLength(newStudent.name, 24);

    printf("\n\t\t\t\t\t\t-> Enter student phone number ( max 19 characters ): ");
    
	scanf(" %[^\n]s", newStudent.phone);
    
	checkStringLength(newStudent.phone, 19);

    printf("\n\t\t\t\t\t\t-> Enter student email ( max 29 characters ): ");
    
	scanf(" %[^\n]s", newStudent.email);
    
	checkStringLength(newStudent.email, 29);

    int tempGender;
    
	do
    {
        printf("\n\t\t\t\t\t\t-> Enter student gender ( 0: Male, 1: Female; 1 character ): ");
        
		scanf("%d", &tempGender);
    } 
	
	while(tempGender != 0 && tempGender != 1);
    
	newStudent.gender = tempGender;
	
	do 
	{
        printf("\n\t\t\t\t\t\t-> Enter student date of birth ( dd mm YYYY ): ");
        
		scanf("%d %d %d", &newStudent.dateOfBirth.day, &newStudent.dateOfBirth.month, &newStudent.dateOfBirth.year);

        if(newStudent.dateOfBirth.day < 1 || newStudent.dateOfBirth.day > 31 || newStudent.dateOfBirth.month < 1 || newStudent.dateOfBirth.month > 12 || newStudent.dateOfBirth.year < 1000 || newStudent.dateOfBirth.year > 3000)
        {
            printf("\n\t\t\t\t\t\t[x] Error: Invalid date of birth, try again!");
        }
        
		else
        {
            break;
        }
    } 
	
	while(1);

    for(int i = 0; i < (*studentCount); i++)
    {
        if(strcmp(students[i].name, newStudent.name) == 0)
        {
            c;
			
			printf("\n\t\t\t\t\t\t[x] Error: Student name '%s' already exists!\n", newStudent.name);
			
			fclose(file);
        	
			exit(0);
        }

        if(strcmp(students[i].phone, newStudent.phone) == 0)
        {
            c;
			
			printf("\n\t\t\t\t\t\t[x] Error: Student phone number '%s' already exists!\n", newStudent.phone);
			
			fclose(file);
            
			exit(0);
        }

        if(strcmp(students[i].email, newStudent.email) == 0)
        {
            c;
			
			printf("\n\t\t\t\t\t\t[x] Error: Student email '%s' already exists!\n", newStudent.email);
			
			fclose(file);
            
			exit(0);
        }
    }

    students[*studentCount] = newStudent;
    
    fwrite(&newStudent, sizeof(Student), 1, file);
    
    c;
    
    printf("\n\t\t\t\t\t\t[*] Write this student data to file 'studentData.bin' successfully!");
    
    fclose(file);
    
	(*studentCount)++;

}



void readStudentsFromFile()
{
    FILE *file = fopen("studentData.bin", "rb");
    
	if(file == NULL)
    {        
		return;
    }
    
    c;
	
	printf("\n\t\t\t\t\t\t[*] Read student data from file 'studentData.bin' successfully!");
	
	s;
	
	c;

    Student tempStudent;
    
	printf("\n\n\t\t\t\t\t\t+----------x STUDENT LIST: x----------+\n");

    while(fread(&tempStudent, sizeof(Student), 1, file)) 
    {
        printf("\n\t\t\t\t\t\t+ Student code: %s", tempStudent.student_id);
        
		printf("\n\n\t\t\t\t\t\t+ Name: %s", tempStudent.name);
        
		printf("\n\n\t\t\t\t\t\t+ Phone: %s", tempStudent.phone);
        
		printf("\n\n\t\t\t\t\t\t+ Email: %s", tempStudent.email);
        
		printf("\n\n\t\t\t\t\t\t+ Gender: %s", (tempStudent.gender == 0) ? "Male" : "Female");
        
		printf("\n\n\t\t\t\t\t\t+--------------------------------------+");
    }

    fclose(file);    
}
	


void displayListStudents(Student students[], int studentCount)
{
    c;
    
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t*  ALL STUDENTS:  *\n\n");

    printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
	printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Email", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");

    for(int i = 0; i < (studentCount); i++)
    {
        printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", students[i].student_id, students[i].name, students[i].email, students[i].phone, students[i].dateOfBirth.day, students[i].dateOfBirth.month, students[i].dateOfBirth.year, (students[i].gender == 0) ? "Male" : "Female", "NULL");
    }

    printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
}



void searchStudentsByName(Student students[], int studentCount, const char* name)
{
    int found = 0;

    printf("\n\t\t\t\t\t\t\t\t\t\t\t*  LIST OF STUDENTS HAVE NAME '%s':  *", name);
  
    printf("\n\n\t\t\t\t\t\t+------+---------------------+------------------------------+--------------------+--------------------+---------------+\n");
    
	printf("\t\t\t\t\t\t|%-6s|%-21s|%-30s|%-20s|%-20s|%-15s|\n", "  ID", "         Name", "             Email", "         Phone", "        Gender", "  NO.Course ");
    
	printf("\t\t\t\t\t\t+------+---------------------+------------------------------+--------------------+--------------------+---------------+\n");
 
    for(int i = 0; i < (studentCount); i++)
    {
        if(strstr(students[i].name, name) != NULL)
        {
            printf("\t\t\t\t\t\t|%-6s|%-21s|%-30s|%-20s|%-20s|%-15s|\n", students[i].student_id, students[i].name, students[i].email, students[i].phone, (students[i].gender == 0) ? "Nam" : "Nu", "NULL");

            printf("\t\t\t\t\t\t+------+---------------------+------------------------------+--------------------+--------------------+---------------+\n");
			
			found = 1;
        }
    }
   
    if(found != 1)
    {
        c;
		
		printf("\n\n\t\t\t\t\t\t[x] Error: No students found with the name '%s'!\n", name);
    }
}

	
	
void addClass(Class classes[], int *classCount, char id7[])
{						
	Class newClass;
	
	strcpy(newClass.class_id, id7);
			
	printf("\n\t\t\t\t\t\t-> Enter class name ( max 24 characters ): ");
		
	scanf(" %[^\n]s", newClass.class_name);
	
	checkStringLength(newClass.class_name, 24);
		
	for(int i = 0; i < (*classCount); i++)
    {
        if(strcmp(classes[i].class_name, newClass.class_name) == 0)
        {
            c;
			
			printf("\n\t\t\t\t\t\t[x] Error: Class name '%s' already exists!\n", newClass.class_name);
        	
			exit(0);
        }

    }
    
    classes[*classCount] = newClass;
		 
	(*classCount)++;
				
}
	
	

void displayListClasses(Class classes[], int classCount)
{
	printf("\n\t\t\t\t\t\t*  ALL CLASSES:  *");
		
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+\n");
		
	printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|", "ID", "Name", "Students");
		
	printf("\n\t\t\t\t\t\t+------+----------------------+------------------------------+\n");
		
	for(int j = 0; j < classCount; j++)
	{			
		printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|\n", classes[j].class_id, classes[j].class_name, "NULL");				
	}
		
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+\n");
}
	



void manageClasses(Class classes[], int *classCount)
{
	int choiceMenuClass;
		
	do
		{				
			c;				
				
			printf("\n\n\t\t\t\t\t\t-> Enter your choice: ");
				
			scanf("%d", &choiceMenuClass);				
				
			switch(choiceMenuClass)
				{
					case 5:
						{
							c;
								
							printf("\n\t\t\t\t\t\tExit program!");
								
							s;
								
							printf("\n\n\t\t\t\t\t\t");
								
							p;
								
							exit(0);								
								
							break;
						}
							
					case 1:
						{
							if(*classCount == 0)
							{
								c;
										
								printf("\n\t\t\t\t\t\t[x] Error: There are currently no classes in the list!");
									
								s;
										
								exit();
							}
									
									else
										{
											displayListClasses(classes, *classCount);
											
											goBackOrExit();
										}
																
								break;
						}
							
						case 2:
							{								
								c;
								
								char id7[10];
								
								int found7 = -1;
								
								printf("\n\t\t\t\t\t\t-> Enter class code ( Check phrase, max 9 characters ): ");
								
								scanf("%9s", id7);
								
								checkStringLength(id7, 9);								
								
								c;
								
								printf("\n\n\t\t\t\t\t\t");
								
								p;												
								
								for(int t = 0; t < (*classCount); t++)
								{
									if(strcmp(classes[t].class_id, id7) == 0)
									{	
										found7 = 1;
										
										c;
										
										printf("\n\t\t\t\t\t\t[x] Error: This class code is already exist, try different class code!");
										
										exit();
									}
								}																
									
									if(found7 == -1)
									{																																																																																			
										c;
										
										f;
										
										addClass(classes, classCount, id7);
										
										printf("\n\n\t\t\t\t\t\t[*] Add class successfully!");
										
										printf("\n\n\t\t\t\t\t\t");
										
										p;
										
										c;
										
										printf("\n\n\n\t\t\t\t\t\t");
										
										p;
											
										c;																		
											
										goBackOrExit();											
									}
								
								break;
							}
							
						case 3:
							{
								c;
								
								char id8[10];
								
								int found8 = -1;
								
								printf("\n\t\t\t\t\t\t-> Enter the class code to edit ( Check phrase, max 9 characters ): ");
								
								scanf("%9s", id8);
								
								checkStringLength(id8, 9);
								
								for(int i = 0; i < (*classCount); i++)
								{
									if(strcmp(classes[i].class_id, id8) == 0)
									{
										found8 = i;
												
										break;
									}
								}
									
								if(found8 == -1)
								{
									printf("\n\t\t\t\t\t\t[x] Error: Class code '%s' not found!", id8);
										
									exit();
								}
									
									else
										{
											printf("\n\t\t\t\t\t\t[*] Found class with code: %d!", id8);
											
											s;
											
											c;																					
											
											printf("\n\t\t\t\t\t\t-> Enter new class name: ");
											
											scanf(" %[^\n]s", classes[found8].class_name);
											
											checkStringLength(classes[found8].class_name, 10);
											
											c;
																						
											printf("\n\t\t\t\t\t\t[*] Class information updated successfully!");
											
											exit();
																						
										}
										
									break;
							}
							
						case 4:
							{
								c;
								
								char id9[6];
								
								int found9 = -1;
								
								printf("\n\t\t\t\t\t\t-> Enter the class code you want to delete ( Check phrase, max 9 characters ): ");
								
								scanf(" %[^\n]s", classes[found9].class_id);
											
								checkStringLength(classes[found9].class_id, 9);
								
								for(int x = 0; x < (*classCount); x++)
								{
									if(strcmp(classes[x].class_id, id9) == 0)
									{
										found9 = x;
												
										break;
									}
								}
									
								if(found9 == -1)
								{
									printf("\n\t\t\t\t\t\t[x] Error: Class code '%s' not found!", id9);
										
									exit();
								}																			
											
									else
										{
											s;
											
											printf("\n\t\t\t\t\t\t[*] Found class with code: %s!", id9);
																																
											s;
											
											c;
											
											printf("\n\n\t\t\t\t\t\t*  CLASS INFORMATIONS:  *");
											
											printf("\n\n\t\t\t\t\t\t-----------------------------");
											
											printf("\n\n\t\t\t\t\t\t+ ID: %s", classes[found9].class_id);
											
											printf("\n\n\t\t\t\t\t\t+ Name: %s", classes[found9].class_name);										
										}
											
											char yourChoice3;
	
											do
												{													
													printf("\n\n\n\t\t\t\t\t\t-> Are you sure want to delete this class? (y/n): ");
	
													scanf(" %c", &yourChoice3);
	
													yourChoice3 = tolower(yourChoice3);
	
													if(yourChoice3 == 'y')
													{	
														for(int g = found9; g < (*classCount) - 1; g++)
														{
															classes[g] = classes[g + 1];
														}
														
														(*classCount)--;
										
														printf("\n\t\t\t\t\t\t[*] Delete this class successfully!");
														
														c;
										
														break;
														
													}
	
														else if(yourChoice3 == 'n')
														{
															c;
															
															printf("\n\t\t\t\t\t\t[*] You choose not delete this class!");
															
															c;
													
															break;			
														}
			
															else
																{
																	c;
					
																	printf("\n\n\t\t\t\t\t\t[x] Error: Invalid choice, try again!");
					
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
								
								printf("\n\t\t\t\t\t\t[x] Error: Invalid choice, try again!");
								
								exit();
							}
					}
			}
			
			while(choiceMenuClass != 5);						
	}
	

	

void manageStudents(Student students[], int *studentCount)
	{
		int choiceStudentMenu;
		
		do 
			{
				showStudentMenu();
				
				printf("\n\n\t\t\t\t\t\t-> Enter your choice: ");
				
				scanf("%d", &choiceStudentMenu);
				
				switch(choiceStudentMenu)
					{
						case 0:
							{
								c;
								
								printf("\n\t\t\t\t\t\tExit program!");
								
								s;
								
								printf("\n\n\t\t\t\t\t\t");
								
								p;
								
								exit(0);								
								
								break;
							}
						
						case 2:
							{
								if(*studentCount == 0)
								{
									c;
										
									printf("\n\t\t\t\t\t\t[x] Error: There are currently no students in the list!");
									
									s;
										
									exit();
								}
									
									else
										{
											displayListStudents(students, *studentCount);
											
											goBackOrExit();
										}
																
								break;							
							}
							
						case 1:
							{
								c;
								
								char id0[10];
								
								int found0 = -1;
								
								printf("\n\t\t\t\t\t\t-> Enter student code ( Check phrase, max 9 characters ): ");
								
								scanf("%9s", id0);
								
								checkStringLength(id0, 9);								
								
								c;
								
								printf("\n\n\t\t\t\t\t\t");
								
								p;												
								
								for(int t = 0; t < (*studentCount); t++)
								{
									if(strcmp(students[t].student_id, id0) == 0)
									{	
										found0 = 1;
										
										c;
										
										printf("\n\t\t\t\t\t\t[x] Error: This student code is already exist, try different student code!");
										
										exit();
									}
								}																
									
									if(found0 == -1)
									{																																																																																			
										c;
										
										f;
										
										addStudent(students, studentCount, id0);
										
										printf("\n\n\t\t\t\t\t\t[*] Add student successfully!");
										
										printf("\n\n\t\t\t\t\t\t");
										
										p;
										
										c;
										
										readStudentsFromFile();
										
										printf("\n\n\n\t\t\t\t\t\t");
										
										p;
											
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
								
								printf("\n\t\t\t\t\t\t\t\t*  UPDATE THE NEW STUDENT:  *");
								
								printf("\n\n\t\t\t\t\t\t-> Enter the student code to edit ( Check phrase, max 9 characters ): ");
								
								scanf("%9s", id2);
								
								checkStringLength(id2, 9);
								
								for(int z = 0; z < (*studentCount); z++)
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
									
									printf("\n\t\t\t\t\t\t[x] Error: Student code '%s 'not found!", id2);
										
									exit();
								}
									
									else
										{											
											s;
											
											printf("\n\t\t\t\t\t\t[*] Found student with code: %s!", id2);
											
											s;
											
											c;
											
											printf("\n\n\t\t\t\t\t\t\t*  STUDENT INFORMATIONS:  *");
											
											printf("\n\t\t\t\t\t\t---------------------------------------");
											
											printf("\n\n\t\t\t\t\t\t+ ID: %s", students[found2].student_id);
											
											printf("\n\n\t\t\t\t\t\t+ Name: %s", students[found2].name);
											
											printf("\n\n\t\t\t\t\t\t+ Email: %s", students[found2].email);
											
											printf("\n\n\t\t\t\t\t\t+ Phone: %s", students[found2].phone);
											
											printf("\n\n\t\t\t\t\t\t+ Gender: %s", (students[found2].gender == 0) ? "Male" : "Female");
											
											printf("\n\t\t\t\t\t\t---------------------------------------");
											
											printf("\n\n\n\t\t\t\t\t\t");
											
											p;
											
											c;
											
											printf("\n\t\t\t\t\t\t-> Enter new student name ( max 24 characters ): ");
    
											scanf(" %[^\n]s", students[found2].name);
											
											checkStringLength(students[found2].name, 24);
											
											printf("\n\t\t\t\t\t\t-> Enter new student phone ( max 19 characters ): ");							
											
											scanf(" %[^\n]s", students[found2].phone);
											
											checkStringLength(students[found2].phone, 19);
											
											printf("\n\t\t\t\t\t\t-> Enter new student email ( max 29 characters ): ");							
											
											scanf(" %[^\n]s", students[found2].email);
											
											checkStringLength(students[found2].email, 29);
											
											do 
											{
        										printf("\n\t\t\t\t\t\t-> Enter new student date of birth ( dd mm YYYY ): ");
        
												scanf("%d %d %d", &students[found2].dateOfBirth.day, &students[found2].dateOfBirth.month, &students[found2].dateOfBirth.year);

        										if(students[found2].dateOfBirth.day < 1 || students[found2].dateOfBirth.day > 31 || students[found2].dateOfBirth.month < 1 || students[found2].dateOfBirth.month > 12 || students[found2].dateOfBirth.year < 1000 || students[found2].dateOfBirth.year > 2025)
        										{
            										printf("\n\t\t\t\t\t\t[x] Error: Invalid date of birth, try again!");
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
											
											c;
											
											printf("\n\t\t\t\t\t\t[*] Student information updated successfully!");																		
											
											goBackOrExit();
										}
									
									break;
							}
							
						case 3:
							{
								c;
								
								char name3[25];
								
								int found3 = -1;
								
								printf("\n\t\t\t\t\t\t-> Enter the student name you want to search ( Check phrase, max 24 characters ): ");
								
								scanf(" %[^\n]s", name3);
    
								checkStringLength(name3, 24);
		
								c;
								
								searchStudentsByName(students, *studentCount, name3); 
								
								goBackOrExit();
										
								break;																
							}
							
						case 5:
							{
								c;
								
								char id4[10];
								
								int found4 = -1;
								
								printf("\n\t\t\t\t\t\t\t\t*  DELETE A STUDENT:  *");
								
								printf("\n\n\t\t\t\t\t\t-> Enter the student code you want to delete ( Check phrase, max 9 characters ): ");
								
								scanf("%9s", id4);
											
								checkStringLength(id4, 9);
								
								for(int u = 0; u < (*studentCount); u++)
								{
									if(strcmp(students[u].student_id, id4) == 0)
									{
										found4 = u;
												
										break;
									}
																					
								}
									
								if(found4 == -1)
								{
									printf("\n\t\t\t\t\t\t[x] Error: Student code '%s 'not found!", id4);
										
									exit();																				
								}
									
									else
										{
											s;
											
											printf("\n\t\t\t\t\t\t[*] Found student with code: %s!", id4);
																																
											s;
											
											c;																				
											
											printf("\n\n\t\t\t\t\t\t*  STUDENT INFORMATIONS:  *");
											
											printf("\n\n\t\t\t\t\t\t-----------------------------");
											
											printf("\n\n\t\t\t\t\t\t+ ID: %s", students[found4].student_id);
											
											printf("\n\n\t\t\t\t\t\t+ Name: %s", students[found4].name);
											
											printf("\n\n\t\t\t\t\t\t+ Email: %s", students[found4].email);
											
											printf("\n\n\t\t\t\t\t\t+ Phone: %s", students[found4].phone);
											
											printf("\n\n\t\t\t\t\t\t+ Gender: %s", (students[found4].gender == 0) ? "Male" : "Female");
											
										//	printf("\n\n\t\t\t\t\t\t+ Total Number of Courses: %s", students[found4].phone);
											
										//	printf("\n\n\t\t\t\t\t\t+ Course 1 Code: %s", students[found4].phone);
											
										//	printf("\n\n\t\t\t\t\t\t+ Course 1 Name: %s", students[found4].phone);
										
											printf("\n\n\t\t\t\t\t\t-----------------------------");
											
										}
											
											char yourChoice1;
	
											do
												{
													f;
													
													printf("\n\n\n\t\t\t\t\t\t-> Are you sure want to delete this student? (y/n): ");
	
													scanf(" %c", &yourChoice1);
	
													yourChoice1 = tolower(yourChoice1);
	
													if(yourChoice1 == 'y')
													{	
														for(int r = found4; r < (*studentCount) - 1; r++)
														{
															students[r] = students[r + 1];
														}
														
														(*studentCount)--;
										
														printf("\n\t\t\t\t\t\t[*] Delete this student successfully!");
														
														s;
														
														c;
										
														break;
														
													}
	
														else if(yourChoice1 == 'n')
														{
															c;
															
															printf("\n\t\t\t\t\t\t[*] You choose not delete this student!");
															
															s;
															
															c;
													
															break;			
														}
			
															else
																{
																	c;
					
																	printf("\n\n\t\t\t\t\t\t[x] Error: Invalid choice, try again!");
					
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
		
									printf("\t\t\t\t\t\t|%-38s|\n\t\t\t\t\t\t", "[1] Sort students by name Descending.");
		
									printf("|%-38s|\n\t\t\t\t\t\t", "[2] Sort students by name Ascending.");

									printf("+--------------------------------------+");
								
									printf("\n\n\t\t\t\t\t\t-> Enter your choice: ");
								
									scanf("%d", &sortChoice);
								
									c;
								
									if(sortChoice == 1)
									{
										for(int i = 0; i < (*studentCount) - 1; i++)
										{
											for(int j = 0; j < (*studentCount) - i - 1; j++)
											{
												if(strcmp(students[j].name, students[j + 1].name) < 0)
												{
													Student temp = students[j];
												
													students[j] = students[j + 1];
												
													students[j + 1] = temp;
												}
											}	
										}
									
										printf("\n\t\t\t\t\t\tStudents after Descending arrangement: ");
									
										displayListStudents(students, *studentCount);
									
										goBackOrExit();
									}
									
										else if(sortChoice == 2)
										{
											for(int a = 0; a < (*studentCount) - 1; a++)
											{
												for(int b = 0; b < (*studentCount) - a - 1; b++)
												{
													if(strcmp(students[b].name, students[b + 1].name) > 0)
													{
														Student temp = students[b];
												
														students[b] = students[b + 1];
												
														students[b + 1] = temp;
													}
												}	
											}
										
											printf("\n\n\t\t\t\t\t\tStudents after Ascending arrangement: ");
									
											displayListStudents(students, *studentCount);
									
											goBackOrExit();
										}
										
											else
												{
													printf("\n\n\t\t\t\t\t\t[x] Error: Invalid choice, try again!");																										
												}
										
								}
								
								while(sortChoice != 1 && sortChoice != 2);
								
								break;	
							}
							
						default:
						{
							printf("\n\t\t\t\t\t\t[x] Error: Invalid choice, try again!");
								
							exit();
						}
					}
			}
			
			while(choiceStudentMenu != 0);				
	}	
	
	
	
void adminMenu(Student students[], int *studentCount, Class classes[], int *classCount)
{
	printf("\n\t\t\t\t\t       *** STUDENT MANAGEMENT SYSTEM USING C ***\n");
	
	printf("\n\t\t\t\t\t\t+--------------x MENU x--------------+\n");
		
	printf("\t\t\t\t\t\t|%-36s|\n\t\t\t\t\t\t", "[1] Students Management.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[2] Classrooms Management.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[3] Teachers Management.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[4] User Guideline.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[5] About Us.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[0] Exit The Program.");
	
	printf("+------------------------------------+");
	
	int adminMenuChoice;
	
	printf("\n\n\t\t\t\t\t\t-> Enter you choice: ");
	
	scanf("%d", &adminMenuChoice);
	
	switch(adminMenuChoice)
		{
			case 0:
				{
					c;
					
					printf("\n\t\t\t\t\t\tExit program!");
								
					s;
								
					exit(0);					
				}
				
			case 1:
				{
					c;
					
					manageStudents(students, studentCount);
					
					printf("\n\n\t\t\t\t\t\t");
					
					p;
					
					break;
				}
				
			case 2:
				{
					c;					
					
					showClassMenu();
					
					manageClasses(classes, classCount);
					
					printf("\n\n\t\t\t\t\t\t");
					
					p;
					
					s;
					
					break;
				}
				
			case 3:
				{
					
				}
				
			case 4:
				{
					c;
										
					printf("\n\t\t\t\t\t\t+--------------------------------------* USER GUIDELINE: *--------------------------------------+");
					
					printf("\n\n\t\t\t\t\t\t-> Use the number and letter keys on your keyboard to interact with different menus in the program.");
					
					printf("\n\n\t\t\t\t\t\t-> Requires correct data entry requirements, limits input data errors and when searching, it will take some time to perform the request.");
					
					printf("\n\n\t\t\t\t\t\t-> Runs on almost any IDE.");
					
					printf("\n\n\t\t\t\t\t\t+-----------------------------------------------------------------------------------------------+");
					
					printf("\n\n\t\t\t\t\t\t");
					
					p;
					
					break;
				}
				
			case 5:
				{
					c;
					
					printf("\n\t\t\t\t\t\t+----------------------------------------------------------* ABOUT US: *----------------------------------------------------------+");
					
					printf("\n\n\t\t\t\t\t\t*  The program was created by N24DTCN021 to create a C program that can manage many different functions to help with managements.  *");
					
					printf("\n\n\t\t\t\t\t\t*  © 19/04/2006 By Tran Hoang Duy - N24DTCN021 - All rights reserved - No copyright!  *");
					
					printf("\n\n\t\t\t\t\t\t+-------------------------------------------------------------------------------------------------------------------------------+");
					
					printf("\n\n\t\t\t\t\t\t");
					
					p;
					
					break;										
				}
				
			default:
				{
					c;
					
					printf("\n\n\t\t\t\t\t\tError: Invalid choice, try again!");
					
					s;
					
					break;
				}
		}
		
}


void checkAccountAdmin(Student students[], int *studentCount, Class classes[], int *classCount) 
{
    Admin adminFromFile, adminInput;
    
	FILE *file;

    file = fopen("adminAccount.bin", "rb");
    
	if(file == NULL) 
	{              
		return;
    }
    
    
	loginMenu();

    printf("\n\n\n\t\t\t\t\t\t*  SECOND | LOGIN ACCOUNT:  *");
	
	printf("\n\n\t\t\t\t\t\t-> Enter email to check: ");
    
	fgets(adminInput.userName, sizeof(adminInput.userName), stdin);
    
	adminInput.userName[strcspn(adminInput.userName, "\n")] = '\0'; 

    printf("\n\t\t\t\t\t\t-> Enter password to check: ");
	
	encryptPassword(adminInput.password, sizeof(adminInput.password));

    fread(&adminFromFile, sizeof(Admin), 1, file);
    
	
	fclose(file);

    if(strcmp(adminInput.userName, adminFromFile.userName) == 0 && strcmp(adminInput.password, adminFromFile.password) == 0) 
		{
        	c;
			
			printf("\n\n\t\t\t\t\t\t[*] Email and password match!\n");
			
			s;
			
			c;
			
			adminMenu(students, studentCount, classes, classCount);
    	} 
		
		else 
		{
        	c;
			
			printf("\n\n\t\t\t\t\t\t[x] Error: Email and password do not match, try again!\n");
			
			s;
			
			c;
        	
        	showMainMenu();
   		}
}
