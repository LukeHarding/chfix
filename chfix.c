/*
 * This is a program that takes in prefix and outputs
 * infix, prefix (polish), and postfix (reverse polish)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// here is the tree, hopefully simple is better.
	struct tree
	{
		char value;
		struct tree *left;
		struct tree *right;
	};
	printf("struct created\n");
	int len = strlen(argv[1])+1;
	if (argc < 1)
	{
		printf("useage: %s \"expression\"\n", argv[0]);
		return 0;
	}
	char expr[len];
	int i;
	memset(expr, 0, len*sizeof(char));	
	expr[0] = argv[1];
	printf("%s", expr);

}
