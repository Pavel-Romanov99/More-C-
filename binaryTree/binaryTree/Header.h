#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename T>
struct node {
	T data;
	node<T>* right, * left;
};

template <typename T>
node<T>* getNewNode(T data) {
	node<T>* temp = new node<T>{ data, nullptr, nullptr };
	return temp;
}

template<typename T>
class BinaryTree {
public:
	node<T>* root;

	BinaryTree() {
		root = nullptr;
	}
	BinaryTree(T data) {
		root = getNewNode(data);
	}
	void Print(node<T>* root) {
		if (root == nullptr) {
			return;
		}
		
		Print(root->left);
		cout << root->data << " ";
		Print(root->right);
	}

	int numElements(node<T>* root);
	int numEven(node<T>* root);

	//Predicate
	int search(bool (*pred)(const T&), node<T>* root) {
		if (root == nullptr) {
			return 0;
		}

		if (pred(root->data)) {
			return 1 + search(pred, root->left) + search(pred, root->right);
		}
		else return 0 + search(pred, root->left) + search(pred, root->right);
	}
	//================================
	int height(node<T>* root);
	int numberLeaves(node<T>* root);
	node<T>* biggestLeaf(node<T>* root);
};
//================================
//Number of elements
template<typename T>
int BinaryTree<T>::numElements(node<T>* root) {

	if (root == nullptr) {
		return 0;
	}

	return 1 + numElements(root->left) + numElements(root->right);
}
//================================
//Number of even elements
template<typename T>
int BinaryTree<T>::numEven(node<T>* root) {

	if (root == nullptr) {
		return 0;
	}

	if (root->data % 2 == 0) {
		return 1 + numEven(root->left) + numEven(root->right);
	}
	else return 0 + numEven(root->left) + numEven(root->right);
}	
//================================
template<typename T>
bool odd(const T& data) {
	if (data % 2 == 1) return true;
	return false;
}
//================================
//Height of the tree =============
template <typename T>
T max(T x, T y) {
	if (x > y) return x;
	return y;
}

template<typename T>
int BinaryTree<T>::height(node<T>* root) {
	if (root == nullptr) return 0;
	
	return 1 + max(height(root->left), height(root->right));
}
//================================
//Number of leaves
template<typename T>
int BinaryTree<T>::numberLeaves(node<T>* root) {
	if (root == nullptr) return 0;

	if (root->left == nullptr && root->right == nullptr) {
		return 1 + numberLeaves(root->left) + numberLeaves(root->right);
	}
	else return 0 + numberLeaves(root->left) + numberLeaves(root->right);
}
//================================
//Biggest leaf in the tree
template <typename T>
node<T>* BinaryTree<T>::biggestLeaf(node<T>* root) {
	if (root == nullptr) return nullptr;

	if (root->left == nullptr || root->right == nullptr) {
		return root;
	}

	node<T>* l = biggestLeaf(root->left);
	node<T>* r = biggestLeaf(root->right);

	if (l->data > r->data)
	{
		return l;
	}
	else
	{
		return r;
	}

}
//================================
