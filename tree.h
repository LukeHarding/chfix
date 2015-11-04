#ifndef TREE_H
#define TREE_H


class tree
{
public:
	char root;
	tree *left;
	tree *right;
	tree();
	tree(char value);
	void add_left_node(char value);
	void add_right_node(char value);
	void set_root_value(char value);
	char get_left_node();
	char get_right_node();
};

#endif
