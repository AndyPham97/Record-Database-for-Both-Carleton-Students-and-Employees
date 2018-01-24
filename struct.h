#ifndef STRUCT_HEADER
#define STRUCT_HEADER

#define NAME_SIZE 16

struct student {
	float tuitionFees;
	unsigned int gpa: 4;
	unsigned int numCourses: 6;
};

struct employee {
	float salary;
	unsigned int yearsService: 6;
	unsigned int level: 4;
};

struct person {
	char firstName[NAME_SIZE];
	char familyName[NAME_SIZE];
	char telephone[11];
	union {
		struct student stu;
		struct employee emp;	
	};
	unsigned int emplyeeOrStudent: 1;
};

#endif
