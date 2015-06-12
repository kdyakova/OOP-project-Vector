#include "Student.h"


Student::Student() : m_name("Georgi"), m_age(19) {}
Student::Student(std::string name, int age) : m_name(name), m_age(age) {}