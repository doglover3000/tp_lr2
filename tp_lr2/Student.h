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

	friend bool operator<(Student& l, Student& r);
	friend bool operator>(Student& l, Student& r);
	friend bool operator==(Student& l, Student& r);

private:
	string _name;
	int* _scores;
	int _scoresSize();
};
