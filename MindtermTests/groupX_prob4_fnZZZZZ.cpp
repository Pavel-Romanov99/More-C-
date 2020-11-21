#include "node.h"
#include <iostream>
#include <stack>


using namespace std;

/***********************************************************************
  Задача 4. Да се дефинира шаблон на функция mirror, която приема като
  единствен параметър указател към линеен едносвързан списък. Към края
  на списъка да се долепят оригиналните му елементи в обратен
  ред. Например, списъкът с елементи 1, 2, 3 да се преобразува до
  списъка 1, 2, 3, 3, 2, 1.
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/
template <typename T>
void addEnd(node<T>* head, node<T>* elem) {
	if (head == nullptr) {
		head = elem;
		return;
	}

	node<T>* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = elem;
}

template<typename T>
node<T>* createNode(T data) {
	node<T>* temp = new node<T>();
	temp->data = data;
	return temp;
}

template <typename T>
void mirror(node<T>* l) {

	stack<node<T>*> s;

	node<T>* temp = l;

	while (temp != nullptr) {

		node<T>* elem = createNode(temp->data);
		s.push(elem);
		temp = temp->next;
	}

	while (!s.empty()) {
		cout << "adding " << s.top()->data << endl;
		addEnd(l, s.top());
		s.pop();
	}
}

template<typename T>
void print(node<T>* l) {
	node<T>* temp = l;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}



/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
#include "prob4_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
	node<int>* head = createNode(1);
	head->next = createNode(3);
	head->next->next = createNode(4);

	head->next->next->next = createNode(2);

	print(head);

	mirror(head);
	print(head);

    return 0;
}
