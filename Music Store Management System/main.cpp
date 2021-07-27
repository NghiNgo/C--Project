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
        conn = mysql_real_connect(conn, "localhost", "root", "", "cpp_musicstore_db", 0, NULL, 0);
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

void AddNewItemInDatabase();
void ShowAllItems();
void ItemInStock();
void FindMusic();
void EditItem();
void RemoveItem();
void CreateOrder();
void SoldItems();

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
    // Variables End

    cout << "Welcome To Music Store" << endl << endl;
    cout << "Music Store Menu" << endl;
    cout << "1. Create Order." << endl;
    cout << "2. Find Music." << endl;
    cout << "3. Sold Items." << endl;
    cout << "4. Item in Stock." << endl;
    cout << "5. All Items." << endl;
    cout << "6. Add New Item." << endl;
    cout << "7. Edit Item." << endl;
    cout << "8. Remove Item." << endl;
    cout << "9. Exit." << endl;
    cout << "Choose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        CreateOrder();
        break;
    case 2:
        FindMusic();
        break;
    case 3:
        SoldItems();
        break;
    case 4:
        ItemInStock();
        break;
    case 5:
        ShowAllItems();
        break;
    case 6:
        AddNewItemInDatabase();
        break;
    case 7:
        EditItem();
        break;
    case 8:
        RemoveItem();
        break;
    case 9:
        ExitProgram:
        cout << "Program terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            return 0;
        }else if (exitSurity == 'n' || exitSurity == 'N') {
            system("cls");
            main();
        }else {
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
