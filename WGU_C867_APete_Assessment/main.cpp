/***************************************************************************
* main.cpp : This file contains the 'main' function.
* Program execution begins and ends here.
*
* Author: Arance Pete apete5@wgu.edu
****************************************************************************/
// 
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "roster.h"


/******************************************************************************
 * Helpers
 ******************************************************************************/

namespace WGU_C867_APete_Assessment
{


	std::vector<std::string> ProcessStudent(std::string student)
	{
		try
		{

			std::istringstream studentString(student);
			std::string studentDataItem;
			std::vector<std::string> studentData(9);

			std::size_t s = 0;

			/* Extracts characters from the stream as unformatted input and stores them into studentString as a c-string, until
			either the extracted character is the delimiting character, or n characters have been written to studentString
			(including the terminating null character). */
			while (std::getline(studentString, studentDataItem, ',')) {
				studentData[s] = studentDataItem;
				s++;
			}

			return studentData;


		}
		catch (const std::exception& e)
		{
			// catch and report any unexpected exceptions thrown
			std::cerr << "ERROR: Processing student data "
				<< e.what() << std::endl;
		}

	}

	DegreeProgramType::Enum GetDegreeProgramEnum(std::string degree)
	{
		try
		{
			if (degree == "NETWORK") {
				return DegreeProgramType::Enum::NETWORK;
			}
			else if (degree == "SECURITY") {
				return DegreeProgramType::Enum::SECURITY;
			}
			else {
				return DegreeProgramType::Enum::SOFTWARE;
			}
		}
		catch (const std::exception& e)
		{
			// catch and report any unexpected exceptions thrown
			std::cerr << "ERROR: Processing student degree string to enumeration"
				<< e.what() << std::endl;
		}
	}


}

/******************************************************************************
 * Main function
 ******************************************************************************/

int main(int argc, char** argv)
{
	// initialize status value to one, indicating an error condition
	std::int32_t status = 1;
	try
	{
		using namespace WGU_C867_APete_Assessment;

		// Requirement A
		const std::string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Arance,Pete,apete5@wgu.edu,46,25,35,50,SOFTWARE"
		};

		std::int32_t studentCount = sizeof(studentData) / sizeof(studentData[0]);

		Roster* classRoster = new Roster(studentCount);

		if (classRoster != nullptr)
		{
			// Load the Class Roster
			std::size_t i = 0;
			while (i < studentCount)
			{
				std::vector<std::string> values = ProcessStudent(studentData[i]);
				classRoster->Add(values[0], values[1], values[2], values[3], stoi(values[4]), stoi(values[5]), stoi(values[6]), stoi(values[7]), GetDegreeProgramEnum(values[8]));
				i++;
			}

			//My student info as as required in F1
			std::cout << "===================================================================="   << std::endl;
			std::cout << "=========================My Student Info============================\n" << std::endl;
			std::cout << "Course Name: Scripting and Programming - Applications - C867"           << std::endl;
			std::cout << "Programming Language Used: C++ via Microsoft Visual Studio"             << std::endl;
			std::cout << "Student ID: #004858154"                                                 << std::endl;
			std::cout << "Student Name: Arance Pete / apete5@wgu.edu \r\n"                        << std::endl;
			std::cout << "\n====================================================================" << std::endl;
			std::cout << "                          Class Roster                                " << std::endl;
			std::cout << "====================================================================\n" << std::endl;
			classRoster->PrintAll();
			std::cout << "\n====================================================================" << std::endl;
			std::cout << "                          Invalid Emails                              " << std::endl;
			std::cout << "====================================================================\n" << std::endl;
			classRoster->PrintInvalidEmails();
			std::cout << "\n====================================================================" << std::endl;
			std::cout << "                        Average Days In Course                        " << std::endl;
			std::cout << "====================================================================\n" << std::endl;
			i = 0;
			while (i < studentCount)
			{
				classRoster->PrintAverageDaysInCourse(classRoster->GetClassRosterArray()[i]->getStudentID());
				i++;
			}
			std::cout << "\n====================================================================" << std::endl;
			std::cout << "                         By Degree Program                            " << std::endl;
			std::cout << "====================================================================\n" << std::endl;
			classRoster->PrintByDegreeProgram(DegreeProgramType::Enum::SOFTWARE);
			std::cout << "\n====================================================================" << std::endl;
			std::cout << "                             Remove A3                                " << std::endl;
			std::cout << "====================================================================\n" << std::endl;
			classRoster->Remove("A3");
			classRoster->PrintAll();
			classRoster->Remove("A3");
			std::cout << "====================================================================\n" << std::endl;
			
			// set status value to zero to indicate successful completion
			status = system("pause");
		}

		// destroy Roster from memory
		delete classRoster;
				
		
	}
	catch (std::exception& e) {
		// catch and report any unexpected exceptions thrown
		std::cerr << "ERROR: Unexpected exception encountered - "
			<< e.what() << std::endl;
	}

	return status;
}

