#pragma once
#include <iostream>
#include <vector>

#include "Student.h"

using namespace std;

class Marks:public Student
{
	private:
		int s_id, chemistry, maths, english, computerscience, physics;

	protected:

	public:
		void setStudentID(int id);
		void setPhysicsMarks(int marks);
		void setChemistryMarks(int marks);
		void setMathsMarks(int marks);
		void setEnglishMarks(int marks);
		void setCSMarks(int marks);

		int getstudentID();
		int getPhysicsMarks();
		int getChemistryMarks();
		int getMathsMarks();
		int getEnglishMarks();
		int getCSMarks();

		void createStudentReport(string fName, string lName, int id, int phys, int chem, int math, int eng, int cs);
		void displayStudentInfo();
		double getExamAvg(int id);
		char getStudentLetterGrade(string subject);
		int getStudentAverageScore();
		void getStudentAverageLetterGrade();

		~Marks() = default;
};
