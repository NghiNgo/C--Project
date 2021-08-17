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
