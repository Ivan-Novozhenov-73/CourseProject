#include <iostream>
#include <chrono>
#include <iomanip>
#include "Set_Node.h"
#include "Set_Class.h"
#include "Set_List.h"
#include "Set_Set.h"
#include "Set_Vector.h"
#include "Set_Queue.h"
#include <regex>

using namespace std;

int main() {
	setlocale(0, "");
	srand(time(NULL));

	cout << "Size of Set: ";
	string input;
	int SET_SIZE = 0;
	cin >> input;

	regex pattern("^[0-9]+$");
	if (regex_match(input, pattern)) {
		SET_SIZE = stoi(input);
	}
	else {
		cout << "Non-integer number entered!" << endl;		// Введено не целое число
		cin >> input;
		return 1;
	}

	if (SET_SIZE < 1000) {
		cout << "Set sizes are too small!" << endl;			// Слишком малый размер множеств
		cin >> SET_SIZE;
		return 1;
	}
	else if (SET_SIZE > 1000000) {
		cout << "Set sizes are too big" << endl;			// Слишком большой размер множеств
		cin >> SET_SIZE;
		return 1;
	}

	// Шапка
	cout << setw(22) << "|" << setw(22) << "Single link list |" << setw(22) 
		<< "Class \"List\" |" << setw(22) << "List |" << setw(22) << "Set |" << setw(22)  << "Vector |" << setw(22) << "Queue |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	

	// СОЗДАНИЕ МНОЖЕСТВА
	cout << setw(22) << "Creating a set |";

	// ����������� ������
	auto startTime = chrono::steady_clock::now();
	Node* setA = create_set(SET_SIZE);
	auto endTime = chrono::steady_clock::now();
	double time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";
	Node* setB = create_set(SET_SIZE);

	// ����� "������"
	startTime = chrono::steady_clock::now();
	Set_Class* set_classA = new Set_Class(SET_SIZE);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";
	Set_Class* set_classB = new Set_Class(SET_SIZE);

	// ����� List
	startTime = chrono::steady_clock::now();
	Set_List* set_listA = new Set_List(SET_SIZE);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";
	Set_List* set_listB = new Set_List(SET_SIZE);

	// ����� Set
	startTime = chrono::steady_clock::now();
	Set_Set* set_setA = new Set_Set(SET_SIZE);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";
	Set_Set* set_setB = new Set_Set(SET_SIZE);

	// ����� Vector
	startTime = chrono::steady_clock::now();
	Set_Vector* set_vectorA = new Set_Vector(SET_SIZE);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";
	Set_Vector* set_vectorB = new Set_Vector(SET_SIZE);

	// ����� Queue
	startTime = chrono::steady_clock::now();
	Set_Queue* set_queueA = new Set_Queue(SET_SIZE);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |" << endl;
	Set_Queue* set_queueB = new Set_Queue(SET_SIZE);

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	
	// МОЩНОСТЬ
	cout << setw(22) << "Power |";

	// ����������� ������
	startTime = chrono::steady_clock::now();
	size(setA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� "������"
	startTime = chrono::steady_clock::now();
	set_classA->size();
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� List
	startTime = chrono::steady_clock::now();
	set_listA->size();
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Set
	startTime = chrono::steady_clock::now();
	set_setA->size();
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Vector
	startTime = chrono::steady_clock::now();
	set_vectorA->size();
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Queue
	startTime = chrono::steady_clock::now();
	set_queueA->size();
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	
	// ПОДМНОЖЕСТВО А-А
	cout << setw(22) << "Subset A-A |";
	
	// ����������� ������
	startTime = chrono::steady_clock::now();
	is_sub_set(setA, setA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� "������"
	startTime = chrono::steady_clock::now();
	set_classA->is_sub_set(set_classA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� List
	startTime = chrono::steady_clock::now();
	set_listA->is_sub_set(set_listA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Set
	startTime = chrono::steady_clock::now();
	set_setA->is_sub_set(set_setA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Vector
	startTime = chrono::steady_clock::now();
	set_vectorA->is_sub_set(set_vectorA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Queue
	startTime = chrono::steady_clock::now();
	set_queueA->is_sub_set(set_queueA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	
	// ПОДМНОЖЕСТВО А-В
	cout << setw(22) << "Subset A-B |";
	
	// ����������� ������
	startTime = chrono::steady_clock::now();
	is_sub_set(setA, setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� "������"
	startTime = chrono::steady_clock::now();
	set_classA->is_sub_set(set_classB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";
	
	// ����� List
	startTime = chrono::steady_clock::now();
	set_listA->is_sub_set(set_listB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Set
	startTime = chrono::steady_clock::now();
	set_setA->is_sub_set(set_setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Vector
	startTime = chrono::steady_clock::now();
	set_vectorA->is_sub_set(set_vectorB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Queue
	startTime = chrono::steady_clock::now();
	set_queueA->is_sub_set(set_queueB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	
	// РАВЕНСТВО А-А
	cout << setw(22) << "Equality A-A |"; 
		
	// ����������� ������
	startTime = chrono::steady_clock::now();
	is_equal(setA, setA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� "������"
	startTime = chrono::steady_clock::now();
	set_classA->is_equal(set_classA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� List
	startTime = chrono::steady_clock::now();
	set_listA->is_equal(set_listA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Set
	startTime = chrono::steady_clock::now();
	set_setA->is_equal(set_setA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Vector
	startTime = chrono::steady_clock::now();
	set_vectorA->is_equal(set_vectorA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Queue
	startTime = chrono::steady_clock::now();
	set_queueA->is_equal(set_queueA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	

	// РАВЕНСТВО A-B
	cout << setw(22) << "Equality A-B |";
	
	// ����������� ������
	startTime = chrono::steady_clock::now();
	is_equal(setA, setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� "������"
	startTime = chrono::steady_clock::now();
	set_classA->is_equal(set_classB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� List
	startTime = chrono::steady_clock::now();
	set_listA->is_equal(set_listB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Set
	startTime = chrono::steady_clock::now();
	set_setA->is_equal(set_setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Vector
	startTime = chrono::steady_clock::now();
	set_vectorA->is_equal(set_vectorB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Queue
	startTime = chrono::steady_clock::now();
	set_queueA->is_equal(set_queueB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	
	// ОБЪЕДИНЕНИЕ
	cout << setw(22) << "Unification |"; 
	
	// ����������� ������
	startTime = chrono::steady_clock::now();
	unification(setA, setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� "������"
	startTime = chrono::steady_clock::now();
	set_classA->unification(set_classB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� List
	startTime = chrono::steady_clock::now();
	set_listA->unification(set_listB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Set
	startTime = chrono::steady_clock::now();
	set_setA->unification(set_setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Vector
	startTime = chrono::steady_clock::now();
	set_vectorA->unification(set_vectorB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Queue
	startTime = chrono::steady_clock::now();
	set_queueA->unification(set_queueB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |" << endl;
	
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	

	// ПЕРЕСЕЧЕНИЕ
	cout << setw(22) << "Intersection |";

	// ����������� ������
	startTime = chrono::steady_clock::now();
	intersection(setA, setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� "������"
	startTime = chrono::steady_clock::now();
	set_classA->intersection(set_classB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� List
	startTime = chrono::steady_clock::now();
	set_listA->intersection(set_listB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Set
	startTime = chrono::steady_clock::now();
	set_setA->intersection(set_setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Vector
	startTime = chrono::steady_clock::now();
	set_vectorA->intersection(set_vectorB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Queue
	startTime = chrono::steady_clock::now();
	set_queueA->intersection(set_queueB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	
	// РАЗНОСТЬ А-В
	cout << setw(22) << "Difference A-B |"; 
	
	// ����������� ������
	startTime = chrono::steady_clock::now();
	difference(setA, setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� "������"
	startTime = chrono::steady_clock::now();
	set_classA->difference(set_classB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� List
	startTime = chrono::steady_clock::now();
	set_listA->difference(set_listB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Set
	startTime = chrono::steady_clock::now();
	set_setA->difference(set_setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Vector
	startTime = chrono::steady_clock::now();
	set_vectorA->difference(set_vectorB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Queue
	startTime = chrono::steady_clock::now();
	set_queueA->difference(set_queueB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |" << endl;
	
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	
	// РАЗНОСТЬ В-А
	cout << setw(22) << "Difference B-A |"; 
	
	// ����������� ������
	startTime = chrono::steady_clock::now();
	difference(setB, setA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� "������"
	startTime = chrono::steady_clock::now();
	set_classB->difference(set_classA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� List
	startTime = chrono::steady_clock::now();
	set_listB->difference(set_listA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Set
	startTime = chrono::steady_clock::now();
	set_setB->difference(set_setA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Vector
	startTime = chrono::steady_clock::now();
	set_vectorB->difference(set_vectorA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Queue
	startTime = chrono::steady_clock::now();
	set_queueB->difference(set_queueA);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |" << endl;
	
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	
	// СИММЕТРИЧНАЯ РАЗНОСТЬ
	cout << setw(22) << "Sym difference |"; 

	// ����������� ������
	startTime = chrono::steady_clock::now();
	sym_difference(setA, setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� "������"
	startTime = chrono::steady_clock::now();
	set_classA->sym_difference(set_classB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� List
	startTime = chrono::steady_clock::now();
	set_listA->sym_difference(set_listB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Set
	startTime = chrono::steady_clock::now();
	set_setA->sym_difference(set_setB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Vector
	startTime = chrono::steady_clock::now();
	set_vectorA->sym_difference(set_vectorB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |";

	// ����� Queue
	startTime = chrono::steady_clock::now();
	set_queueA->sym_difference(set_queueB);
	endTime = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
	cout << setw(20) << time << " |" << endl;

	cin >> SET_SIZE;

	return 0;
}