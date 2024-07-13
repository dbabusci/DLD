#makefile
dld: src/main.cpp src/dld.cpp
	g++ -o dld src/main.cpp src/dld.cpp
