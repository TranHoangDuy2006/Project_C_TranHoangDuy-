#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <windows.h>

#include <conio.h> // getch library

#define c system("cls")

#define p system("pause")

#define f fflush(stdin)

#define s Sleep(2000)

#include "datatypes.h"


void showMainMenu(); // Hien thi menu chinh

void adminMenu(Student students[], int *studentCount, Class classes[], int *classCount, Admin *admin, Teacher teachers[], int *teacherCount); // Quan li menu admin

void loginAdminMenu(); // Hien thi menu dang nhap admin

void loginUserMenu(); // Hien thi menu dang nhap user

void checkAccountAdmin(Student students[], int *studentCount, Class classes[], int *classCount, Admin *admin); // Kiem tra dang nhap cho admin

void checkAccountUser(Student students[], int *studentCount, Class classes[], int *classCount, User *user); // Kiem tra dang nhap cho user

void checkAccountTeacher(Student students[], int *studentCount, Class classes[], int *classCount, Teacher *teacher); // Kiem tra dang nhap cho teacher

//void saveAccount(); // Luu tai khoan nguoi dung

void encryptPassword(char *password, int maxLength); // Ma hoa mat khau dang nhap

void userAndPassword(Admin *admin); // Quan li dang nhap tai khoan admin

void userAndPassword1(User *user); // Quan li dang nhap tai khoan user

//void addStudentToClass(); Them sinh vien vao lop hoc

void showClassMenu(); // Hien thi menu lop hoc

void exit();


