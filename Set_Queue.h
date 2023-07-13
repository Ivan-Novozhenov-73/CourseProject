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

	// �������� �� �������
	bool empty();

	// �������� �������� �� �������
	bool contain(int);

	// ���������� �������� � ������
	void add(int);

	// ������ ��������� 
	int size();

	// � ������������ �
	bool is_sub_set(Set_Queue*);

	// � ����� �
	bool is_equal(Set_Queue*);

	// �����������
	Set_Queue* unification(Set_Queue*);

	// �����������
	Set_Queue* intersection(Set_Queue*);

	// ��������
	Set_Queue* difference(Set_Queue*);

	// ������������ ��������
	Set_Queue* sym_difference(Set_Queue*);

	// ����� ���������
	string print();
};