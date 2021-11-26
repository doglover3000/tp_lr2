#include <iostream>
#include "Student.h"

using namespace std;

class List
{
public:
	List(Student& st);
	~List();
	int getSize();
	void add(Student& st);
	void remove(int i);
	void clear();
private:
	int _size;
	struct ListItem
	{
		Student* _item;
		ListItem* _next;
	};
	ListItem* _first;
};