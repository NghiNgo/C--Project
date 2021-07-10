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
