#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <windows.h>

#define c system("cls")

#define p system("pause")

#define f fflush(stdin)

#include "function.h"


void showMainMenu()
{
	printf("\n\t\t\t\t\t        *** STUDENT MANAGEMENT SYSTEM USING C ***\n");
		
	printf("\n\t\t\t\t\t\t+========== CHOOSE YOUR ROLE: ==========+\n");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[1] Admin.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[2] Student.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[3] Teacher.");
		
	printf("\t\t\t\t\t\t|%-39s|\n", "[0] Exit the Program.");
		
	printf("\t\t\t\t\t\t+=======================================+");
		
	printf("\n");
}
	
void adminMenu()
{
	printf("\n\t\t\t\t\t       *** STUDENT MANAGEMENT SYSTEM USING C ***\n");
		
	printf("\n\t\t\t\t\t\t+=============== MENU ===============+\n");
		
	printf("\t\t\t\t\t\t|%-36s|\n\t\t\t\t\t\t", "[1] Students Management.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[2] Classrooms Management.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[3] Teachers Management.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[4] User Guideline.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[5] About Us.");
		
	printf("|%-36s|\n\t\t\t\t\t\t", "[0] Exit The Program.");
		
	printf("+====================================+");
}
	
void showStudentMenu()	
{
	printf("\n\t\t\t\t\t      *** STUDENT MANAGEMENT SYSTEM USING C ***\n");
		
	printf("\n\t\t\t\t\t\t+=========== STUDENT MENU ==========+\n");
		
	printf("\t\t\t\t\t\t|%-35s|\n\t\t\t\t\t\t", "[1] Add A New Student.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[2] Show All Students.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[3] Search A Student.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[4] Edit A Student.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[5] Delete A Student.");
		
	printf("|%-35s|\n\t\t\t\t\t\t", "[0] Exit The Program.");
		
	printf("+===================================+");
}
	

void showStatisticsTable(const Student *students, int studentCount, Class *classes, int classCount, int countMajors)
	{
		int activeClasses = 0, endedClasses = 0, waitingClasses = 0, totalStudent = studentCount, waitingStudent = 0, studyingStudent = 0, suspendedStudent = 0, graduatedStudent = 0;		
		
		printf("\n\n\t\t\t\t\t      *** STUDENT MANAGEMENT SYSTEM USING C ***");
		
		printf("\n\n\t\t\t\t\t\t +------------------------------------+");
		
		printf("\n\t\t\t\t\t\t |%-36s|", "Thong ke khoa hoc:");
		
		printf("\n\t\t\t\t\t\t |So khoa hoc: %-23d|", countMajors);
		
		printf("\n\t\t\t\t\t\t +------------------------------------+");
		
		printf("\n\t\t\t\t\t\t |%-36s|", "Thong ke lop hoc:");
		
		printf("\n\t\t\t\t\t\t |So lop hoc: %-24d|", classCount);
		
		printf("\n\t\t\t\t\t\t |So lop dang hoat dong: %-13d|", activeClasses);
		
		printf("\n\t\t\t\t\t\t |So lop da ket thuc: %-16d|", endedClasses);
		
		printf("\n\t\t\t\t\t\t |So lop dang cho: %-19d|", waitingClasses);
		
		printf("\n\t\t\t\t\t\t +------------------------------------+");
		
		printf("\n\t\t\t\t\t\t |%-36s|", "Thong ke sinh vien:");
		
		printf("\n\t\t\t\t\t\t |Tong so sinh vien: %-17d|", totalStudent);
		
		printf("\n\t\t\t\t\t\t |So sinh vien cho lop: %-14d|", waitingStudent);
		
		printf("\n\t\t\t\t\t\t |So sinh vien dang hoc: %-13d|", studyingStudent);
		
		printf("\n\t\t\t\t\t\t |So sinh vien bao luu / dinh chi: %-3d|", suspendedStudent);
		
		printf("\n\t\t\t\t\t\t |So sinh vien tot nghiep: %-11d|", graduatedStudent);
		
		printf("\n\t\t\t\t\t\t +------------------------------------+");
		
		exit();
		
	}
	
	
void loginMenu()
{
	printf("\n\n\t\t\t\t\t      *** STUDENT MANAGEMENT SYSTEM USING C ***");
	
	printf("\n\n\t\t\t\t\t\tLOGIN");
	
	printf("\n\n\t\t\t\t\t\t==================================");
	
	printf("\n\n\t\t\t\t\t\tEmail: ");
	
	printf("\n\n\t\t\t\t\t\tPassword: ");
	
	printf("\n\n\t\t\t\t\t\t==================================");
}
	
/*
void writeTextFile(Class classes[], int classCount)
{
	FILE *f1 = fopen("data.txt", "w");
	
	if(f1 == NULL)
	{
		perror("\nKhong the mo file 'data.txt'!");
		
		exit(1);
	}
	
	for(int i = 0; i < classCount; i++)
	{
		fprintf(f1,"\n\t\t\t\t\t\tMa lop hoc: %s, Ten lop hoc: %s, Chuyen nganh hoc: %s, Tinh trang lop: %s", classes[i].class_id, classes[i].class_name, classes[i].majors, classes[i].status);				
	}
	
	printf("\n\n\t\t\t\t\t\tDa ghi du lieu vao file 'data.txt' thanh cong!");	
	
	fclose(f1);
	
}


void readTextFile()
{
	FILE *f2 = fopen("data.txt", "r");
	
	if(f2 == NULL)
	{
		perror("\nKhong the doc file 'data.txt'!");
		
		exit(1);
	}
	
	char line[100];
	
	while(fgets(line, sizeof(line), f2) != NULL) 
	{	
		printf("%s ", line);
	}
	
	printf("\n\n\t\t\t\t\t\tDa doc du lieu tu file 'data.txt' thanh cong!");

	fclose(f2);

}
*/	
	
void exit()
{									
	printf("\n\n\t\t\t\t\t\t");
								
	p;
								
	c;
}



void endProgram()
{
	printf("\n\t\t\t\t\t\t========== THANK YOU ==========");
	
	printf("\n\t\t\t\t\t\t======== SEE YOU SOON ========+");
}
	

void addStudent(Student students[], int *studentCount)
{		
	c;
		
	f;
		
	printf("\n\t\t\t\t\t\t-> Enter student code: ");
		
	fgets(students[*studentCount].student_id, sizeof(students[*studentCount].student_id), stdin);
		
	students[*studentCount].student_id[strcspn(students[*studentCount].student_id, "\n")] = '\0';
		
	printf("\n\t\t\t\t\t\t-> Enter student name: ");
		
	fgets(students[*studentCount].name, sizeof(students[*studentCount].name), stdin);
		
	students[*studentCount].name[strcspn(students[*studentCount].name, "\n")] = '\0';
		
	printf("\n\t\t\t\t\t\t-> Enter student phone number: ");
		
	fgets(students[*studentCount].phone, sizeof(students[*studentCount].phone), stdin);
		
	students[*studentCount].phone[strcspn(students[*studentCount].phone, "\n")] = '\0';
		
	printf("\n\t\t\t\t\t\t-> Enter student email: ");
		
	f;
		
	fgets(students[*studentCount].email, sizeof(students[*studentCount].email), stdin);
		
	students[*studentCount].email[strcspn(students[*studentCount].email, "\n")] = '\0';
		
	int tempGender;
		
	do
		{
			printf("\n\t\t\t\t\t\t-> Enter student gender: ");
				
			scanf("%d", &tempGender);
		}
			
	while(tempGender != 0 && tempGender != 1);
			
	students[*studentCount].gender = (tempGender == 0) ? 0 : 1;
				
	(*studentCount)++;
	
}
	
	
void displayListStudents(Student students[], int studentCount)
{		
	c;
		
	printf("\n\t\t\t\t\t\t\t\t\t\t\t*** All students: ***\n\n");	
		
	for(int i = 0; i < studentCount; i++)		 
	{												
		printf("\t\t\t\t\t\t+---------------------------------------------------------------------------------------------+");
			
		printf("\n\t\t\t\t\t\t|%-6s|%-21s|%-30s|%-20s|%-12s|\n","  ID","         Name","             Email","         Phone"," NO.Course ");
			
		printf("\t\t\t\t\t\t%-26s|%-30s|%-20s|%-12s|\n","-------|---------------------","------------------------------","--------------------","------------");
						
		printf("\t\t\t\t\t\t|%-6s|%-21s|%-30s|%-20s|%-12s|\n",students[i].student_id,students[i].name,students[i].email,students[i].email,"1");
		
	// printf("\n\t\t\t\t\t\tTest: %s", (students[i].gender == 0) ? "Nam" : "Nu");																		
	}
		
		printf("\t\t\t\t\t\t+---------------------------------------------------------------------------------------------+");		
					
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
				
				printf("\n\n\t\t\t\t\t\t-> Enter The Choice: ");
				
				scanf("%d", &choiceStudentMenu);
				
				switch(choiceStudentMenu)
					{
						case 0:
							{
								c;
								
								printf("\n\t\t\t\t\t\tReturn main menu!");
								
								Sleep(1000);								
								
								break;
							}
						
						case 2:
							{
								if(*studentCount == 0)
								{
									c;
										
									printf("\n\t\t\t\t\t\tThere are currently no students on the list!");
										
									exit();
								}
									
									else
										{
											displayListStudents(students, *studentCount);
											
											exit();
										}
																
								break;
							
							}
							
						case 1:
							{
								c;
								
								char id0[10];
								
								int found0 = -1;
								
								printf("\n\t\t\t\t\t\tEnter student code ID ( Check Phrase ): ");
								
								f;
								
								fgets(id0, sizeof(id0), stdin);
								
								id0[strcspn(id0, "\n")] = '\0';
								
								for(int t = 0; t < (*studentCount); t++)
								{
									if(strcmp(students[t].student_id, id0) == 0)
									{	
										found0 = 1;
										
										printf("\n\t\t\t\t\t\tError: This ID is already exist!");
										
										exit();
									}
								}																
									
									if(found0)
									{																																											
										addStudent(students, studentCount);
											
										c;
											
										printf("\n\t\t\t\t\t\tAdd student successfully!");
											
										exit();											
									}
								
								break;
							}
							
						case 4:
							{
								c;
								
								char id2[10];
								
								int found2 = -1;
								
								printf("\n\t\t\t\t\t\t\t**** UPDATE THE NEW STUDENT ****");
								
								printf("\n\n\t\t\t\t\t\t-> Enter the student code to edit: ");
								
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
									printf("\n\t\t\t\t\t\tStudent code not found!");
										
									exit();
								}
									
									else
										{											
											Sleep(2000);
											
											printf("\n\t\t\t\t\t\tFound student!");
											
											Sleep(2000);
											
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
											
											printf("\n\t\t\t\t\t\tStudent information updated successfully!");																		
											
											exit();
										}
									
									break;
							}
							
						case 3:
							{
								c;
								
								char name3[25];
								
								int found3 = -1;
								
								printf("\n\t\t\t\t\t\t-> Enter the student name you want to find: ");
								
								f;
								
								fgets(name3, sizeof(name3),stdin);
								
								name3[strcspn(name3, "\n")] = '\0';
								
								for(int i = 0; i < (*studentCount); i++)
								{
									if(strcmp(students[i].name, name3) == 0)
									{
										found3 = i;
										
										break;
									}
								}
								
								if(found3 == -1)
								{
									printf("\n\t\t\t\t\t\tError: Student name not found!");
										
									exit();	
								}
								
									else
										{
											Sleep(2000);
											
											printf("\n\n\t\t\t\t\t\tStudent found!");
											
											Sleep(2000);
											
											c;
											
											printf("\n\n\t\t\t\t\t\tStudent informations: ");
											
											printf("\n\n\t\t\t\t\t\t-------------------------");
											
											printf("\n\n\t\t\t\t\t\tID: %s", students[found3].student_id);
											
											printf("\n\n\t\t\t\t\t\tName: %s", students[found3].name);
											
											printf("\n\n\t\t\t\t\t\tEmail: %s", students[found3].email);
											
											printf("\n\n\t\t\t\t\t\tPhone: %s", students[found3].phone);
											
											printf("\n\n\t\t\t\t\t\tTotal Number of Courses: %s", students[found3].phone);
											
											printf("\n\n\t\t\t\t\t\tCourse 1 Code: %s", students[found3].phone);
											
											printf("\n\n\t\t\t\t\t\tCourse 1 Name: %s", students[found3].phone);																																																																																					
										}
										
								break;																
							}
							
						case 5:
							{
								c;
								
								char id4[10];
								
								int found4 = -1;
								
								printf("\n\t\t\t\t\t\t\t**** DELETE A STUDENT ****");
								
								printf("\n\n\t\t\t\t\t\t-> Enter the student code you want to delete: ");
								
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
											Sleep(2000);
											
											printf("\n\t\t\t\t\t\tStudent found!");
											
											Sleep(2000);
											
											c;
											
											printf("\n\n\t\t\t\t\t\tStudent informations: ");
											
											printf("\n\n\t\t\t\t\t\t-------------------------");
											
											printf("\n\n\t\t\t\t\t\tID: %s", students[found4].student_id);
											
											printf("\n\n\t\t\t\t\t\tName: %s", students[found4].name);
											
											printf("\n\n\t\t\t\t\t\tEmail: %s", students[found4].email);
											
											printf("\n\n\t\t\t\t\t\tPhone: %s", students[found4].phone);
											
											printf("\n\n\t\t\t\t\t\tTotal Number of Courses: %s", students[found4].phone);
											
											printf("\n\n\t\t\t\t\t\tCourse 1 Code: %s", students[found4].phone);
											
											printf("\n\n\t\t\t\t\t\tCourse 1 Name: %s", students[found4].phone);
											
											char yourChoice1[5];
											
											printf("\n\n\n\t\t\t\t\t\tAre you sure want to delete this student? (Y/N): ");
											
											f;
											
											fgets(yourChoice1, sizeof(yourChoice1), stdin);
											
											yourChoice1[strcspn(yourChoice1, "\n")] = '\0';
											
											if(yourChoice1[0] == 'Y' || yourChoice1[0] == 'y')
											{
												for(int r = found4; r < (*studentCount) - 1; r++)
												{
													students[r] = students[r + 1];
													
													(*studentCount)--;
										
													printf("\n\t\t\t\t\t\tDelete student successfully!");
										
													exit();
												}
															
											}
												
												else if(yourChoice1[0] == 'N' || yourChoice1[0] == 'n')
												{
													printf("\n\t\t\t\t\t\tNot delete this student!");
													
													exit();
												}
																																																			
										}																			
																											
								break;
							}
							
						default:
						{
							printf("\n\t\t\t\t\t\tLua chon khong hop le!");
								
							exit();
						}
					}
			}
			
			while(choiceStudentMenu != 0);				
	}	
