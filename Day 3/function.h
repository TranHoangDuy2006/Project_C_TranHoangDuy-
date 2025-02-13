#include "datatypes.h"


void showMainMenu();

void adminMenu(Student students[], int *studentCount, Class classes[], int *classCount);

void loginMenu();

void checkAccountAdmin(Student students[], int *studentCount, Class classes[], int *classCount);

void saveAccountAdmin();

void readStudentsFromFile();

void encryptPassword(char *password, int maxLength);

void showStudentMenu();

void exit();

void goBackOrExit();

void endProgram();

void checkStringLength(const char *str, int maxLength);

void addStudent(Student students[], int *studentCount, char id0[]);

void displayListStudents(const Student students[], int studentCount);

void addClass(Class classes[], int *classCount, char id7[]);

void displayListClasses(const Class classes[], int classCount);

void manageClasses(Class classes[], int *classCount);

void manageStudents(Student students[], int *studentCount);

void showClassMenu();

//void writeTextFile(Class classes[], int classCount);

//void readTextFile();


