*******************************************************
*  Name      :  Chad S Funckes         
*  Student ID:  103528424               
*  Class     :  CSC 2421           
*  HW#       :  4                
*  Due Date  :  Apr 6, 2015
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program takes a number from 0-100 from the user and tells you the
total number of ways you can make change in quarter, dimes, nickels and pennies.
it uses a recursive function to get the minium number of coins needed to make change
and also used a 2d vector of vector<int> to map all of the coin combinations and 
output them to the screen.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that utilizes 
functions.h for program functions.

Name:  functions.cpp
   Contains function implementations used in main.

   
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
       % unzip [8424HW9]

   Now you should see a directory named 8428HW6 with the the files:
        main.cpp
        functions.h
	functions.cpp
        makefile
        Readme.txt
	
2. Build the program.

    Compile the program by:
    % make

3. Run the program by:
   % ./[HW9]

4. Delete the obj files, executables, and core dump by
   % make clean
