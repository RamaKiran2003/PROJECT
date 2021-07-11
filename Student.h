#pragma once
#include <iostream>

using namespace std;

class Student {
private:
protected:
	string firstName, lastName;
public:
	void setFirstName(string fname);
	void setLastName(string lname);

	string getFirstName();
	string getLastName();
};
