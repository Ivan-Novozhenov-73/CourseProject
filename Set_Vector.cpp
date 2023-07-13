#include "Set_Vector.h"

// �������� �� ������� ���������
bool Set_Vector::empty() {
	return set_vector.empty();
}

// �������� �� ��������� ����� �� ���������
bool Set_Vector::contain(int num) {
	if (this->empty()) {
		return false;
	}
	for (auto iter{ set_vector.begin() }; iter != set_vector.end(); ++iter) {
		if (*iter == num) {
			return true;
		}
	}
	return false;
}

// ���������� �������� � ������
void Set_Vector::add(int num) {
	if (!this->contain(num)) {
		set_vector.push_back(num);
	}
}

// ������ ���������
int Set_Vector::size() {
	return set_vector.size();
}

// ������� ���������
string Set_Vector::print() {
	string str_set;
	if (this->empty()) {
		return str_set;
	}

	for (auto iter{ set_vector.begin() }; iter != set_vector.end(); iter++) {
		str_set += to_string(*iter) + ' ';
	}
	str_set.erase(str_set.size() - 1);
	return str_set;
}

// � ������������ �
bool Set_Vector::is_sub_set(Set_Vector* set2) {
	for (int i : set_vector) {
		if (!set2->contain(i)) {
			return false;
		}
	}
	return true;
}

// � ����� �
bool Set_Vector::is_equal(Set_Vector* set2) {
	return (this->is_sub_set(set2) && set2->is_sub_set(this));
}

// �����������
Set_Vector* Set_Vector::unification(Set_Vector* set2) {
	Set_Vector* set3 = new Set_Vector();
	for (auto iter{ set_vector.begin() }; iter != set_vector.end(); ++iter) {
		set3->add(*iter);
	}

	for (auto iter{ set2->set_vector.begin() }; iter != set2->set_vector.end(); ++iter) {
		set3->add(*iter);
	}

	return set3;
}

// �����������
Set_Vector* Set_Vector::intersection(Set_Vector* set2) {
	Set_Vector* set3 = new Set_Vector();
	for (auto iter{ set_vector.begin() }; iter != set_vector.end(); ++iter) {
		if (set2->contain(*iter)) {
			set3->add(*iter);
		}
	}
	return set3;
}

// ��������
Set_Vector* Set_Vector::difference(Set_Vector* set2) {
	Set_Vector* set3 = new Set_Vector();
	for (auto iter{ set_vector.begin() }; iter != set_vector.end(); ++iter) {
		if (!set2->contain(*iter)) {
			set3->add(*iter);
		}
	}
	return set3;
}

// ������������ ��������
Set_Vector* Set_Vector::sym_difference(Set_Vector* set2) {
	Set_Vector* set3 = this->unification(set2);
	Set_Vector* set4 = this->intersection(set2);
	return set3->difference(set4);
}