﻿#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<iterator>

using namespace std;

class Person {

public:
	int math;
	int physics;
	int language;
	string name;

	Person(string name, int math, int physics, int language) {
		this->name = name;
		this->math = math;
		this->physics = physics;
		this->language = language;
	}

	friend int result(Person s);
};

int result(Person s) {
	int sum = s.math + s.language + s.physics;
	return sum;
}

struct Subject {
	string math;
	string physics;
	string language;
	string name_of_people;
	string result_t;
	Subject(string name_of_people, string math, string physics, string language, string result_t) : name_of_people(name_of_people), math(math),
		physics(physics), language(language), result_t(result_t) {

	}

	void print_information_subjects() {
		cout << this->name_of_people << "\t\t" << this->math << "\t"
			<< this->physics << "\t\t" << this->language << "\t" << this->result_t;
		//cout << endl;
	}
};

int main() {

	system("chcp 1251");

	cout << "\nНомер \t";

	Subject subject("Имена", "Математика", "Физика", "Русский язык", "Общий балл");

	subject.print_information_subjects();

	cout << "\t Вид обучении\n";
	vector<int> str(102, '-');

	copy(str.begin(), str.end(), ostream_iterator<char>(cout, ""));

	cout << "\n";

	vector<Person> ans{ {Person("Сергей", 98, 70, 45)},
						{Person("Алексей", 99, 45, 55)},
						{Person("Дмитрий", 45, 99, 10)},
						{Person("Аленка", 99, 98, 99)},
						{Person("Алиса", 50, 40, 90)},
						{Person("Маша", 40, 50, 96)},
						{Person("Михаил", 70, 75, 76)},
						{Person("Никита", 80, 65, 96)},
						{Person("Абрам", 60, 50, 40)},
						{Person("Андрей", 100, 100, 100)},
						{Person("Руслан", 65, 45, 78)}
	};


	sort(ans.begin(), ans.end(), [&](Person lok, Person pok) {

		return result(lok) > result(pok);

		});

	vector<string> passed;

	vector<string> names;

	int i = 1;

	for (auto n : ans) {

		if (result(n) >= 180) {

			passed.push_back("Бюджет");

		}

		else {

			passed.push_back("Договор");

		}

		cout << i << ")\t" << n.name << "\t\t" << n.math << "\t\t" << n.physics << "\t\t" << n.language << "\t\t" << result(n) << "\t\t " << passed[i - 1] << "\n";

		copy(str.begin(), str.end(), ostream_iterator<char>(cout, ""));

		names.push_back(n.name);

		cout << endl;

		++i;
		//Номер   Имена           Математика      Физика          Русский язык    Общий балл       Вид обучении

		//	1)      Аленка          99              98              99              296              Бюджет

		//	2)      Никита          80              65              96              241              Бюджет

		//	3)      Михаил          70              75              76              221              Бюджет

		//	4)      Сергей          98              70              45              213              Бюджет

		//	5)      Алексей         99              45              55              199              Бюджет

		//	6)      Руслан          65              45              78              188              Бюджет

		//	7)      Маша            40              50              96              186              Бюджет

		//	8)      Алиса           50              40              90              180              Бюджет

		//	9)      Дмитрий         45              99              10              154              Договор

		//	10)     Абрам           60              50              40              150              Договор
	}

	cout << "\nТаблица студентов в алфавитном порядке\n";

	sort(names.begin(), names.end(), [&](string name_1, string name_2) {
		return  name_1 < name_2;
		});

	for (auto name : names) {

		cout << "\n" << name << "\n";
		/*Таблица студентов в алфавитном порядке

		Абрам

		Алексей

		Аленка

		Алиса

		Дмитрий

		Маша

		Михаил

		Никита

		Руслан

		Сергей*/

	}

	return 0;
}