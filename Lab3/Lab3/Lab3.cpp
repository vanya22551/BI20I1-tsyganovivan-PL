﻿// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
	int massiv[10] = { 10, 7, 4, 2, 8, 1, 9, 3, 5, 6 };
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < 9; i++)
		{
			
			if (massiv[i] > massiv[i + 1])
			{
				int elem = massiv[i];
				massiv[i] = massiv[i + 1];
				massiv[i + 1] = elem;
				flag = true;

			}
			else if(massiv[i] < massiv[i - 1])
			{
				int elem = massiv[i];
				massiv[i] = massiv[i - 1];
				massiv[i - 1] = elem;
				flag = true;
			}
			
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << massiv[i] << endl;
	}
	return 0;
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
