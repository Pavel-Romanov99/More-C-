#include "Header.h"

int main() {
	BinaryTree<int> a(5);
	a.root->left = getNewNode(6);
	a.root->right = getNewNode(4);
	a.root->left->left = getNewNode(10);
	a.root->left->left->left = getNewNode(11);
	a.root->left->right = getNewNode(12);
	a.root->right->left = getNewNode(20);
	a.root->right->right = getNewNode(50);
	a.Print(a.root);
	cout << endl;

	cout << "Number of elements: " << a.numElements(a.root) << endl;
	cout << "Number of even elements: "<< a.numEven(a.root) << endl;
	cout << "Predicate returns: " << a.search(odd, a.root) << endl;
	cout << "Tree height is: " << a.height(a.root) << endl;
	cout << "Number of leaves: " << a.numberLeaves(a.root) << endl;
	cout << "Biggest leaf is: " << a.biggestLeaf(a.root)->data << endl;
}