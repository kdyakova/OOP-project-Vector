#include <iostream>
#include<string>
#include"Vector.h"
#include "Student.h"
using namespace std;

int main()
{
	Vector<int> v;
	v.push_back(11);
	v.push_back(19);
	v.push_back(23);
	v.push_back(31);
	for (auto it4 = v.begin(); it4 != v.end(); it4++)
	{
		cout << *it4 << " ";
	}

	cout << endl;


	Student st1("Ivan", 20);
	Student st2("Petur", 20);

	Vector<Student> students;
	students.push_back(st1);
	students.push_back(st2);

	Vector<int> v1;
	v1.push_back(1);
	v1.push_back(13);
	v1.push_back(37);
	v1.push_back(73);
	v1.push_back(121);
	v1.push_back(181);
	v1.push_back(253);

	cout << v1.back() << endl; //253

	v1.pop_back();

	cout << v1.back() << endl; //181
	cout << v1[4] << endl; //121

	v1.push_back(777);

	//Извежда 1 13 37 73 121 181 777
	for (auto it = v1.begin(); it != v1.end() ; it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	Vector<string> v2;
	v2.push_back("Aut viam");
	v2.push_back("inveniam");
	v2.push_back("aut faciam");

	//Извежда Aut viam inveniam aut faciam
	for (auto it = v2.begin(); it != v2.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	Vector<string> v3;
	v3.push_back("Aut");
	v3.push_back("vincere");
	v3.push_back("mori");

	v3.insert(2, "aut");

	//Извежда Aut vincere aut mori
	for (auto it = v3.begin(); it != v3.end() ;it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	v3.erase(0);

	//Извежда vincere aut mori
 	for (auto it = v3.begin(); it != v3.end(); ++it)
	{
		cout << *it << " ";
	}

	cout << endl << endl;

	Vector<int>::iterator it1(v1, 2);
	Vector<int>::iterator it2 = v1.end();
	cout << *it2 << endl;
	it1--;
	it2 = it1;

	cout << *it2 << endl;
	cout << *it1 << endl;

	cout << endl << endl;
	Vector<int> v4;
	Vector<int> v5;
	Vector<int> v6;

	v4.assign(7, 100);

	Vector<int>::iterator it;
	it = v4.begin() + 1;

	v5.assign(it, v4.end() - 1); 

	int myints[] = { 1776, 7, 4 };
	v6.assign(myints, myints + 3);
	//Извежда 100 100 100 100 100 100 100
	for (auto it = v4.begin(); it != v4.end(); ++it) 
	{
		cout << *it << " ";
	}
	cout << endl;
	//Извежда 100 100 100 100 100
	for (auto it = v5.begin(); it != v5.end(); ++it) 
	{
		cout << *it << " ";
	}
	cout << endl;
	// 1776 7 4 
	for (auto it = v6.begin(); it != v6.end(); ++it) 
	{
		cout << *it << " ";
	}
	cout << endl;
	v4.assign(myints, myints + 3);
	for (auto it = v4.begin(); it != v4.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}