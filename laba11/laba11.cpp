#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct atelie
{
	string naim;
	string marka;
	int date;
	int month;
	int year;
	bool ok;
	int full;
};

void quickSort(vector<atelie> a, int left, int right) {
	int i = left, j = right;
	int tmp;
	string tmp1;
	int pivot = a[(left + right) / 2].full;

	while (i <= j) {
		while (a[i].full < pivot)
			i++;
		while (a[j].full > pivot)
			j--;
		if (i <= j) {
			tmp = a[i].full;
			a[i].full = a[j].full;
			a[j].full = tmp;
			tmp = a[i].date;
			a[i].date = a[j].date;
			a[j].date = tmp;
			tmp1 = a[i].marka;
			a[i].marka = a[j].marka;
			a[j].marka = tmp1;
			tmp = a[i].month;
			a[i].month = a[j].month;
			a[j].month = tmp;
			tmp1 = a[i].naim;
			a[i].naim = a[j].naim;
			a[j].naim = tmp1;
			tmp = a[i].year;
			a[i].year = a[j].year;
			a[j].year = tmp;
			tmp = a[i].ok;
			a[i].ok = a[j].ok;
			a[j].ok = tmp;
			i++;
			j--;
		}
	};
	if (left < j)
		quickSort(a, left, j);
	if (i < right)
		quickSort(a, i, right);
	for (int i = 0; i < right - 1; i++) {
		cout << a[i].date << ' ' << a[i].month << ' ' << a[i].year << endl;
	}
}


int main()
{
	struct atelie a;
	setlocale(LC_ALL, "Russian");
	int i, coun = 0;
	string s;
	vector <atelie> at;
	do {
		cout << "Создать - 1\nПросмотр - 2\nДобавление - 3\nНовый заказ - 4 \nЛинейный поиск - 5\nСортировка прямым выбором - 6\nQuickSort - 7\nБинарный поиск - 8\nВыход - 0\n";
		cin >> i;
		if (i == 1) {
			ofstream file("text.txt");
			file.close();
		}
		else if (i == 2) {
			ifstream file("text.txt");
			while (!file.eof()) {
				getline(file, s, '\n');
				cout << s << endl;
			}
			file.close();
		}
		else if (i == 3) {
			char c;
			ofstream file("text.txt", ios::app);
			cout << "write your text here\n";
			do {
				cin >> s;
				file << s << endl;
				cout << "\nContinue? Y/N\n";
				cin >> c;
				cout << endl;
			} while (c == 'Y' || c == 'y');
			file.close();
		}
		else if (i == 4) {
			char c;
			cout << "Введите наименование группы изделий:\n";
			cin >> a.naim;
			cout << "\nВведите марку изделия:\n";
			cin >> a.marka;
			cout << "\nВведите день, месяц и год поступления изделия(через пробел):\n";
			cin >> a.date >> a.month >> a.year;
			cout << "\nИзделие готово?Y/N\n";
			cin >> c;
			if (c == 'Y' || c == 'y') a.ok = 1;
			else if (c == 'N' || c == 'n') a.ok = 0;
			if (a.year % 4 != 0) {
				if (a.month == 1) a.full = a.date;
				else if (a.month == 2) a.full = a.date + 31;
				else if (a.month == 3) a.full = a.date + 59;
				else if (a.month == 4) a.full = a.date + 90;
				else if (a.month == 5) a.full = a.date + 120;
				else if (a.month == 6) a.full = a.date + 151;
				else if (a.month == 7) a.full = a.date + 181;
				else if (a.month == 8) a.full = a.date + 212;
				else if (a.month == 9) a.full = a.date + 243;
				else if (a.month == 10) a.full = a.date + 273;
				else if (a.month == 11) a.full = a.date + 304;
				else if (a.month == 12) a.full = a.date + 334;
				a.full += a.year * 365;
			}
			else {
				if (a.month == 1) a.full = a.date;
				else if (a.month == 2) a.full = a.date + 31;
				else if (a.month == 3) a.full = a.date + 60;
				else if (a.month == 4) a.full = a.date + 91;
				else if (a.month == 5) a.full = a.date + 121;
				else if (a.month == 6) a.full = a.date + 152;
				else if (a.month == 7) a.full = a.date + 182;
				else if (a.month == 8) a.full = a.date + 213;
				else if (a.month == 9) a.full = a.date + 244;
				else if (a.month == 10) a.full = a.date + 274;
				else if (a.month == 11) a.full = a.date + 305;
				else if (a.month == 12) a.full = a.date + 335;
				a.full += a.year * 365;
			}
			at.push_back(a);
			coun++;
		}
		else if (i == 5) {
			int day, month, year;
			cout << "\nВведите день, месяц и год поступления изделия(через пробел):\n";
			cin >> day >> month >> year;
			for (int j = 0; j < coun; j++) {
				if (at[j].date == year and at[j].month == month and at[j].date == day) {
					cout << '\n' << at[j].date << '.' << at[j].month << '.' << at[j].year << '\n';
					cout << at[j].marka << '\n';
					cout << at[j].naim << '\n';
					if (at[j].ok) cout << "Изделие готово\n";
					else cout << "Изделие не готово\n";
				}
				else {
					cout << "В этот день вещей не поступало";
				}
			}
		}
		else if (i == 6) {
			int tmp, m;
			string tmp1;
			for (int q = 0; q < coun - 1; q++) {
				m = q;
				for (int j = 1; j < coun; j++) {
					if (at[j].full < at[m].full) {
						tmp = at[i].full;
						at[i].full = at[j].full;
						at[j].full = tmp;
						tmp = at[i].date;
						at[i].date = at[j].date;
						at[j].date = tmp;
						tmp1 = at[i].marka;
						at[i].marka = at[j].marka;
						at[j].marka = tmp1;
						tmp = at[i].month;
						at[i].month = at[j].month;
						at[j].month = tmp;
						tmp1 = at[i].naim;
						at[i].naim = at[j].naim;
						at[j].naim = tmp1;
						tmp = at[i].year;
						at[i].year = at[j].year;
						at[j].year = tmp;
						tmp = at[i].ok;
						at[i].ok = at[j].ok;
						at[j].ok = tmp;
					}
				}
			}
		}
		else if (i == 7) {
			quickSort(at, 0, coun-1);
		}
			else if (i == 8) {
				int day, month, year, full;
				cout << "\nВведите день, месяц и год поступления изделия(через пробел):\n";
				cin >> day >> month >> year;
				if (a.year % 4 != 0) {
					if (month == 1) full = day;
					else if (month == 2) full = day + 31;
					else if (month == 3) full = day + 59;
					else if (month == 4) full = day + 90;
					else if (month == 5) full = day + 120;
					else if (month == 6) full = day + 151;
					else if (month == 7) full = day + 181;
					else if (month == 8) full = day + 212;
					else if (month == 9) full = day + 243;
					else if (month == 10) full = day + 273;
					else if (month == 11) full = day + 304;
					else if (month == 12) full = day + 334;
					full += year * 365;
				}
				else {
					if (month == 1) full = day;
					else if (month == 2) full = day + 31;
					else if (month == 3) full = day + 60;
					else if (month == 4) full = day + 91;
					else if (month == 5) full = day + 121;
					else if (month == 6) full = day + 152;
					else if (month == 7) full = day + 182;
					else if (month == 8) full = day + 213;
					else if (month == 9) full = day + 244;
					else if (month == 10) full = day + 274;
					else if (month == 11) full = day + 305;
					else if (month == 12) full = day + 335;
					full += year * 365;
				}
				int q = 0, j = coun - 1, m;
				while (q < j) {
					m = (q + j) / 2;
					if (full > at[m].full) q = m + 1;
					else j = m;
				}
			}
	} while (i != 0);
}