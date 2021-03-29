# About Library Management System Project

For library management, this project considers six departments – Computer, Electrical, Civil, Electronics, Mechanical and Architecture. These departments work simultaneously with the operations mentioned above. You can add a book to the Civil section, delete a book from the Electrical section or view issued book details of the Mechanical department.

These are the functions used in this mini project:

**void mainmenu(void)** – This function is used to display the main menu of this project. Scroll down to Output to view the main menu.

**void returnfunc(void)** – Inside this function, the main menu function (mentioned above) is called when the user presses a key. With this, the user can return back to the main menu.

**void addbooks(void)** – This function adds books in a file. For that, you need to mention the department to which you want to add the book. The record is saved in a file. And, it is similar for the following functions as well.

**void deletebooks(void)**

**void editbooks(void)**

**void searchbooks(void)**

**void issuebooks(void)**

**void viewbooks(void)**

**void issuerecord()** – With this function, you can keep record of the student to whom the book has been issued.

**void closeapplication(void)** – This function is for closing the application.

**int  getdata()** – This function asks for data input from the user.

**int checkid(int)** – This function is used to check whether the ID of a book entered by a user exists in file or not.

**void Password()** – Due to this function, the user is asked to input password to run the application after it is opened. You can’t change the password upon running the application.

**void gotoxy (int x, int y)** – You need to understand this function as it is one of the most important one used in mini project on Library Management System in C. This function allows you to print text in any place of screen.