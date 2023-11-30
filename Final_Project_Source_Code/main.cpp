#include "Lib_Header.h"
#include <iostream>


int main()
{

    int option = 0;

    for(;;)
    {


        intro(); /// Intro function.

        cout << "\n\t\t  ********************************************"
                "\n\t\t  Press 1 to ISSUE BOOKS"
                "\n\t\t  Press 2 to RETURN BOOKS"
                "\n\t\t\t---Administrative Options---"
                "\n\t\t\t           (3-4)"
                "\n\t\t  Press 3 to UPDATE STUDENT RECORDS"
                "\n\t\t  Press 4 to UPDATE BOOK RECORDS"
                "\n\t\t  Press 5 to TO EXIT"
                "\n\t\t  ********************************************"
                "\n\t\t  Option: ";

        cin >> option;

        switch (option)
        {
            case 1:
                issue_Book();   /// Function to issue a book to a student.
                break;
            case 2:
                book_Return();  /// Function to return a book to the system.
                break;
            case 3:
                student_Menu(); /// Function that displays a student menu to edit student related items.
                break;
            case 4:
                book_Menu();    /// Function that displays a book menu to edit student related items.
                break;
            case 5:
                cout << "\n\t\tThank you for using the Eagle's Library Management "
                        "\n\t\t                    System. "
                        "\n\t\t               Have a nice day!";

                exit(0);        /// Exits out of the program.
            default:
                cout << "\a";
        }

    }

}


