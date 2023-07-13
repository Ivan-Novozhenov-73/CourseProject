#pragma once
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Set_Queue {
private:
	queue<int> set_queue;

public:
	Set_Queue() {}

	Set_Queue(int size) {
		this->add(rand() % (size + 1));
		for (int i = 1; i < size;) {
			int temp = set_queue.back();
			int num = rand() % (size * 10 + 1);
			this->add(num);
			if (temp != set_queue.back()) {
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
	bool is_sub_set(Set_Queue*);

	// А равно В
	bool is_equal(Set_Queue*);

	// объединение
	Set_Queue* unification(Set_Queue*);

	// пересечение
	Set_Queue* intersection(Set_Queue*);

	// разность
	Set_Queue* difference(Set_Queue*);

	// симметричная разность
	Set_Queue* sym_difference(Set_Queue*);

	// вывод множества
	string print();
};