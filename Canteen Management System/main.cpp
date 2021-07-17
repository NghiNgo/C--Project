#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
#include <typeinfo>
using namespace std;

// Global Variable
int qstate, previousQuantity = 0;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
// Global Variable End

class Canteen
{
public:
    Canteen();
    void show();
    void allItems();
    void soldItems();
    void addNewItem();
    void editItem();
    void deleteItem();
    bool searchById(string);
    bool searchByName(string);
    bool checkQuantity(string,string);
    void addNewSale(string,string);
};

Canteen::Canteen()
{
    conn = mysql_init(0);
    if (conn)
    {
        cout << "Database Connected" << endl;
        cout << "Press any key to continue..." << endl;
        getchar();
        system("cls");
    }
    else {
        cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
    conn = mysql_real_connect(conn, "localhost", "root", "", "cpp_canteen_management", 0, NULL, 0);
    if (conn)
    {
//        cout << "Database Connected To MySql" << conn << endl;
//        cout << "Press any key to continue..." << endl;
//        getchar();
        system("cls");
    }
    else
        cout << "Failed To Connect!" << mysql_errno(conn) << endl;
}

void Canteen::addNewItem()
{
    system("cls");

    string name;
    string quantity;
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter quantity: ";
    cin>>quantity;

    string query = "insert into items (name, quantity) values ('"+name+"','"+quantity+"')";

    const char* q = query.c_str();

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "New Item Added." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
}

void Canteen::addNewSale(string name, string quantity)
{
    string query = "insert into sold (name, quantity) values ('"+name+"','"+quantity+"')";

    const char* q = query.c_str();

    qstate = mysql_query(conn, q);
    int current = 0;

    if (!qstate)
    {
        cout << endl << "New Sale Item Added." << endl;
        stringstream geek1(quantity), ss;
        geek1 >> current;
        previousQuantity = previousQuantity - current;
        ss << previousQuantity;
        quantity = ss.str();
        string update_query = "update items set quantity = '"+quantity+"' where name = '"+name+"'";
        q = update_query.c_str();

        qstate = mysql_query(conn, q);
        if(qstate)
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
}

void Canteen::allItems()
{
    qstate = mysql_query(conn, "select * from items");

    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("\n------------------------------------------------\n");
        printf("| %-20s | %-10s | %-10s\n", "ID","Item Name", "Quantity");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-20s | %-10s | %-10s\n", row[0], row[1], row[2]);
        }
        printf("------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
}

void Canteen::soldItems()
{
    qstate = mysql_query(conn, "select * from sold");

    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("\n------------------------------------------------\n");
        printf("| %-20s | %-10s | %-10s\n", "ID","Item Name", "Quantity");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-20s | %-10s | %-10s\n", row[0], row[1], row[2]);
        }
        printf("------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
}

bool Canteen::searchById(string id)
{
    string query = "SELECT id FROM items";
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);

    bool found = false;

    if(!qstate)
    {
        while ((row = mysql_fetch_row(res)))
        {
            if(row[0] == id)
            {
                found = true;
                break;
            }
        }
    }

    return found;
}
