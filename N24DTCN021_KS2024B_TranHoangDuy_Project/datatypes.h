#ifndef DATATYPES_H  

#define DATATYPES_H


typedef struct
{
	int day, month, year;

} Date;



typedef struct
{
	char student_id[10]; 
	
	char classroom_id[10];
		
	char name[25];
		
	bool gender;
	
	Date dateOfBirth;
		
	char phone[20];
		
	char gmail[30];
	
} Student;
	

typedef struct
{
	char class_id[10];
		
	char teacher_id[10];
		
	char class_name[10];
	
	Student students[];
	
	int studentCount;
	
} Class;


typedef struct
{
	char teacher_id[10];
	
	char classroom_id[10];
	
	char name[25];
	
	Date dateOfBirth;
	
	bool gender;
	
	char gmail[30];
	
	char phone[20];
	
	char userName[20];
	
	char password[10];
	
	Class classes[];

} Teacher;


typedef struct
{
	char userName[20];
	
	char password[10];

} Admin;


typedef struct
{
	char userName[20];
	
	char password[10];

} User;


#endif

