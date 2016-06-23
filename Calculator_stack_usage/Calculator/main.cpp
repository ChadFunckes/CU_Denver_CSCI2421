#include <iostream>
#include <string>
#include <stack>

using namespace std;

void evaluate_tops(stack<double>& numbers, stack<char>& operations);
double read_evaluate(istream& ins);

int main(){
	double answer;

	cout << "Type a full aritmetic expression:\n";
	answer = read_evaluate(cin);
	cout << "The answer is: \n" << answer << endl;

	system("pause");
}

double read_evaluate(istream& ins){

	const char DECIMAL = '.';
	const char RIGHT_PAREN = ')';

	stack<double> numbers;
	stack<char> operations;
	double number;
	char symbol;

	while (ins && (ins.peek() != '\n')){

		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)){
			ins >> number;
			numbers.push(number);
		}
		else if (strchr("+-*/", ins.peek()) != NULL){
			ins >> symbol;
			operations.push(symbol);
		}
		else if (ins.peek() == RIGHT_PAREN){
			ins.ignore();
			evaluate_tops(numbers, operations);
		}
		else
			ins.ignore();
	}
	return numbers.top();
}

void evaluate_tops(stack<double>& numbers, stack<char>& operations){
	double operand1, operand2;

	operand2 = numbers.top();
	numbers.pop();
	operand1 = numbers.top();
	numbers.pop();
	switch (operations.top())
	{
	case '+': numbers.push(operand1 + operand2);
		break;
	case '-': numbers.push(operand1 - operand2);
		break;
	case '*': numbers.push(operand1 * operand2);
		break;
	case '/': numbers.push(operand1 / operand2);
		break;
	}
	operations.pop();
}

