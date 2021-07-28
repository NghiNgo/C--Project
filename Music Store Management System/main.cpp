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

void ShowAllItems()
{
    system("cls");

    // Variables
    char choose;
    // Variables End

    cout << "Welcome To Music Store" << endl << endl;
    cout << "Show All Items Menu" << endl << endl;

    qstate = mysql_query(conn, "select * from musicinfo_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << "ID: " << row[0] << "\nCategory: " << row[1] << "\nType: " << row[2] << "\nName: " << row[3] << "\nArtist: " << row[4] << "\nPrice: " << row[5] << "\nQuantity: " << row[6] << endl << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
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

void AddNewItemInDatabase()
{
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string category = "";
    string type = "";
    string name = "";
    string artist = "";
    float price = 0.0;
    int quantity = 0;
    char choose;
    // Variables End

    cout << "Welcome To Music Store" << endl << endl;
    cout << "Add New Item Menu" << endl << endl;

    cin.ignore(1, '\n');
    cout << "Enter Category: ";
    getline(cin, category);
    cout << "Enter Type: ";
    getline(cin, type);
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Artist: ";
    getline(cin, artist);
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Quantity: ";
    cin >> quantity;

    stringstream streamPrice, streamQuan;
    string sprice, squan;
    streamPrice << price;
    streamPrice >> sprice;
    streamQuan << quantity;
    streamQuan >> squan;


    string insert_query = "insert into musicinfo_tb (m_category, m_type, m_name, m_artist, m_price, m_quantity) values ('" + category + "','" + type + "','" + name + "','" + artist + "','" + sprice + "','" + squan + "')";

    const char* q = insert_query.   c_str(); // c_str converts string to constant char and this is required

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
        AddNewItemInDatabase();
    }
    else
    {
        exit(0);
    }
}
