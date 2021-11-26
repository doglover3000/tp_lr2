#include <iostream>
#include "Student.h"

using namespace std;

class List
{
public:
	List();
	List(Student& st);
	~List();
	int getSize();
	void add(Student& st);
	void add_at(int i, Student& st);
	void remove(int i);
	void clear();
	void getInfo(int i);
	bool isHighScore(int i);

private:
	int _size;
	struct ListItem
	{
		Student* _item;
		ListItem* _next;
	};
	ListItem* _first;
};