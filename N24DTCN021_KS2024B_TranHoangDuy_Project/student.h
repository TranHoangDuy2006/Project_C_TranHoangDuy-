#ifndef STUDENT_H  

#define STUDENT_H

#include "datatypes.h"


void showStudentMenu(); // Hien thi menu quan li sinh vien

int loadStudents(Student students[], int *studentCount); // Tai thong tin sinh vien tu file studentData.bin

void saveStudents(Student students[], int studentCount); // Luu thong tin sinh vien vao file studentData.bin

void addStudent(Student students[], int *studentCount, char id0[]); // Quan li them sinh vien vao file studentData.bin

void displayListStudents(); // Hien thi danh sach sinh vien

void manageStudents(Student students[], int *studentCount); // Quan li cac chuc nang sinh vien

void inputString(char *str, int maxLength, const char *prompt); // Kiem tra du lieu dau vao cua nguoi dung nhap

void endProgram(); // Hien thi giao dien thoat chuong trinh

void goBackOrExit(); // Quan li quay tro lai hoac thoat chuong trinh trong menu

void exit(); 


#endif
