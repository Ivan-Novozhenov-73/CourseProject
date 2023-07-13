#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Set_Vector {
private:
	vector<int> set_vector;

public:
	Set_Vector() {}

	Set_Vector(int size) {
		this->add(rand() % (size + 1));
		for (int i = 1; i < size;) {
			int temp = set_vector.back();
			int num = rand() % (size * 10 + 1);
			this->add(num);
			if (temp != set_vector.back()) {
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
	bool is_sub_set(Set_Vector*);

	// � ����� �
	bool is_equal(Set_Vector*);

	// �����������
	Set_Vector* unification(Set_Vector*);

	// �����������
	Set_Vector* intersection(Set_Vector*);

	// ��������
	Set_Vector* difference(Set_Vector*);

	// ������������ ��������
	Set_Vector* sym_difference(Set_Vector*);

	// ����� ���������
	string print();
};