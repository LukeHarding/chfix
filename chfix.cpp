#include <iostream>
#include "tree.h"

using std::cout;
using std::endl;
bool isOperator(char c);
int main(int argc, char *argv[])	
{

  std::string input;
  cout << "enter an expression: ";
  std::cin >> input;
  int len = (sizeof(input)/sizeof(char));
  tree expr(input.at(0));
  cout << "Building tree\n";
  cout << "Input = " << input;
  for (int i = 1; i < len-1; i++)
    {
      cout << i <<"\n";
      if(isalnum(input.at(i)))
	{
	  cout << input.at(i) << " is a digit\n";
	  expr.add_left_node(input.at(i));
	  expr.add_right_node(input.at(i+1));
	}
      else if (isOperator(input.at(i)))
	{
	  cout << input.at(i) << " is an operator\n";
	  if(input.at(i) == '+' || input.at(i) == '-' )
	    expr.add_left_node(input.at(i));
	  if(input.at(i) == '*' || input.at(i) == '/' || input.at(i) == '%' )
	    expr.add_right_node(input.at(i));
	}
      else
	{
	  cout << "Invalid character\nExiting!\n";
	  return 0;
	}
    }
}
bool isOperator(char c)
{
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    return true;
  return false;
}
