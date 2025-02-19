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

#include "student.h"


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
				
				s;
				
				exit(0);
            }

            if(strcmp(tempStudent.phone, newStudent.phone) == 0 || strcmp(tempStudent.gmail, newStudent.gmail) == 0) 
            {
                printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Student information already exists!\033[0m\n");
                
				fclose(file);
				
				s;
                
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
    
    inputString(newStudent.gmail, 29, "Enter student gmail");
    
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
	
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t     \033[1m*  ALL STUDENTS:  *\033[0m\n\n");

    printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
	printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Gmail", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
	
	while(fread(&students, sizeof(Student), 1, file))
	{
		printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", students.student_id, students.name, students.gmail, students.phone, students.dateOfBirth.day, students.dateOfBirth.month, students.dateOfBirth.year, (students.gender == 0) ? "Male" : "Female", "NULL");
		
		printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
	}
    
    fclose(file);
}



void searchStudentsByName(Student students[], int studentCount, const char* name)
{
    int found = 0;

    printf("\n\t\t\t\t\t\t\t\t\t\t\t\033[1m*  LIST OF STUDENTS HAVE NAME '%s':  *\033[0m", name);
  
    printf("\n\n\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
	printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Gmail", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
	printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
	for(int i = 0; i < (studentCount); i++)
    {
        if(strstr(students[i].name, name) != NULL)
        {
            printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", students[i].student_id, students[i].name, students[i].gmail, students[i].phone, students[i].dateOfBirth.day, students[i].dateOfBirth.month, students[i].dateOfBirth.year, (students[i].gender == 0) ? "Male" : "Female", "NULL");

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
								
								printf("\n\t\t\t\t\t\t\t\t\033[1m*  UPDATE THE NEW STUDENT:  *\033[0m");						
								
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
											
											printf("\n\t\t\t\t\t\t\t\t\t\t\t\033[1m*  STUDENT CODE '%s' INFORMATION:  *\033[0m", id2);
  
    										printf("\n\n\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Gmail", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
											printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
											
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", students[found2].student_id, students[found2].name, students[found2].gmail, students[found2].phone, students[found2].dateOfBirth.day, students[found2].dateOfBirth.month, students[found2].dateOfBirth.year, (students[found2].gender == 0) ? "Male" : "Female", "NULL");

            								printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");										
											
											printf("\n\n\t\t\t\t\t\t");
											
											p;
											
											c;
											
											inputString(students[found2].name, 24, "Enter new student name");
											
											inputString(students[found2].phone, 19, "Enter new student phone");																
											
											inputString(students[found2].gmail, 29, "Enter new student gmail");
											
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
								
								printf("\n\t\t\t\t\t\t\t\t\033[1m*  DELETE A STUDENT:  *\033[0m");
								
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
											
											printf("\n\t\t\t\t\t\t\t\t\t\t\t\033[1m*  STUDENT CODE '%s' INFORMATION:  *\033[0m", id4);
  
    										printf("\n\n\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Gmail", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
											printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
											
											printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%02d/%02d/%04d      |%-9s|%-14s|\n", students[found4].student_id, students[found4].name, students[found4].gmail, students[found4].phone, students[found4].dateOfBirth.day, students[found4].dateOfBirth.month, students[found4].dateOfBirth.year, (students[found4].gender == 0) ? "Male" : "Female", "NULL");

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
									printf("\n\t\t\t\t\t\t+------------|\033[1m SORT MENU\033[0m |-------------+\n");
		
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
										
										printf("\n\t\t\t\t\t\t\t\t\t\t\t\033[1m*  Students after Ascending arrangement  *\033[0m\n");
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
											
											printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\033[1m*  Students after Descending arrangement  *\033[0m\n");
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
