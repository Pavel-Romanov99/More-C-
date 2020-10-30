#include <iostream>
#include <stack>
using namespace std;

int power(int num, int p) {
	if (p == 0) return 1;
	return num * power(num, p - 1);
}

void expression(string input) {

	stack<int> stack;
	int i = 0;
	char symbol = input[0];
	string result = "";

	while (symbol != '\0') {
		if (symbol >= 'A' && symbol <= 'Z') result += symbol;
		else if (symbol >= '0' && symbol <= '9') {
			//==============================
			int num = 0;
			int p = 0;

			while (symbol != '(') {
				num = symbol - '0';
				stack.push(num); //if we have consecutive numbers we push them to the stack
				symbol = input[++i];
			}
			num = 0;
			while (!stack.empty()) {
				num = num + stack.top() * power(10, p); //out of the numbers in the stack we make the number
				stack.pop();
				p++;
			}
			//==============================

			symbol = input[++i];
			string str = "";

			while (symbol != ')') {
				str += symbol;
				symbol = input[++i];
			}
			
			for (int i = 0; i < num; i++)
			{
				result += str;
			}
		}
		symbol = input[++i];
	}
	cout << result << endl;
}

int main() {
	string str = "ABC10(BC)2(D)";
	expression(str);
}