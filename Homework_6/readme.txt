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

This program uses a circular doubly linked list by to do the following:

Program simulates a travel agent selecting customers for a free world cruize.  The user selects how many contestants are in the pool.
Then those numbers are dropped into a hat and randomly selected by the agent.

The program then takes the number selected from the hat, and then starting at the begining of the list walks forward that many people and the person
they end up at is eliminated from the competition.  The agent then turns around and walks back the other direction the same number of people and then that person
is eliminated.  This process is continued until only 1 person is left in the game and that person is the winner of the competition.

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
       % unzip [8424HW6]

   Now you should see a directory named 8428HW6 with the the files:
        main.cpp
        functions.h
	functions.cpp
	node1.h
        node1.cpp
        makefile
        Readme.txt
	
2. Build the program.

    Compile the program by:
    % make

3. Run the program by:
   % ./[HW6]

4. Delete the obj files, executables, and core dump by
   % make clean
