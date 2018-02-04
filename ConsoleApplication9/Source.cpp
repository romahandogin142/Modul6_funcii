#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

float f();
void findMax();
int isLeap(int year);
void getCountDaysInMonth_5(int year, int month, int day);
int getCountDaysInMonth(int month, int year);
int Task9(char letter);

void main()
{
	setlocale(LC_ALL, "Rus");



	int nz = 0;
	do
	{
		cout << "Введите номер задания: ";
		cin >> nz;
		switch (nz)
		{

			/*3.	Описать функцию IsLeapYear(Y) логического типа, которая возвращает
			True, если год Y (целое положительное число) является високосным, и False в противном случае.
			Вывести значение функции IsLeapYear для пяти данных значений параметра Y. Високосным считается год,
			делящийся на 4, за исключением тех годов, которые делятся на 100 и не делятся на 400.
			4.	Используя функцию IsLeapYear из задания 3, описать функцию MonthDays(M, Y) целого типа, которая
			возвращает количество дней для M-го месяца года Y (1 ≤ M ≤ 12, Y > 0 — целые числа). Вывести значение функции
			MonthDays для данного года Y и месяцев M1, M2, M3.
			5.	Используя функцию MonthDays из задания 4, описать процедуру PrevDate(D, M, Y), которая по информации о
			правильной дате, включаю- щей день D, номер месяца M и год Y, определяет предыдущую дату (пара- метры целого
			типа D, M, Y являются одновременно входными и выходными). Применить процедуру PrevDate к трем исходным датам и
			вывести полученные значения предыдущих дат
			6.	Используя функцию MonthDays из задания 4, описать процедуру NextDate(D, M, Y), которая
			по информации о правильной дате, включаю- щей день D, номер месяца M и год Y, определяет следующую дату
			(пара- метры целого типа D, M, Y являются одновременно входными и выходными). Применить процедуру NextDate к трем
			исходным датам и вывести полученные значения следующих дат
			*/
		case 1:
		{
			cout << "Введите год: ";
			int year;
			cin >> year;

			cout << "Введите месяц: ";
			int month;
			cin >> month;

			cout << "Введите день: ";
			int day;
			cin >> day;

			getCountDaysInMonth_5(year, month, day);
		}
		break;


		}

	} while (nz > 0);
}


void getCountDaysInMonth_5(int year, int month, int day)
{
	int leap = isLeap(year);

	//дату предыдущего дня;
	if (day < 1 && day >31)
	{
		cout << "Введите правильную дату";
	}
	else if (day == 1)
	{
		if (day == 1 && month == 1)
			year = year - 1;

		if (month == 1)
			month = 12;
		else
			month = month - 1;

		day = getCountDaysInMonth(month, year);
	}
	else
		day = day - 1;

	cout << "дату предыдущего дня: " <<
		day << "." <<
		month << "." <<
		year << endl;
}

//Функция которая возвращает високосный ли год
int isLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}

//Функция которая возвращает количество дней в месяце
int getCountDaysInMonth(int month, int year)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
#pragma region MyRegion
		//1-ый
		int leap = isLeap(year);
		if (leap == 1)//високсоный
			return 29;
		else
			return 28;

		//2
		//if (isLeap(year) == 1)//високсоный
		//	return 29;
		//else
		//	return 28;

		//3
		//return isLeap(year) == 1 ? 29 : 28;
#pragma endregion
	}
	else
		return 31;
}

