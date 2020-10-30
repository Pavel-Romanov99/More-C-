#include <iostream>
#include <stack>

using namespace std;

void expression(string input) {
	stack<char> symbols;
	stack<int> numbers;

	int i = 0;
	char character = input[0];

	while (character != '\0') {
		if (character >= '0' && character <= '9') {
			numbers.push(character - '0');
		}
		else if (character == '+' || character == '-' || character == '*' || character == '/') {
			symbols.push(character);
		}
		else if (character == ')') {
			int num1 = numbers.top();
			numbers.pop();
			int num2 = numbers.top();
			numbers.pop();

			char sym = symbols.top();
			symbols.pop();

			if (sym == '+') {
				numbers.push(num1 + num2);
				cout << "Pushed " << num1 + num2 << endl;
			}
			else if (sym == '-') {
				numbers.push(num1 - num2);
				cout << "Pushed " << num1 - num2 << endl;
			}
			else if (sym == '*') {
				numbers.push(num1 * num2);
				cout << "Pushed " << num1 * num2 << endl;
			}
			else if (sym == '/') {
				numbers.push(num1 / num2);
				cout << "Pushed " << num1 / num2 << endl;
			}
		}
		character = input[++i];
	}
	cout << numbers.top() << endl;
}

int main() {
	string str = "(5 + (7 + (2 * (3 + 4))))";
	expression(str);
}