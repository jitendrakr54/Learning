/*
 * StackUtil.cpp
 *
 *  Created on: 17-Nov-2020
 *      Author: Jitendra
 */

#include "StackUtil.h"

#include <stack>

#include "StackSTL.h"

namespace ds {
namespace stack {

void reverseStringUsingStack(std::string& data) {
	int length = data.length();
	ds::stack::StackSTL<char> s(length);

	for(int i = 0; i<=length-1; i++) {
		s.push(data[i]);
	}

	for(int i = 0; i<=length-1; i++) {
		data[i] = s.pop();
	}
}

bool checkBalancedParanthesis(std::string exp) {
	int length = exp.length();
	std::stack<char> s;
	for(int i = 0; i<length; ++i) {
		char c = exp[i];
		if(c == '[' || c == '{' || c == '(') {
			s.push(c);
		} else if(c == ']' || c == '}' || c == ')') {
			if(s.empty() || !isPair(s.top(), c)) {
				return false;
			} else {
				s.pop();
			}
		}
	}
	return s.empty() ? true : false;
}

int evaluatePostfix(std::string exp) {
	std::stack<int> s;
	char c;
	for(unsigned int i = 0; i < exp.length(); ++i) {
		c = exp[i];
		if(c == ' ' || c == ',') {
			continue;
		} else if(isOperator(c)) {
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();
			int res = performOperation(op1, op2, c);
			s.push(res);
		} else if(isNumeric(c)) {
			int operand = 0;
			while( i < exp.length() && isNumeric(c)) {
				operand = (operand*10) + (c - '0');
				c = exp[++i];
			}
			--i;
			s.push(operand);
		}
	}
	return s.top();
}

std::string infixToPostfix(std::string infix) {
	std::string postfix{""};
	std::stack<char> s;
	char c;
	for(unsigned int i=0; i<infix.length(); i++) {
		c = infix[i];
		if(c==' ' && c==',' ) continue;
		else if(isOperator(c)) {
			while(!s.empty() && s.top()!='(' && hasHigherPrecedence(s.top(), c)) {
				postfix += s.top();
				s.pop();
			}
			s.push(c);
		} else if(isOperand(c)) {
			postfix += c;
		} else if(c == '(') {
			s.push(c);
		} else if(c == ')') {
			while(!s.empty() && s.top() != '(') {
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while(!s.empty()) {
		postfix += s.top();
		s.pop();
	}
	return postfix;
}

bool hasHigherPrecedence(char op1, char op2) {
	int weight1 = getOperatorWeight(op1);
	int weight2 = getOperatorWeight(op2);

	if(weight1 == weight2) {
		if(isRightAssociative(op1)) return false;
		else return true;
	}
	return weight1 > weight2 ? true : false;
}

bool isRightAssociative(char c) {
	if(c=='$') return true;
	else return false;
}

int getOperatorWeight(char c) {
	int weight = -1;
	switch(c) {
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
		weight = 2;
		break;
	case '$':
		weight = 3;
		break;
	default:
		weight = -1;
		break;
	}
	return weight;
}

bool isPair(char opening, char closing) {
	if(opening == '[' and closing == ']') return true;
	else if(opening == '{' and closing == '}') return true;
	else if(opening == '(' and closing == ')') return true;
	else return false;
}

bool isOperator(char c) {
	return ( c == '*' || c == '/' || c == '+' || c == '-' );
}

bool isOperand(char c) {
	if(c >= '0' && c <= '9') return true;
	else if(c >= 'a' && c <= 'z') return true;
	else if(c >= 'A' && c <= 'Z') return true;
	return false;
}

bool isNumeric(char c) {
	return (c >= '0' && c <= '9');
}

int performOperation(int op1, int op2, char operation) {
	if(operation == '*') return op1*op2;
	else if(operation == '/') return op1/op2;
	else if(operation == '+') return op1+op2;
	else if(operation == '-') return op1-op2;
	else std::cout<<"Unexpected error!\n";
	return -1;
}

}
}


