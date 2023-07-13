#include "Set_Class.h"

// �������� �� �������
bool Set_Class::empty() {
	return set == nullptr;
}

// �������� �������� �� �������
bool Set_Class::contain(int num) {
	Node* temp = set;
	while (temp != nullptr) {
		if (temp->number == num) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

// ���������� �������� � ������
void Set_Class::add(int num) {
	if (!this->contain(num)) {
		Node* temp = new Node();
		temp->number = num;
		temp->next = set;
		set = temp;
	}
}

// ������ ��������� 
int Set_Class::size() {
	int count = 0;
	Node* temp = set;
	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}
	return count;
}

// � ������������ �
bool Set_Class::is_sub_set(Set_Class* setB) {
	Node* temp = set;
	while (temp != nullptr) {
		if (!setB->contain(temp->number)) {
			return false;
		}
		temp = temp->next;
	}
	return true;
}

// � ����� �
bool Set_Class::is_equal(Set_Class* setB) {
	return (is_sub_set(setB) && is_sub_set(this));
}

// �����������
Set_Class* Set_Class::unification(Set_Class* setB) {
	Set_Class* setC = new Set_Class();

	Node* temp = set;
	while (temp != nullptr) {
		setC->add(temp->number);
		temp = temp->next;
	}

	temp = setB->set;
	while (temp != nullptr) {
		setC->add(temp->number);
		temp = temp->next;
	}

	return setC;
}

// �����������
Set_Class* Set_Class::intersection(Set_Class* setB) {
	Set_Class* setC = new Set_Class();

	Node* temp = set;
	while (temp != nullptr) {
		if (setB->contain(temp->number)) {
			setC->add(temp->number);
		}
		temp = temp->next;
	}

	return setC;
}

// ��������
Set_Class* Set_Class::difference(Set_Class* setB) {
	Set_Class* setC = new Set_Class();

	Node* temp = this->set;
	while (temp != nullptr) {
		if (!setB->contain(temp->number)) {
			setC->add(temp->number);
		}
		temp = temp->next;
	}

	return setC;
}

// ������������ ��������
Set_Class* Set_Class::sym_difference(Set_Class* setB) {
	Set_Class* setC = new Set_Class();
	setC = this->unification(setB);

	Set_Class* setD = new Set_Class();
	setC = this->intersection(setB);

	Set_Class* setE = new Set_Class();
	setE = setC->difference(setD);

	return setE;
}

// ����� ���������
string Set_Class::print() {
	string str_set;
	
	Node* temp = set;
	while (temp != nullptr) {
		str_set += to_string(temp->number) + ' ';
		temp = temp->next;
	}
	str_set.erase(str_set.size() - 1);
	return str_set;
}