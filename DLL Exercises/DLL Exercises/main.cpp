#include "DLL.h"

//Exercise 2: Create a list with elements from x to y
//=====================================
node* addRange(int x, int y) {
	DLL a;

	for (int i = x; i <= y; i++)
	{
		a.addEnd(i);
	}
	return a.getHead();
}

void print(node* head) {
	node* temp = head;
	while (temp->next != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
//=====================================

int main() {
	DLL a;
	a.addEnd(5);
	a.addEnd(1);
	a.addEnd(2);
	a.addEnd(5);
	a.addEnd(7);
	a.addEnd(7);
	a.addEnd(3);
	a.addEnd(4);
	a.addEnd(4);
	a.addEnd(4);
	a.addEnd(5);
	a.addEnd(6);
	a.addEnd(7);

	a.print();

	cout << "removing duplicates" << endl;

	a.removeDuplicates();
	a.print();
}