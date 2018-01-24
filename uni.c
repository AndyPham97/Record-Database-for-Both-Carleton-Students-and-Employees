/***********HEADER FILES***********/
#include "stdio.h"
#include "stdlib.h"
#include "populateRecords.h"
#include "student.h"
#include "employee.h"
#include "struct.h"

#define NUM_RECORDS 20

/***********FUNCTION PROTOTYPES***********/
int menu();
void printSummary(struct person *person, int numPersons);
int quitProgram();

/***********MAIN PROGRAM***********/
int main()
{
	int choice = 0, option = 0; //Option is the user's answer to agreeing to quit or not
	int run = 1; //Dictates if the program is running or going to stop

    struct person person[NUM_RECORDS];
    populateRecords(person, NUM_RECORDS);

	choice = menu(); //This statement will display the menu

	while (run == 1) {
		switch(choice) {

		case 0: option = quitProgram();
			if (option == 1) {
				printf("EXITING PROGRAM.\n");
				run = 0;
			}
			else
				choice = menu();
			break;
		case 1: printEmployees(person, NUM_RECORDS);
				choice = menu();
				break;
		case 2: printStudents(person, NUM_RECORDS);
				choice = menu();
				break;
		case 3: searchStudents(person, NUM_RECORDS);
				choice = menu();
				break;
		case 4: printSummary(person, NUM_RECORDS);
				choice = menu();
				break;
		default: printf("\nIncorrect option.\n");
				 choice = menu();
			     break;
		}
	}
    return 0;
}

/**********FUNCTION DEFINITIONS***********/

void printSummary(struct person *person, int numPersons) {
	int length = 0, numStudents = 0, numEmployees = 0;
	float totalYrs = 0, totalSrly = 0;
	float totalGpa = 0, totalCourses = 0, totalTuition = 0;
	int maxLevel = 0, minLevel = 0;
	struct person * p; //Pointer for struct person

	p = &person[0]; //p points to the first array of person

	printf("\n*****SUMMARY OF DATA*****\n");
	//Loops through the person array and length increases as each element is not empty
	for(int i = 0; i < numPersons; i++) {
		if (p != '\0')
			length++;
		p++;
	} 

	p = &person[0]; //Resets to same position as before

	for(int i = 0; i < numPersons; i++) {
		if(p->emplyeeOrStudent == 0) {
			totalYrs += p->emp.yearsService;
			totalSrly += p->emp.salary;
			numEmployees++;
		}
		else {
			totalGpa += p->stu.gpa;
			totalCourses += p->stu.numCourses;
			totalTuition += p->stu.tuitionFees;
			numStudents++;
		}
		p++;
	} 

	p = &person[0]; //Resets to same position as before
	
	//Setting both the max and min level variables to the first element of person's level
	minLevel = p->emp.level; 
	maxLevel = p->emp.level;

	//Traversing through the loop to manage the updated new min and max levels
	for(int i = 0; i < numPersons; i++) {
		if(p->emplyeeOrStudent == 0) {
			if (p->emp.level > maxLevel)
					maxLevel = p->emp.level;
			if (p->emp.level < minLevel)
					minLevel = p->emp.level;
			
		}
		p++;
	}

	printf("Total number of records: %d\n", length);
	printf("\nStudent Stats:\n");
	printf("Number of students: %d\n", numStudents);
	printf("Average GPA: %.2f, Average Number of courses: %.2f, Average Tuition Fees: %.2f\n", totalGpa/numStudents, totalCourses/numStudents, totalTuition/numStudents);
	printf("\nEmployee Stats:\n");
	printf("Number of employees: %d, Min Level: %d, Max Level: %d\n", numEmployees, minLevel, maxLevel);
	printf("Average Years of Service: %.2f, Average Salary: %.2f\n", totalYrs/numEmployees, totalSrly/numEmployees); 
}


int menu () {
	printf("\n");
	int num = 0; //User's choice to picking which menu option
	printf("1. Print all employees\n");
	printf("2. Print all students\n");
	printf("3. Search students using Family Name\n");
	printf("4. Summary of Data\n");
	printf("0. Quit\n");

	printf("Enter in a number (1,2,3,4,0): ");
	scanf("%d", &num);
	return num;
}

int quitProgram() {
	int answer = 0;

	printf("\nWant to quit program? (1 for yes, 0 for no): ");
	scanf("%d", &answer);	

	if (answer != 1 || answer != 0) {
		while (answer != 1 && answer != 0) {
			printf("Incorrect input: ");
			scanf("%d", &answer);	
		}
	}
	else if (answer == 0)
		return 1;
	else
		return 0;

}
