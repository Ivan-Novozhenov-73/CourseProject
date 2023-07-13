#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Set_List {
private:
	list<int> set_list;

public:
	Set_List() {}

	Set_List(int size) {
		this->add(rand() % (size + 1));
		for (int i = 1; i < size;) {
			int temp = set_list.front();
			int num = 0 + rand() % (size * 10 + 1);
			this->add(num);
			if (temp != set_list.front()) {
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
	bool is_sub_set(Set_List*);

	// А равно В
	bool is_equal(Set_List*);

	// объединение
	Set_List* unification(Set_List*);

	// пересечение
	Set_List* intersection(Set_List*);

	// разность
	Set_List* difference(Set_List*);

	// симметричная разность
	Set_List* sym_difference(Set_List*);

	// вывод множества
	string print();
};