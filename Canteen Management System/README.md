# Canteen Management System Program in C++ and MySQL Description:

The program has a database connection class call at the beginning of the program. Our main class is Canteen class and this class has some public functions like show, allItems, soldItems, addNewItem, editItem, deleteItem, searchById, searchByName, checkQuantity, addNewSale.

**Below are the things we can do in this program:**

1. All Items

2. Sold Items

3. Add New Item

4. Edit Item

5. Delete Item

6. Search By Id

7. Search By Name

8. Check Quantity

9. Add New Sale

## Canteen Management System Program Detail:

### Global variables

- qstate represent the state of the query. If 0 is successful 1 is failed.

- conn is the mysql connection variable.

- row is for getting the current row of the database.

- res is for getting all the values form the database.

### Class Canteen

This class contains connection of the database.

- mysql_init is the initializer of mysql_real_connect

- mysql_real_connect connects to the database. (MySql server should open while connecting)

- the if statement shows the successful or failed connection.

### Function main

**The Program Features**

- New Customer

- All Items

- Sold Items

- Add New Item

- Edit Item

- Delete Item

- Exit

**If else is used to select**

- New Customer

- All Items

- Sold Items

- Add New Item

- Edit Item

- Delete Item

- Exit

### Uses of class’s functions Constructor ()

In here, I connected with MySql database. If connection failure, then error message will be shown

### Function show ()

It print the project name. Print our main menu to the user and ask the user to choose one

### Function addNewItem ()

I took name and quantity input from user and added with insert query string. Then run the built in function mysql_query(). If insertion query work successfully, then success message will be shown if not then error message will be shown in this Canteen Management System program.

### Function addNewSale()

In this function I passed two parameter name and quantity of the item stored in canteen. In this function I used stringstream to convert string to integer and integer to string. After adding new item to sold table, an update query will run to update the quantity of item in items table in Canteen Management System C++ program.

### Function allItems()

In this function, I fetched all items from the items table and showing them in a table. If query failed, then it will show the error message.

### Function soldItems ()

In this function, I fetched all sold items from the sold table and showing them in a table. If query failed, then it will show the error message.

### Function searchById ()
In this function, I searched item with one specific id passed as parameter. First selects all items and then checking if the row[0] means our id column from database table is equal to or not. If equal then loop will break and assign true to the found variable. At last it return found variable.

### Function searchByName ()
In this function, I searched item with one specific name passed as parameter. First selects all items and then checking if the row[1] means our name column from database table is equal to or not. If equal then loop will break and assign true to the found variable. At last it return found bool variable.

### Function checkQuantity ()

When user select item from the whole list, then it checks if the quantity is available or not with the specific name passed name and quantity
- **Stringstream** used to convert string to integer
- **previousQuantity** is a global variable. It is used to update items after user purchase any item. It will return the found variable

### Function editItem()

In this function, it first show all items available in the store. Then prompt for user input to enter an ID to edit. Then it checks if the id is valid or not by searchById() function. If id is found, then it will select the specific id from the items table and show in the console. After then it ask the user to input the new item name and the quantity. After then an update query will be created with new name and quantity. Then run update query in C++ program and if run successfully, It will show the success message.

### Function deleteItem ()

At first, it shows all the items from the item table. Then ask the user to enter an valid to Id which he/she want to delete. Then it check if the is valid or not
If valid then run a delete query to delete the item.

### Database and Table Name used in this C++ program

- Table: items, sold

- Database: cpp_canteen_management

- Usage: XAMPP Server, MySql Headers, MySql Libs
