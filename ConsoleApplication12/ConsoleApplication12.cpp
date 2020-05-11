#include <iostream>
#include <string>
#include<fstream>
#include<cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void create_file(ofstream& fout, char* namef) {
	int f;
	fout.open(namef, ios::out | ios::binary);
	cout << "\n f=";
	cin >> f;
	while (f != 999)
	{
		fout.write((char*)& f, sizeof f);
		cout << "\n f=";
		cin >> f;
	} fout.close();
	cout << endl;

}
void read_file(ifstream& fin, char* namef) {
	int f;
	fin.open(namef, ios::in | ios::binary);

	if (!fin.is_open())
		exit(1);
	if (fin.eof())
	{
		fin.clear();
		fin.seekg(0);
	}
	while (fin.read((char*)& f, sizeof f)) {

		cout << f << '\t';
	}
	fin.close();
}
void search(ifstream& fin, char* namef, char* nameg, ofstream& gout) {

	fin.open(namef, ios::in | ios::binary);
	gout.open(nameg, ios::out | ios::binary);
	if (fin.eof()) {
		fin.clear();
		fin.seekg(0);
	}
	int i = 0; int f; int g;
	while (fin.read((char*)& f, sizeof f)) {
		if (f % 2 == 0) {

			cout << f << endl;
		}
		i++;

		gout << f << endl;
	}   fin.close(); gout.close();

}

	

void BaseTask()
{
	cout << "Базовый уровень" << endl;
	cout << "««Абитуриент»: фамилия; имя; отчество; пол; национальность; дата рождения(год, месяц число); домашний адрес(почтовый индекс, страна, область, район, город,улица, дом, квартира); оценки по экзаменам; проходной балл.Вывести данные про абитуриентов, проходной балл которых равен больше 4 ." << endl;

	struct d_birthday
	{
		int year;
		int month;
		int day;
	};
	struct home_address
	{
		int index;
		char country[20];
		char region[30];
		char rayon[30];
		char city[30];
		char street[30];
		int home;
		int kvartira;
	};
	struct abiturient
	{
		char surname[20];
		char name[20];
		char otch[20];
		char pol[10];
		char nationality[20];
		d_birthday birthday;
		home_address address;
		int mark;
		float ball;
	};

		setlocale(LC_ALL, "rus");

		const int N = 1;
		abiturient mas[N];

		for (int i = 0; i < N; i++)
		{
			cout << "Введите фамилию: "; cin >> mas[i].surname;
			cout << "Введите имя: "; cin >> mas[i].name;
			cout << "Введите отчество: "; cin >> mas[i].otch;
			cout << "Введите пол: "; cin >> mas[i].pol;
			cout << "Введите национальность: "; cin >> mas[i].nationality;
			cout << "Введите день рождения: "; cin >> mas[i].birthday.day;
			cout << "Введите месяц рождения: "; cin >> mas[i].birthday.month;
			cout << "Введите год рождения: "; cin >> mas[i].birthday.year;
			cout << "Введите индекс: "; cin >> mas[i].address.index;
			cout << "Введите страну: "; cin >> mas[i].address.country;
			cout << "Введите регион: "; cin >> mas[i].address.region;
			cout << "Введите район: "; cin >> mas[i].address.rayon;
			cout << "Введите город: "; cin >> mas[i].address.city;
			cout << "Введите улицу: "; cin >> mas[i].address.street;
			cout << "Введите номер дома: "; cin >> mas[i].address.home;
			cout << "Введите номер квартиры: "; cin >> mas[i].address.kvartira;
			cout << "Введите оценку: "; cin >> mas[i].mark;
			cout << "Введите проходной балл: "; cin >> mas[i].ball;
		}
		string filename = "my.txt";

		ofstream fout(filename);
		if (!fout)
		{
			cerr << "Ошибка создания/открытия файла `" << filename << "`";
		}

		for (int i = 0; i < N; i++)
		{
			fout << mas[i].surname << ' ';
			fout << mas[i].name << ' ';
			fout << mas[i].otch << ' ';
			fout << mas[i].pol << ' ';
			fout << mas[i].nationality << ' ';
			fout << mas[i].birthday.day << ' ';
			fout << mas[i].birthday.month << ' ';
			fout << mas[i].birthday.year << ' ';
			fout << mas[i].address.index << ' ';
			fout << mas[i].address.country << ' ';
			fout << mas[i].address.region << ' ';
			fout << mas[i].address.rayon << ' ';
			fout << mas[i].address.city << ' ';
			fout << mas[i].address.street << ' ';
			fout << mas[i].address.home << ' ';
			fout << mas[i].address.kvartira << ' ';
			fout << mas[i].mark << ' ';
			fout << mas[i].ball << ' ';
			fout << endl;
		}

		fout.close(); // Закрытие файла после записи.

		ifstream fin(filename/*, ios::binary*/);
		if (!fin)
		{
			cerr << "Ошибка открытия файла";
		}

		for (int i = 0; i < N; i++)
		{
			fin >> mas[i].surname;
			fin >> mas[i].name;
			fin >> mas[i].otch;
			fin >> mas[i].pol;
			fin >> mas[i].nationality;
			fin >> mas[i].birthday.day;
			fin >> mas[i].birthday.month;
			fin >> mas[i].birthday.year;
			fin >> mas[i].address.index;
			fin >> mas[i].address.country;
			fin >> mas[i].address.region;
			fin >> mas[i].address.rayon;
			fin >> mas[i].address.city;
			fin >> mas[i].address.street;
			fin >> mas[i].address.home;
			fin >> mas[i].address.kvartira;
			fin >> mas[i].mark;
			fin >> mas[i].ball;
		}
		fin.close();

		cout << endl << "[Прочитано из файла]" << endl;
		for (int i = 0; i < N; i++)
		{
			cout << "[" << i + 1 << "]" << endl;
			cout << "Фамилия: " << mas[i].surname << endl;
			cout << "Имя: " << mas[i].name << endl;
			cout << "Отчество: " << mas[i].otch << endl;
			cout << "Пол: " << mas[i].pol << endl;
			cout << "Национальность: " << mas[i].nationality << endl;
			cout << "День рождения: " << mas[i].birthday.day << endl;
			cout << "Месяц рождения: " << mas[i].birthday.month << endl;
			cout << "Год рождения: " << mas[i].birthday.year << endl;
			cout << "Индекс: " << mas[i].address.index << endl;
			cout << "Страна: " << mas[i].address.country << endl;
			cout << "Регион: " << mas[i].address.region << endl;
			cout << "Район: " << mas[i].address.rayon << endl;
			cout << "Город: " << mas[i].address.city << endl;
			cout << "Улица: " << mas[i].address.street << endl;
			cout << "Номер дома: " << mas[i].address.home << endl;
			cout << "Номер квартиры: " << mas[i].address.kvartira << endl;
			cout << "Оценка: " << mas[i].mark << endl;
			cout << "Проходной балл: " << mas[i].ball << endl;
			cout << endl;
		}
}

void MediumTask()
{
	cout << "Средний уровень:" << endl;
	cout << "Дан файл f, компоненты которого являются целыми числами. Получить в файле g все компоненты файла f являющиеся чётными числами." << endl;
	ofstream fout;
	ifstream fin;
	ifstream gin;

	char namef[100];
	char nameg[20];
	cout << "Enter name for new file f: ";
	cin >> namef;
	create_file(fout, namef);
	read_file(fin, namef);
	cout << "Enter name for new file g: ";
	cin >> nameg;
	ofstream gout;
	search(fin, namef, nameg, gout);

	read_file(gin, nameg);
	system("pause");
}

void HardTask()
{
	cout << "Высокий уровень:" << endl;
	cout << "Заданы две строки. Построить новую строку, состоящую из символов, которые входят в первую строку, но не входят во вторую." << endl;
	
}

int main()
{
	setlocale(LC_ALL, "Rus");
	BaseTask();
	MediumTask();
	HardTask();
}