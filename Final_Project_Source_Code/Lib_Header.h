#ifndef FINAL_EAGLE_LIBRARY_SYSTEM_LIB_HEADER_H
#define FINAL_EAGLE_LIBRARY_SYSTEM_LIB_HEADER_H

#include <iostream>
using namespace std;


class library_Book
{
private:
    char book_Number[500];
    char book_Name[500];
    char author_Name[500];

public:
    void create_Book();
    void show_Book();
    void modify_Book();

    char* get_Book_Number();

    void report();
};


class student
{
private:
    char ID_Number[500];
    char student_Name[500];
    char stbno[6];
    int token;

public:
    void create_Student();
    void show_Student();
    void modify_Student();

    char* get_ID_Number();
    char* ret_Stu_B_Number();

    int get_Token();
    void add_token();
    void reset_Token();

    void get_Stu_B_Number(char num[]);

    void report();
};

void write_Book();

void write_Student();

void display_A_Book(char n[]);

void display_A_Student(char n[]);

void modify_Book();

void modify_Student();

void delete_Student();

void delete_Book();

void display_All_Students();

void display_All_Books();

void issue_Book();

void book_Return();

void intro();

void book_Menu();

void student_Menu();




#endif //FINAL_EAGLE_LIBRARY_SYSTEM_LIB_HEADER_H

