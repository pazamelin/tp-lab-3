// main3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	DateTime date(1, 3, 2000);
	DateTime datenow{};
	cout << date.getToday() << endl;
	cout << date.getYesterday() << endl;
	cout << date.getTomorrow() << endl;
	cout << date.getFuture(5) << endl;
	cout << date.getPast(5) << endl;
	cout << "\n";
	cout << datenow.getToday() << endl;
	cout << datenow.getYesterday() << endl;
	cout << datenow.getTomorrow() << endl;
	cout << datenow.getFuture(5) << endl;
	cout << datenow.getPast(5) << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
