#ifndef TEACHER_H  

#define TEACHER_H

#include "datatypes.h"


void showTeacherMenu(); // Hien thi menu quan li giao vien

int loadTeachers(Teacher teachers[], int *teacherCount); // Tai thong tin giao vien tu file teacherData.bin

void saveTeachers(Teacher teachers[], int teacherCount); // Luu thong tin giao vien vao file teacherData.bin

void displayListTeachers(); // Hien thi danh sach giao vien

void addTeacher(Teacher teachers[], int *teacherCount, char id12[]); // Quan li them giao vien vao file teacherData.bin

void searchTeachersByName(Teacher teachers[], int teacherCount, const char* name1); // Quan li tim kiem giao vien trong file teacherData.bin

void manageTeachers(Teacher teachers[], int *teacherCount); // Quan li danh sach giao vien

void inputString(char *str, int maxLength, const char *prompt); // Kiem tra du lieu dau vao cua nguoi dung nhap

void endProgram(); // Hien thi giao dien thoat chuong trinh

void goBackOrExit(); // Quan li lua chon quay tro lai hoac thoat chuong trinh trong menu

void exit();


#endif
