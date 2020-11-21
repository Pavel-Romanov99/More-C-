#include <iostream>
#include <stack>
using namespace std;

//Pavel Romanov fn-81762

template <class T>
struct node { T data; node<T>* next; };

//pomoshtni funkcii

template<typename T>
node<T>* createNode(T data) {
	node<T>* temp = new node<T>();
	temp->data = data;
	temp->next = nullptr;
	return temp;
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

template<typename T>
void addElement(node<T>* head, T data) {
	if (head == nullptr) {
		head = createNode(data);
		return;
	}

	node<T>* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = createNode(data);
}



//EX1 =======================
template<typename T>
T reduce(node<T>* head) { 
	if (head == nullptr) {
		return 0;
	}

	if (head->next == nullptr) {
		return head->data;
	}
	//ne se seshtam kak da podam funkciq kato argument inache trqbva da stane taka
	//return f(f(head->data, head->next->data), reduce(head->next->next));
	return head->data + head->next->data + reduce(head->next->next);
}
//================================
//Ex3
template<typename T>
int numberElements(node<T>* head) {
	int counter = 0;
	if (head == nullptr) {
		return 0;
	}
	node<T>* temp = head;
	while (temp != nullptr) {
		counter++;
		temp = temp->next;
	}
	return counter;
}


template<typename T>
void shuffle(node<T>* head) {

	if (head == nullptr) {
		return;
	}

	if (head->next == nullptr) {
		return;
	}

	stack<T> s1;
	stack<T> s2;
	int n = numberElements(head) / 2;
	int index = 1;

	node<T>* temp1 = head;
	while (temp1 != nullptr) {
		s1.push(temp1->data);
		temp1 = temp1->next;
	}

	node<T>* temp2 = head;

	while (n > 0) {
		temp2->data = s1.top();
		s1.pop();
		temp2 = temp2->next;
		n--;
	}

	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}

	node<T>* temp3 = head;
	while (temp3 != nullptr) {
		if (index > numberElements(head) / 2) {
			temp3->data = s2.top();
			s2.pop();
		}
		temp3 = temp3->next;
		index++;
	}
}
//================================
//Ex2

template<typename T>
node<stack<T>>* equalize(node<stack<T>>* head) {

	if (head == nullptr) {
		return nullptr;
	}

	if (head->next == nullptr) {
		return head;
	}

	node<stack<T>>* temp = head;

	while (temp != nullptr) {
			node<stack<T>> * temp2 = temp->next;

			if (temp->data->size() > temp2->data->size() - 2) {
				//equalize them
			}
			temp = temp->next;
	}

}


int main() {
	node<int>* head = createNode(1);
	addElement(head, 2);
	addElement(head, 3);
	addElement(head, 4);
	addElement(head, 5);

	print(head);
	cout << reduce(head) << endl;

}