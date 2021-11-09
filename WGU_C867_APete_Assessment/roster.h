/***************************************************************************
* roster.h : This file contains the interface Roster class.
* Requirement: B and E
* Author: Arance Pete apete5@wgu.edu
****************************************************************************/
#ifndef Roster_H
#define Roster_H

#include <string>
#include "student.h"
#include "degree.h"


namespace WGU_C867_APete_Assessment
{	
	class Roster
	{
	private:
		//		
		Student** _classRosterArray = { nullptr };
		int32_t _item_ref_count = 0;
		//
	public:
		// Constructor
		Roster(int32_t count);
		// Destructor
		~Roster();
		//
		int GetSize();
		//
		void Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgramType::Enum degreeprogram);
		//
		void Remove(std::string studentID);
		//
		void PrintAll();
		//
		void PrintAverageDaysInCourse(std::string studentID);
		//
		void PrintInvalidEmails();
		//
		void PrintByDegreeProgram(DegreeProgramType::Enum degreeProgram);
		//
		Student** GetClassRosterArray();


	};

}

#endif // 