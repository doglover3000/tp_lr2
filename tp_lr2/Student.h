#pragma once
#include <iostream>
using namespace std;

class Student
{
public:
	Student(string& name, string& group);
	~Student();

	void setScore(int score);
	string getName();
	int getScore(int i);
	float getAvgScore();

	friend bool operator<(Student& l, Student& r);
	friend bool operator>(Student& l, Student& r);
	friend bool operator==(Student& l, Student& r);

private:
	string _name;
	string _group;
	int* _scores;
	int _scoresSize();
};
