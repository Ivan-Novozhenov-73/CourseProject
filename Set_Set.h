#pragma once
#include <iostream>
#include <set>
#include <string>

using namespace std;

class Set_Set {
public:
	set<int> set_set;

	Set_Set() {}

	Set_Set(int size) {
		while (set_set.size() < size) {
			int num = 0 + rand() % (size * 10 + 1);
			this->add(num);
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
	bool is_sub_set(Set_Set*);

	// А равно В
	bool is_equal(Set_Set*);

	// объединение
	Set_Set* unification(Set_Set*);

	// пересечение
	Set_Set* intersection(Set_Set*);

	// разность
	Set_Set* difference(Set_Set*);

	// симметричная разность
	Set_Set* sym_difference(Set_Set*);

	// вывод множества
	string print();
};