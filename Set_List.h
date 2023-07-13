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

	// �������� �� �������
	bool empty();

	// �������� �������� �� �������
	bool contain(int);

	// ���������� �������� � ������
	void add(int);

	// ������ ��������� 
	int size();

	// � ������������ �
	bool is_sub_set(Set_List*);

	// � ����� �
	bool is_equal(Set_List*);

	// �����������
	Set_List* unification(Set_List*);

	// �����������
	Set_List* intersection(Set_List*);

	// ��������
	Set_List* difference(Set_List*);

	// ������������ ��������
	Set_List* sym_difference(Set_List*);

	// ����� ���������
	string print();
};