#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Set_Vector {
private:
	vector<int> set_vector;

public:
	Set_Vector() {}

	Set_Vector(int size) {
		this->add(rand() % (size + 1));
		for (int i = 1; i < size;) {
			int temp = set_vector.back();
			int num = rand() % (size * 10 + 1);
			this->add(num);
			if (temp != set_vector.back()) {
				i++;
			}
		}
	}

	// проверка на пустоту
	bool empty();

	// проверка элемента на наличие
	bool contain(int);

	// добавление элемента в начало
	void add(int);

	// размер множества 
	int size();

	// А подмножество В
	bool is_sub_set(Set_Vector*);

	// А равно В
	bool is_equal(Set_Vector*);

	// объединение
	Set_Vector* unification(Set_Vector*);

	// пересечение
	Set_Vector* intersection(Set_Vector*);

	// разность
	Set_Vector* difference(Set_Vector*);

	// симметричная разность
	Set_Vector* sym_difference(Set_Vector*);

	// вывод множества
	string print();
};