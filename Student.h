#pragma once
#include <string>
class Student
{
public:
	Student();
	Student(std::string name, int age);

private:
	std::string m_name;
	int m_age;
};

