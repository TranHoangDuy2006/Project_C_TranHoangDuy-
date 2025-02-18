#include "datatypes.h"


void showMainMenu();

void showTeacherMenu();

void adminMenu(Student students[], int *studentCount, Class classes[], int *classCount, Admin *admin, Teacher teachers[], int *teacherCount);

void loginMenu();

void checkAccountAdmin(Student students[], int *studentCount, Class classes[], int *classCount, Admin *admin);

//void saveAccountAdmin();

int loadTeachers(Teacher teachers[], int *teacherCount);

void saveTeachers(Teacher teachers[], int teacherCount);

void inputString(char *str, int maxLength, const char *prompt); 

void encryptPassword(char *password, int maxLength);

void showStudentMenu();

void exit();

void userAndPassword(Admin *admin);

int loadClasses(Class classes[], int *classCount);

void saveClasses(Class classes[], int classCount);

void displayListTeachers();

int loadStudents(Student students[], int *studentCount);

void saveStudents(Student students[], int studentCount);

void goBackOrExit();

void endProgram();

void addTeacher(Teacher teachers[], int *teacherCount, char id12[]);

void searchTeachersByName(Teacher teachers[], int teacherCount, const char* name1);

//void addStudentToClass();

void checkStringLength(const char *str, int maxLength);

void addStudent(Student students[], int *studentCount, char id0[]);

void displayListStudents();

void addClass(Class classes[], int *classCount, char id7[]);

void displayListClasses();

void manageClasses(Class classes[], int *classCount);

void manageStudents(Student students[], int *studentCount);

void showClassMenu();


