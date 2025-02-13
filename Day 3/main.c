#include <stdio.h>

#include <stdlib.h>

#include "function.h"

#include <windows.h>

#define MAX_STUDENTS 50

#define MAX_CLASSES 20

#define b break

#define n printf("\n\n\t\t\t\t\t\t")

#define c system("cls")

#define p system("pause")



int main(int argc, char *argv[]) 
{	
	system("color 0b");
	
	int yourChoice0;
	
	Student students[MAX_STUDENTS];
	
	Class classes[MAX_CLASSES];
	
	int studentCount = 0, classCount = 0;
	
	do
		{						
			c;
			
			showMainMenu();
	
			printf("\n\t\t\t\t\t\t-> Enter your choice: ");
	
			scanf("%d", &yourChoice0);
	
			switch(yourChoice0)
				{
					case 0:
						{
							c;
							
							printf("\n\t\t\t\t\t\t\tExit program!\n");
							
							endProgram();
							
							n;
							
							p;							
							
							exit(0);
						}
						
					case 1:
						{
							c;
							
							loginMenu();
							
							saveAccountAdmin();
							
							c;
							
							checkAccountAdmin(students, &studentCount, classes, &classCount);
							
							adminMenu(students, &studentCount, classes, &classCount);
							
							n;
							
							p;
							
							b;							
						}
						
					case 2:
						{
							c;
							
							manageStudents(students, &studentCount);
							
							n;
							
							p;
							
							b;							
							
						}
						
					case 3:
						{
							c;
							
							
							
							n;
							
							b;							
						}
						
					default:
						{
							c;
							
							printf("\n\n\t\t\t\t\t\tError: Invalid choice, try again!");
							
							n;
							
							p;
							
							b;
						}
				}	
		}
		
		while(yourChoice0 != 0);
	
	return 0;
}
