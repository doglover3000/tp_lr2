#include <iostream>
#include "Student.h"

int main()
{
	string name = "oleg";
	Student a(name);
	a.setScore(5);
	a.setScore(3);
	a.setScore(2);
	a.setScore(5);
	cout << a.getScore(0) << " " << a.getScore(1) << " " << a.getScore(2) << " " << a.getScore(3) << " " << a.getAvgScore();
}
