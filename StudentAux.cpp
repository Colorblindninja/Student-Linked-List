#include "StudentLinkedList.h"
#include "Student.h"
#include <iostream>
#include <fstream>

int ReadStudentFile(const std::string &filename, StudentLinkedList &students)
{
	int duplicates = 0;
	std::ifstream fin(filename);
	if (!fin)
	{
		std::cout << "could not read the file" << std::endl;
		return 0;
	}
	Student s;
	while (fin)
	{
		fin >> s;
		if (!students.Insert(s))
		{
			duplicates++;
		}
	}

	fin.close();
	return duplicates;
}

int RemoveStudents(const std::string &filename, StudentLinkedList &students)
{
	int no_exist = 0;
	std::ifstream fin(filename);
	if (!fin)
	{
		std::cout << "could not read the file" << std::endl;
		return 0;
	}
	char ssn[12];
	Student s;
	while (fin.getline(ssn, 12))
	{

		s.setSsn(ssn);
		if (!students.Delete(s))
		{
			no_exist++;
		}
	}
	fin.close();
	return no_exist;
}

double AverageAgeStudents(const std::string &filename, StudentLinkedList &students)
{
	double average = 0;
	int count = 0;
	std::ifstream fin(filename);
	if (!fin)
	{
		std::cout << "could not read the file" << std::endl;
		return 0;
	}
	while (fin)
	{
		Student s;
		fin >> s;
		int age = students.Retrieve(s).getAge();
		if (age != 0)
		{
			average += age;
			count += 1;
		}
	}
	fin.close();
	return average / (count-1);
}