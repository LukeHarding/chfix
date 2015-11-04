#include <iostream>
#include "tree.h"

using std::cout;
using std::endl;
int main(int argc, char *argv[])	
{
	
	if(argc < 2)
	{
		cout << "Useage: " << argv[0] << " \"expression\"" << endl;
		return -1;
	}
	return 0;
}
