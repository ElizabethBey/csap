//12
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input_vector(int n) { // ввод вектора
	vector<int> vec;
	int c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		vec.push_back(c);
	}
	return vec;
}

void output_vector(vector<int> vec) { //вывод вектора
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

int x;
bool kratn(int y) { // кратно ли число у х
	return y % x == 0;
}

int a, b;
bool interval(int y) { // входит ли число в интервал
	return y <= b && y >= a;
}

int main(){
	setlocale(LC_ALL, "rus");
	int n; cout << "n = "; cin >> n;

	cout << "Введите 1 последовательность: " << endl;
	vector<int> vec1 = input_vector(n);
	cout << "Введите 2 последовательность: " << endl;
	vector<int> vec2 = input_vector(n);

	cout << "В 1 уда­лить все элементы, кратные x" << endl << "x = ";
	cin >> x;
	vector<int>::iterator it = remove_if(vec1.begin(), vec1.end(), kratn);
	vec1.erase(it, vec1.end());
	output_vector(vec1);

	cout << "В 2 заменить элементы, попадающие в [a, b] числом y" << endl;
	int y;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "y = "; cin >> y;
	replace_if(vec2.begin(), vec2.end(), interval, y);
	output_vector(vec2);

	cout << "Сортируем 1: " << endl;
	sort(vec1.begin(), vec1.end());
	output_vector(vec1);

	cout << "Сортируем 2: " << endl;
	sort(vec2.begin(), vec2.end());
	output_vector(vec2);

	cout << "Слияние 1 и 2: " << endl;
	vector<int> vec3(vec1.size() + vec2.size());
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
	output_vector(vec3);

	system("pause");
	return 0;
}
