#include "stdio.h"
#include "string.h"
#include "student.h"


void printStudents(struct person *person, int numStudents) {
	char tmpNames[16]; //Tempoary string holder for both first and last name
	printf("\n*****STUDENTS*****\n");

	//Simply prints out every person's record data that is a student
	for(int i = 0; i < numStudents; i++) {
		if (person->emplyeeOrStudent == 1) {
			sprintf(tmpNames, "%s %s", person->firstName, person->familyName);
			printf("%-33s", tmpNames);
			printf("GPA: %d, Courses: %d, Tuition: %.2f\n", person->stu.gpa, person->stu.numCourses, person->stu.tuitionFees);
		}
		person++;
	}
	
}

void searchStudents(struct person *person, int numStudents) {
	char input[80]; //For entering in a last name
	char tmp[16]; //Tempoary string holder for last name
	int found = 0;
	int studentsFound = 0; //A variable holding the number of students with that last name in the system

	printf("\n*****FINDING STUDENT*****\n");
	printf("Enter in a family name: \n");
	scanf("%s", input);

	printf("\n");
	//Goes through and sees if the entered last name matches with the person's last name in each record
	for(int i = 0; i < numStudents; i++) {
		
		if (person->emplyeeOrStudent == 1) {
			if (strcmp(input, person->familyName) == 0) {
				studentsFound++;
				found = 1;
				sprintf(tmp, "%s %s", person->firstName, person->familyName);
				printf("%-33s", tmp);
				printf("GPA: %d, Courses: %d, Tuition: %.2f\n", person->stu.gpa, person->stu.numCourses, person->stu.tuitionFees);
			}
		}
		person++;
	}

	if (found == 0) 
		printf("Cannot find '%s' in our records.\n", input);
	else 
		printf("\n# of students with family name '%s' found: %d\n", input, studentsFound); 	
}

