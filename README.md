# COMP2401---Assignment-3
The purpose of this software is to populate several records of people from Carleton University and gives you the options to either print out all the
current employees and students records, search for a student by their last name and print out the matching student(s) record(s) and print out the summary
of each stat for students and employees, and the total records the university holds

The developer is Andy Pham, student ID# 101006098 and the development date started on November 4th

The main file is ran on uni.c, other files containing the function definitions from the header files
 are student.c, employee.c, and populateRecords.c, the header files are student.h, employee.h, 
student.h, and populateRecords.h

Go into the extracted folder onto the terminal, then with the following commands:
gcc uni.c student.c employee.c populateRecords.c, and next to debug it
gcc -g uni.c student.c employee.c populateRecords.c, and then to execute the program
./a.out

To create a named program rather than the default: ./a.out, do:
gcc -o "Whatever name you want to call it" uni.c student.c employee.c populateRecords.c,
gcc -g -o "Whatever name you want to call it" uni.c student.c employee.c populateRecords.c, and then to execute the program
./"With whatever name you called the program"

After entering in several found names in the search option, it would all of the sudden lock itself to quitting and not 
wanting to quit in a continous loop. But I believe I have fixed it with no knowledge to reason of that occurence, so
I believe you don't need to worry about it happening again because I have tested it after fixing it

It will show you a menu in the format below:

1. Print all employees
2. Print all students
3. Search students using Family Name
4. Summary of Data\n
0. Quit

Enter in a number (1,2,3,4,0): 

Basically, you enter in a number beside each menu option to execute that request. After executing that request or not entering in the correct option, 
it will immediately show the menu below whatever gets printed afterwards according to the option you typed in. 
However, when you enter in 3, you are first prompted to enter in a name before printing out the results after. You can quit by pressing 0, but you are 
given a warning to ensure that you certainly want to quit the program. Pressing 1 finishes running the program and 0 brings you back to the menu.
