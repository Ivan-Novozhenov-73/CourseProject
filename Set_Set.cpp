#include "Set_Set.h"

bool Set_Set::empty() {
	return set_set.empty();
}

// проверка на вхождение числа во множество
bool Set_Set::contain(int num) {
	return set_set.count(num);
}

// добавление элемента в начало
void Set_Set::add(int num) {
	set_set.insert(num);
}

// размер множества
int Set_Set::size() {
	return set_set.size();
}

// выводит множество
string Set_Set::print() {
	string str_set;
	if (set_set.empty()) {
		return str_set;
	}
	for (auto iter{ set_set.begin() }; iter != set_set.end(); iter++) {
		str_set += to_string(*iter) + ' ';
	}
	str_set.erase(str_set.size() - 1);
	return str_set;
}

// А подмножество В
bool Set_Set::is_sub_set(Set_Set* set2) {
	for (auto iter{ set_set.begin() }; iter != set_set.end(); iter++) {
		if (!set2->contain(*iter)) {
			return false;
		}
	}
	return true;
}

// А равно В
bool Set_Set::is_equal(Set_Set* set2) {
	return (this->is_sub_set(set2) && set2->is_sub_set(this));
}

// объединение множеств
Set_Set* Set_Set::unification(Set_Set* set2) {
	Set_Set* set3 = new Set_Set();
	for (auto iter{ this->set_set.begin() }; iter != this->set_set.end(); iter++) {
		set3->add(*iter);
	}
	for (auto iter{ set2->set_set.begin() }; iter != set2->set_set.end(); iter++) {
		set3->add(*iter);
	}

	return set3;
}

// пересечение множеств
Set_Set* Set_Set::intersection(Set_Set* set2) {
	if (this->set_set.empty() || set2->set_set.empty()) {
		return nullptr;
	}

	Set_Set* set3 = new Set_Set();
	for (auto iter{ this->set_set.begin() }; iter != this->set_set.end(); iter++) {
		if (set2->contain(*iter)) {
			set3->add(*iter);
		}
	}

	return set3;
}

// разность множеств
Set_Set* Set_Set::difference(Set_Set* set2) {
	Set_Set* set3 = new Set_Set();
	for (auto iter{ this->set_set.begin() }; iter != this->set_set.end(); iter++) {
		if (!set2->contain(*iter)) {
			set3->add(*iter);
		}
	}

	return set3;
}

// симмитричная разность множеств
Set_Set* Set_Set::sym_difference(Set_Set* set2) {
	Set_Set* set3 = this->unification(set2);
	Set_Set* set4 = this->intersection(set2);
	Set_Set* set5 = set3->difference(set4);

	return set5;
}