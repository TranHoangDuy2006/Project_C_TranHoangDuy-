#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <windows.h>

#include <conio.h>

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
		
		printf("\n\t\t\t\t\t\tError: String exceeds the allowed character limit, try again!");
        
        s;
        
        exit(0);         
    }	
}


void showMainMenu()
{
	printf("\n\t\t\t\t\t        *** STUDENT MANAGEMENT SYSTEM USING C ***\n");
		
	printf("\n\t\t\t\t\t\t+---------* CHOOSE YOUR ROLE: *---------+\n");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[1] Admin.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[2] Student.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[3] Teacher.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[0] Exit the Program.");
		
	printf("\t\t\t\t\t\t+---------------------------------------+");
		
	printf("\n");
}
	


void showStudentMenu()	
{
	printf("\n\t\t\t\t\t      *** STUDENT MANAGEMENT SYSTEM USING C ***\n");
		
	printf("\n\t\t\t\t\t\t+----------- STUDENT MENU ----------+\n");
		
	printf("\t\t\t\t\t\t|%-35s|\n\t\t\t\t\t\t", "[1] Add A New Student.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[2] Show All Students.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[3] Search A Student.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[4] Edit A Student.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[5] Delete A Student.");
	
	printf("|%-35s|\n\t\t\t\t\t\t", "[6] Sort Students.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[0] Exit The Program.");
	
	printf("+-----------------------------------+");
}



void adminMenu()
{
	printf("\n\t\t\t\t\t       *** STUDENT MANAGEMENT SYSTEM USING C ***\n");
	
	printf("\n\t\t\t\t\t\t+--------------- MENU ---------------+\n");
		
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
					
					showStudentMenu();
					
					c;
				}
				
			case 2:
				{
					
				}
				
			case 3:
				{
					
				}
				
			case 4:
				{
					
				}
				
			case 5:
				{
					
				}
				
			default:
				{
					
				}
		}
		
}
		
	
	
void loginMenu()
{
	printf("\n\t\t\t\t\t      *** STUDENT MANAGEMENT SYSTEM USING C ***");
	
	printf("\n\n\t\t\t\t\t\t\t\tLogin UI: ");
	
	printf("\n\n\t\t\t\t\t\t----------------------------------");
	
	printf("\n\n\t\t\t\t\t\tEmail:...........................");
	
	printf("\n\n\t\t\t\t\t\tPassword:........................");
	
	printf("\n\n\t\t\t\t\t\t----------------------------------");
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


void getPassword(char *password, int maxLength) 
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
					
					printf("\n\n\t\t\t\t\t\tError: Invalid choice, try again!");
					
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
	
	printf("\n\n\n\t\t\t\t\t\t* Create account: *");

    printf("\n\n\t\t\t\t\t\t-> Enter username: ");
    
	fgets(admin.userName, sizeof(admin.userName), stdin);
    
	admin.userName[strcspn(admin.userName, "\n")] = '\0'; 

    printf("\n\t\t\t\t\t\t-> Enter password: ");
	
	getPassword(admin.password, sizeof(admin.password));
	
	fwrite(&admin, sizeof(Admin), 1, file);
  
	fclose(file);   
}



void checkAccountAdmin() 
{
    Admin adminFromFile, adminInput;
    
	FILE *file;

    file = fopen("adminAccount.bin", "rb");
    
	if(file == NULL) 
	{              
		return;
    }
    
    
	loginMenu();

    printf("\n\n\n\t\t\t\t\t\t* Login account: *");
	
	printf("\n\n\t\t\t\t\t\t-> Enter username to check: ");
    
	fgets(adminInput.userName, sizeof(adminInput.userName), stdin);
    
	adminInput.userName[strcspn(adminInput.userName, "\n")] = '\0'; 

    printf("\n\t\t\t\t\t\t-> Enter password to check: ");
	
	getPassword(adminInput.password, sizeof(adminInput.password));

    fread(&adminFromFile, sizeof(Admin), 1, file);
    
	
	fclose(file);

    if(strcmp(adminInput.userName, adminFromFile.userName) == 0 && strcmp(adminInput.password, adminFromFile.password) == 0) 
		{
        	c;
			
			printf("\n\n\t\t\t\t\t\tUsername and password match!\n");
			
			s;
			
			c;
			
			adminMenu();
    	} 
		
		else 
		{
        	c;
			
			printf("\n\n\t\t\t\t\t\tError: Username and password do not match, try again!\n");
			
			s;
			
			c;
        	
        	showMainMenu();
   		}
}
	


void exit()
{									
	printf("\n\n\t\t\t\t\t\t");
								
	p;
								
	c;
}

	
		
void addStudent(Student students[], int *studentCount, char id0[])
{
    c;
    
	f;

    Student newStudent;

    strcpy(newStudent.student_id, id0);

    printf("\n\t\t\t\t\t\t-> Enter student name (max 24 characters): ");
    
	scanf(" %[^\n]s", newStudent.name);
    
	checkStringLength(newStudent.name, 24);

    printf("\n\t\t\t\t\t\t-> Enter student phone number (max 19 characters): ");
    
	scanf(" %[^\n]s", newStudent.phone);
    
	checkStringLength(newStudent.phone, 19);

    printf("\n\t\t\t\t\t\t-> Enter student email (max 29 characters): ");
    
	scanf(" %[^\n]s", newStudent.email);
    
	checkStringLength(newStudent.email, 29);

    int tempGender;
    
	do
    {
        printf("\n\t\t\t\t\t\t-> Enter student gender (0: Male, 1: Female): ");
        
		scanf("%d", &tempGender);
    } 
	
	while (tempGender != 0 && tempGender != 1);
    
	newStudent.gender = tempGender;

    for (int i = 0; i < *studentCount; i++)
    {
        if (strcmp(students[i].name, newStudent.name) == 0)
        {
            printf("\n\t\t\t\t\t\tError: Name '%s' already exists!\n", newStudent.name);
        	
			return;
        }

        if (strcmp(students[i].phone, newStudent.phone) == 0)
        {
            printf("\n\t\t\t\t\t\tError: Phone number '%s' already exists!\n", newStudent.phone);
            
			return;
        }

        if (strcmp(students[i].email, newStudent.email) == 0)
        {
            printf("\n\t\t\t\t\t\tError: Email '%s' already exists!\n", newStudent.email);
            
			return;
        }
    }

    students[*studentCount] = newStudent;
    
	(*studentCount)++;

}

	
	

void displayListStudents(Student students[], int studentCount)
{		
	c;
		
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t*  All students:  *\n\n");
	
	printf("\t\t\t\t\t\t+------+---------------------+------------------------------+--------------------+--------------------+---------------+");	
			
	printf("\n\t\t\t\t\t\t|%-6s|%-21s|%-30s|%-20s|%-20s|%-15s|\n","  ID","         Name","             Email","         Phone","        Gender","  NO.Course ");	
		
	for(int i = 0; i < studentCount; i++)		 
	{															
		printf("\t\t\t\t\t\t%-26s|%-30s|%-20s|%-20s|%-15s|\n","+------|---------------------","------------------------------","--------------------","--------------------","---------------");
						
		printf("\t\t\t\t\t\t|%-6s|%-21s|%-30s|%-20s|%-20s|%-15s|\n", students[i].student_id, students[i].name, students[i].email, students[i].phone, (students[i].gender == 0) ? "Nam" : "Nu", "1");
																		
	}		
		printf("\t\t\t\t\t\t+------+---------------------+------------------------------+--------------------+--------------------+---------------+");		
					
}



void searchStudentsByName(Student students[], int studentCount, const char* name)
{
    int found = 0;

    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t* List of students name '%s': *", name);
  
    printf("\n\n\t\t\t\t\t\t+------+---------------------+------------------------------+--------------------+--------------------+---------------+\n");
    
	printf("\t\t\t\t\t\t|%-6s|%-21s|%-30s|%-20s|%-20s|%-15s|\n", "  ID", "         Name", "             Email", "         Phone", "        Gender", "  NO.Course ");
    
	printf("\t\t\t\t\t\t+------+---------------------+------------------------------+--------------------+--------------------+---------------+\n");
 
    for(int i = 0; i < studentCount; i++)
    {
        if(strstr(students[i].name, name) != NULL)
        {
            printf("\t\t\t\t\t\t|%-6s|%-21s|%-30s|%-20s|%-20s|%-15s|\n", students[i].student_id, students[i].name, students[i].email, students[i].phone, (students[i].gender == 0) ? "Nam" : "Nu", "1");

            printf("\t\t\t\t\t\t+------+---------------------+------------------------------+--------------------+--------------------+---------------+\n");
			
			found = 1;
        }
    }
   
    if(found != 1)
    {
        c;
		
		printf("\n\n\t\t\t\t\t\tError: No students found with the name '%s'!\n", name);
    }
}

	
/*	
void addClass(Class classes[], int *classCount)
{						
	printf("\n\t\t\t\t\t\t-> Nhap ma lop hoc: ");
		
	f;
		
	fgets(classes[*classCount].class_id, sizeof(classes[*classCount].class_id), stdin);
	
	classes[*classCount].class_id[strcspn(classes[*classCount].class_id, "\n")] = '\0';
		
	printf("\n\t\t\t\t\t\t-> Nhap ten lop hoc: ");
		
	f;
		
	fgets(classes[*classCount].class_name, sizeof(classes[*classCount].class_name), stdin);
		
	classes[*classCount].class_name[strcspn(classes[*classCount].class_name, "\n")] = '\0';
		
	printf("\n\t\t\t\t\t\t-> Nhap nganh hoc: ");
		
	f;
		
	fgets(classes[*classCount].majors, sizeof(classes[*classCount].majors), stdin);
		
	classes[*classCount].majors[strcspn(classes[*classCount].majors, "\n")] = '\0';
		
	printf("\n\t\t\t\t\t\t-> Nhap trang thai lop hoc: ");
		
	f;
		
	fgets(classes[*classCount].status, sizeof(classes[*classCount].status), stdin);
		
	classes[*classCount].status[strcspn(classes[*classCount].status, "\n")] = '\0';
		
	(*classCount)++;
				
	}
	
	
void displayListClasses(Class classes[], int classCount)
	{
		printf("\n\t\t\t\t\t\t* Danh sach cac lop hoc: ");
		
		for(int j = 0; j < classCount; j++)
		{	
			printf("\n\n\t\t\t\t\t\tThong tin lop hoc thu %0d: ", j + 1);
				
			printf("\n");
		
			printf("\n\t\t\t\t\t\tMa lop hoc: %s, Ten lop hoc: %s, Chuyen nganh hoc: %s, Trang thai lop hoc: %s", classes[j].class_id, classes[j].class_name, classes[j].majors, classes[j].status);
				
		}
	}
	

void manageClasses(Class classes[], int *classCount, int *countMajors)
{
	int choiceMenuClass;
		
	do
		{				
			c;				
				
			printf("\n\n\t\t\t\t\t\t-> Nhap lua chon cua ban: ");
				
			scanf("%d", &choiceMenuClass);				
				
			switch(choiceMenuClass)
				{
					case 7:
						{
							c;
								
							printf("\n\t\t\t\t\t\tQuay lai Menu!");
								
							Sleep(2000);
								
							c;
								
							break;
						}
							
					case 1:
						{
							if(*classCount == 0)
							{
								c;
										
									printf("\n\t\t\t\t\t\tKhong co lop hoc nao trong danh sach!");
										
									exit();																	
								}
									
									else
										{
											c;
											
											displayListClasses(classes, *classCount);
											
											exit();
										}
										
									break;
							}
							
						case 2:
							{
								if(*classCount >= 20)
								{
										printf("\n\t\t\t\t\t\tLop hoc da day, khong the them lop hoc moi!");
										
										exit();
								}
									
									else
										{
											c;
											
											addClass(classes, classCount);
											
											(*countMajors)++;
											
											c;
											
											printf("\n\t\t\t\t\t\tThem lop hoc thanh cong!");
											
											exit();
										}
										
									break;
							}
							
						case 3:
							{
								c;
								
								char id0[6];
								
								int found = -1;
								
								f;
								
								printf("\n\t\t\t\t\t\t-> Nhap ma lop hoc can chinh sua: ");
								
								fgets(id0, sizeof(id0), stdin);
								
								id0[strcspn(id0, "\n")] = '\0';
								
								for(int i = 0; i < (*classCount); i++)
								{
									if(strcmp(classes[i].class_id, id0) == 0)
									{
										found = i;
												
										break;
									}
								}
									
								if(found == -1)
								{
									printf("\n\t\t\t\t\t\tMa lop hoc khong ton tai!");
										
									exit();
								}
									
									else
										{
											printf("\n\t\t\t\t\t\tDa tim thay lop hoc co ma la %d!", found);
											
											Sleep(2000);
											
											c;
											
											printf("\n\t\t\t\t\t\t-> Nhap ma lop hoc moi: ");
											
											fgets(classes[found].class_id, sizeof(classes[found].class_id), stdin);
											
											classes[found].class_id[strcspn(classes[found].class_id, "\n")] = '\0';
											
											printf("\n\t\t\t\t\t\t-> Nhap ten moi cho lop hoc: ");
											
											fgets(classes[found].class_name, sizeof(classes[found].class_name), stdin);
											
											classes[found].class_name[strcspn(classes[found].class_name, "\n")] = '\0';
											
											printf("\n\t\t\t\t\t\t-> Nhap chuyen nganh hoc moi: ");
											
											fgets(classes[found].majors, sizeof(classes[found].majors), stdin);
											
											classes[found].majors[strcspn(classes[found].majors, "\n")] = '\0';
											
											printf("\n\t\t\t\t\t\t-> Nhap trang thai lop hoc: ");
											
											fgets(classes[found].status, sizeof(classes[found].status), stdin);
											
											classes[found].status[strcspn(classes[found].status, "\n")] = '\0';
											
											printf("\n\t\t\t\t\t\tCap nhat thong tin lop hoc thanh cong!");
											
											exit();
																						
										}
										
									break;
							}
							
						case 4:
							{
								c;
								
								char id1[6];
								
								int found1 = -1;
								
								f;
								
								printf("\n\t\t\t\t\t\t-> Nhap ma lop hoc can xoa: ");
								
								fgets(id1, sizeof(id1), stdin);
								
								id1[strcspn(id1, "\n")] = '\0';
								
								for(int x = 0; x < (*classCount); x++)
								{
									if(strcmp(classes[x].class_id, id1) == 0)
									{
										found1 = x;
												
										break;
									}
								}
									
								if(found1 == -1)
								{
									printf("\n\t\t\t\t\t\tMa lop hoc khong ton tai!");
										
									exit();
								}																			
											
									else
										{
											for(int k = found1; k < (*classCount) - 1; k++)
											{
												classes[k] = classes[k + 1];
											}
														
											(*classCount)--;
													
											printf("\n\t\t\t\t\t\tDa xoa lop hoc thanh cong!");
													
											exit();
										}
									
									break;							
							}
							
						case 5:
							{
								c;
								
								writeTextFile(classes, *classCount);
								
								exit();
								
								break;
							}
							
						case 6:
							{
								c;
								
								readTextFile();
								
								exit();
								
								break;
							}
							
						default:
							{
								c;
								
								printf("\n\t\t\t\t\t\tLua chon khong hop le!");
								
								exit();
							}
					}
			}
			
			while(choiceMenuClass != 7);						
	}
	
*/
	

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
								
								exit(0);								
								
								break;
							}
						
						case 2:
							{
								if(*studentCount == 0)
								{
									c;
										
									printf("\n\t\t\t\t\t\tError: There are currently no students on the list!");
									
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
								
								printf("\n\t\t\t\t\t\t-> Enter student code ( Check phrase ): ");
								
								f;
								
								scanf("%9s", id0);
								
								checkStringLength(id0, sizeof(id0));								
								
								c;
								
								printf("\n\n\t\t\t\t\t\t");
								
								p;												
								
								for(int t = 0; t < (*studentCount); t++)
								{
									if(strcmp(students[t].student_id, id0) == 0)
									{	
										found0 = 1;
										
										c;
										
										printf("\n\t\t\t\t\t\tError: This student code is already exist!");
										
										exit();
									}
								}																
									
									if(found0 == -1)
									{																																																																																			
										addStudent(students, studentCount, id0);
											
										c;
											
										printf("\n\t\t\t\t\t\tAdd student successfully!");
											
										goBackOrExit();											
									}
								
								break;
							}
							
						case 4:
							{
								c;
								
								char id2[10];
								
								int found2 = -1;
								
								printf("\n\t\t\t\t\t\t\t****  UPDATE THE NEW STUDENT ****");
								
								printf("\n\n\t\t\t\t\t\t-> Enter the student code to edit ( Check phrase ): ");
								
								f;
								
								fgets(id2, sizeof(id2), stdin);
								
								id2[strcspn(id2, "\n")] = '\0';
								
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
									printf("\n\t\t\t\t\t\tError: Student code not found!");
										
									exit();
								}
									
									else
										{											
											s;
											
											printf("\n\t\t\t\t\t\tFound student!");
											
											s;
											
											c;
											
											printf("\n\t\t\t\t\t\t-> Enter new student code: ");
											
											f;
											
											fgets(students[found2].student_id, sizeof(students[found2].student_id), stdin);
											
											students[found2].student_id[strcspn(students[found2].student_id, "\n")] = '\0';
											
											printf("\n\t\t\t\t\t\t-> Enter new student name: ");							
											
											fgets(students[found2].name, sizeof(students[found2].name), stdin);
											
											students[found2].name[strcspn(students[found2].name, "\n")] = '\0';
											
											printf("\n\t\t\t\t\t\t-> Enter new student phone: ");							
											
											fgets(students[found2].phone, sizeof(students[found2].phone), stdin);
											
											students[found2].phone[strcspn(students[found2].phone, "\n")] = '\0';
											
											printf("\n\t\t\t\t\t\t-> Enter new student email: ");							
											
											fgets(students[found2].email, sizeof(students[found2].email), stdin);
											
											students[found2].email[strcspn(students[found2].email, "\n")] = '\0';
											
											int tempGender1;
											
											do
												{
													printf("\n\t\t\t\t\t\t-> Enter new student gender ( 0: Male, 1: Female ): ");
				
													scanf("%d", &tempGender1);
												}
			
											while(tempGender1 != 0 && tempGender1 != 1);
			
											students[found2].gender = (tempGender1 == 0) ? 0 : 1;																																								
											
											c;
											
											printf("\n\t\t\t\t\t\tStudent information updated successfully!");																		
											
											goBackOrExit();
										}
									
									break;
							}
							
						case 3:
							{
								c;
								
								char name3[25];
								
								int found3 = -1;
								
								printf("\n\t\t\t\t\t\t-> Enter the student name you want to search ( Check phrase ): ");
								
								f;
								
								fgets(name3, sizeof(name3),stdin);
								
								name3[strcspn(name3, "\n")] = '\0';
								
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
								
								printf("\n\t\t\t\t\t\t\t**** DELETE A STUDENT ****");
								
								printf("\n\n\t\t\t\t\t\t-> Enter the student code you want to delete ( Check phrase ): ");
								
								f;
								
								fgets(id4, sizeof(id4), stdin);
								
								id4[strcspn(id4, "\n")] = '\0';
								
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
									printf("\n\t\t\t\t\t\tError: Student code not found!");
										
									exit();																				
								}
									
									else
										{
											s;
											
											printf("\n\t\t\t\t\t\tStudent found!");
											
											s;
											
											c;
											
											printf("\n\n\t\t\t\t\t\tStudent informations: ");
											
											printf("\n\n\t\t\t\t\t\t-----------------------------");
											
											printf("\n\n\t\t\t\t\t\tID: %s", students[found4].student_id);
											
											printf("\n\n\t\t\t\t\t\tName: %s", students[found4].name);
											
											printf("\n\n\t\t\t\t\t\tEmail: %s", students[found4].email);
											
											printf("\n\n\t\t\t\t\t\tPhone: %s", students[found4].phone);
											
											printf("\n\n\t\t\t\t\t\tGender: %s", (students[i].gender == 0) ? "Nam" : "Nu");
											
											printf("\n\n\t\t\t\t\t\tTotal Number of Courses: %s", students[found4].phone);
											
											printf("\n\n\t\t\t\t\t\tCourse 1 Code: %s", students[found4].phone);
											
											printf("\n\n\t\t\t\t\t\tCourse 1 Name: %s", students[found4].phone);
											
										}
											
											char yourChoice1;
	
											do
												{
													f;
													
													printf("\n\n\n\t\t\t\t\t\tAre you sure want to delete this student? (Y/N): ");
	
													scanf(" %c", &yourChoice1);
	
													yourChoice1 = tolower(yourChoice1);
	
													if(yourChoice1 == 'y')
													{	
														for(int r = found4; r < (*studentCount) - 1; r++)
														{
															students[r] = students[r + 1];
														}
														
														(*studentCount)--;
										
														printf("\n\t\t\t\t\t\tDelete student successfully!");
														
														c;
										
														break;
														
													}
	
														else if(yourChoice1 == 'n')
														{
															c;
															
															printf("\n\t\t\t\t\t\tYou choose not delete this student!");
															
															c;
													
															break;			
														}
			
															else
																{
																	c;
					
																	printf("\n\n\t\t\t\t\t\tError: Invalid choice, try again!");
					
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
									printf("\n\t\t\t\t\t\t+------------* SORT MENU *-------------+\n");
		
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
									
										printf("\n\n\t\t\t\t\t\tStudents after descending arrangement: ");
									
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
										
											printf("\n\n\t\t\t\t\t\tStudents after ascending arrangement: ");
									
											displayListStudents(students, *studentCount);
									
											goBackOrExit();
										}
										
											else
												{
													printf("\n\n\t\t\t\t\t\tError: Invalid choice, try again!");																										
												}
										
								}
								
								while(sortChoice != 1 && sortChoice != 2);
								
								break;	
							}
							
						default:
						{
							printf("\n\t\t\t\t\t\tError: Invalid choice, try again!");
								
							exit();
						}
					}
			}
			
			while(choiceStudentMenu != 0);				
	}	
