#makefile
dld: src/main.cpp src/dld.cpp
	g++ -o dld.out src/main.cpp src/dld.cpp
