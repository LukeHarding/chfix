#include <iostream>
#include "tree.h"

using std::cout;

int main(int argc, char *argv[])	
{
	
	if(argc < 2)
	{
		cout << "Useage: " << argv[1] << " \"expression\"" << endl;
		return -1;
	}
	return 0;
}
