#include <stdbool.h>

typedef struct
{
	int day, month, year;

} Date;


typedef struct
{
	char student_id[10]; // Nine characters including the Null character
	
	char classroom_id[10];
		
	char name[25];
		
	bool gender;
	
//  Date dateOfBirth;
		
	char phone[20];
		
	char email[30];
	
} Student;
	

typedef struct
{
	char class_id[6];
		
	char teacher_id[10];
		
	char class_name[10];
	
	Student students[];
	
} Class;


typedef struct
{
	char teacher_id[10];
	
	char classroom_id[10];
	
	char name[20];
	
//	Date dateOfBirth;
	
	bool gender;
	
	char email[30];
	
	char phone[20];
	
	Class classes[];

} Teacher;


typedef struct
{
	char userName[30];
	
	char password[10];

} Admin;
