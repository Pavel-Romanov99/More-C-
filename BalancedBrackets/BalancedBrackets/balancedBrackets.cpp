#include <iostream>
#include <stack>
using namespace std;

bool balancedBrackets(string input) {
	stack<char> stack;

	if (input[0] == '\0') {
		return true;
	}

	int i = 0;
	char symbol = input[i];


	while (symbol != '\0') {
		
		if (symbol == '(') {
			stack.push(')');
		}
		else if (symbol == '[') {
			stack.push(']');
		}
		else if (symbol == '{') {
			stack.push('}');
		}
		else if (symbol == ')' || symbol == ']' || symbol == '}') {
			if ( !stack.empty() && symbol == stack.top() ) {
				stack.pop();
			}
			else return false;
		}
		symbol = input[++i];
	}
	return true;
}

int main() {
	string str = "{[((()[])]}";
	cout << balancedBrackets(str) << endl;
}
