#pragma once
#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class DLL {
private:
	node* head;
	node* tail;
public:
	DLL();
	void addEnd(int data);
	void print();
	node* getHead();
	int timesFound(node* head, int data); //exercise 1: How many times an element is found
	void removeAll(int data); //exercise 3
	void append(node* list2); //exercise 4
	void backwardsPrint();
	void removeDuplicates();
};

void DLL::backwardsPrint() {

	if (tail == nullptr) {
		cout << "list is empty" << endl;
		return;
	}

	node* temp = tail;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

void DLL::print() {

	if (head == nullptr) {
		cout << "List is empty " << endl;
		return;
	}

	node* temp = head;

	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

DLL::DLL() {
	head = nullptr;
	tail = nullptr;
}

void DLL::addEnd(int data) {

	node* temp = new node();
	temp->data = data;
	temp->next = nullptr;
	temp->prev = nullptr;

	if (head == nullptr) {
		head = temp;
		tail = temp;
		return;
	}

	tail->next = temp;
	temp->prev = tail;
	tail = temp;

}

node* DLL::getHead() {
	return this->head;
}

int DLL::timesFound(node* head, int data) {
	int counter = 0;

	if (head == nullptr) {
		return 0;
	}

	node* temp = head;
	while (temp != nullptr) {
		if (temp->data == data) {
			counter++;
		}
		temp = temp->next;
	}
	return counter;
}

//Exercise 3: Remove all elements with data == data
//=====================================

void DLL::removeAll(int data) {
	
	//if the list is empty
	if (head == nullptr) {
		cout << "list is empty" << endl;
		return ;
	}

	//if we have to remove the first element
	if (head->data == data) {
		head->next->prev = nullptr;
		head = head->next;
	}

	node* temp = head;

	while (temp != nullptr) {

		if (temp->data == data) { //if we have to remove temp
			temp = temp->next; // we point the the next element
			temp->prev->prev->next = temp; //previous element of the one we delete->next points to the one after the deleted
			temp->prev = temp->prev->prev; //next element->prev = prev element of the one we have to remove
			cout << "current temp is " <<  temp->data << endl;
		}
		else temp = temp->next;
	}
}
//=====================================

//Exercise 4: Append two lists
void DLL::append(node* list2) {
	
	if (list2 == nullptr) {
		return;
	}
	node* temp = list2;

	while (temp != nullptr) {
		this->addEnd(temp->data);
		temp = temp->next;
	}
}
//=====================================

//Exercise 5: Removing all duplicates
void DLL::removeDuplicates() {
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return;
	}

	node* temp = head;

	while (temp != nullptr && temp->next != nullptr) {

		node* temp2 = temp->next;

		if (temp->data == tail->data) {
			tail->prev->next = nullptr;
			tail = tail->prev;
		}

		while (temp2 != nullptr) {
			if (temp2->data == temp->data) {
				cout << "removing " << temp2->data << endl;
				temp2 = temp2->next; // we point the the next element
				temp2->prev->prev->next = temp2; //previous element of the one we delete->next points to the one after the deleted
				temp2->prev = temp2->prev->prev; //next element->prev = prev element of the one we have to remove
			}
			else temp2 = temp2->next;
		}
		temp = temp->next;
		this->print();
		cout << endl;
	}

}
//=====================================
