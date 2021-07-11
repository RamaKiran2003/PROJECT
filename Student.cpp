#include <iostream>
#include "Student.h"

using namespace std;

void Student::setFirstName(string fname) {
	this->firstName = fname;
}

void Student::setLastName(string lname) {
	this->lastName = lname;
}

string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}