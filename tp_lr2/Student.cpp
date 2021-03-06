#include "Student.h"

Student::Student(string& name, string& group)
{
	_scores = new int;
	_scores[0] = 0;
 	_name = name;
	_group = group;
	_highscore = true;
}

Student::~Student()
{
	_name.~basic_string();
	delete[] _scores;
}

void Student::setScore(int score)
{
	int* tmp = nullptr;
	if (score != 4 && score != 5)
		_highscore = false;
	if (_scores[0] == 0)
		_scores[0] = score;
	else
	{
		tmp = new int[_scoresSize()+1];
		memcpy(tmp, _scores, _scoresSize() * sizeof(int));
		tmp[_scoresSize()] = score;
		_scores = tmp;
	}
}

string Student::getName()
{
	return _name;
}

string Student::getGroup()
{
	return _group;
}

int Student::getScore(int i)
{
	int tmp = 0;
	if (i <= _scoresSize() && i >= 0)
		tmp = _scores[i];
	return tmp;
}

float Student::getAvgScore()
{
	float tmp = 0;
	if (_scoresSize() <= 0)
		return 0;
	for (int i = 0; i < _scoresSize(); i++)
		tmp += _scores[i];
	return (float)((float)tmp / (float)_scoresSize());
}

bool Student::getHighScore()
{
	return _highscore;
}

void Student::printScore()
{
	for (int i = 0; i < _scoresSize(); i++)
		cout << _scores[i] << " ";
}

int Student::_scoresSize()
{
	return _msize(_scores) / sizeof(int);
}

bool operator<(Student& l, Student& r)
{
	if (l.getAvgScore() < r.getAvgScore())
		return true;
	else
		return false;
}

bool operator>(Student& l, Student& r)
{
	if (l.getAvgScore() > r.getAvgScore())
		return true;
	else
		return false;
}

bool operator==(Student& l, Student& r)
{
	if (l.getAvgScore() == r.getAvgScore())
		return true;
	else
		return false;
}