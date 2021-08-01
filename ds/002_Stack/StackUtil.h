/*
 * StackUtil.h
 *
 *  Created on: 17-Nov-2020
 *      Author: Jitendra
 */

#pragma once

#include <iostream>

namespace ds {
namespace stack {

/**
 * reverseStringUsingStack reverse a string using string
 * */
void reverseStringUsingStack(std::string& data);

/**
 * checkBalancedParanthesis validates whether expression is balanced
 * */
bool checkBalancedParanthesis(std::string exp);

/**
 * evaluatePostFix evaluate postfix expression eg: 2 3*5 4*+9-
 * */
int evaluatePostfix(std::string exp);

/**
 * infixToPostfix converts infix expression to postfix expression
 * */
std::string infixToPostfix(std::string infix);

/**
 * isPair checks whether opening and closing are in pair eg. []. {}, ()
 * */
bool isPair(char opening, char closing);


bool isOperator(char c);

bool isOperand(char c);

bool isNumeric(char c);

int performOperation(int op1, int op2, char operation);

bool hasHigherPrecedence(char op1, char op2);

int getOperatorWeight(char c);

bool isRightAssociative(char c);
}
}
