all:
	g++ -c tree.cpp
	g++ chfix.cpp tree.o -o chfix
