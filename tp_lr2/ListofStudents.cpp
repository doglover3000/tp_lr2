#include "ListofStudents.h"

List::List()
{
	_size = 0;
	_first = nullptr;
}

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

void List::add_at(int i, Student& st)
{
	if (i < 0 || i >= _size)
		throw exception("Неверный индекс!");
	ListItem* tmp = _first;
	ListItem* prev = _first;
	for (int j = 0; j < i; j++)
	{
		prev = tmp;
		tmp = tmp->_next;
	}
	ListItem* added = new ListItem;
	added->_item = &st;
	if (prev == tmp)
	{
		added->_next = tmp;
		_first = added;
	}
	else
	{
		prev->_next = added;
		added->_next = tmp;
	}
	_size++;
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
			if (st < *tmp->_item)
			{
				this->add_at(i, st);
				return;
			}
			if (tmp->_next != nullptr)
				tmp = tmp->_next;
		}
		tmp->_next = new ListItem;
		tmp = tmp->_next;
		tmp->_item = &st;
		tmp->_next = nullptr;
	}
}

void List::remove(int i)
{
	if (i < 0 || i >= _size)
		throw exception("Неверный индекс!");
	if (_size == 1)
	{
		this->clear();
		return;
	}
	ListItem* tmp = _first;
	ListItem* prev = _first;
	for (int j = 0; j < i; j++)
	{
		prev = tmp;
		tmp = tmp->_next;
	}
	if (tmp = prev)
		_first = tmp->_next;
	else
		prev->_next = tmp->_next;
	_size--;
	delete tmp;
}

void List::clear()
{
	ListItem* tmp = _first;
	for (int i = 0; i < _size; i++)
	{
		ListItem* removed = tmp;
		tmp = tmp->_next;
		delete removed->_item;
		delete removed;
	}
	_size = 0;
}

void List::getInfo(int i)
{
	if (i < 0 || i >= _size) 
		throw exception("Неверный индекс!");
	ListItem* tmp = _first;
	for (int j = 0; j < i; j++) 
		tmp = tmp->_next;
	cout << tmp->_item->getName() << ", группа: " << tmp->_item->getName() << "\nОценки: ";
	tmp->_item->printScore();
	cout << "\nСредний балл: " << tmp->_item->getAvgScore() << endl;
}

bool List::isHighScore(int i)
{
	if (i < 0 || i >= _size)
		throw exception("Неверный индекс!");
	ListItem* tmp = _first;
	for (int j = 0; j < i; j++)
		tmp = tmp->_next;
	return tmp->_item->getHighScore();
}
