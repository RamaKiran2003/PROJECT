#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "Student.h"
#include "Marks.h"
#include "Database.h"

using namespace std;

bool fileExist(string filename);
void parseFile(string filename, Database *db);
void displayMenuOptions();
void storeStudentInfo(Database *db);
void getStudentInfo(Database *db);
void getgrade(Database *db);

int main()
{
	cout << "Welcome to Students Scorecard Record Application..." << endl;

	int userInput;
	string filename;
	Database db;

	displayMenuOptions();
	cin >> userInput;

	while (userInput != -1)
	{	

		//option 1: open and read the file, store all the data into the database.
		if (userInput == 1) {
			//open file
			cout << "Enter File Name" << endl;
			cin >> filename;

			if (!fileExist(filename)) {
				cout << "Error Found...\n" << "Exiting..." << endl;
				system("pause");
				return -1;
			}
			parseFile(filename, &db);
		}

		//option 2: Display all the records store into the database.
		if (userInput == 2) {
			db.readAllStudentsRecord();
		}

		//option 3: Allow user to enter a student base from the application manually i.e not through file
		if (userInput == 3) {
			storeStudentInfo(&db);
		}

		//option 4: Allow user to get information about a particular student stored in the database given ID
		if (userInput == 4) {
			getStudentInfo(&db);
		}

		//option 5: Allow user to make changes in the student information stored in the database
		if (userInput == 5) {
			db.modifyStudentInfo();
		}

		//option 6: Allow user to make changes in the student's score
		if (userInput == 6) {
			db.modifyStudentScore();
		}

		//option 7:  Allow user to delete student record in the database
		if (userInput == 7) {
			//delete record
			db.deleteStudentRecord();
		}

		//option 8:  Allow user to delete every student record in the database
		if (userInput == 8) {
			//delete  all records
			db.deleteAllStudentsRecord();
		}

		//option 9:  Get average score given course name
		if (userInput == 9) {
			string courseName;
			cout << "Enter course Name" << endl;
			cin >> courseName;
			double avg = db.getCourseAvg(courseName);
			if (avg == -1.0) {
				cout << "Inavlid Course Name" << endl;
			}
			else if (avg == -2.0) {
				cout << "No data in the database" << endl;
			}
			else {
				cout << courseName << " average is " << avg << endl;
			}
		}
          //option 10: Get Grade of the student
		if(userInput == 10){
			getgrade(&db);
		}

		cout << endl;

		displayMenuOptions();
		cin >> userInput;

	} 

	system("pause");
	return 0;
}

bool fileExist(string filename) {

	fstream file(filename);

	return file.good();
}
void parseFile(string filename, Database *db) {

	string line, fName, lName;
	string token;
	int id, physics, chemistry, maths, english; 

	string s_id, phy, chem, math, eng, cs;

	fstream file(filename);
	
	getline(file, line);

	while (getline(file, line))
	{
		stringstream ss(line);

		getline(ss, fName, ',');
		getline(ss, lName, ',');
		getline(ss, s_id, ',');
		getline(ss, phy, ',');
		getline(ss, chem, ',');
		getline(ss, math, ',');
		getline(ss, eng, ',');
		getline(ss, cs, ',');

		Marks s;

		s.setFirstName(fName);
		s.setLastName(lName);
		s.setStudentID(stoi(s_id));
		s.setPhysicsMarks(stoi(phy));
		s.setChemistryMarks(stoi(chem));
		s.setMathsMarks(stoi(math));
		s.setEnglishMarks(stoi(eng));
		s.setCSMarks(stoi(cs));

		//store this student into the database
		db->updateStudentsDirectory(s);
	}
	file.close();
}

void displayMenuOptions() {
	cout << "\nPlease Select Options below or type -1 to quit the application\n" << endl;
	cout << "(1) Store Information from file" << endl;
	cout << "(2) Retrieve All Students Information and Scores from Database" << endl;
	cout << "(3) Store Student information manually" << endl;
	cout << "(4) Retrieve Student Information and Scores" << endl;
	cout << "(5) Modify Student Information" << endl;
	cout << "(6) Modify Student Scores" << endl;
	cout << "(7) Delete Student Record from the Database" << endl;
	cout << "(8) Delete All Students from the Database" << endl;
	cout << "(9) Get average score of all Students" << endl;
	cout << "(10) Get student average Letter Grade\n"<<endl; 
}

void storeStudentInfo(Database *db) {
	string fName, lName;
	int id, phys, chem, math, eng, cs;

	cout << "Enter student first name, last name, and ID" << endl;
	cin >> fName >> lName >> id;

	cout << "Enter student marks in this order: '\n'";
	cout << "Physics, Chemistry, Maths, English, and Computer Science" << endl;
	cin >> phys >> chem >> math >> eng >> cs;

	Marks s;
	s.createStudentReport(fName, lName, id, phys, chem, math, eng, cs);

	db->updateStudentsDirectory(s);
}

void getStudentInfo(Database *db) {
	int id;
	cout << "Enter student ID to get information about the student" << endl;
	cin >> id;

	db->getStudentInfo(id);
}

void getgrade(Database *db){
	int id;
	cout<<" Give the student id :";
	cin>>id;
	db->getStudentgrade(id);
	
}

