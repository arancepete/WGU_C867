/***************************************************************************
* roster.cpp : This file contains the implementation for Roster class.
* Requirement: B and E
*
* Author: Arance Pete apete5@wgu.edu 
****************************************************************************/

#include <iostream>
#include "roster.h"


using namespace WGU_C867_APete_Assessment;

Roster::Roster(int32_t count)
{
	this->_classRosterArray = new Student * [count];
}

Roster::~Roster()
{
	// clean up 
	if (this->_classRosterArray != nullptr)
	{
		for (std::size_t i = 0; i < this->GetSize(); i++)
		{
			// clean inside
			if (this->_classRosterArray[i] != nullptr)
			{

				delete this->_classRosterArray[i];
			}			
		}
		// now the free array
		delete[] this->_classRosterArray;
	}
	
}


int Roster::GetSize()
{
	return this->_item_ref_count;
}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgramType::Enum degreeprogram)
{
	try
	{
		int *numDaysToComplete = new int[3];
		numDaysToComplete[0] = daysInCourse1;
		numDaysToComplete[1] = daysInCourse2;
		numDaysToComplete[2] = daysInCourse3;
		auto size = this->GetSize();

		switch (degreeprogram) {
		case DegreeProgramType::Enum::NETWORK:
			this->_classRosterArray[this->_item_ref_count] = new Student(studentID, firstName, lastName, emailAddress, age, numDaysToComplete, degreeprogram);
			break;
		case DegreeProgramType::Enum::SECURITY:
			this->_classRosterArray[this->_item_ref_count] = new Student(studentID, firstName, lastName, emailAddress, age, numDaysToComplete, degreeprogram);
			break;
		case DegreeProgramType::Enum::SOFTWARE:
			this->_classRosterArray[this->_item_ref_count] = new Student(studentID, firstName, lastName, emailAddress, age, numDaysToComplete, degreeprogram);
			break;
		}

		// add 1 to roster array count
		this->_item_ref_count++;

		// clean up
		delete[] numDaysToComplete;
		 
	}
	catch (const std::exception& e)
	{
		// catch and report any unexpected exceptions thrown
		std::cerr << "ERROR: Unexpected exception encountered - adding student"
			<< e.what() << std::endl;
	}
}

void Roster::Remove(std::string studentID)
{
	try
	{
		bool remove = false;
		for (std::size_t i = 0; i < this->GetSize(); i++)
		{
			if (this->_classRosterArray[i]->getStudentID() == studentID)
			{
				this->_classRosterArray[i] = nullptr;
				// shift or resize array 
				for (std::size_t j = i; j < this->GetSize(); ++j)
					this->_classRosterArray[j] = this->_classRosterArray[j + 1];
				// decrease array item ref count 
				this->_item_ref_count--;
				std::cout << "Student ID: " << studentID << " was successfuly removed." << std::endl;
				return;
			}
			
		}
		
		std::cout << "Student ID: " << studentID << " was not found." << std::endl;

	}
	catch (const std::exception& e)
	{
		// catch and report any unexpected exceptions thrown
		std::cerr << "ERROR: Unexpected exception encountered - removing student"
			<< e.what() << std::endl;
	}	
}

void Roster::PrintAll()
{
	try
	{	
		for (std::size_t i = 0; i < this->GetSize(); i++)
		{
			this->_classRosterArray[i]->Print();
		}
	}
	catch (const std::exception& e)
	{
		// catch and report any unexpected exceptions thrown
		std::cerr << "ERROR: Unexpected exception encountered - printing all students"
			<< e.what() << std::endl;
	}
	
}

void Roster::PrintAverageDaysInCourse(std::string studentID)
{
	try
	{
		float averageDaysInCourse = 0;
		int maximumValue = 3;

		for (std::size_t i = 0; i < this->GetSize(); i++) 
		{
			if (this->_classRosterArray[i] != nullptr && this->_classRosterArray[i]->getStudentID() == studentID) {
				std::int32_t* daysInCourse = this->_classRosterArray[i]->getDaysToComplete();
				for (std::size_t x = 0; x < maximumValue; x++) {
					averageDaysInCourse += daysInCourse[x];
				}

				std::cout << "Student ID " << this->_classRosterArray[i]->getStudentID() << " has an average of " << (averageDaysInCourse / maximumValue) << " days to complete 3 courses." << std::endl;
				break;
			}
		}
	}
	catch (const std::exception& e)
	{
		// catch and report any unexpected exceptions thrown
		std::cerr << "ERROR: Unexpected exception encountered - printing average days"
			<< e.what() << std::endl;
	}
}

void Roster::PrintInvalidEmails()
{
	try
	{
		for (std::size_t i = 0; i < this->GetSize(); ++i)
		{
			std::string invalidEmails = this->_classRosterArray[i]->getEmail();
			static const std::size_t npos = -1; //declaration of static member constant 

			if ((invalidEmails.find("@") == npos) || (invalidEmails.find(".") == npos) || !(invalidEmails.find(" ") == npos)) 
			{
				std::cout << invalidEmails << " is an invalid email" << std::endl;
			}
		}
	}
	catch (const std::exception& e)
	{
		// catch and report any unexpected exceptions thrown
		std::cerr << "ERROR: Unexpected exception encountered - printing invalid emails"
			<< e.what() << std::endl;
	}
}

void Roster::PrintByDegreeProgram(DegreeProgramType::Enum degreeProgram)
{
	try
	{
		for (std::size_t i = 0; i < 5; i++)
		{
			if (this->_classRosterArray[i]->getDegreeProgram() == degreeProgram)
			{
				this->_classRosterArray[i]->Print();
			}
		}
	}
	catch (const std::exception& e)
	{
		// catch and report any unexpected exceptions thrown
		std::cerr << "ERROR: Unexpected exception encountered - printing degree program"
			<< e.what() << std::endl;
	}
}

Student** Roster::GetClassRosterArray()
{
	return this->_classRosterArray;
}
