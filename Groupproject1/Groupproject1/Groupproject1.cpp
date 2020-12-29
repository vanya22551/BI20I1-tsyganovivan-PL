#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

string uInput;

vector <int> Num;
vector <int> a;
vector <int> b;
vector <int> result;
vector <int> getNumber();

int operand;
int len_a;
int checkStr();
void sum();
void subtraction();
void showResult();
int trans();
int checkLength();
void multiplication();
void WelcomeMes();

void WelcomeMes() {
	cout << "WelcomeMessage>>>" << endl;
	cout << "Вам доступны действия:" << endl;
	cout << "1. Сумма двух чисел (+) >>>" << endl;
	cout << "2. Разность двух чисел (-) >>>" << endl;
	cout << "3. Произведение двух чисел (*) >>>" << endl;
	cout << "4. Частное двух чисел (/) (в разработке) >>>" << endl;
	cout << "5. Остаток от деления (%)(в разработке )  >>>" << endl;
	cout << "0. Выйти (!)  >>>" << endl;
	cout << "Пример ввода: 48495562145464+7864595413543513" << endl;
	cout << ">>>" << endl;
}

int trans(char element) {
	if (element == '0')
		return 0;
	else if (element == '1')
		return 1;
	else if (element == '2')
		return 2;
	else if (element == '3')
		return 3;
	else if (element == '4')
		return 4;
	else if (element == '5')
		return 5;
	else if (element == '6')
		return 6;
	else if (element == '7')
		return 7;
	else if (element == '8')
		return 8;
	else if (element == '9')
		return 9;
}

int checkStr() {
	int counter = 0;
	len_a = 0;
	for (int i = 0; i < uInput.length(); i++) {
		if (uInput[i] == '0' || uInput[i] == '1' || uInput[i] == '2' || uInput[i] == '3' || uInput[i] == '4' || uInput[i] == '5' || uInput[i] == '6' || uInput[i] == '7' || uInput[i] == '8' || uInput[i] == '9') {
			if (counter == 0) len_a++;
		}
		else counter++;
	}
	if (counter > 1 || counter == 0)
		return true;
	else
		return false;
}
int checkOp() {
	operand = 0;
	for (int i = 0; i < uInput.length(); i++) {
		if (uInput[i] == '+') operand = 1;
		else if (uInput[i] == '-') operand = 2;
		else if (uInput[i] == '*') operand = 3;
		else if (uInput[i] == '/') operand = 4;
		else if (uInput[i] == '!') operand = 0;
	}
	return operand;
}


vector <int> getNumber(vector <int>& a, vector <int>& b) {
	for (int i = 0; i < len_a; i++) {
		a.push_back(trans(uInput[i]));
	}
	for (int i = len_a + 1; i < uInput.length(); i++) {
		b.push_back(trans(uInput[i]));
	}
	return a, b;
}


void showResult() {
	int counter = 0;
	for (int i = 0; i < result.size(); i++) {
		if (result[i] == 0) counter++; else break;
	}
	for (int i = 0 + counter; i < result.size(); i++) {
		cout << result[i];
	}
	cout << "" << endl;
	cout << ">>>" << endl;
	a.clear();
	b.clear();
	result.clear();
}




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {
		WelcomeMes();
		do {
			cout << "Введите числа и действие, или ! для выхода." << endl;
			cout << ">>>";
			cin >> uInput;
			if (checkStr()) {
				system("cls");
				cout << "Сделайте ввод корректно, используя пример." << endl;
				cout << ">>>";
				system("pause");
			}
			system("cls");
		} while (checkStr());
		checkOp();
		switch (operand) {
		case 1:
			getNumber(a, b);
			sum();
			showResult();
			break;
	
		
		case 4: break;

		}
	} while (operand != 0);

	system("pause");
	return 0;
