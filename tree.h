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
	void add_left(tree root, char value);
	void add_right(tree root, char value);
}

#endif
