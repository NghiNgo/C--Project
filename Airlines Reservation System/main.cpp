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

// Global Variable
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
            //getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "", "cpp_airlinereservation_db", 0, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            cout << "Press any key to continue..." << endl;
            //getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
};

// Functions
void ReserveSeat();
void UserTicket();
void FlightSchedule();
void DisplayPassenger();

void FlightDetails();
void AddNewFlight();
void EditFlight();
void DeleteFlight();
void FlightLeaveArrive();

// Functions End

int main()
{
    // Initial Load
    system("cls");
    system("title Airlines Reservation System Program");
    system("color 0f");
    // Initial Load End

    // Call Methods
    db_response::ConnectionFunction();
    // Call Methods End

    // Variables
    int chooseOneFromMenu = 0;
    char exitSurity;
    // Variables End

    cout << "Welcome To Airlines Reservation System" << endl << endl;
    cout << "Airlines Reservation System Menu" << endl;
    cout << "1. Reserve Seat." << endl;
    cout << "2. User Ticket." << endl;
    cout << "3. Flights Schedule." << endl;
    cout << "4. Display Passenger." << endl;
    cout << "5. Flight Details." << endl;
    cout << "6. Exit Program." << endl;
    cout << "Choose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        ReserveSeat();
        break;
    case 2:
        UserTicket();
        break;
    case 3:
        FlightSchedule();
        break;
    case 4:
        DisplayPassenger();
        break;
    case 5:
        FlightDetails();
        break;
    case 6:
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
        cout << "Please choose between The Given Numbers. Press Enter To Continue...";
        getch();
        system("cls");
        main();
        break;
    }
    return 0;
}

// Functions
void ReserveSeat()
{
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string userFlightNo = "";
    string userName = "";
    string userPhone = "";
    string userPassportNo = "";
    string userTicket = "";
    string userAddress = "";
    char choose;
    // Variables End

    // Store Variables
    string store2dArray[500][500];
    int storeIndex1 = 0, storeIndex2 = 0;
    // Store Variables End


    cout << "Welcome To Airlines Reservation System" << endl << endl;
    cout << "Reserve Seat Menu" << endl << endl;

    cin.ignore(1, '\n');
    cout << "Enter User Name: ";
    getline(cin, userName);
    cout << "Enter User Phone No: ";
    getline(cin, userPhone);
    cout << "Enter User Passport: ";
    getline(cin, userPassportNo);
    cout << "Enter User Ticket: ";
    getline(cin, userTicket);
    cout << "Enter User Address: ";
    getline(cin, userAddress);

    qstate = mysql_query(conn, "select * from flightdetails_tb where f_available = 'A'");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", "Flight No", "From", "Destination", "Time", "Amount");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", row[1], row[3], row[4], row[5], row[6]);
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    cout << "Enter Flight No: ";
    getline(cin, userFlightNo);

    string insert_query = "insert into userreservation_tb (u_name, u_phone, u_passportno, u_ticket, u_flightno, u_address) values ('" + userName + "','" + userPhone + "','" + userPassportNo + "','" + userTicket + "','" + userFlightNo + "','" + userAddress + "')";

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
    cout << "Press 'm' to Menu and 'a' to Reserve Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        ReserveSeat();
    }
    else
    {
        exit(0);
    }
}

void UserTicket()
{
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string input = "";
    char choose;
    // Variables End

    cout << "Welcome To Airlines Reservation System" << endl << endl;
    cout << "User Ticket Menu" << endl << endl;

    cin.ignore(1, '\n');
    cout << "Enter User Name: ";
    getline(cin, input);
    string findbyname_query = "select * from userreservation_tb where u_name like '%" + input + "%'";
    const char* qn = findbyname_query.c_str();
    qstate = mysql_query(conn, qn);

    cout << endl;
    cout << "Showing Ticket of " << input << endl << endl;
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << "Ticket No.: " << row[4] << "\nUser Name: " << row[1] << "\nUser Phone No.: " << row[2] << "\nUser Passport: " << row[3] << "\nFlight No.: " << row[5] << "\nUser Address: " << row[6] << endl << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
ExitMenu:
    cout << "Press 'm' to Menu, 'a' to Search again and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        UserTicket();
    }
    else
    {
        exit(0);
    }
}

