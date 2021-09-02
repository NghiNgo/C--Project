#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
using namespace std;

// Global Variable Movie Ticket Booking System in C++ with MySQL
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
// Global Variable End

class db_response
{
public:
    static void ConnectionFunction()
    {
        conn = mysql_init(0);
        if (conn)
        {
            cout << "Database Connected" << endl;
            cout << "Press any key to continue..." << endl;
            // getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "", "cpp_movieticketbookingsystem", 0, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            cout << "Press any key to continue..." << endl;
            // getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
};

void Welcome() {
    cout << "Welcome To Movie Ticket Booking System" << endl << endl;
    cout << "Menu" << endl;
}

// Fucntions
void BookTicket();
void ShowMyTicket();
void CheckSeat();
void ReserveSeat();
void AddNewMovie();
void EditMovie();
void DeleteMovie();
void ShowMovieList();

int main()
{
    // Initial Load
    system("cls");
    system("title Music Store Management Program");
    system("color 0f");
    // Initial Load End

    // Call Methods
    db_response::ConnectionFunction();
    // Call Methods End

    // Variables
    int chooseOneFromMenu = 0;
    char exitSurity;
    int num = 1;
    int fin = 0;
    // Variables End

    Welcome();
    for (int i = 0; i < 1; i++) {
        fin = num;
        cout << fin << ". Book Ticket" << endl;
        fin += num;
        cout << fin << ". Show My Ticket" << endl;
        fin += num;
        cout << fin << ". Check Seat" << endl;
        fin += num;
        cout << fin << ". Add New Movie" << endl;
        fin += num;
        cout << fin << ". Edit Movie" << endl;
        fin += num;
        cout << fin << ". Delete Movie" << endl;
        fin += num;
        cout << fin << ". Show Movie List" << endl;
        fin += num;
        cout << fin << ". Exit" << endl;
        cout << "Choose One: ";
    }
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        BookTicket();
        break;
    case 2:
        ShowMyTicket();
        break;
    case 3:
        CheckSeat();
        break;
    case 4:
        AddNewMovie();
        break;
    case 5:
        EditMovie();
        break;
    case 6:
        DeleteMovie();
        break;
    case 7:
        ShowMovieList();
        break;
    case 8:
ExitProgram:
        cout << "Program terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            return 0;
        } else if (exitSurity == 'n' || exitSurity == 'N') {
            system("cls");
            main();
        } else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "Please choose between 1 - 7. Press Enter To Continue...";
        getch();
        system("cls");
        main();
        break;
    }
    return 0;
}

// Function Implementation
void BookTicket() {

    system("cls");

    // Variables
    char choose;
    string c_name = "";
    string c_phone = "";
    string c_seat = "";
    string getId = "";
    char chooseEditOrBuy;
    int itemIndex = 0;
    float totalPrice = 0.0;
    string totPrice = "";
    bool purchase, itemFalse = false, exitcode = false;

    string storeId[5000];
    string storeid = "";
    string storename = "";
    string storegenre = "";
    string storeformat = "";
    string storeshowDate = "";
    string storeshowTime = "";
    string storeticketPrice = "";
    string storeseat = "";
    int storeIndex = 0, storeIndexN = 0;
    // Variables End

    Welcome();
    qstate = mysql_query(conn, "select * from movie_tb");
    if (!qstate)
    {

        res = mysql_store_result(conn);

        printf("---------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-15s | %-7s | %-15s | %-15s | %-10s | %-5s |\n", "Column Id", "Name", "Format", "Show Date", "Show Time", "Price", "Seat");
        while ((row = mysql_fetch_row(res)))
        {

            if (atoi(row[7]) > 0)
            {
                printf("| %-10s | %-15s | %-7s | %-15s | %-15s | %-10s | %-5s |\n", row[0], row[1], row[3], row[4], row[5], row[6], row[7]);
                storeId[storeIndex] = row[0];
                storeIndex++;
            }

        }
        printf("---------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    itemFalse = true;
    for (;;) {
        cout << "Enter a Movie ID's (q to exit): ";
        cin >> getId;

        if (getId == "q") {
            exitcode = true;
            break;
        }

        for (int i = 0; i < storeIndex; i++)
        {
            if (getId == storeId[i])
            {
                itemFalse = false;
                break;
            }
        }
        if (itemFalse) {
            cout << "Enter a valid number." << endl;
            itemFalse = true;
        } else {
            break;
        }
    }

    if (!exitcode) {
        cout << "Enter Customer Name: "; cin >> c_name;
        cout << "Enter Customer Phone: "; cin >> c_phone;
        cout << "Book Seat: "; cin >> c_seat;

        string selectMovie = "select * from movie_tb where m_id = '" + getId + "'";
        const char* qn = selectMovie.c_str();
        qstate = mysql_query(conn, qn);

        if (!qstate)
        {

            res = mysql_store_result(conn);

            printf("--------------------------------------------------------------------\n");
            printf("| %-10s | %-15s | %-15s | %-15s |\n", "Column Id", "Name", "Format", "Price");
            while ((row = mysql_fetch_row(res)))
            {
                if (atoi(row[7]) > 0)
                {
                    printf("| %-10s | %-15s | %-15s | %-15s |\n", row[0], row[1], row[3], row[6]);
                    storeid = row[0];
                    storename = row[1];
                    storegenre = row[2];
                    storeformat = row[3];
                    storeshowDate = row[4];
                    storeshowTime = row[5];
                    storeticketPrice = row[6];
                    storeseat = row[7];
                }

            }
            printf("--------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }

        string updatQuery = "update movie_tb set m_seat = m_seat - '" + c_seat + "' where m_id = '" + getId + "'";
        const char* un = updatQuery.c_str();
        qstate = mysql_query(conn, un);

        totalPrice = strtof((storeticketPrice).c_str(), 0) * strtof((c_seat).c_str(), 0);
        stringstream tPrice;
        tPrice << totalPrice;
        tPrice >> totPrice;

        string insert_query = "insert into customer_tb (name, phone, movie, format, seat, price, showdate, showtime) values ('" + c_name + "','" + c_phone + "','" + storename + "', '" + storeformat + "', '" + c_seat + "', '" + totPrice + "', '" + storeshowDate + "', '" + storeshowTime + "')";
        const char* in = insert_query.c_str();
        qstate = mysql_query(conn, in);

        if (!qstate)
        {
            cout << endl << "Purchase Successfully Done." << endl;
            cout << endl << "Total Price: " << totalPrice << endl;
        }
    }

    // Exit Code
    cout << endl << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else
    {
        exit(0);
    }
}

void ShowMyTicket() {

    system("cls");

    // Variables
    char choose;
    string input;
    // Variables End

    Welcome();
    cin.ignore(1, '\n');
    cout << "Enter Your Id Or Name: ";
    getline(cin, input);
    string findbyname_query = "select * from  customer_tb where id = '" + input + "' or name = '" + input + "'";
    const char* qn = findbyname_query.c_str();
    qstate = mysql_query(conn, qn);

    cout << endl;
    int c = 0;
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << "ID: " << row[0] << "\nName: " << row[1] << "\nPhone: " << row[2] << "\nMovie: " << row[3] << "\nFormat: " << row[4] << "\nSeat: " << row[5] << "\nPrice: " << row[6] << "\nShow Date: " << row[7] << "\nShow Time: " << row[8] << endl << endl;
            c++;
        }

        if (c == 0) {
            cout << "No ticket with this input" << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

ExitMenu:
    cout << "Press 'm' to Menu, 'a' to Search again and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        ShowMyTicket();
    }
    else
    {
        exit(0);
    }

}

void CheckSeat() {
    system("cls");

    // Variables
    char choose;
    string input;
    // Variables End

    Welcome();
    cin.ignore(1, '\n');
    qstate = mysql_query(conn, "select * from  movie_tb");

    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("-------------------------------------\n");
        printf("| %-15s | %-15s |\n", "Name", "Seat");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-15s |\n", row[1], row[7]);
        }
        printf("-------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

ExitMenu:
    cout << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else
    {
        exit(0);
    }
}

void AddNewMovie() {

    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string name = "";
    string genre = "";
    string format = "";
    string showDate = "";
    string showTime = "";
    string ticketPrice = "";
    string seat = "";
    char choose;
    // Variables End

    Welcome();
    cin.ignore(1, '\n');
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Genre: ";
    getline(cin, genre);
    cout << "Enter format: ";
    getline(cin, format);
    cout << "Enter Show Date (dd-mm-yyyy): ";
    getline(cin, showDate);
    cout << "Enter Show Time: ";
    getline(cin, showTime);
    cout << "Enter Ticket Price: ";
    getline(cin, ticketPrice);
    cout << "Enter Seat: ";
    getline(cin, seat);

    string insert_query = "insert into movie_tb (m_name, m_genre, m_format, m_showdate, m_showtime, m_ticketprice, m_seat) values ('" + name + "','" + genre + "','" + format + "',STR_TO_DATE('" + showDate + "', '%d-%m-%Y'),'" + showTime + "','" + ticketPrice + "', '" + seat + "')";

    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "Successfully added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and 'a' to Insert Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        AddNewMovie();
    }
    else
    {
        exit(0);
    }
}
