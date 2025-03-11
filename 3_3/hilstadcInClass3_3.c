/*
	* File: hilstadcInClass.c
	* Author: Cameron Hilstad
	* Assignment: In Class 03/03/2025
	* Date: 03/03/2025
	* References: w3 C Structures (structs)
*/

#include <stdio.h>

// create student struct 
struct Student {
		char name[50];
		int age;
		char grade;
		int num_courses;
	};

void setStudentStruct(struct Student arr[], int size) {
	int i, c;
	for (i = 0; i < size; i++) {
		printf("Enter student %d's name: ",i+1);
		scanf("%s", &arr[i].name);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		printf("Enter student %d's age: ",i+1);
		scanf("%d", &arr[i].age);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		printf("Enter student %d's grade: ",i+1);
		scanf("%c", &arr[i].grade);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		printf("Enter student %d's number of courses: ",i+1);
		scanf("%d", &arr[i].num_courses);
		while ((c = getchar()) != '\n' && c != EOF) { }
		printf("\n");
	}
}

void printStudentStruct(struct Student arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("Student %d: \n",i+1);
		printf("Name: %s \n",arr[i].name);
		printf("Age: %d \n",arr[i].age);
		printf("Grade: %c \n",arr[i].grade);
		printf("Number of courses: %d \n\n",arr[i].num_courses);
	}
}

int main() {
	int num_students;
	printf("Enter the number of students: ");
    scanf("%d", &num_students);
	
	// decleare struct array
	struct Student students[num_students];
	
	setStudentStruct(students, num_students);
	printStudentStruct(students, num_students);
	
	// Find average number of courses
	int i, totalCourses, averageCourses = 0;
	for (i = 0; i < num_students; i++) {
		totalCourses = totalCourses + students[i].num_courses;
	}
	averageCourses = totalCourses/num_courses;
	print("The average number of courses is %d\n", averageCourses);
	
	return 0;
}