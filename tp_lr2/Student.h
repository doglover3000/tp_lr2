#pragma once
#include <iostream>
using namespace std;

class Student
{
public:
	Student(string& name);
	~Student();

	void setName(string& name);
	void setScore(int score);
	string getName();
	int getScore(int i);
	float getAvgScore();

	/*friend bool operator==(const Student&, const Student&);
	friend bool operator!=(const Student&, const Student&);
	friend bool operator<(const Student&, const Student&);
	friend bool operator>(const Student&, const Student&);*/

private:
	string _name;
	int* _scores;
	int _scoresSize();
};
