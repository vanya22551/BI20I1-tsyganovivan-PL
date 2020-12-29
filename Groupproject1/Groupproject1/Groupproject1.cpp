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

void sum() {
	int flag = 0;

	if (a.size() > b.size()) {
		for (int i = a.size() - b.size(); i > 0; i--) {
			b.insert(b.begin(), 0);
		}
	}
	else if (b.size() > a.size()) {
		for (int i = b.size() - a.size(); i > 0; i--) {
			a.insert(a.begin(), 0);
		}
	}

	for (int i = a.size() - 1; i >= 0; i--) {
		result.insert(result.begin(), (a[i] + b[i] + flag) % 10);

		if (i == 0 && a[i] + b[i] + flag > 9)
			result.insert(result.begin(), 1);

		if ((a[i] + b[i] + flag) > 9)
			flag = 1;
		else
			flag = 0;
	}
}

void subtraction() {
	int flag = 0;
	auto begin = result.cbegin();

	if (a.size() > b.size()) {
		for (int i = a.size() - b.size(); i > 0; i--) {
			b.insert(b.begin(), 0);
		}
	}
	else if (b.size() > a.size()) {
		for (int i = b.size() - a.size(); i > 0; i--) {
			a.insert(a.begin(), 0);
		}
	}

	if (checkLength()) {
		for (int i = a.size() - 1; i >= 0; i--) {
			if (a[i] < b[i]) {
				result.insert(result.begin(), (a[i] + 10) - b[i]);
				int j = i;
				while (j > 0) {
					if (a[j - 1] > 0) {
						a[j - 1] = a[j - 1] - 1;
						flag++;
						if (flag == 2)
							a[j - 1] += 1;
						break;
					}
					else {
						a[j - 1] = -1;
						j--;
					}
				}
			}
			else {
				result.insert(result.begin(), a[i] - b[i]);
			}
			if (b[i] < 0 && i == 0) {
				result[i] = 0;
			}
		}
		for (int i = 0; i < result.size(); i++) {
			if (result[i] < 0) {
				result[i] = 0;
			}
		}
	}
	else {
		for (int i = a.size() - 1; i >= 0; i--) {
			if (b[i] < a[i]) {
				result.insert(result.begin(), (b[i] + 10) - a[i]);
				int j = i;
				while (j > 0) {
					if (b[j - 1] != 0) {
						b[j - 1] = b[j - 1] - 1;
						flag++;
						if (flag == 2)
							b[j - 1] += 1;
						break;
					}
					else {
						b[j - 1] = -1;
						j--;
					}
				}
			}
			else {
				result.insert(result.begin(), b[i] - a[i]);
			}
			if (b[i] < 0 && i == 0) {
				result[i] = 0;
			}
		}
		cout << "-";
	}
}

void multiplication() {
	int flag = 0;
	int counter = 0;

	vector <int> cur;
	vector <int> carry1;
	vector <int> carry2 = { 0 };

	while (b.empty() == false) {

		int def = 0;
		for (int i = a.size() - 1; i >= 0; i--) {
			cur.insert(cur.begin(), (a[i] * b.back() + def) % 10);

			if (i == 0 && a[i] * b.back() + def > 9)
				cur.insert(cur.begin(), (a[i] * b.back() + def) / 10);

			if ((a[i] * b.back() + def) > 9)
				def = (a[i] * b.back() + def) / 10;
			else
				def = 0;
		}
		if (counter > 0)
			for (int i = counter; i >= 1; i--) {
				cur.push_back(0);
			}
		int j = cur.size() - carry2.size();
		int k = cur.size() - carry1.size();

		if (carry1.empty()) {
			for (int i = abs(j); i > 0; i--) {
				carry2.insert(carry2.begin(), 0);
			}
		}
		else
			for (int i = abs(k); i > 0; i--) {
				carry1.insert(carry1.begin(), 0);
			}

		if (carry1.empty()) {
			for (int i = carry2.size() - 1; i >= 0; i--) {
				carry1.insert(carry1.begin(), (carry2[i] + cur[i] + flag) % 10);

				if (i == 0 && carry2[i] + cur[i] + flag > 9)
					carry1.insert(carry1.begin(), 1);

				if ((carry2[i] + cur[i] + flag) > 9)
					flag = 1;
				else
					flag = 0;
			}
			carry2.clear();
		}
		else if (carry2.empty()) {
			for (int i = carry1.size() - 1; i >= 0; i--) {
				carry2.insert(carry2.begin(), (carry1[i] + cur[i] + flag) % 10);

				if (i == 0 && carry1[i] + cur[i] + flag > 9)
					carry2.insert(carry2.begin(), 1);

				if ((carry1[i] + cur[i] + flag) > 9)
					flag = 1;
				else
					flag = 0;
			}
			carry1.clear();
		}

		counter++;
		cur.clear();
		b.pop_back();
	}

	if (carry1.empty()) result.swap(carry2); else result.swap(carry1);
	carry1.clear();
	carry2.clear();
	cur.clear();
}


int checkLength() {
	if (a.size() > b.size())
		return 1;
	else if (b.size() > a.size())
		return 0;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] > b[i])
			return 1;
		else if (b[i] > a[i])
			return 0;
	}
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
		case 2:
			getNumber(a, b);
			subtraction();
			showResult();
			break;
		case 3:
			getNumber(a, b);
			multiplication();
			showResult();
			break;
		case 4: break;

		}
	} while (operand != 0);

	system("pause");
	return 0;
}