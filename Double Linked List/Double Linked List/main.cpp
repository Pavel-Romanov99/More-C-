#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class DoubleLinkedList
{
private:
	node* head;
	node* tail;
public:
	DoubleLinkedList() { //constructor
		head = NULL;
		tail = NULL;
	}

	void addBeginning(int data) {

		node* temp = new node();
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;

		if (head == NULL) { //if the list is empty
			head = temp;
			tail = temp;
			return;
		}

		//else
		temp->next = head; //new first element points to old first element
		head->prev = temp; //the prev of the now second element points to the new first
		head = temp; //the new first becomes the head
	}

	void addAt(int data, int position) {
		
		node* temp = new node();//new node
		temp->data = data;
		temp->next = nullptr;
		temp->prev = nullptr;

		if (position == 1) { //insert at the beginning
			temp->next = head;
			head->prev = temp;
			head = temp;
			return;
		}

		node* prevNode = head;
		for (int i = 1; i < position - 1;i++)
		{
			prevNode = prevNode->next; //points to the node at position - 1
		}

		node* nextNode = prevNode->next; //points to the node at position + 1
		temp->next = nextNode; //temp->next points to the next node
		temp->prev = prevNode; //temp->prev points to the previous node
		prevNode->next = temp; //previous node -> next points to the new node
		nextNode->prev = temp; //the next node->prev points to the new node

	}

	void addEnd(int data){

		node* temp = new node();//new node
		temp->data = data;
		temp->next = nullptr;
		temp->prev = nullptr;

		tail->next = temp;//add it at the end
		temp->prev = tail;
		tail = temp;
	}

	void print() {
		if (head == nullptr) cout << "list is empty" << endl;
		node* temp = head;

		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void removeAt(int position) {
		if (position == 1) { //if we have to remove the first element
			head->next->prev = nullptr;
			head = head->next;
			return;
		}
		node* temp = head;

		for (int i = 1; i < position - 1; i++)
		{
			temp = temp->next; //points to the node before the one we delete
		}

		node* deleted = temp->next; //the node we have to delete
		node* afterDeleted = temp->next->next; //the node after the one we have to delete

		temp->next = deleted->next; //the node before points to the one after the deleted
		afterDeleted->prev = temp; //the one after the deleted points to the one before
		delete deleted; //we delete the node 
	}

	void backwardsPrint() {
		node* temp = tail;

		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout << endl;
	}
};

int main()
{
	DoubleLinkedList a;
	a.addBeginning(1);
	a.addBeginning(2);
	a.addBeginning(3);
	a.addBeginning(4);
	a.addAt(10, 2);
	a.addAt(10, 4);
	a.addAt(10, 1);
	a.print();
	a.backwardsPrint();

	cout << "before removing" << endl;
	a.removeAt(1);
	a.print();
	a.backwardsPrint();
}