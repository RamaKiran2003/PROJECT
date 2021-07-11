#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Database.h"
#include "Student.h"
#include "Marks.h"

void Database::updateStudentsDirectory(Marks s) {
	for (Marks i : studentsDirectory)
	{
		if (i.getstudentID() == s.getstudentID()) { 
			cout << "Student with the same ID already exist.  Unable to store in the directory" << endl;
			return;
		}
	}
	studentsDirectory.push_back(s);
	cout << "Successfully added student in the directory" << endl;
	return;
}

void Database::readAllStudentsRecord() {
	if (studentsDirectory.empty()) {
		cout << "Database is empty.  No records found..." << endl;
		return;
	}

	for (Marks s : studentsDirectory) {
		cout << s.getLastName() << ", " << s.getFirstName() << endl;
		cout << "ID: " << s.getstudentID() << endl;
		cout << "Physics: " << s.getPhysicsMarks() << endl;
		cout << "Chemistry: " << s.getChemistryMarks() << endl;
		cout << "Maths: " << s.getMathsMarks() << endl;
		cout << "English: " << s.getEnglishMarks() << endl;
		cout << "Computer Science: " << s.getCSMarks() << endl;
		cout << '\n';
	}
	return;
}

void Database::getStudentInfo(int id) {
	for (Marks i : studentsDirectory) {
		if (i.getstudentID() == id)
		{
			i.displayStudentInfo();
			return;
		}
	}
	
	cout << "No student record exist of this ID '" << id << "'" << endl;
	return;
}
void Database::getStudentgrade(int id) {
	for (Marks i : studentsDirectory) {
		if (i.getstudentID() == id)
		{
			i.getStudentAverageLetterGrade();
			return;
		}
	}
	
	cout << "No student record exist of this ID '" << id << "'" << endl;
	return;
}

bool Database::_modifyStudentInfo(Marks *s) {
	int userInput, id;
	string name;
	bool isModified = false;

	cout << "\nChoose option below to modify or enter any other number to return\n" << endl;
	cout << "1: Modify student first name" << endl;
	cout << "2: Modify student last name" << endl;
	cout << "3: Modify student ID\n" << endl;

	cin >> userInput;
	while (userInput > 0 && userInput < 4)
	{
		if (userInput == 1) {
			cout << "\nEnter First Name" << endl;
			cin >> name;
			s->setFirstName(name);
		}

		if (userInput == 2) {
			cout << "\nEnter Last Name" << endl;
			cin >> name;
			s->setLastName(name);
		}

		if (userInput == 3) {
			cout << "\nEnter Student ID" << endl;
			cin >> id;

			for (auto i : studentsDirectory)
			{
				if (i.getstudentID() == id) { 
					cout << "Student with the same ID already exist.  Unable to update Student ID in the directory" << endl;
					return isModified;
				}
			}

			s->setStudentID(id);
		}
		isModified = true;

		cout << "\nChoose option below to modify or enter any other number to return\n" << endl;
		cout << "1: Modify student first name" << endl;
		cout << "2: Modify student last name" << endl;
		cout << "3: Modify student ID\n" << endl;
		cin >> userInput;
	} 

	return isModified;
}

void Database::modifyStudentInfo() {
	int student_id;
	cout << "Enter Student ID to make changes in the Student's Information" << endl;
	cin >> student_id;

	bool isModified = false;
	for (Marks &i : studentsDirectory)
	{
		if (i.getstudentID() == student_id)
		{
			isModified = _modifyStudentInfo(&i);
			if (isModified) {
				cout << "Student record has been updated in the database" << endl;
			}
			else {
				cout << "No changes in the database" << endl;
			}
			return;
		}
	}

	cout << "No student record exist of this ID '" << student_id << "'" << endl;
	return;
}

bool Database::_modifyStudentScore(Marks *s) {
	int userInput, score;
	bool isModified = false;

	cout << "1: Modify student Physics score" << endl;
	cout << "2: Modify student Chemistry score" << endl;
	cout << "3: Modify student Maths score" << endl;
	cout << "4: Modify student English score" << endl;
	cout << "5: Modify student Computer Science score" << endl;

	cout << "Select \"1 - 5\" to modify or enter any other number to return" << endl;
	cin >> userInput;
	while (userInput > 0 && userInput < 6)
	{
		if (userInput == 1) {
			cout << "Enter Physics Score" << endl;
			cin >> score;
			s->setPhysicsMarks(score);
		}

		if (userInput == 2) {
			cout << "Enter Chemistry Score" << endl;
			cin >> score;
			s->setChemistryMarks(score);
		}

		if (userInput == 3) {
			cout << "Enter Maths Score" << endl;
			cin >> score;
			s->setMathsMarks(score);
		}

		if (userInput == 4) {
			cout << "Enter English Score" << endl;
			cin >> score;
			s->setEnglishMarks(score);
		}

		if (userInput == 5) {
			cout << "Enter Computer Science Score" << endl;
			cin >> score;
			s->setCSMarks(score);
		}

		isModified = true;

		cout << "Select \"1 - 5\" to modify or enter any other number to return" << endl;
		cin >> userInput;
	} 

	return isModified;
}

void Database::modifyStudentScore() {
	int student_id;
	cout << "Enter Student ID to make changes in the Student's Score" << endl;
	cin >> student_id;

	bool isModified = false;

	for (auto &i : studentsDirectory)
	{
		if (i.getstudentID() == student_id)
		{
			isModified = _modifyStudentScore(&i);
			if (isModified) {
				cout << "Student score has been updated in the database" << endl;
			}
			else {
				cout << "No changes in the database" << endl;
			}
			return;
		}
	}
	cout << "No student record exist of this ID '" << student_id << "'" << endl;
	return;
}

void Database::deleteStudentRecord() {
	int id, index = 0;

	cout << "Enter student ID to delete from the database" << endl;
	cin >> id;

	for (Marks &i : studentsDirectory) {
		if (i.getstudentID() == id) {
			studentsDirectory.erase(studentsDirectory.begin() + index);
			cout << "Student record has been deleted" << endl;
			return;
		}
		index++;
	}

	cout << "No student record exist of this ID '" << id << "'" << endl;
}

void Database::deleteAllStudentsRecord() {
	if (studentsDirectory.empty()) {
		cout << "Database is empty.  No records found..." << endl;
		return;
	}

	studentsDirectory.clear();
	cout << "Students Record has been deleted" << endl;
	return;
}

double Database::getCourseAvg(string courseName) {
	double avgScore = 0;

	transform(courseName.begin(), courseName.end(), courseName.begin(), ::tolower);

	if (studentsDirectory.empty()) {
		cout << "Database is empty.  No records found..." << endl;
		return -2.0;
	}

	for (Marks S : studentsDirectory) {
		if (courseName == "chemistry")
			avgScore += double(S.getChemistryMarks()) / studentsDirectory.size();
		else if (courseName == "physics")
			avgScore += double(S.getPhysicsMarks()) / studentsDirectory.size();
		else if (courseName == "maths")
			avgScore += double(S.getMathsMarks()) / studentsDirectory.size();
		else if (courseName == "computer science" || courseName == "cs")
			avgScore += double(S.getCSMarks()) / studentsDirectory.size();
		else if (courseName == "english")
			avgScore += double(S.getEnglishMarks()) / studentsDirectory.size();
		else {
			return -1.0;
		}
	}
	return avgScore;
}