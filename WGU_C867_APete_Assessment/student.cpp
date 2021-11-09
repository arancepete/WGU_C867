/***************************************************************************
* student.cpp : This file contains the implementation for Student class.
* Requirement: B and D
* Author: Arance Pete apete5@wgu.edu / arancepete@hotmail.com
****************************************************************************/

#include "student.h"
#include <iostream>

using namespace WGU_C867_APete_Assessment;


Student::Student()
{
}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* daysToComplete, DegreeProgramType::Enum degreeProgram)
{
	this->_studentID = studentID;
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_emailAddress = emailAddress;
	this->_age = age;
	this->_daysToComplete[0] = daysToComplete[0];
	this->_daysToComplete[1] = daysToComplete[1];
	this->_daysToComplete[2] = daysToComplete[2];
	this->_degreeProgram = degreeProgram;
}

Student::~Student()
{
}

std::string Student::getStudentID()
{
	return this->_studentID;
}

void Student::setStudentID(std::string studentID)
{
	this->_studentID = studentID;
}

std::string Student::getFirstName()
{
	return this->_firstName;
}

void Student::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

std::string Student::getLastName()
{
	return this->_lastName;
}

void Student::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

std::string Student::getEmail()
{
	return this->_emailAddress;
}

void Student::setEmail(std::string emailAddress)
{
	this->_emailAddress = emailAddress;
}

int Student::getAge()
{
	return this->_age;
}

void Student::setAge(int age)
{
	this->_age = age;
}

int* Student::getDaysToComplete()
{
	return this->_daysToComplete;
}

void Student::setDaysToComplete(int* daysToComplete)
{
	this->_daysToComplete[0] = daysToComplete[0];
	this->_daysToComplete[1] = daysToComplete[1];
	this->_daysToComplete[2] = daysToComplete[2];
}

DegreeProgramType::Enum  Student::getDegreeProgram()
{	
	return this->_degreeProgram;
}

void Student::setDegree(DegreeProgramType::Enum degreeprogram)
{
	this->_degreeProgram = degreeprogram;
}

void Student::Print()
{
	static const char* EnumToString[] = { "Security", "Network", "Software" };
	 
	std::cout            << this->getStudentID() <<
	"\tFirst Name: "     << this->getFirstName() <<
	"\tLast Name: "      << this->getLastName()  <<
	"\tAge: "            << this->getAge()       <<
	"\tEmail Address: "  << this->getEmail()     <<
	"\tdaysInCourse: {"  << this->getDaysToComplete()[0] << ", " << this->getDaysToComplete()[1] << ", " << this->getDaysToComplete()[2] << "}" <<
	"\tDegree Program: " << EnumToString[this->getDegreeProgram()] << std::endl;
}


