#ifndef CLASS_H  

#define CLASS_H

#include "datatypes.h"



int loadClasses(Class classes[], int *classCount); // Tai thong tin lop hoc tu file classData.bin

void saveClasses(Class classes[], int classCount);  // Luu thong tin lop hoc tu file classData.bin

void addClass(Class classes[], int *classCount, char id7[]); // Quan li them lop hoc vao file classData.bin

void displayListClasses(); // Hien thi danh sach lop hoc

void manageClasses(Class classes[], int *classCount, Student students[], int studentCount); // Quan li cac chuc nang lop hoc

void inputString(char *str, int maxLength, const char *prompt); // Kiem tra du lieu dau vao cua nguoi dung nhap

void endProgram(); // Hien thi giao dien thoat chuong trinh

void goBackOrExit(); // Quan li lua chon quay tro lai hoac thoat chuong trinh trong menu

void exit(); 



#endif
