/***************************************************************************
* student.h : This file contains the interface Student class.
* Requirement: B and D
* Author: Arance Pete apete5@wgu.edu
****************************************************************************/
#ifndef Student_H
#define Student_H

#include <string>
#include "student.h"
#include "degree.h"

namespace WGU_C867_APete_Assessment
{
	class Student
	{
	private:
		//
		std::string _studentID;
		std::string _firstName;
		std::string _lastName;
		std::string _emailAddress;
		int         _age;
		int         _daysToComplete[3];
		DegreeProgramType::Enum _degreeProgram;
		//
	public:
		// Default Constructor
		Student();
		// Parametrized Constructor
		Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* daysToComplete, DegreeProgramType::Enum degreeProgram);
		// Destructor
		~Student();

		//
		// Getters and Setters || Accessors and Mutators
		//
		std::string getStudentID();		
		void setStudentID(std::string studentID);
		//
		std::string getFirstName();
		void setFirstName(std::string firstName);
		//
		std::string getLastName();
		void setLastName(std::string lastName);
		//
		std::string getEmail();
		void setEmail(std::string emailAddress);
		//
		int getAge();
		void setAge(int age);
		//
		int* getDaysToComplete();
		void setDaysToComplete(int* daysToComplete);
		//
		void setDegree(DegreeProgramType::Enum degreeProgram);
		DegreeProgramType::Enum getDegreeProgram();
		//
		// Print Function
		void Print();


	};

}

#endif //


