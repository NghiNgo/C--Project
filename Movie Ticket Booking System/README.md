# Movie Ticket Booking System

## Global variables used in Movie Ticket Booking System

- qstate represent the state of the query. If 0 is successful 1 is failed.

- conn is the mysql connection variable.

- row is for getting the current row of the database.

- res is for getting all the values form the database.

## Class db_response

This class contains connection of the database.

- mysql_init is the initializer of mysql_real_connect

- mysql_real_connect connects to the database. (MySql server should open while connecting)

- the if statement shows the successful or failed connection.

## Function main in Movie Ticket Booking System C++

- Here firstly the clear screen command then the title command and the color command.

- db_response::ConnectionFunction() is create the connection to the database.

## The program features

- Book Ticket

- Show My Ticket

- Check Seat

- Add New Movie

- Edit Movie

- Delete Movie

- Delete Movie

## The switch case is used for switching between this functions

- BookTicket ();

- ShowMyTicket ();

- CheckSeat ();

- AddNewMovie ();

- EditMovie ();

- DeleteMovie ();

- ShowMovieList ();

## Function BookTicket ()

- The function called when the user choose book a ticket

- Initially the program loads all the movies in the console

- Then ask for a movie id

- If the id is wrong then it ask again

- Otherwise it ask for the user name and phone no.

- Then finally update the movie seat list and

- Insert the data to customers table

## Function ShowMyTicket ()

- This function called when the user want to find a specific user ticket

- Initially the program want the name or id of the user

- If any result found program displayed in the console

- If no result found then the program display nothing found message

## Function CheckSeat ()

- When the user want to check all the seats then this function will call

- Simple select query will get all the data from movies table and display only the Name and Seat values

## Function AddNewMovie ()

- This function can add new movies to the database

- Firstly user can fill all the movie information one by one

- Then Insert query will insert the data into the database

- And show success or failed result in the console

## Function EditMovie ()

- User can edit movie info as their need

- When the function called by the user the program shows only the movie and column name in the console

- After that the program get the column id from the user wants to modify

- If the id found then all the properties of the specific id will show in the console

- And it the id is in the database the all the properties of the movie will execute step by step and user can enter new value or ‘xN’ to keep the data as it is.
  Finally success or failure message show in the console

## Function DeleteMovie ()

- bIf user want to delete an element from the database then this function is called

- The program initially show some properties of all the movies

- Then it asks for an id

- After checking the validity of the id the program check for is the value is in the database

- If the id is in the database then all the values of that id will delete

- Finally success or failure result will show in the console

## Function ShowMovieList ()

- If the user want to see all the movies then this function will execute

- When the query executes all the data in the database will display in the console

## Database and Table Name

- Table: movie_tb, customer_tb

- Database: cpp_movieticketbookingsystem

- Usage – XAMPP Server, MySql Headers, MySql Libs
