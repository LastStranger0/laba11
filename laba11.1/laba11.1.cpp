#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>

using namespace std;

struct order
{
	string group, mark;
	int day, month, year, full;
	bool is_ok;
};

void create() {
	ofstream file("text.txt");
	file.close();
}

void look() {
	string s;
	ifstream file("text.txt");
	while (!file.eof()) {
		getline(file, s, '\n');
		cout << s << endl;
	}
	file.close();
}

order rec() {
	char is_ok;
	struct order ord;
	cout << "Введите группу изделия\n";
	cin >> ord.group;
	cout << "\nВведите марку изделия\n";
	cin >> ord.mark;
	cout << "\nВведите день месяц и год поступления изделия:\n";
	cin >> ord.day;
	cin >> ord.month;
	cin >> ord.year;
	cout << "\nЗаказ готов?(y/n)\n";
	cin >> is_ok;
	(is_ok == 'Y' || is_ok == 'y') ? ord.is_ok = 1 : ord.is_ok = 0;
	return ord;
}

vector<order> full(vector<order> a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i].year % 4 != 0) {
			if (a[i].month == 1) a[i].full = a[i].day;
			else if (a[i].month == 2) a[i].full = a[i].day + 31;
			else if (a[i].month == 3) a[i].full = a[i].day + 59;
			else if (a[i].month == 4) a[i].full = a[i].day + 90;
			else if (a[i].month == 5) a[i].full = a[i].day + 120;
			else if (a[i].month == 6) a[i].full = a[i].day + 151;
			else if (a[i].month == 7) a[i].full = a[i].day + 181;
			else if (a[i].month == 8) a[i].full = a[i].day + 212;
			else if (a[i].month == 9) a[i].full = a[i].day + 243;
			else if (a[i].month == 10) a[i].full = a[i].day + 273;
			else if (a[i].month == 11) a[i].full = a[i].day + 304;
			else if (a[i].month == 12) a[i].full = a[i].day + 334;
			a[i].full += a[i].year * 365;
		}
		else {
			if (a[i].month == 1) a[i].full = a[i].day;
			else if (a[i].month == 2) a[i].full = a[i].day + 31;
			else if (a[i].month == 3) a[i].full = a[i].day + 60;
			else if (a[i].month == 4) a[i].full = a[i].day + 91;
			else if (a[i].month == 5) a[i].full = a[i].day + 121;
			else if (a[i].month == 6) a[i].full = a[i].day + 152;
			else if (a[i].month == 7) a[i].full = a[i].day + 182;
			else if (a[i].month == 8) a[i].full = a[i].day + 213;
			else if (a[i].month == 9) a[i].full = a[i].day + 244;
			else if (a[i].month == 10) a[i].full = a[i].day + 274;
			else if (a[i].month == 11) a[i].full = a[i].day + 305;
			else if (a[i].month == 12) a[i].full = a[i].day + 335;
			a[i].full += a[i].year * 365;
		}
	}
	return a;
}

void fil(vector<order> a) {
	ofstream file("text.txt");
	for (int i = 0; i < a.size(); i++) {
		file << a[i].group << ' ';
		file << a[i].mark << ' ';
		file << a[i].day << ' ';
		file << a[i].month << ' ';
		file << a[i].year << ' ';
		file << a[i].is_ok << '\n';
	}
	file.close();
}

int s() {
	string s;
	int i = 0;
	ifstream file("text.txt");
	while (!file.eof()) {
		getline(file, s, '\n');
		i++;
	}
	return i;
	file.close();
}

vector<order> oopen() {
	vector<order> a;
	struct order ord;
	ifstream fil("text.txt");
	for (int i = 0; i < s()-1; i++) {
		fil >> ord.group;
		fil >> ord.mark;
		fil >> ord.day;
		fil >> ord.month;
		fil >> ord.year;
		fil >> ord.is_ok;
		a.push_back(ord);
	}
	fil.close();
	return a;
}

void linear_search(vector<order> a, int day, int month, int year) {
	int k = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i].day == day && a[i].month == month && a[i].year == year) {
			k = 1;
			cout << a[i].group << ' ' << a[i].mark << ' ' << a[i].day << '.' << a[i].month << '.' << a[i].year << ' ';
			if (a[i].is_ok) {
				cout << "Готов\n";
			}
			else {
				cout << "Не готов\n";
			}
		}
		if (k == 0) {
			cout << "В этот день не поступало изделий\n";
		}
	}
}

vector<order> direct_selection(vector<order> a) {
	int min, tmp;
	string tmp1;
	for (int i = 0; i < a.size() - 1; i++) {
		min = i;
		for (int j = i + 1; j < a.size(); j++) {
			if (a[j].year < a[min].year) min = j;
		}
		tmp = a[i].day;
		a[i].day = a[min].day;
		a[min].day = tmp;
		tmp = a[i].month;
		a[i].month = a[min].month;
		a[min].month = tmp;
		tmp = a[i].year;
		a[i].year = a[min].year;
		a[min].year = tmp;
		tmp1 = a[i].mark;
		a[i].mark = a[min].mark;
		a[min].mark = tmp1;
		tmp1 = a[i].group;
		a[i].group = a[min].group;
		a[min].group = tmp1;
		tmp = a[i].is_ok;
		a[i].is_ok = a[min].is_ok;
		a[min].is_ok = tmp;
		tmp = 0;
		tmp1.clear();
		if (a[i].year == a[min].year) {
			tmp = a[i].day;
			a[i].day = a[min].day;
			a[min].day = tmp;
			tmp = a[i].month;
			a[i].month = a[min].month;
			a[min].month = tmp;
			tmp = a[i].year;
			a[i].year = a[min].year;
			a[min].year = tmp;
			tmp1 = a[i].mark;
			a[i].mark = a[min].mark;
			a[min].mark = tmp1;
			tmp1 = a[i].group;
			a[i].group = a[min].group;
			a[min].group = tmp1;
			tmp = a[i].is_ok;
			a[i].is_ok = a[min].is_ok;
			a[min].is_ok = tmp;
			tmp = 0;
			tmp1.clear();
		if (a[i].year == a[min].year && a[i].month == a[min].month) {
			tmp = a[i].day;
			a[i].day = a[min].day;
			a[min].day = tmp;
			tmp = a[i].month;
			a[i].month = a[min].month;
			a[min].month = tmp;
			tmp = a[i].year;
			a[i].year = a[min].year;
			a[min].year = tmp;
			tmp1 = a[i].mark;
			a[i].mark = a[min].mark;
			a[min].mark = tmp1;
			tmp1 = a[i].group;
			a[i].group = a[min].group;
			a[min].group = tmp1;
			tmp = a[i].is_ok;
			a[i].is_ok = a[min].is_ok;
			a[min].is_ok = tmp;
			tmp1.clear();
			tmp = 0;
			}
		}
	}
	return a;
}

vector<order> quickSort(vector<order> a, int L, int R) {

	int i = L, j = R;
	int tmp;
	string tmp1;
	int av = a[(L + R) / 2].full;
	do {
		while (a[i].full < av)
				i++;
		while (a[j].full > av)
				j--;	
			if (i <= j) {
			tmp = a[i].day;
			a[i].day = a[j].day;
			a[j].day = tmp;
			tmp1 = a[i].mark;
			a[i].mark = a[j].mark;
			a[j].mark = tmp1;
			tmp = a[i].month;
			a[i].month = a[j].month;
			a[j].month = tmp;
			tmp1 = a[i].group;
			a[i].group = a[j].group;
			a[j].group = tmp1;
			tmp = a[i].year;
			a[i].year = a[j].year;
			a[j].year = tmp;
			tmp = a[i].is_ok;
			a[i].is_ok = a[j].is_ok;
			a[j].is_ok = tmp;
			tmp = a[i].full;
			a[i].full = a[j].full;
			a[j].full = tmp;
			i++;
			j--;
		}
	}	while (i < j);
	if (L < j)
		quickSort(a, L, j);
	if (i < R)
		quickSort(a, i, R);
	return a;
}

void binarySearch(vector<order> a, int day, int month, int year) {
	int i = 0, j = a.size(), m;
	while (i < j) {
		m = (i + j) / 2;
		if (year > a[m].year) i = m + 1;
		else if (year < a[m].year) j = m;
		else {
			m = (i + j) / 2;
			if (month > a[m].month) i = m + 1;
			else if (month < a[m].month) j = m;
			else {
				m = (i + j) / 2;
				if (day > a[m].day) i = m + 1;
				else j = m;
			}
		}
	}
	if (a[i].day == day && a[i].month == month && a[i].year == year) {
		cout << a[i].group << ' ' << a[i].mark << ' ' << a[i].day << '.' << a[i].month << '.' << a[i].year << ' ';
		if (a[i].is_ok) {
			cout << "Готов\n";
		}
		else {
			cout << "Не готов\n";
		}
	}
	else {
		cout << "В этот день не поступало изделий\n";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<order> a, a1;
	int q;
	int day, month, year;
	a = oopen();
	a = full(a);
	do {
		cout << "Создать файл - 1\nПросмотр - 2\nНовый заказ - 3\nЛинейный поиск - 4 \nСортировка прямым выбором - 5\nQuickSort - 6\nБинарный поиск - 7\nВыход - 0\n";
		cin >> q;
		switch (q)
		{
		default: cout << "Введите 1,2,3,4,5,6,7,0\n";
			break;
		case 1: create();
			break;
		case 2: look();
			break;
		case 3: a.push_back(rec());
			fil(a);
			break;
		case 4:
			cout << "\nВведите день, месяц и год поступления изделия(через пробел):\n";
			cin >> day >> month >> year;
			linear_search(a, day, month, year);
			break;
		case 5:
			a = direct_selection(a);
			for (int i = 0; i < a.size(); i++) {
				cout << a[i].group << ' ' << a[i].mark << ' ' << a[i].day << '.' << a[i].month << '.' << a[i].year << ' ';
				if (a[i].is_ok) {
					cout << "Готов\n";
				}
				else {
					cout << "Не готов\n";
				}
			}
			break;
		case 6:
			a = quickSort(a, 0, a.size() - 1);
			a = quickSort(a, 0, a.size() - 1);
			for (int i = 0; i < a.size(); i++) {
				cout << a[i].group << ' ' << a[i].mark << ' ' << a[i].day << '.' << a[i].month << '.' << a[i].year << ' ';
				if (a[i].is_ok) {
					cout << "Готов\n";
				}
				else {
					cout << "Не готов\n";
				}
			}
			break;
		case 7:
			cout << "\nВведите день, месяц и год поступления изделия(через пробел):\n";
			cin >> day >> month >> year;
			a1 = direct_selection(a);
			binarySearch(a1, day, month, year);
			break;
		case 0:
			system("pause");
			break;
		}
	} while (q != 0);
}