//Tarik Alauddin & Carter Mooring
//Assignment: PROG 6
//Class: CPSC 122, Fall 2018
//Date: 10/25/2018
// Gonzaga University, CPSC 122, Dr. Yerion

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

//Description: Ensures the program runs and stops when needed.
//Pre: No pre-conditions were required.
//Post: The program will be ran or stopped per the users instructions.
void runConversion();

//Description: Checks to see if the character is a letter.
//Pre: achar is a defined item type.
//Post: The boolean returns whether the character is a letter or not.
bool isOperand(ItemType achar);

//Description: Checks to see if the character is a left parenthesis.
//Pre: achar is a defined item type.
//Post: The boolean returns whether the character is a left parenthesis or not.
bool isLeftParenthesis(ItemType achar);

//Description: Checks to see if the character is a operator.
//Pre: achar is a defined item type.
//Post: The boolean returns whether the character is a operator or not.
bool isOperator(ItemType achar);

//Description: Checks to see if the character is a right parenthesis or not.
//Pre: achar is a defined item type.
//Post: The boolean returns whether the character is a right parenthesis or not.
bool isRightParenthesis (ItemType achar);

//Description: Checks the users input and determines how to organize, store, and print it.
//Pre: The user provided a infix expression and the postfix string is defined.
//Post: Infix expression is sorted based on presedence into a postfix expression.
void convertInfixToPostfix(string inFixExpression, string& postFixExpression);

//Description: Checks the operators for presedence over one another.
//Pre: achar is a defined item type.
//Post: Returns what precedence the operator has as a integer.
int precedence(ItemType achar);

//Description: Gets the users infix expression.
//Pre: inFixExpression is a defined string.
//Post: The users infix expression can now be used.
void userInput(string& inFixExpression);

//Description: Checks to see if the infix expression is an x.
//Pre: inFixExpression is a defined string.
//Post: The boolean returns whether the user wants to quit or not.
bool isFinished(string inFixExpression);

int main()
{
  cout << "          type x to quit" << endl << endl;
  runConversion();
  cout << "thank you for using our infix to postfix converter" << endl;
  return 0;
}

//Description: Ensures the program runs and stops when needed.
//Pre: No pre-conditions were required.
//Post: The program will be ran or stopped per the users instructions.
void runConversion()
{
  string postFixExpression;
  string inFixExpression;
  bool userQuits;
  bool quit = false;

  while (!quit)
  {
    userInput(inFixExpression);
    userQuits = isFinished(inFixExpression);
    if (userQuits)
    {
      quit = true;
    } else
    {
      convertInfixToPostfix(inFixExpression, postFixExpression);
      cout << "       the equivalent postfix expression > " << postFixExpression << endl << endl;
      postFixExpression.clear();
    }
  }
}

//Description: Checks the users input and determines how to organize, store, and print it.
//Pre: The user provided a infix expression and the postfix string is defined.
//Post: Infix expression is sorted based on presedence into a postfix expression.
void convertInfixToPostfix(string inFixExpression, string& postFixExpression)
{
  ItemType achar;
  Stack operatorStack;
  bool operand;
  bool leftParen;
  bool Operator;
  bool rightParen;

  for (int index = 0; index < inFixExpression.length(); index++)
  {
    achar = inFixExpression[index];
    operand = isOperand(achar);
    leftParen = isLeftParenthesis(achar);
    Operator = isOperator(achar);
    rightParen = isRightParenthesis(achar);

    if (operand)
    {
      postFixExpression += achar;
    } else if (leftParen)
    {
      bool isAdded;
      operatorStack.push(achar, isAdded);
    } else if (Operator)
    {
      bool isAdded;
      if (!operatorStack.isEmpty())
      {
        ItemType topItem = operatorStack.peek();
        int precedenceOfachar = precedence(achar);
        int precedenceOfTopItem = precedence(topItem);

        while (!operatorStack.isEmpty() and topItem != '(' and precedenceOfachar <= precedenceOfTopItem)
        {
          postFixExpression += topItem;
          operatorStack.pop();
        }
      }
        operatorStack.push(achar, isAdded);
    } else if (rightParen)
    {
        ItemType topItem = operatorStack.peek();

        while (topItem != '(')
        {
          postFixExpression += topItem;
          operatorStack.pop();

          topItem = operatorStack.peek();
        }
        operatorStack.pop();
    }
  }

  while (!operatorStack.isEmpty())
  {
    ItemType topItem = operatorStack.peek();
    postFixExpression += topItem;
    operatorStack.pop();
  }
}

//Description: Checks to see if the character is a letter.
//Pre: achar is a defined item type.
//Post: The boolean returns whether the character is a letter or not.
bool isOperand(ItemType achar)
{
  if (achar >= 97 and achar <= 122)
  {
    return true;
  } else
  {
    return false;
  }
}

//Description: Checks to see if the character is a left parenthesis.
//Pre: achar is a defined item type.
//Post: The boolean returns whether the character is a left parenthesis or not.
bool isLeftParenthesis(ItemType achar)
{
  if (achar == '(')
  {
    return true;
  } else
  {
    return false;
  }
}

//Description: Checks to see if the character is a operator.
//Pre: achar is a defined item type.
//Post: The boolean returns whether the character is a operator or not.
bool isOperator(ItemType achar)
{
  if (achar == '+' or achar == '-' or achar == '*' or achar == '/')
  {
    return true;
  } else
  {
    return false;
  }
}

//Description: Checks to see if the character is a right parenthesis or not.
//Pre: achar is a defined item type.
//Post: The boolean returns whether the character is a right parenthesis or not.
bool isRightParenthesis (ItemType achar)
{
  if (achar == ')')
  {
    return true;
  } else
  {
    return false;
  }
}

//Description: Checks the operators for presedence over one another.
//Pre: achar is a defined item type.
//Post: Retunrs what precedence the operator has as a integer.
int precedence (ItemType achar)
{
  if (achar == '+' or achar == '-')
  {
    return 1;
  } else
  {
    return 2;
  }
}

//Description: Gets the users infix expression.
//Pre: inFixExpression is a defined string.
//Post: The users infix expression can now be used.
void userInput(string& inFixExpression)
{
  cout << "input an infix expression without spaces > ";
  getline(cin, inFixExpression);
  cout << endl;
}

//Description: Checks to see if the infix expression is an x.
//Pre: inFixExpression is a defined string.
//Post: The boolean returns whether the user wants to quit or not.
bool isFinished(string inFixExpression)
{
  if (inFixExpression.at(0) == 'x' and inFixExpression.length() <= 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
