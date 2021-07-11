#ifndef __Database
#define __Database
#include <iostream>
#include <vector>
#include <string>

#include "Student.h"
#include "Marks.h"

using namespace std;

class Database{
private:
	vector<Marks> studentsDirectory;
public:
	void updateStudentsDirectory(Marks s);
	void readAllStudentsRecord();
	void getStudentInfo(int id);

	bool _modifyStudentInfo(Marks *s);
	void modifyStudentInfo(); 

	bool _modifyStudentScore(Marks *s);
	void modifyStudentScore();

	void deleteStudentRecord();
	void deleteAllStudentsRecord();

	double getCourseAvg(string courseName);

	int getAllStudentsPhysicsAvg();
	int getAllStudentsChemistryAvg();
	int getAllStudentsMathsAvg();
	int getAllStudentsEnglishAvg();
	int getAllStudentsComputerScienceAvg();
	void getStudentgrade(int id);

};
#endif