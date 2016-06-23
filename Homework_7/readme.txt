*******************************************************
*  Name      :  Chad S Funckes         
*  Student ID:  103528424               
*  Class     :  CSC 2421           
*  HW#       :  4                
*  Due Date  :  Mar 20, 2015
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program uses STL classes to create a gift list for a holiday.  It takes input from a file with the gift in quotes preceded by
name.  EX: Tom "books" seperated by line breaks either specififed at run time or from the program menu.  It then allows the user
to add and remove gifts from a person and to add and remove people from the list, with the caveat that names can not be duplicated
and gifts cannot be duplicated within a names list.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that utilizes thenode1 class and
functions.h.

Name:  functions.h, functions.cpp
   Contains functions used in main.


   
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
       % unzip [8424HW7]

   Now you should see a directory named 8428HW6 with the the files:
        main.cpp
        functions.h
	functions.cpp
	input.dat
        makefile
        Readme.txt
	
2. Build the program.

    Compile the program by:
    % make

3. Run the program by:
   % ./[HW7]

4. Delete the obj files, executables, and core dump by
   % make clean
