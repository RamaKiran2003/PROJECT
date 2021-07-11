#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "Marks.h"

using namespace std;

void Marks::setStudentID(int id) {
	this->s_id = id;
}

void Marks::setPhysicsMarks(int marks) {
	this->physics = marks;
}

void Marks::setChemistryMarks(int marks) {
	this->chemistry = marks;
}

void Marks::setMathsMarks(int marks) {
	this->maths = marks;
}

void Marks::setEnglishMarks(int marks) {
	this->english = marks;
}

void Marks::setCSMarks(int marks) {
	this->computerscience = marks;
}

int Marks::getstudentID() {
	return this->s_id;
}

int Marks::getPhysicsMarks() {
	return this->physics;
}

int Marks::getChemistryMarks() {
	return this->chemistry;
}

int Marks::getMathsMarks() {
	return this->maths;
}

int Marks::getEnglishMarks() {
	return this->english;
}

int Marks::getCSMarks() {
	return this->computerscience;
}

void Marks::createStudentReport(string fName, string lName, int id, int phys, int chem, int math, int eng, int cs) {
	this->firstName = fName;
	this->lastName = lName;
	this->s_id = id;
	this->physics = phys;
	this->chemistry = chem;
	this->maths = math;
	this->english = eng;
	this->computerscience = cs;
}

void Marks::displayStudentInfo() {
	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "ID: " << s_id <<endl;
	cout << "Physics: " << physics << endl;
	cout << "Chemistry: " << chemistry << endl;
	cout << "Maths: " << maths << endl;
	cout << "English: " << english << endl;
	cout << "Computer Science: " << computerscience << endl;

}

double Marks::getExamAvg(int id) {
	return (chemistry + physics + maths + english + computerscience) / 5.0;
}

void Marks::getStudentAverageLetterGrade(){

	int id=(chemistry + physics + maths + english + computerscience)/ 5.0;

 //int id;
 if (getExamAvg(id)>90&&getExamAvg(id)<=100){
 cout<<"A++";
 }
 else if(getExamAvg(id)>80&&getExamAvg(id)<=90){
	 cout<<"A";
 }
 else if(getExamAvg(id)>70&&getExamAvg(id)<=80){
	 cout<<"B";
 }
 else if(getExamAvg(id)>60&&getExamAvg(id)<=70){
	 cout<<"C";
 }
 else if(getExamAvg(id)>50&&getExamAvg(id)<=60){
	 cout<<"D";
 }
 else{
	 cout<<"F";
 }

}
