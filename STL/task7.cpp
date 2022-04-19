#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <set>

using namespace std;

void output_vector(vector<int> a) { //вывод вектора
	for_each(a.begin(), a.end(), [](int n) {
		cout << n << "  ";
	});
	cout << endl;
}

void output_list(list<int> a) { //вывод списка
	for_each(a.begin(), a.end(), [](int n) {
		cout << n << "  ";
	});
	cout << endl;
}

void task1() { //В векторе сначала все элементы, меньшие 5-го элемента, потом большие. 
	vector<int> a = { 1, 9, 3, 4, 5, 6, 7, 8, 2, 0 };
	cout << "Задача 1: " << endl;
	cout << "Initial vector: ";
	output_vector(a);
	nth_element(a.begin(), a.begin() + 5, a.end());
	cout << "Changed vector: ";
	output_vector(a);
}

void task2() { //в списке на первом месте стоит первый максимальный элемент
	list<int> a = { 2, 5, 8, 1, 3, 9, 6, 4, 7, 0 };
	cout << "Задача 2: " << endl;
	cout << "Initial list: ";
	output_list(a);
	rotate(a.begin(), max_element(a.begin(), a.end()), a.end());
	cout << "Changed list: ";
	output_list(a);
}

void task3() { //сделать вектор кучей
	vector<int> a = { 2, 9, 8, 1, 3, 5, 6, 4, 7, 0 };
	cout << "Задача 1: " << endl;
	cout << "Initial vector: ";
	output_vector(a);
	make_heap(a.begin(), a.end());
	cout << "Changed list: ";
	output_vector(a);
}

void task4() { //Найти скалярное произведение данных списков
	cout << "Задача 4" << endl;
	list<int> a = { 2, 5, 8, 1, 3, 9, 6, 4, 7, 0 };
	list<int> b = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	cout << "Initial list1: "; output_list(a); 
	cout << "Initial list2: "; output_list(b);
	transform(a.begin(), a.end(), b.begin(), a.begin(), multiplies<int>());
	cout << "List1 * list2: ";
	output_list(a);
	int pr = 0;
	for_each(a.begin(), a.end(), [&pr](int n) {
		pr += n;
	});
	cout << "Скалярное произведение: " << pr << endl;
}

void task5() { //Используя множество, найти количество различных букв в строке
	cout << "Задание 5" << endl;
	string s = "aabbcc";
	cout << "Initial string: " << s << endl;
	set<char> a;
	for_each(s.begin(), s.end(), [&a](char n) {
		a.insert(n);
	});
	cout << "Number of different letters: " << a.size() << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	task1();
	task2();
	task3();
	task4();
	task5();
	system("pause");
	return 0;
}
