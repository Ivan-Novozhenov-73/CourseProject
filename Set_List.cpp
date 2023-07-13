#include "Set_List.h"

// проверка на пустоту множества
bool Set_List::empty() {
	return set_list.empty();
}

// проверка на вхождение числа во множество
bool Set_List::contain(int num) {
	if (this->empty()) {
		return false;
	}
	for (auto iter = set_list.begin(); iter != set_list.end(); ++iter) {
		if (*iter == num) {
			return true;
		}
	}
	return false;
}

// добавление элемента в начало
void Set_List::add(int num) {
	if (!this->contain(num)) {
		set_list.push_front(num);
	}
}

// размер множества
int Set_List::size() {
	return set_list.size();
}

// выводит множество
string Set_List::print() {
	string str_set;

	for (auto iter{ set_list.begin() }; iter != set_list.end(); iter++) {
		str_set += to_string(*iter) + ' ';
	}
	str_set.erase(str_set.size() - 1);
	return str_set;
}

// А подмножество В
bool Set_List::is_sub_set(Set_List* set2) {
	for (int i : set_list) {
		if (!set2->contain(i)) {
			return false;
		}
	}
	return true;
}

// А равно В
bool Set_List::is_equal(Set_List* set2) {
	return (this->is_sub_set(set2) && set2->is_sub_set(this));
}

// объединение
Set_List* Set_List::unification(Set_List* set2) {
	Set_List* set3 = new Set_List();
	for (auto iter{ set_list.begin() }; iter != set_list.end(); ++iter) {
		set3->add(*iter);
	}

	for (auto iter{ set2->set_list.begin() }; iter != set2->set_list.end(); ++iter) {
		set3->add(*iter);
	}

	return set3;
}

// пересечение
Set_List* Set_List::intersection(Set_List* set2) {
	Set_List* set3 = new Set_List();
	for (auto iter{ set_list.begin() }; iter != set_list.end(); ++iter) {
		if (set2->contain(*iter)) {
			set3->add(*iter);
		}
	}
	return set3;
}

// разность
Set_List* Set_List::difference(Set_List* set2) {
	Set_List* set3 = new Set_List();
	for (auto iter{ set_list.begin() }; iter != set_list.end(); ++iter) {
		if (!set2->contain(*iter)) {
			set3->add(*iter);
		}
	}
	return set3;
}

// симмитричная разность
Set_List* Set_List::sym_difference(Set_List* set2) {
	Set_List* set3 = this->unification(set2);
	Set_List* set4 = this->intersection(set2);
	return set3->difference(set4);
}