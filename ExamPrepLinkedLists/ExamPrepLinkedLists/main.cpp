//#include "Implementation.h"
#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

void addBeginning(node** head, int data) {
	
	node* temp = new node();
	temp->data = data;

	if (head == nullptr) {
		(*head) = temp;
		return;
	}

	temp->next = (*head);
	(*head) = temp;
}

void printList(node* head) {
	node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main() {
	
	node* head = nullptr;
	addBeginning(&head, 2);
	addBeginning(&head, 3);
	addBeginning(&head, 4);
	printList(head);
}