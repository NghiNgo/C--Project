# Travel Agency Management System Program Description

## Global variables

- **qstate** represent the state of the query. If 0 is successful 1 is failed.

- **conn** is the mysql connection variable.

- **row** is for getting the current row of the database.

- **res** is for getting all the values form the database.

## Class db_response

This class contains connection of the database.

- mysql_init is the initializer of mysql_real_connect

- mysql_real_connect connects to the database. (MySql server should open while connecting)

- the if statement shows the successful or failed connection.

## Function main

Here firstly the clear screen command then the title command and the color command.

**db_response::ConnectionFunction()** is create the connection to the database.

### The program features

- New Travel Trip.

- Show Users.

- Find User.

- Edit User.

- Delete User.

- Add Trip.

- Edit Trip.

- Delete Trip.

### The switch case is used for switching between this functions

- NewTravelTrip();

- ShowUsers();

- FindUser();

- EditUser();

- DeleteUser();

- AddTrip();

- EditTrip();

- DeleteTrip();

### Function NewTravelTrip

- Firstly the user can enter traveler’s information like username, address, phone, email, trip date, trip id (that is actually the id of the trip Name), trip cost.

- Then the insert query insert the data into the database.

- Then if all the process executes fine then the program show successful result.

- Finally the Exit Code runs.

### Function ShowUsers

- In the beginning of the program the select query execute.

- Then all the data shows in the console.

- The “select \* from travelagency_tb” sql query, used for getting the values from database and print the value from “res” variable using while loop.

- Finally Exit Code executes.

### Function FindUser

- User can search any record from the database.

- The user can search by username.

- The user can find by only one character if the character matches with the respective columns row.

- Then by the user choice the program show the desired result.

- Finally Exit Code run for go to menu or repeat the function or exit from the console.

### Function EditUser

- The program can edit the student record.

- Firstly the “select \* from travelagency_tb” query execute for getting the user

- Then the user can enter the column id. The input has a number validator.

- Now the program checks is the record is in the database or not. If not then the program show an item not found pop up message.

- If the program found the record then the program show the record in the console.

- And the user can edit as their need.

- ‘X’ is the symbol for keep the same data in the database.

- Finally the ‘’Update” query update the new record as given by the user.

- And show success pop up message.

- Finally Exit Code run for go to menu or repeat the function or exit from the console.

### Function DeleteUser

- The function can delete user record.

- The “Delete” query used to delete the record from the database.

- It shows all the records than want the input of the user column id.

- The input is number validator so the user cannot use any other character except numbers.

- Then the program checks is the record is in the database or not.

- If this is in the database than the program delete the record and if not then the program shows not in database message in the console.

- Finally Exit Code run for go to menu or repeat the function or exit from the console.

### Function AddTrip

- Here user can add new trip record.

- User can enter the trip name and add into the database.

- After the input the program execute the insert_query (A variable holing the insertion query).

- Then the program show the successful message.

- Finally Exit Code run for go to menu or repeat the function or exit from the console.

### Function EditTrip

- The program can edit the trip record.

- Firstly the “select \* from travelagency_tb” query execute for getting the student record.

- Then the user can enter the column id. The input has a number validator.

- Now the program checks is the record is in the database or not. If not then the program show an item not found pop up message.

- If the program found the record then the program show the record in the console.

### Function DeleteTrip

- The function can delete trip record.

- The “Delete” query used to delete the record from the database.

- It shows all the records than want the input of the user column id.

- The input is number validator so the user cannot use any other character except numbers.

- Then the program checks is the record is in the database or not.

- If this is in the database than the program delete the record and if not then the program shows not in database message in the console.

- Finally Exit Code run for go to menu or repeat the function or exit from the console.

## Database and Table Name

- Table: travelagency_tb , travelagencytrips_tb

- Database: cpp_travelagency_db

- Usage: XAMPP Server, MySql Headers, MySql Libs
