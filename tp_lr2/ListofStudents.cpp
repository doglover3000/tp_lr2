#include "ListofStudents.h"

List::List(Student& st)
{
	_first = new ListItem;
	_first->_next = nullptr;
	_first->_item = &st;
	_size = 1;
}

List::~List()
{
	clear();
}

int List::getSize()
{
	return _size;
}

void List::add(Student& st)
{
	if (_size == 0)
	{
		_first = new ListItem;
		_first->_next = nullptr;
		_first->_item = &st;
		_size = 1;
	}
	else
	{
		ListItem *tmp = _first;
		for (int i = 0; i < _size; i++)
		{
			////////добавить перегрузку сравнения
		}
	}
}

void List::remove(int i)
{
}

void List::clear()
{
}
