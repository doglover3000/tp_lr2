#include <iostream>
#include <conio.h>
#include <string>
#include "Student.h"
#include "ListofStudents.h"

void Print(List& lst);
void PrintHighScore(List& lst);
void AddStudent(List& lst);
void EditStudent(List& lst);
void RemoveStudent(List& lst);
void RemoveAll(List& lst);

int main()
{
	setlocale(LC_ALL, "Rus");

	int menu, entered = 0;
	List list;

	while (true)
	{
		system("cls");
		cout << "Введите номер команды:\n"
			"1 - Вывод информации о студентах\n"
			"2 - Вывод информации о студентах с оценками только 4 и 5\n"
			"3 - Добавить студента\n"
			"4 - Изменить информацию о студенте\n"
			"5 - Удалить студента\n"
			"6 - Отчистить базу\n"
			"0 - Выход\n> ";
		menu = _getch();

		switch (menu)
		{
		default:
			break;
		case '1':
			system("cls");
			Print(list);
			break;
		case '2':
			system("cls");
			PrintHighScore(list);
			break;
		case '3':
			system("cls");
			AddStudent(list);;
			break;
		case '4':
			system("cls");
			EditStudent(list);
			break;
		case '5':
			system("cls");
			RemoveStudent(list);
			break;
		case '6':
			system("cls");
			RemoveAll(list);
			break;
		case '0':
			return 0;
		}
	}
}

void Print(List& lst)
{
	if (lst.getSize() == 0)
		throw exception("Список студентов пуст!");
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << i << ") ";
		lst.getInfo(i);
	}
	_getch();
}

void PrintHighScore(List& lst)
{
	if (lst.getSize() == 0)
		throw exception("Список студентов пуст!");
	for (int i = 0; i < lst.getSize(); i++)
	{
		if (lst.isHighScore(i))
		{
			cout << i << ") ";
			lst.getInfo(i);
		}
	}
	_getch();
}

void AddStudent(List& lst)
{
	if (lst.getSize() > 0)
		cin.ignore();
	string ln1, ln2;
	cout << "Введите имя студента: \n>> ";
	getline(cin, ln1);
	cout << "Введите номер группы: \n>> ";
	getline(cin, ln2);
	Student *a = new Student(ln1, ln2);
	lst.add(*a);
	cout << "Студент успешно добавлен!";
	_getch();

	int menu, entered, tmp;
	while (true)
	{
		system("cls");
		cout << "1 - Ввести оценки студента\n"
			"0 - Вернуться в меню\n> ";
		menu = _getch();
		cout << endl;
		switch (menu)
		{
		default:
			break;
		case '1':
			cout << "Введите количество оценок, которые вы хотите добавить: ";
			cin >> entered;
			cout << "Вводите оценки по одной:" << endl;
			for (int i = 0; i < entered; i++)
			{
				cout << i+1 << ") ";
				cin >> tmp;
				a->setScore(tmp);
			}
			return;
		case '0':
			return;
		}
	}
}

void EditStudent(List& lst)
{}

void RemoveStudent(List& lst)
{}

void RemoveAll(List& lst)
{}