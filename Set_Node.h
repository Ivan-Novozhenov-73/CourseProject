#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Node {
	Node* next = NULL;
	int number;
};

// �������� ������� ���������
Node* create_set();

// �������� ��������� � �����������
Node* create_set(int);

// �������� �� �������
bool empty(Node*);

// �������� �������� �� �������
bool contain(Node*, int);

// ���������� �������� � ������
Node* add(Node*, int);

// ������ ��������� 
int size(Node*);

// �������� ���������
Node* delete_set(Node*);

// � ������������ �
bool is_sub_set(Node*, Node*);

// � ����� �
bool is_equal(Node*, Node*);

// �����������
Node* unification(Node*, Node*);

// �����������
Node* intersection(Node*, Node*);

// ��������
Node* difference(Node*, Node*);

// ������������ ��������
Node* sym_difference(Node*, Node*);

// ����� ���������
string print(Node*);