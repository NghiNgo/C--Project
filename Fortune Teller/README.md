# About Fortune Teller Project:

## Features and Functions:

The source code of this project is written without the use of graphics, but user defined header files and functions have been used to make the code user friendly. The header files defined in the source code are:

- “horoscopes.h”:
- “fcn.h”

**“horoscopes.h”**: In the source code of Fortune Teller project in C++, the this header file has been used to control the 12 horoscopes by using user defined function for each horoscope. The functions contained by this header file are:

void aries(int,int,char *,char);

void taurus(int,int,char *,char);

void gemini(int,int,char *,char);

void cancer(int,int,char *,char);

void leo(int,int,char *,char);

void virgo(int,int,char *,char);

void libra(int,int,char *,char);

void scorpio(int,int,char *,char);

void saggitarius(int,int,char *,char);

void capricorn(int,int,char *,char);

void aquarius(int,int,char *,char);

void pisces(int,int,char *,char);

**“fcn.h”**: “fch.h” is a header file created in the source code of Fortune Teller project in C++ which contains all the functions requires throughout the program like functions to locate cursor in the screen, functions to draw ASCII representations, functions to display different menus, functions to check passwords etc. The list of functions defined in the header file is as follows:

void gotoxy(int,int);

void welcomescreen();

int password();

void cusp(int);

void delay(int);

int main();

void fortunes();

void asciiaries();

void asciitaurus();

void asciigemini();

void asciicancer();

void asciileo();

void asciivirgo();

void asciilibra();

void asciiscorpio();

void asciisaggitarius();

void asciicapricorn();

void asciiaquarius();

void asciipisces();

void compat(int);

void details(char *,char,int);

int zodmenu();

int lovemenu();

void admintools();

The type of arguments that the functions above take are given in the parenthesis.

## Features:

The key features of Fortune Teller project in C++:

- It asks for the date of birth, name of the user, and sex. Based on these information, the application determines your horoscope and predicts your future about yourselves, your fortunes, lucky number, about your love etc.

- Using this C++ project, you can check your love compatibility, if you know either horoscope or date of birth of your partner.
