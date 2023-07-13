#pragma once
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Set_Class {
private:
	struct Node {
		Node* next = nullptr;
		int number;
	};
	Node* set;

public:
	// �������� ������� ���������
	Set_Class() {
		set = nullptr;
	}

	// �������� ��������� � �����������
	Set_Class(int size) {
		Node* temp = set;

		for (int i = 0; i < size;) {
			int num = 0 + rand() % (size * 10 + 1);
			this->add(num);
			if (set != temp) {
				i++;
				temp = set;
			}
		}
	}

	// �������� �� �������
	bool empty();

	// �������� �������� �� �������
	bool contain(int);

	// ���������� �������� � ������
	void add(int);

	// ������ ��������� 
	int size();

	// �������� ���������
	~Set_Class() {
		Node* temp;
		while (set != nullptr) {
			temp = set;
			set = set->next;
			delete temp;
		}
		set = nullptr;
	}

	// � ������������ �
	bool is_sub_set(Set_Class*);

	// � ����� �
	bool is_equal(Set_Class*);

	// �����������
	Set_Class* unification(Set_Class*);

	// �����������
	Set_Class* intersection(Set_Class*);

	// ��������
	Set_Class* difference(Set_Class*);

	// ������������ ��������
	Set_Class* sym_difference(Set_Class*);

	// ����� ���������
	string print();
};