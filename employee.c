#include "employee.h"
#include "string.h"
#include "stdio.h"

void printEmployees(struct person *person, int numPersons) {
	char tmpNames [16]; //Tempoary string holder for both first and last name
	printf("\n*****EMPLOYEES*****\n");
	
	//Simply prints out every person's record data that is an employee
	for(int i = 0; i < numPersons; i++) {
		if (person->emplyeeOrStudent == 0) {
			sprintf(tmpNames, "%s %s", person->firstName, person->familyName);
			printf("%-33s", tmpNames);
			printf("Years: %d, Level: %d, Salary: %.2f\n", person->emp.yearsService, person->emp.level, person->emp.salary);
		}
		person++;
	}

}
