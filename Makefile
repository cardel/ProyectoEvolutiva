all:
	g++ -c *.cpp
	g++ -o exe *.o
	rm -rf *.o
