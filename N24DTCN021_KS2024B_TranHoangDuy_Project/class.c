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

#include "class.h"



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
    
	printf("\033[32m\n\n\t\t\t\t\t\t[*] Successfully saved '%d' classes to file 'classData.bin'!\033[0m\n", classCount);
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
								
							printf("\033[33m\n\t\t\t\t\t\t\t[*] Exit program!\033[0m\n");
							
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
											
											printf("\n\t\t\t\t\t\t\t\t\033[1m *  CLASS CODE '%s' INFORMATION:  *\033[0m\n\n", id8);
    
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
											
											printf("\n\t\t\t\t\t\t\t\t\033[1m *  CLASS CODE '%s' INFORMATION:  *\033[0m\n\n", id9);
    
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
								c;
								
								//addStudentToClass();
								
								break;															
							}
							
						default:
							{
								c;
								
								printf("\033[31m\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");
								
								exit();
							}													
					}
			}
			
			while(choiceMenuClass != 0);						
	}
	
