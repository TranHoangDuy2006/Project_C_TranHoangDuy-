#include <stdio.h>

#include <stdlib.h>

#include "function.h"

#include "student.h"

#include "class.h"

#include "teacher.h"

#include <windows.h>

#define MAX_STUDENTS 50

#define MAX_CLASSES 20

#define MAX_TEACHERS 10

#define b break

#define n printf("\n\n\t\t\t\t\t\t")

#define c system("cls")

#define p system("pause")

#define s Sleep(2000)



int main(int argc, char *argv[]) 
{		
	int yourChoice0;
	
	Student students[MAX_STUDENTS];
	
	Class classes[MAX_CLASSES];
	
	Teacher teachers[MAX_TEACHERS];
	
	Admin admin;
	
	User user;
	
	Teacher teacher;
	
	int studentCount = 0, classCount = 0, teacherCount = 0;
	
	do
		{						
			c;
			
			showMainMenu();
	
			printf("\033[1m\n\t\t\t\t\t\t-> Enter your choice:\033[0m ");
	
			scanf("%d", &yourChoice0);
	
			switch(yourChoice0)
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
							
							checkAccountAdmin(students, &studentCount, classes, &classCount, &admin);
							
							adminMenu(students, &studentCount, classes, &classCount, &admin, teachers, &teacherCount);
							
							adminMenu(students, &studentCount, classes, &classCount, &admin, teachers, &teacherCount);
							
							b;							
						}
						
					case 2:
						{
							c;
							
							checkAccountUser(students, &studentCount, classes, &classCount, &user);
							
							manageStudents(students, &studentCount);
							
							n;
							
							p;
							
							b;							
							
						}
						
					case 3:
						{
							c;
							
							checkAccountTeacher(students, &studentCount, classes, &classCount, &teacher);

							manageTeachers(teachers, &teacherCount);
							
							n;
							
							p;
							
							b;							
						}
						
					default:
						{
							c;
							
							printf("\033[31m\n\n\t\t\t\t\t\t[x] Warning: Invalid choice, try again!\033[0m");
							
							n;
							
							p;
							
							b;
						}
				}	
		}
		
		while(yourChoice0 != 0);
	
	return 0;
}
