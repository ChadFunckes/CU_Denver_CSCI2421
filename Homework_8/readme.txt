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

This program simulates 5 lines at a grocery store.  Each machine takes a random number of time
to operate, between 10 and 600 seconds.  A new customer comes into the line 25% probability every second.
The program keeps track of the average wait time and how many customers go through each line.

*******************************************************
*  Source files
*******************************************************

Name:  grocery.cpp
   Main program.  This is the driver program that utilizes 
grocery.h.

Name:  grocery.h, functions.cpp
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
       % unzip [8424HW8]

   Now you should see a directory named 8428HW6 with the the files:
        grocery.cpp
        grocery.h
		functions.cpp
        makefile
        Readme.txt
	
2. Build the program.

    Compile the program by:
    % make

3. Run the program by:
   % ./[HW8]

4. Delete the obj files, executables, and core dump by
   % make clean
