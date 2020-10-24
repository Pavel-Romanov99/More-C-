#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class LinkedList
{
private:
	node* head;
	node* tail;
public:
	LinkedList() { //constructor
		head = NULL; //initialize the head
		tail = NULL;
	}

	void addElement(int data) {

		node* temp = new node();
		temp->data = data;
		temp->next = NULL;

		if (head == NULL) { //if the linked list is empty then temp is the head and the tail
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}

	void print() {
		node* temp = head;

		while (temp != NULL) {
			cout << temp->data << " "; 
			temp = temp->next;
		}
		cout << endl;
	}

	node* getHead() {
		return head;
	}

	void concatenate(node* head1, node* head2) {

		if (head1 == NULL) return; //if list1 is empty
		if (head2 == NULL) return; //if list2 is empty

		node* temp = head1; 
		while (temp->next != NULL) { //temp = list1.tail
			temp = temp->next; 
		}
		temp->next = head2; //we connect the tail of list1 and the head of list2
	}

	void addBeginning(int data) {
		node* temp = new node();
		temp->data = data;

		temp->next = head; //temp next is pointing to the head
		head = temp; //we change the head to be the new node
	}

	void addAt(int data, int position) {
		node* temp = new node(); // create new node
		temp->data = data;
		temp->next = NULL;

		if (position == 1) { //if we have to add at the beginning
			temp->next = head;
			head = temp;
			return;
		}

		node* temp2 = head; //we create a node to point to the node before position
		for (int i = 1; i < position - 1; i++)
		{
			temp2 = temp2->next;
		}
		
		temp->next = temp2->next;
		temp2->next = temp;
	}

	void removeAt(int position) {
		node* temp = head;

		if (position == 1) { //if we remove the first element
			head = temp->next;
			delete temp;
			return;
		}

		for (int i = 1; i < position - 1; i++) //temp points to the element before the one we want to remove
		{
			temp = temp->next;
		}

		node* temp2 = temp->next; //temp2 points to the element we want to remove
		temp->next = temp2->next; //the node before the one we want to remove point the the one after
		delete temp2;//we remove the element
		
	}
};

int main()
{
	LinkedList a;
	a.addElement(1);
	a.addElement(2);
	a.addElement(3);
	a.addElement(4);

	a.addBeginning(10);
	a.addAt(10, 4);
	a.print();
	a.removeAt(3);
	a.print();
}