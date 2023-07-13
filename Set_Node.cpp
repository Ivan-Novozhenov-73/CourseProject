#include "Set_Node.h"

// создание пустого множества
Node* create_set() {
	return nullptr;
}

// создание множества с параметрами
Node* create_set(int size) {
	Node* set = create_set();
	Node* temp = set;
	srand(time(NULL));

	for (int i = 0; i < size;) {
		int num = 0 + rand() % (size * 10 + 1);
		set = add(set, num);
		if (set != temp) {
			i++;
			temp = set;
		}
	}

	return set;
}

// проверка на пустоту
bool empty(Node* set) {
	return set == nullptr ? true : false;
}

// проверка элемента на наличие
bool contain(Node* set, int num) {
	Node* temp = set;
	while (temp != nullptr) {
		if (temp->number == num) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

// добавление элемента в начало
Node* add(Node* set, int num) {
	if (!contain(set, num)) {
		Node* temp = new Node;
		temp->number = num;
		temp->next = set;
		set = temp;
	}
	return set;
}

// размер множества 
int size(Node* set) {
	Node* temp = set;
	int count = 0;
	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}
	return count;
}

// удаление множества
Node* delete_set(Node* set) {
	Node* temp;
	while (set != nullptr) {
		temp = set;
		set = set->next;
		delete temp;
	}
	set = nullptr;
	return set;
}

// А подмножество В
bool is_sub_set(Node* setA, Node* setB) {
	while (setA != nullptr) {
		if (!contain(setB, setA->number)) {
			return false;
		}
		setA = setA->next;
	}
	return true;
}

// А равно В
bool is_equal(Node* setA, Node* setB) {
	return (is_sub_set(setA, setB) && is_sub_set(setB, setA));
}

// объединение
Node* unification(Node* setA, Node* setB) {
	Node* setC = create_set();
	
	while (setA != nullptr) {
		setC = add(setC, setA->number);
		setA = setA->next;
	}
	while (setB != nullptr) {
		setC = add(setC, setB->number);
		setB = setB->next;
	}
	
	return setC;
}

// пересечение
Node* intersection(Node* setA, Node* setB) {
	Node* setC = create_set();

	while (setA != nullptr) {
		if (contain(setB, setA->number)) {
			setC = add(setC, setA->number);
		}
		setA = setA->next;
	}

	return setC;
}

// разность
Node* difference(Node* setA, Node* setB) {
	Node* setC = create_set();

	while (setA != nullptr) {
		if (!contain(setB, setA->number)) {
			setC = add(setC, setA->number);
		}
		setA = setA->next;
	}

	return setC;
}

// симметричная разность
Node* sym_difference(Node* setA, Node* setB) {
	Node* setC = unification(setA, setB);
	Node* setD = intersection(setA, setB);
	Node* setE = difference(setC, setD);
	
	return setE;
}

// вывод множества
string print(Node* set) {
	string str_set;
	if (empty(set)) {
		return str_set;
	}
	while (set != nullptr) {
		str_set += to_string(set->number) + " ";
		set = set->next;
	}
	str_set.erase(str_set.size() - 1);
	return str_set;
}