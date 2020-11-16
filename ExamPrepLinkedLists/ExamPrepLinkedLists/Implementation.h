#pragma once
#include "LinkedList.h"

template<typename T>
node<T>* createNode(T data) {
	node<T>* temp = new node<T>();
	temp->data = data;
	temp->next = nullptr;
	temp->prev = nullptr;
	return temp;
}

template<typename T>
node<T>* LinkedList<T>::getHead() {
	return this->head;
}

template<typename T>
LinkedList<T>::LinkedList() { head = nullptr, tail = nullptr; }

template<typename T>
void LinkedList<T>::add(T data) {

	node<T>* temp = createNode(data);

	if (head == nullptr) {
		head = temp;
		tail = temp;
		return;
	}

	tail->next = temp;
	temp->prev = tail;
	tail = temp;

}

template<typename T>
void LinkedList<T>::print() {
	node<T>* temp = head;

	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
//Exercise 1
template<typename T>
int LinkedList<T>::count(T data) {
	node<T>* temp = head;
	int counter = 0;

	while (temp != nullptr) {
		if (temp->data == data) {
			counter++;
		}
		temp = temp->next;
	}
	return counter;
}
//=================================
//Exercises 2
template<typename T>
node<T>* range(int x, int y) {
	LinkedList<T> list;
	if (x <= y) {
		while (x <= y) {
			list.add(x++);
		}
	}
	else return nullptr;

	return list.getHead();
}

template<typename T>
void print(node<T>* head) {
	node<T>* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
//================================
//Exercise 3
template<typename T>
void LinkedList<T>::removeElement(T data) {

	//remove all the heads and tails == data
	while (head->data == data || tail->data == data) {
		if (head->data == data) {
			head->next->prev = nullptr;
			head = head->next;
		}

		if (tail->data == data) {
			tail->prev->next = nullptr;
			tail = tail->prev;
		}
	}

	node<T>* temp = head;
	while (temp != nullptr) {
		if (temp->data == data) {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		temp = temp->next;
	}
}
//================================
//Execise 4
template <typename T>
void append(node<T>* l1, node<T>* l2) {
	node<T>* tail = l1;
	while (tail->next != nullptr) {
		tail = tail->next;
	}//tail points to the last element of l1
	
	node<T>* temp = l2;//points to the head of l2
	while (temp != nullptr) {
		node<T>* a = createNode(temp->data);//add new elements to the end of l1
		tail->next = a;
		a->prev = tail;
		tail = a;
		temp = temp->next;
	}
}	
//================================
//Exercise 5
template<typename T>
node<T>* concat(node<T>* l1, node<T>* l2) {
	LinkedList<T> list;
	
	node<T>* temp1 = l1;
	while (temp1 != nullptr) {
		list.add(temp1->data);
		temp1 = temp1->next;
	}
	node<T>* temp2 = l2;
	while (temp2 != nullptr) {
		list.add(temp2->data);
		temp2 = temp2->next;
	}
	return list.getHead();
}
//================================
//Exercise 6
template<typename T>
void LinkedList<T>::reverse() {
	node<T>* temp = nullptr;
	node<T>* current = head;

	while (current != nullptr) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev; //taka minavame napred poneje sme smenili prev i next
	}

	if (temp != nullptr) {
		head = temp->prev;
	}
}
//================================
//Exercise 7
template<typename T>
void LinkedList<T>::removeDuplicates() {

	if (head == nullptr) {
		cout << "list is empty" << endl;
		return;
	}
	node<T>* temp = head;

	while (temp != nullptr) { //traverse till the last element

		node<T>* temp2 = temp->next; 

		while (temp2 != nullptr) {//traverse from the second to the last
			if (temp2->data == temp->data) {
				cout << "We are removing :" << temp2->data << endl;

				if (temp2 == tail) {//if we remove the tail
					tail->prev->next = nullptr;
					tail = temp2;
				}
				else {//if we remove a middle element
					temp2->prev->next = temp2->next;
					temp2->next->prev = temp2->prev;
				}
				cout << "List left is ";
				this->print();
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
//================================
//Exercise 8
template<typename T>
void LinkedList<T>::removeIndex(int index) {
	if (head == nullptr) {
		cout << "List empty" << endl;
		return;
	}

	if (index == 0) { //if we remove the first element
		head->next->prev = nullptr;
		head = head->next;
		return;
	}

	int counter = 0;
	node<T>* temp = head;
	while (temp != nullptr) {

		if (counter == index) {

			if (temp == tail) { //if we remove the last element
				tail->prev->next = nullptr;
				tail = tail->prev;
				return;
			}

			//if we remove a middle element
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			return;
		}

		counter++;
		temp = temp->next;
	}
}
//================================
//exercise 9
template<typename T>
void LinkedList<T>::mergeSorted(LinkedList<T> &list) {
	if (list.getHead() == nullptr) {
		cout << "Second list is empty " << endl;
		return;
	}

	node<T>* temp = list.getHead();
	while (temp != nullptr) { //traverse the second list
		node<T>* list1 = head;

		while (list1 != nullptr) { //traverse the first list

			node<T>* replacement = new node<T>();
			replacement->data = temp->data;

			if (list1 == tail && replacement->data > tail->data) {//if element of list2 is bigger than list2->tail
				tail->next = replacement;
				replacement->prev = tail;
				tail = replacement;
			}

			else if (replacement->data < list1->data && list1 != head) {//if we have to add to the middle

				//we create a new node to put in the list
				list1->prev->next = replacement;
				replacement->prev = list1->prev;
				list1->prev = replacement;
				replacement->next = list1;
				break; //za da ne se pusne i dolni else if
			}

			else if (list1 == head && replacement->data < head->data) { //if we add to the front
				head->prev = replacement;
				replacement->next = head;
				head = replacement;
				break;//za da ne se pusne gorniq else if
			}

			list1 = list1->next;
		}
		temp = temp->next;
	}
}
//================================
//exercise 10
template<typename T>
int LinkedList<T>::find(const T& data) {
	int counter = 0;
	node<T>* temp = head;

	while (temp != nullptr) {
		if (temp->data == data) {
			return counter;
		}
		temp = temp->next;
		counter++;
	}
	return -1;
}
//================================
//exercise 1: Github
template<typename T>
void LinkedList<T>::threeDubs() {
	if (head == nullptr) {
		cout << "list is empty" << endl;
		return;
	}
	node<T>* temp = head;

	while (temp->next != nullptr) {
		if (	temp->next != nullptr && temp->next->next != nullptr
			&&	temp->data == temp->next->data && temp->data == temp->next->next->data) {

			if (temp == head) {
				head->next->prev = nullptr;
				head = head->next;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
		}
		temp = temp->next;
	}
}
//================================
//exercise 2: Github
template<typename T>
void LinkedList<T>::sumReverse() {
	if (head == nullptr) {
		cout << "list is empty" << endl;
		return;
	}
	int sum = 0;
	node<T>* current = head;
	node<T>* temp = nullptr;

	//we reverse the list and sum the elements
	while (current != nullptr) {
		sum += current->data;
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	//we set the head
	if (temp != nullptr) {
		head = temp->prev;
	}

	node<T>* finalSum = new node<T>();//we create the new node 
	finalSum->data = sum;

	//we add it in the front
	finalSum->next = head;
	head->prev = finalSum;
	head = finalSum;
}
//================================
