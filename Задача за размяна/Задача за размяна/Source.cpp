#include <iostream>
using namespace std;

struct node {
	float data;
	node* next;
	node* prev;
};

class LinkedList {
private:
	node* head;
	node* tail;
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	void addBeginning(int data)	{ //add at the beginning works

		node* temp = new node();
		temp->data = data;
		temp->next = nullptr;
		temp->prev = nullptr;

		if (head == nullptr) {
			head = temp;
			tail = temp;
			return;
		}

		head->prev = temp;
		temp->next = head;
		head = temp;
	}

	void printBackwards() { //backwards traversal

		node* temp = tail;

		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout << endl;
	}

	void print() { //forward traversal

		node* temp = head;

		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}


	void sortAdd(int data) {
		node* temp = new node();
		temp->data = data;
		temp->next = nullptr;
		temp->prev = nullptr;

		if (head == nullptr) { //if the list is empty
			head = temp;
			tail = temp;
			return;
		}

		if (data < head->data) { //add at the beginning 
			temp->next = head;
			head->prev = temp;
			head = temp;
			return;
		}

		node* trav = head;
		while (data > trav->data) { //trav points to the first node bigger than data
			trav = trav->next;
		}

		trav->prev->next = temp;
		temp->prev = trav->prev;
		trav->prev = temp;
		temp->next = trav;

	}	
};


int main()
{
	LinkedList a;
	a.sortAdd(6);
	a.sortAdd(3);
	a.sortAdd(2);
	a.sortAdd(1);
	a.print();
	a.sortAdd(4);
	a.sortAdd(5);
	a.print();
	a.printBackwards();
}