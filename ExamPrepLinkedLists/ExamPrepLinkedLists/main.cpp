#include "Implementation.h"

int main() {
	LinkedList<int> l;
	l.add(4);
	l.add(4);
	l.add(4);
	l.add(2);
	l.add(2);
	l.add(2);
	l.add(2);
	l.add(5);
	l.add(6);
	l.add(6);
	l.add(6);
	cout << "list l = ";
	l.print(); 
	l.sumReverse();
	l.print();
}