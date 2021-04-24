# About Snakes and Ladders Game:

The game includes the facilities such as saving and loading the game. The saved games are password protected so that only the authorized user can load the previously saved game. The snakes and ladders game project comprises of multiple functions (scroll down to view the description for each) which can be dealt at ease. Attempt has been made to present the program in user friendly environment.

## Objectives, Features and Scope:

### OBJECTIVES

- To use different user defined function, to break a program into many simplified parts to deal with and to make it easier to understand the codes too.

- To promote the use of array in general programming for simplified version of the program.

- To apply the file handling concepts in order to retrieve the player’s data files that contains the data of the players.

- To use minimum graphics as far as possible to make the program execute fast but also user friendly side by side.

- To use general concept of c language to develop a simple snakes and ladders game that as a whole entertains the user.

### FEATURES

- Compatible as multi-player game.

- Facility to save the game.

- Open the saved game using the password pre-defined by the user.

- Use minimum graphics in snakes and ladders as far as possible avoiding complex codes.

### SCOPE

- Users preferring the classical games can switch to the game.

- Beginners in computer programming can take hints via the mini project to boost up their programming techniques.

- Can be brought in practice in training centers that offers basic programming courses.

- Can be the best choice as stress relieving game in the busy life pattern of the people in present life.

- Simplicity and efficient is main fact that we get using the c language, so user can execute snakes and ladders in each and every computer almost.

- Can be milestone for the programmers trying to learn to build projects in C.

## Functions Used:

*Main()*

This function is the main function. This function contains the control of the whole game. User can switch to resume, new game, load game, save game, tutorial and exit from this function. It calls the respective function as user’s input. In this function user can use pre-defined short cut keys too.

*Save game()*

This part of the program is called from the main function when user wishes to save the game. The player can provide his own password to protect the game from other users. In snakes and ladders, this function calls the password function to get the password from the user. After getting the password the name of game, the name of players, and the value of the player is stored in a file named save.dat that can be reopened further.

*Loadgame()*

This function enables the users to load the initially saved snakes and ladders game. In order to prevent the unauthorized use of the loaded game, there is a password system that user has to go through before he opens or loads the saved game. In order to get game loaded user has to input the game name and the password per defined or per entered. Password functions is called for password input and for matching of the password and the game name data is read from the data file save.dat.

*Tutorial()*

This function in the program prints the tutorial of the snakes and ladders i.e. the help of the game, color indication and so on. The function uses a data file that contains the tutorial of the game. After printing the tutorial the control is transferred to main function.

*Firstscr()*

This function generates the first screen appeared when the program is executed. This function includes some animations and the snakes and ladders title. This function gets control until unless any key of the key board is hit. If any key of the key board is hit the control flows to main function.

*Main game()*

This is the function from where all the game is executed . From this function firstly the layout of the board is called. Then the vipers and the ladders are printed. Then the dice function is called and returned value is added to respective player’s position. Then after the viper and ladder function is called to check the viper and ladder position. Then after the players are displayed at the new position. At last eofgame function is called in this snakes and ladders if the player’s value equals to 100.

*Layout()*

In this function, the general layout of the board is drawn as like in classical game. This function does not get control for long. As soon as it get the control it prints the layout of the board and the control goes to the main game function.

*Drawviperandladder()*

In this function, the vipers and ladders are drawn on the board. This function is called from the main game function of this viper buzz project. The viper are represented by the red color and the ladders are represented by the green color.

*Dice()*

This function is for the value of the dice as per user’s reaction. In snakes and ladders, his function returns an integer value if any key of the keyboard is hit. The value is returned to the main game function. In addition to the dice rolling, this function holds the screen and also responds to the escape key pressed. If escape key is pressed, it flows control to the main menu else the control flows to main menu.

*Position()*

This is the function locating the player in the board of snakes and ladders. This function prints a white space in the old position and it prints the representation character to the new location as the value of the player. The main aim of this function is to prints the player’s indicator in the respective position.

*Viperandladder()*

In this function the player’s position is compared with the initial position of the ladder and respective value of the player is changed only if the initial value matches. In addition to that this function checks the hit condition also. The control flows to the main game after execution of snakes and ladders.

*Locate(int , int)*

This function is used in our program to set the cursor position on the different location of the screen. It takes two arguments and sets the cursor position according to the arguments.

*Draw()*

In this snakes and ladders game project, draw() function helps to print the dice box and the data of the player on the box. It is called each time loop executes so that it overlaps the initial mesh created. This function displays the player’s current position, player’s name and turn.

*Eofgame(char , int)*

This is the final screen after any one of the player reaches to the position of 100. The main loop of the main game function in this snakes and ladders gets break and this function is called. In this function two arguments are passed i.e. firstly the player’s name and the player’s code. This function has the control until unless a key is pressed.

*Password(char)*

In this function, an address is passed as argument and entered password is returned for the pointer. In this snakes and ladders game project, the character that user input is take and the asterisks are printed in place of the character to avoid the identification. This function is called from save game and the load game.

*Playfilesync(char)*

This function is used in the program to play the sound of the game. This function enables the programmer to embed the sound in their console based program. This function takes the file name to be played. The file to be played should be inwav format.

## Algorithm & Flowchart:

Here, individual algorithms and flowcharts have been present in a sequential manner for the functions that make up this gaming project.

