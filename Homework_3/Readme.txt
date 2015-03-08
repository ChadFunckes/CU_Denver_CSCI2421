*******************************************************
*  Name      :  Chad S Funckes         
*  Student ID:  103528424               
*  Class     :  CSC 2421           
*  HW#       :  3                
*  Due Date  :  Feb 16., 2015
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program utilises the set class (an extended version of bag from chapter 3)
To input two sets of integers from a file named input.dat.  Each set of integers will be on a single line
separated by a end of line charictor.  After input of the data set, all duplicate numbers in the data set
 will be deleted, so that the set only contains one copy of any integer.

The two input sets will then be added togather using the set class overloaded operator +.  This will
place the two set togather and then eliminate any common numbers, so that the new set is once again a single
"set" of integers with no repeating numbers and then display the resulting set for the user.

The program will then take the two original sets and utilize the overloaded - operator of the set class
to remove all of the items present in the second set from the first set.  and then display the resulting set
to the user.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that utilizes the set class to take
2 sets of integers from a file and add and subtract them

Name:  functions.h, functions.cpp
   Contains functions used in main.

Name:  set.h
   Contains the definition for the class set.  

Name: set.cpp
   Defines and implements the set class.  This class provides routines to construct,
insert number, remove target numbers, ensure the set constains no duplicates, add and
subtract sets.

   
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
       % unzip [8424HW3]

   Now you should see a directory named 8428HW2 with the the files:
        main.cpp
        functions.h
	functions.cpp
	set.h
        set.cpp
	input.dat
        makefile
        Readme.txt
	runtime.html

2. Build the program.

    Compile the program by:
    % make

3. Run the program by:
   % ./[HW3]

4. Delete the obj files, executables, and core dump by
   % make clean
