*******************************************************
*  Name      :  Chad S Funckes         
*  Student ID:  103528424               
*  Class     :  CSC 2421           
*  HW#       :  4                
*  Due Date  :  Mar 2, 2015
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program gets a txt file from the user utilizes node1.h to stores each word of the file into in a node in a linked list.
The program then reverses the list and send the reversed list to a file called output.txt.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that utilizes thenode1 class and
functions.h.

Name:  functions.h, functions.cpp
   Contains functions used in main.

Name:  node1.h
   Contains the definition for the class node.  

Name: mystring.cpp
   Defines and implements the node class.  

   
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
       % unzip [8424HW5]

   Now you should see a directory named 8428HW5 with the the files:
        main.cpp
        functions.h
		functions.cpp
		node1.h
        node1.cpp
		input.txt
        makefile
        Readme.txt
	
2. Build the program.

    Compile the program by:
    % make

3. Run the program by:
   % ./[HW5]

4. Delete the obj files, executables, and core dump by
   % make clean
