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

	// �������� �� �������
	bool empty();

	// �������� �������� �� �������
	bool contain(int);

	// ���������� �������� � ������
	void add(int);

	// ������ ��������� 
	int size();

	// � ������������ �
	bool is_sub_set(Set_Set*);

	// � ����� �
	bool is_equal(Set_Set*);

	// �����������
	Set_Set* unification(Set_Set*);

	// �����������
	Set_Set* intersection(Set_Set*);

	// ��������
	Set_Set* difference(Set_Set*);

	// ������������ ��������
	Set_Set* sym_difference(Set_Set*);

	// ����� ���������
	string print();
};