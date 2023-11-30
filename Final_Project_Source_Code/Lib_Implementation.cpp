#include "Lib_Header.h"
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <iostream>
/// ----------------------------------Start of Project 11/8/2023 - Collaboration-------------------------------------///
///------------------------------------------------------------------------------------------------------------------///
///------------------------------------------------Notes:------------------------------------------------------------///
/// 1.) (Book_issue) function only allows you to have one book at a time, look into having more than one book.
/// 2.) See about possible get/set functions for private data members. (Complete)
/// 3.) Set-precision in constructor intro can be reworked depending on how it looks on execution.
/// 4.) Can use derived classes with filestream class with either library_book or student class.
/// 5.) Need to throw in exception handling for user input
/// 6.) modify_student I may need your help with because I am not sure which function you dedicated to that.
/// 7.) We may also need to rework our private data members to actual "char" data types. I am running into some issues
///     with modifying the book, I had to rework my types to some chars. We can discuss this soon.




/// 11/12 Note:
/// 1.) Make get/set functions for the "int token" when you find the time. I had to start it for a function so I set it
///     up already in your class. (Complete)


/// 2.) Added your tokens.
/// 3.) Added a function names that we both need to use so double check before you start coding =).




/// Admissions number used in some functions needs to be updated to student ID number
///---------------------------------------------End of Notes---------------------------------------------------------///




///----------------------------------------Who-Did-What-When-Log-----------------------------------------------------///
///-------------------------------------------NASH WORK LOG:---------------------------------------------------------///
/// Solo work 11/8/2023:
/// 11/8 - Worked on Library_Book Class.
/// 11/8 - Worked on Functions to write into a file.
/// 11/8 - Worked on Constructor Intro (Initialized private data members so no wonky variable numbers).




/// Solo Work 11/9/2023:
/// 11/9 - Worked on Get/Set functions for our private data members for "library_Book" class.
/// 11/9 - Reworked "create_A_Book" function to get/set all private data members.
/// 11/9 - Need to continue work on the create_A_Book function. It is wonky as hell.




/// Solo Work 11/10/2023:
/// 11/10 - Fixed & tested "create_A_Book function" with get/set functions.
/// 11/10 - Added a Filestream Class. Just makes sense to have that in a separate class.
/// 11/10 - Finished "show_Book_Information" function that uses get functions.
/// 11/10 - Worked on "status_Report" function.




/// Solo work 11/12:
/// Worked on modify_Book function, may need to work on it more.
/// Finished display_All_Students function.
/// Fixed some value types to chars across the board in our project to help out with fluidity.
/// Finished introduction function.





///------------------------------------------MIKAYLA WORK LOG:-------------------------------------------------------///
/// Solo work 11/09:
/// Worked on function definitions for get/set functions inside student class.
/// Initialized object Student for class student.
/// Worked on function definitions for create_acct, show_acct_info, and modify_acct.




/// Solo work 11/11:
/// Worked on adding scope resolution operator to show_acct_info, modify_info, and create_acct functions.
/// Added constructor implementation for student.
/// Added local instances book and stu inside of write_Book and write_Student function to avoid UB.
/// Created and tested read function. It compiles, but isn't able to pull book numbers that have been stored from
/// the write function.
/// Added a try and catch block inside of the read function.


/// Solo work 11/12.
/// Commented out function descriptions.


/// Solo work 11/18:
/// Changed private data members to strings in class student.
/// Altered existing get/set functions for private data members.
/// Made get and setter functions for int token inside of class student.
/// Created a delete student and delete book function.


/// Solo work 11/19:
/// Created a display books function.
/// Created a issue books function.
/// Created an administration menu function.
/// Fixed inconsistencies in referencing book_Information.txt and student_Information.txt throughout code.
/// Reorganized some of the code for better readability.




///--------------------------------------End of Who-Did-What-When-Log------------------------------------------------///
///------------------------------------------------------------------------------------------------------------------///


//*******************************************************************************************************************///
//------------------------------------------___Start of Program___----------------------------------------------------//
//********************************************************************************************************************//


///********************************************Library-Functions*****************************************************///
// Na - Finished

///Function to create a book to be stored in 3 private data members.
void library_Book::create_Book()
{
    cout << "\n\t\t  Enter The Book Number: ";
    cin.ignore();
    cin >> book_Number;
    cout << "\n\t\t  Enter The Name of The Book: ";
    cin.ignore();
    cin.getline(book_Name,40);
    cout << "\n\t\t  Enter The Authors Name: ";
    std::cin.getline(author_Name,50);
    cout << "\n\t\t  Book Created Successfully: ";
}


///Function to display the entirety of a book.
void library_Book::show_Book()
{
    cout << "\n\t\t  Book Number: " << book_Number;
    cout << "\n\t\t  Book Name: " << book_Name;
    cout << "\n\t\t  Authors Name: " << author_Name;
}


///Function to modify a book already stored in our private data members.
void library_Book::modify_Book()
{
    cout << "\n\t\t  Book Number: " << book_Number;
    cout << "\n\t\t  Modify Book Name: ";
    cin.ignore();
    cin.getline(book_Name,50);
    cout << "\n\t\t  Modify Authors Name: ";
    cin.getline(author_Name,50);
}

/// Function to return our Book Number.
char* library_Book::get_Book_Number() {return book_Number;}

/// Function that will report all books saved in our .dat files.
void library_Book::report(){cout << "\t\t  " << book_Number << setw(37) << book_Name << setw(30) << author_Name << endl;}
///**************************************************END*************************************************************///






///********************************************Student-Functions*****************************************************///
// Na - Finished

/// Function to create a student to be stored in data members.
void student::create_Student()
{
    cout << "\n\t\t  Enter The ID Number: ";
    cin >> ID_Number;
    cout << "\n\t\t  Enter The Name of The Student: ";
    cin.ignore();
    std::cin.getline(student_Name,20);
    token = 0;
    stbno[0] =  '/0';
    cout << "\n\t\t  Student Record Created Successfully";
}


/// Function to display the entirety of a student's records.
void student::show_Student()
{
    cout << "\n\t\t  ID Number: " << ID_Number;
    cout << "\n\t\t  Student Name: ";
    puts(student_Name);
    cout << "\t\t  Number of Books issued: " << token << endl;
    if (token == 1)
    {
        cout << "\n\t\t  Book Number: " << stbno;
    }
}

/// Function to modify a current student already store in our private data members.
void student::modify_Student()
{
    cout << "\n\t\t  ID Number: " << ID_Number;
    cout << "\n\t\t  Modify Student Name: ";
    cin.ignore();
    cin.getline(student_Name,50);
}


/// Function to return our student ID number to the console.
char* student::get_ID_Number() {return ID_Number;}


/// Function to return how many books a student currently has issued to them.
char* student::ret_Stu_B_Number() {return stbno;}


/// Function to return a token that works with our student book number that returns how many books a student has out.
int student::get_Token() {return token;}


/// Function to add a token value to increase the amount of books a student has out.
void student::add_token() {token = 1;}


/// Function that resets the token value to decrease the amount of books a student has out.
void student::reset_Token() {token = 0;}


/// Function that takes a character argument and switches the value into a string.
void student::get_Stu_B_Number(char number[]){strcpy(stbno,number);}


/// Function that will report all students saved in our .dat files.
void student::report(){cout << "\t\t  " << ID_Number << setw(34) << student_Name << setw(20) << token << endl;}
///************************************************END***************************************************************///






///**********************************************Objects*************************************************************///
fstream fp,fp1;
library_Book bk;
student st;
///***********************************************END****************************************************************///





///****************************************Separate-Functions********************************************************///


///
void write_Book()
{
    int choice;
    fp.open("book.dat", ios::out|ios::app);
    do
    {
        bk.create_Book();
        fp.write((char*)&bk,sizeof(library_Book));
        cout << "\n\t\t  Press 1 to add more books. "
                "\n\t\t  Press 2 to return to the main menu."
                "\n\t\t  Enter: ";
        cin >> choice;
    }while (choice == 1);
    fp.close();

} //NA - Finished


/// Function that writes students to file.
void write_Student()
{
    int choice;

    /// Opening our student filepath to store user input of a student.
    fp.open("student.dat",ios::out|ios::app);

    /// Do/While loop that allows the user to write multiple students at once.
    do
    {
        st.create_Student(); /// Function that creates a student to be then stored into our student file.
        fp.write((char*)&st,sizeof(student));
        cout << "\n\t\t  Press 1 to add more students."
                "\n\t\t  Press 2 to return to main menu."
                "\n\t\t  Enter: ";
        cin >> choice;
    }while(choice == 1);
    fp.close();

} //MI - Finished


/// Function that displays a specific book on file found within our book menu.
void display_A_Book(char n[])
{
    cout <<"\n\t\t  BOOK DETAILS\n";
    int check = 0;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(library_Book)))
    {
        if(strcmpi(bk.get_Book_Number(),n) == 0)
        {
            bk.show_Book();
            check = 1;
        }
    }
    fp.close();
    if (check == 0)
    {
        cout << "\n\t\t  Book does not exist";
    }
    cout << "\n\t\t  Press any key to continue:";
    getch();

} //NA - Finished


/// Function that displays a specific student on file found within our student menu.
void display_A_Student(char n[])
{
    cout << "\n\t\t  STUDENT DETAILS\n";
    int check = 0;
    fp.open("student.dat", ios::in);
    while (fp.read((char *) &st, sizeof(student)))
    {
        if ((strcmp(st.get_ID_Number(), n) == 0))
        {
            st.show_Student();
            check = 1;
        }
    }
    fp.close();
    if (check == 0)
    {
        cout << "\n\t\t  Student does not exist";
    }
    cout << "\n\t\t  Press any key to continue:";
    getch();


} //MI - Finished


/// Function that modifies the book record that is stored on file and within our private data members.
void modify_Book()
{
    char n[20];
    int found = 0;
    cout << "\n\t\t  MODIFY BOOK"
            "\n\t\t  Enter The Book Number: ";
    cin >> n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(library_Book)) && found == 0)
    {
        if (strcmpi(bk.get_Book_Number(), n) == 0)
        {
            bk.show_Book();
            cout << "\n\t\t  Enter The New Details of The Book: " << endl;
            bk.modify_Book();
            int pos=-1*sizeof(bk);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&bk,sizeof(library_Book));
            cout << "\n\t\t  Record Updated Successfully: ";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
    {
        cout << "\n\t\t  Record Not Found: ";
    }
    cout << "\n\t\t  Press any key to continue:";
    getch();

} //NA - Finished


/// Function that modifies the student record that is stored on file and within our private data members.
void modify_Student()
{
    char n[20];
    int found=0;

    cout << "\n\t\t  MODIFY STUDENT RECORD... ";
    cout << "\n\t\t  Enter Student's ID number: ";

    cin >> n;

    /// Opening our student file.
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        /// If statement to see if the user input ID# & THE ID# stored on file matches.
        if(strcmp(st.get_ID_Number(),n)==0)
        {
            st.show_Student(); /// Function that shows the student we are about the modify.
            cout<<"\n\t\t  Enter The New Details of student" << endl;
            st.modify_Student(); /// Function to modify a student.

            /// Used to locate within our file where the modifications need to be edited.
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(student));
            cout<<"\n\n\t\t  Record Updated Successfully...";
            found=1;
        }
    }
    fp.close();

    if(found==0)
    {
        cout<<"\n\t\t  Record Not Found ";
    }

    cout << "\n\t\t  Press any key to continue:";
    getch();

} //MI - Finished


/// Function to delete a student that is stored in our file and private data members.
void delete_Student()
{
    char n[20];
    int flag = 0;

    cout << "\n\t\t  DELETE STUDENT";
    cout << "\n\t\t  Enter The ID number of the Student You Want To Delete: ";

    cin >> n;

    fp.open("student.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char *) &st, sizeof(student)))
    {
        if (strcmp(st.get_ID_Number(), n) != 0)
        {
            fp2.write((char *) &st, sizeof(student));
        }
        else
        {
            flag = 1;
        }
    }

    fp2.close();
    fp.close();
    remove("student.dat");
    rename("Temp.dat", "student.dat");

    if (flag == 1)
    {
        cout << "\n\t\t  Record Deleted ..";
    }
    else
    {
        cout << "\n\t\t  Record not found";
    }

    cout << "\n\t\t  Press any key to continue:";
    getch();
} //MI - Finished


/// Function to delete a book that is stored in our file and private data members.
void delete_Book()
{
    char n[20];
    int flag = 0;
    cout << "\n\t\t  DELETE BOOK"
            "\n\t\t  Enter The Books Number You Want To Delete: ";

    cin >> n;

    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);  /// Creating a temporary file to make deletions.

    fp.seekg(0,ios::beg); /// Filepath that sets the position of our character value to be extracted from input stream.

    /// While loop that waits to see if the book you want to delete is on file.
    while (fp.read((char*)&bk,sizeof(library_Book)))
    {
        ///If statement that compares our book numbers so that the book can be deleted.
        if(strcmpi(bk.get_Book_Number(),n) != 0)
        {
            fp2.write((char*)&bk,sizeof(library_Book));
        }
        ///This puts into motion the deletion of our book.
        else
        {
            flag = 1;
        }
    }

    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat","book.dat");

    if (flag == 1)
    {
        cout << "\n\t\t  Record Deleted: ";
    }
    else
    {
        cout << "\n\t\t  Record Not Found\n";
    }

    cout << "\n\t\t  Press any key to continue:";
    getch();

} //NA - Finished


/// Function that displays all students on file.
void display_All_Students()
{
    fp.open("student.dat", ios::in);

    /// If statement that throws an error if there is an error when opening the filepath.
    if (!fp)
    {
        cout << "\n\t\t  ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }

    cout << "\n\t\t                          STUDENT LIST";
    cout << "\n\t\t  ==================================================================\n";
    cout << "\t\t  ID Number.  " << setw(20) << "Name" << setw(31) << "    Book Issued\n";
    cout << "\t\t  ==================================================================\n";


    /// While look that reads all of the private data members from file and prints them neatly to console.
    while (fp.read((char *) &st, sizeof(student)))
    {
        st.report();
    }

    /// Closing our filepath.
    fp.close();

    cout << "\n\t\t  Press any key to continue:";
    getch();

} //MI - Finished


/// Function that displays all books on file.
void display_All_Books()
{
    fp.open("book.dat",ios::in);

    /// If statement that throws an error if there is an error when opening the filepath.
    if(!fp)
    {
        cout<<"\n\t\t  ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }

    cout<<"\n\t\t                             BOOK LIST";
    cout<<"\n\t\t  =========================================================================\n";
    cout<<"\t\t  Book Number"<<setw(25)<<"Book Name"<<setw(30)<<"Author\n";
    cout<<"\t\t  =========================================================================\n";

    /// While look that reads all of the private data members on file and prints them neatly to console.
    while(fp.read((char*)&bk,sizeof(library_Book)))
    {
        bk.report(); /// Function that reports all books stored in our private data members.
    }

    /// Closing our filepath.
    fp.close();

    cout << "\n\t\t  Press any key to continue:";
    getch();

} //NA - Finished


///
void issue_Book()
{
    char sn[20],bn[20];
    int found=0,flag=0;

    cout << "\n\t\t  BOOK ISSUE";
    cout << "\n\t\t  Enter students ID number: ";
    cin >> sn;

    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found == 0)
    {
        if(strcmp(st.get_ID_Number(),sn) == 0)
        {
            found = 1;
            if(st.get_Token() == 0)
            {
                cout << "\n\t\t  Enter book number: ";
                cin >> bn;
                while(fp1.read((char*)&bk,sizeof(bk))&& flag == 0)
                {
                    if(strcmp(bk.get_Book_Number(),bn) == 0)
                    {
                        bk.show_Book();
                        flag = 1;
                        st.add_token();
                        st.get_Stu_B_Number((bk.get_Book_Number()));
                        int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout << "\n\t\t  Book issued successfully...";
                    }
                }
                if(flag == 0)
                {
                    cout << "\n\t\t  Book number does not exist";
                }
            }
            else
            {
                cout << "\n\t\t  You have not returned the last book ";
            }
        }
    }
    if(found == 0)
    {
        cout << "\n\t\t  Student record not exist...";
    }
    fp.close();
    fp1.close();
    cout << "\n\t\t  Press any key to continue:";
    getch();

} //MI - Finished


/// Function that returns book to the program.
void book_Return()
{
    char sn[20], bn[20];
    int found = 0, flag = 0, day, fine;

    cout << "\n\t\t  RETURN BOOKS\n"
            "\n\t\t  Enter The students ID Number: ";
    cin >> sn;

    fp.open("student.dat", ios::in | ios::out);
    fp1.open("book.dat", ios::in | ios::out);

    /// While loop that reads our student file and looks for the  ID number of the student.
    while (fp.read((char *) &st, sizeof(student)) && found == 0)
    {
        /// If statement that compares the file ID# and user input# for a match.
        if (strcmp(st.get_ID_Number(), sn) == 0)
        {
            found = 1;
            if (st.get_Token() == 1)
            {
                /// While Loop that reads our book file to see if the student has a book issued to them on file.
                while (fp1.read((char *) &bk, sizeof(bk)) && flag == 0)
                {
                    /// If statement that compares the book number and the assigned book number the student has.
                    if (strcmp(bk.get_Book_Number(), st.ret_Stu_B_Number()) == 0)
                    {

                        bk.show_Book(); ///Class Object to display the book we are trying to return.
                        flag = 1;
                        cout << "\n\t\t  How many days have you had the book in your possession? "
                                "\n\t\t  Everyday over the 15 day period is a $3 dollar fine: ";
                        cin >> day;

                        /// If statement to see if you are assessed a late fee.
                        if (day > 15)
                        {
                            fine = (day - 15) * 3;
                            cout << "\n\t\t  This Book is late. You have to pay a fine of $" << fine;
                        }
                        st.reset_Token(); /// Resets the book number of the student.

                        /// Position variable that is used to look back at a previous character to be removed.
                        int pos = -1 * sizeof(st);
                        fp.seekp(pos, ios::cur);
                        fp.write((char *) &st, sizeof(student));
                        cout << "\n\t\t  Book returned successfully...";
                    }
                }
                if (flag == 0)
                {
                    cout << "\n\t\t  Book number does not exist";
                }
            }
            else
            {
                cout << "\n\t\t  No book is issued..please check!!";
            }
        }
    }
    if (found == 0)
    {
        cout << "\n\t\t  Student record does not exist...";
    }
    fp.close();
    fp1.close();
    cout << "\n\t\t  Press any key to continue:";
    getch();

} //MI - Finished



/// Function that introduces the program.
void intro()
{
    system("color 03");

    cout <<  "\n  *             *  * * * *   *        * * * *    * * *      *   *     * * * *"
             "\n   *     *     *   *         *        *         *     *    * * * *    *      "
             "\n    *   * *   *    * * *     *        *         *     *   *   *   *   * * *  "
             "\n     * *   * *     *         *        *         *     *  *         *  *      "
             "\n      *     *      * * * *   * * * *  * * * *    * * *  *           * * * * *\n";

    cout << "\n                             * * * * *   * * *                              "
            "\n                                 *      *     *                             "
            "\n                                 *      *     *                             "
            "\n                                 *      *     *                             "
            "\n                                 *       * * *                              \n";

    cout << "\n             * * * *      *      * * *   *        * * * *   * * * *         "
            "\n             *           * *    *        *        *         *               "
            "\n             * * *      * * *   *   * *  *        * * *     * * * *         "
            "\n             *         *     *  *     *  *        *               *         "
            "\n             * * * *  *       *  * * *   * * * *  * * * *   * * * *        \n";

    cout << "\n         *        * * * *   * * *    * * *       *     * * *    *     *     "
            "\n         *           *      *     *  *    *     * *    *    *    *   *      "
            "\n         *           *      * * *    * * *     * * *   * * *       *        "
            "\n         *           *      *     *  *    *   *     *  *    *      *        "
            "\n         * * * *  * * * *   * * *    *     * *       * *     *     *        \n";

} //NA - Finished    test


/// Function that displays a book menu for editing.
void book_Menu()
{
    int option;
    cout << "\n\t\t  ***********************************************"
            "\n\t\t  Press 1 to CREATE BOOKS"
            "\n\t\t  Press 2 to DISPLAY ALL BOOKS"
            "\n\t\t  Press 3 to DISPLAY SPECIFIC BOOK"
            "\n\t\t  Press 4 to MODIFY BOOKS"
            "\n\t\t  Press 5 to DELETE BOOKS"
            "\n\t\t  Press 6 to GO BACK TO MAIN MENU"
            "\n\t\t  ***********************************************"
            "\n\t\t  Option: ";

    cin>>option;

    switch(option)
    {
        case 1:
            write_Book();                /// Function to write book information to a private filestream file.
            break;
        case 2:
            display_All_Books();         /// Function that displays all books from a private filestream file.
            break;
        case 3:
            char num[20];
            cout << "\n\t\t  Please Enter The book Number. ";
            cin >> num;
            display_A_Book(num);         /// Function to display a specific book from a private filestream file.
            break;
        case 4:
            modify_Book();               /// Function to modify a specific book and write the new data by filestream.
            break;
        case 5:
            delete_Book();               /// Function that will delete a book from our private filestream file.
            break;
        case 6:
            break;                       /// Returns our user to the main menu of our program.
        default:
            cout << "\a";
    }


} //NA - Finished


/// Function that displays a student menu for editing.
void student_Menu()
{
    int option;

    cout << "\n\t\t  ********************************************"
            "\n\t\t  Press 1 to CREATE STUDENT RECORD"
            "\n\t\t  Press 2 to DISPLAY ALL STUDENTS RECORD"
            "\n\t\t  Press 3 to DISPLAY SPECIFIC STUDENT RECORD"
            "\n\t\t  Press 4 to MODIFY STUDENT RECORD"
            "\n\t\t  Press 5 to DELETE STUDENT RECORD"
            "\n\t\t  Press 6 to GO BACK TO MAIN MENU"
            "\n\t\t  ********************************************"
            "\n\t\t  Option: ";

    cin >> option;

    switch(option)
    {
        case 1:
            write_Student();        /// Function to write student information to a private filestream file.
            break;
        case 2:
            display_All_Students(); /// Function that displays all students from a private filestream file.
            break;
        case 3:
            char num[20];
            cout << "\n\t\t  Please Enter The ID Number: ";
            cin >> num;
            display_A_Student(num); /// Function to display a specific student from a private filestream file.
            break;
        case 4:
            modify_Student();       /// Function to modify a specific student and write the new data by filestream.
            break;
        case 5:
            delete_Student();       /// Function that will delete a student from our private filestream file.
            break;
        case 6:
            break;                  /// Returns our user to the main menu of our program.
        default:
            cout << "\a";
    }

} //MI - Finished
///***********************************************END****************************************************************///

