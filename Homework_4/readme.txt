*******************************************************
*  Name      :  Chad S Funckes         
*  Student ID:  103528424               
*  Class     :  CSC 2421           
*  HW#       :  4                
*  Due Date  :  Feb 23., 2015
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

// This file contains a program utilizing the class my_string 
// It takes an input text file of any number of lines and any number of columns from
// either a command line parameter or using the default file name data.txt.
// The program then takes from the user a specified column width and then formats that input
// text into a vector that is exactly that many columns wide.  If a word spans the line a hyphen
// is added to the end of the line just past the specified width.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that utilizes the my_string class and
functions.h.

Name:  functions.h, functions.cpp
   Contains functions used in main.

Name:  mystring.h
   Contains the definition for the class my_string.  

Name: mystring.cpp
   Defines and implements the my_string class.  

   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested MS Visual Studio 2013.
   
   It was then compiled, run, and tested on gcc csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [8424HW4]

   Now you should see a directory named 8428HW4 with the the files:
        main.cpp
        functions.h
	functions.cpp
	myclass.h
        myclass.cpp
	data.txt
        makefile
        Readme.txt
	
2. Build the program.

    Compile the program by:
    % make

3. Run the program by:
   % ./[HW4]

4. Delete the obj files, executables, and core dump by
   % make clean
