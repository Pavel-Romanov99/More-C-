#pragma once
#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
struct node {
	T data;
	node* next, * prev;
};

template <typename T>
class LinkedList {
private:
	node<T>* head;
	node<T>* tail;
public:
	LinkedList();
	void add(T data);
	void print();
	node<T>* getHead();
	int count(T data); //exercise 1
	void removeElement(T data);//exercise 3
	void reverse(); //exercise 6
	void removeDuplicates(); //exercise 7
	void removeIndex(int index);//exercise 8
	void mergeSorted(LinkedList<T> &list); //exercise 9
	int find(const T& data); //exercise 10
	void threeDubs(); //exercise 1: Github
	void sumReverse(); //exercise 2: Github
};


