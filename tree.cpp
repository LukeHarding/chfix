#include "tree.h"
#include <iostream>
#include <stdlib.h>

tree::tree()	
{
	root = 0;
	left = 0;
	right = 0;
}
tree::tree(char value)	
{
	root = value;
	left = 0;
	right = 0;
}
void tree::add_left_node(char value)
{
	if (left != 0)
	{
		std::cout << "Tried overwriting left node, exiting\n";
		exit(-1);
	}
	left = new tree(value);
}
void tree::add_right_node(char value)
{
	if (right != 0)
	{
		std::cout << "tried overwriting right node, exiting\n";
		exit(-1);
	}
	right = new tree(value);
}
void tree::set_root_value(char value)		{root = value;}
char tree::get_left_node()			{return left->root;}
char tree::get_right_node()			{return right->root;}
