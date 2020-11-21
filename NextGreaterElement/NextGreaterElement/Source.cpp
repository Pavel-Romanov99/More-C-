#include <iostream>
#include <stack>
#include <string>
using namespace std;

//exercise 1
void nextGreaterElement(int* arr, int n) {
	stack<int> s;
	for (int  i = 0; i < n; i++)
	{
		s.push(arr[i]);
	}

	int biggest = s.top();
	s.pop();
	cout << "(" << biggest << "," << -1 << ")" << endl;

	while (!s.empty()) {
		if (s.top() < biggest) {
			cout << "(" << s.top() << "," << biggest << ")" << endl;
		}
		else {
			biggest = s.top();
			cout << "(" << biggest << "," << -1 << ")" << endl;
		}
		s.pop();
	}

}

//exercise 2
bool balancedBrackets(string input) {
	stack<char> s;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(') {
			s.push(')');
		}
		else if (input[i] == ')' && !s.empty()) {
			s.pop();
		}
		else if (input[i] == ')' && s.empty())
			return false;
	}

	if (s.empty()) {
		return true;
	}
	return false;
}

//exercise 3
int evaluateInfix(string input) {
	stack<int> numbers;
	stack<char> signs;

	if (balancedBrackets(input)) {
		int i = 0;
		while (input[i] != '\0') {
			if (input[i] >= '0' && input[i] <= '9') {
				numbers.push(input[i] - '0');
			}
			else if (input[i] == '+') {
				signs.push('+');
			}
			else if (input[i] == '-') {
				signs.push('-');
			}
			else if (input[i] == '*') {
				signs.push('*');
			}
			else if (input[i] == '/') {
				signs.push('/');
			}
			else if (input[i] == ')') {
				int num1 = numbers.top(); numbers.pop();
				int num2 = numbers.top(); numbers.pop();
				char sign = signs.top(); signs.pop();

				if (sign == '+') {
					numbers.push(num1 + num2);
				}
				else if (sign == '-') {
					numbers.push(num1 - num2);
				}
				else if (sign == '*') {
					numbers.push(num1 * num2);
				}
				else if (sign == '/') {
					numbers.push(num1 / num2);
				}
			}
			i++;
		}
		return numbers.top();
	}
	return -1;

}

//exercise 4:Ermit
int Ermit(int x, int n) {
	if (n == 0) return 1;
	if (n == 1) return 2 * x;

	
    return (2 * x * Ermit(x, n - 1)) - (2 * (n - 1) * Ermit(x, n - 2));
}

int ErmitStack(int x, int n) {
	stack<int> s;
	
	if (n == 0) return 1;
	else if (n == 1) return 2 * x;
	else {
		//we push the base cases
		s.push(1);
		s.push(2*x);
		while (n > 1) {
			
			int num2 = s.top(); s.pop(); //num2 = 2 * x
			int num1 = s.top(); s.pop(); //num1 = 1
			int num3 = (2 * x * num2) - (2 * (--n) * num1); //we calculate the next number

			s.push(num2);
			s.push(num3);
		}
		return s.top();
	}
}
//Exercise 5: Knight's tour
int board[8][8] = {
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}
};

void printBoard() {
	for (int i = 0; i < 8; i++)
	{
		for (int  j = 0; j < 8; j++)
		{
			cout << board[i][j] << "          ";
		}
		cout << endl;
	}
}

struct position {
	int x, y;
	position(int x, int y) { this->x = x; this->y = y; }

	position movement1() { return { x - 2, y - 1 }; }
	position movement2() { return { x - 1, y - 2 }; }
	position movement3() { return { x - 2, y + 1 }; }
	position movement4() { return { x - 1, y + 2 }; }
	position movement5() { return { x + 1, y + 2 }; }
	position movement6() { return { x + 2, y + 1 }; }
	position movement7() { return { x + 2, y - 1 }; }
	position movement8() { return { x + 1, y - 2 }; }
};

bool validPosition(position pos) {
	return pos.x >= 0 && pos.x < 8
		&& pos.y >= 0 && pos.y < 8
		&& board[pos.x][pos.y] == 0;
}

int i = 1;
void knightsTour(position current) {


	if (!validPosition(current)) {
		return;
	}

	board[current.x][current.y] = i++;

	knightsTour(current.movement1());
	knightsTour(current.movement2());
	knightsTour(current.movement3());
	knightsTour(current.movement4());
	knightsTour(current.movement5());
	knightsTour(current.movement6());
	knightsTour(current.movement7());
	knightsTour(current.movement8());

}


//new 
void attack(position horse) {
	if (validPosition(horse.movement1())) {
		board[horse.movement1().x][horse.movement1().y] = 1;
	}
	if (validPosition(horse.movement2())) {
		board[horse.movement2().x][horse.movement2().y] = 1;
	}
	if (validPosition(horse.movement3())) {
		board[horse.movement3().x][horse.movement3().y] = 1;
	}
	if (validPosition(horse.movement4())) {
		board[horse.movement4().x][horse.movement4().y] = 1;
	}
	if (validPosition(horse.movement5())) {
		board[horse.movement5().x][horse.movement5().y] = 1;
	}
	if (validPosition(horse.movement6())) {
		board[horse.movement6().x][horse.movement6().y] = 1;
	}
	if (validPosition(horse.movement7())) {
		board[horse.movement7().x][horse.movement7().y] = 1;
	}
	if (validPosition(horse.movement8())) {
		board[horse.movement8().x][horse.movement8().y] = 1;
	}
	if (validPosition(horse.movement1())) {
		board[horse.movement1().x][horse.movement1().y] = 1;
	}
}

void knightConfig(int k) {

	if (k == 0) {
		printBoard();
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			position horse = { i,j };
			if (validPosition(horse)) {
				board[horse.x][horse.y] = 2;
				attack(horse);
				knightConfig(--k);
			}
			else return;
		}
	}
	return;
}
//===============================


int main() {
	knightConfig(10);
}