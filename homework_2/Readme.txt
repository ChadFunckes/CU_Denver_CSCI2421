*******************************************************
*  Name      :  Chad S Funckes         
*  Student ID:  103528424               
*  Class     :  CSC 2421           
*  HW#       :  1                
*  Due Date  :  Feb 3., 2013
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program takes a number from the user and generates a random
number using the linear congruence method and a user input as a seed number.
The multiplier, increment and modulus are all set by the class constructor,
and the only modifiable element is the seed number input from the user.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that takes a seed number from the user
and then utilizes the my_random class to come up with 3 consecutive random numbers
based upon the user input.

Name:  my_random.h
   Contains the definition for the class my_random.  

Name: my_random.cpp
   Defines and implements the my_random class.  This class provides routines to construct,
change the seed number and generate the random number.

   
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
       % unzip [HW1]

   Now you should see a directory named homework with the files:
        main.cpp
        my_random.h
        my_random.cpp
        makefile
        Readme.txt

2. Build the program.

    Compile the program by:
    % make

3. Run the program by:
   % ./[HW1]

4. Delete the obj files, executables, and core dump by
   % ./make clean
