#include "Set_Queue.h"

// проверка на пустоту множества
bool Set_Queue::empty() {
	return set_queue.empty();
}

// проверка на вхождение числа во множество
bool Set_Queue::contain(int num) {
	if (this->empty()) {
		return false;
	}
	queue<int> temp = set_queue;

	while (!temp.empty()) {
		if (temp.front() == num) {
			return true;
		}
		temp.pop();
	}
	return false;
}

// добавление элементa
void Set_Queue::add(int num) {
	if (!this->contain(num)) {
		set_queue.push(num);
	}
}

// размер множества
int Set_Queue::size() {
	return set_queue.size();
}

// выводит множество
string Set_Queue::print() {
	string str_set;
	if (this->empty()) {
		return str_set;
	}
	queue<int> temp = set_queue;

	while (!temp.empty()) {
		str_set += to_string(temp.front()) + ' ';
		temp.pop();
	}
	str_set.erase(str_set.size() - 1);
	return str_set;
}

// А подмножество В
bool Set_Queue::is_sub_set(Set_Queue* set2) {
	queue<int> temp = set_queue;

	while (!temp.empty()) {
		if (!set2->contain(temp.front())) {
			return false;
		}
		temp.pop();
	}

	return true;
}

// А равно В
bool Set_Queue::is_equal(Set_Queue* set2) {
	return (this->is_sub_set(set2) && set2->is_sub_set(this));
}

// объединение
Set_Queue* Set_Queue::unification(Set_Queue* set2) {
	Set_Queue* set3 = new Set_Queue();
	queue<int> temp1 = set_queue;
	queue<int> temp2 = set2->set_queue;

	while (!temp1.empty()) {
		set3->add(temp1.front());
		temp1.pop();
	}

	while (!temp2.empty()) {
		set3->add(temp2.front());
		temp2.pop();
	}

	return set3;
}

// пересечение
Set_Queue* Set_Queue::intersection(Set_Queue* set2) {
	Set_Queue* set3 = new Set_Queue();
	queue<int> temp = set_queue;

	while (!temp.empty()) {
		if (set2->contain(temp.front())) {
			set3->add(temp.front());
		}
		temp.pop();
	}

	return set3;
}

// разность
Set_Queue* Set_Queue::difference(Set_Queue* set2) {
	Set_Queue* set3 = new Set_Queue();
	queue<int> temp = set_queue;

	while (!temp.empty()) {
		if (!set2->contain(temp.front())) {
			set3->add(temp.front());
		}
		temp.pop();
	}

	return set3;
}

// симмитричная разность
Set_Queue* Set_Queue::sym_difference(Set_Queue* set2) {
	Set_Queue* set3 = this->unification(set2);
	Set_Queue* set4 = this->intersection(set2);
	return set3->difference(set4);
}