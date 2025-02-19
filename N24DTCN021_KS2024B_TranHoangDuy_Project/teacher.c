#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <windows.h>

#include <stdbool.h>

#include <conio.h> // getch library

#define c system("cls")

#define p system("pause")

#define f fflush(stdin)

#define s Sleep(2000)

#include "datatypes.h"

#include "teacher.h"



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
	
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t    \033[1m*  ALL TEACHERS:  *\033[0m\n\n");

    printf("\t\t\t\t\t\t+------+----------------------+------------------------------+--------------------+----------------+---------+--------------+\n");
    
	printf("\t\t\t\t\t\t|%-6s|%-22s|%-30s|%-20s|%-16s|%-9s|%-14s|\n", "ID", "Name", "Gmail", "Phone", "Date Of Birth", "Gender", "NO. Course");
    
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
    
	Teacher tempTeacher;

    file3 = fopen("teacherData.bin", "rb");

    if(file3 != NULL) 
    {
        while(fread(&tempTeacher, sizeof(Teacher), 1, file3)) 
        {
            if(strcmp(tempTeacher.teacher_id, id12) == 0) 
            {
                printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Teacher code '%s' already exists!\033[0m\n", id12);
                
				fclose(file3);
				
				s;
                
				exit(0);  
            }
        }
        
		fclose(file3);
    }

    Teacher newTeacher;
    
	strcpy(newTeacher.teacher_id, id12);

    inputString(newTeacher.name, 24, "Enter teacher name");
    
    c;
    
	inputString(newTeacher.phone, 19, "Enter teacher phone number");
	
	c;
    
	inputString(newTeacher.gmail, 29, "Enter teacher gmail");

    do 
    {
        c;
		
		printf("\n\t\t\t\t\t\t-> Enter teacher gender ( 0: Male, 1: Female ): ");
        
		scanf("%d", &newTeacher.gender);
		
		f;
    } 
	
	while(newTeacher.gender != 0 && newTeacher.gender != 1);

    do 
    {
        c;
		
		printf("\n\t\t\t\t\t\t-> Enter teacher date of birth ( dd mm yyyy ): ");
        
		scanf("%d %d %d", &newTeacher.dateOfBirth.day, &newTeacher.dateOfBirth.month, &newTeacher.dateOfBirth.year);
		
		f;

        if(newTeacher.dateOfBirth.day < 1 || newTeacher.dateOfBirth.day > 31 || newTeacher.dateOfBirth.month < 1 || newTeacher.dateOfBirth.month > 12 || newTeacher.dateOfBirth.year < 1000 || newTeacher.dateOfBirth.year > 3000) 
        {
            printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Invalid date of birth, try again!\033[0m\n");
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




void searchTeachersByName(Teacher teachers[], int teacherCount, const char* name1)
{
    int found1 = 0;

    printf("\n\t\t\t\t\t\t\t\t\t\t\t\033[1m*  LIST OF TEACHERS HAVE NAME '%s':  *\033[0m", name1);
  
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
								
								printf("\n\t\t\t\t\t\t\t\t\033[1m*  UPDATE THE NEW TEACHER:  *\033[0m");						
								
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
											
											printf("\n\t\t\t\t\t\t\t\t\t\t\t\033[1m*  TEACHER CODE '%s' INFORMATION:  *\033[0m", id13);
  
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
								
								printf("\n\t\t\t\t\t\t\t\t\033[1m*  DELETE A TEACHER:  *\033[0m");
								
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
									
									s;
										
									exit(0);																				
								}
									
									else
										{
											c;
											
											printf("\033[32m\n\t\t\t\t\t\t[*] Found teacher with code: %s!\033[0m", id14);
																																
											s;
											
											c;																				
											
											printf("\n\t\t\t\t\t\t\t\t\t\t\t\033[1m*  TEACHER CODE '%s' INFORMATION:  *\033[0m", id14);
  
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
							c;
							
							printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");
							
							s;
								
							exit(0);
						}
					}
			}
			
			while(choiceTeacherMenu != 0);				
	}
