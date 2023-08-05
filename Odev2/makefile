all:compile connect run
compile:
	g++ -c -I "./include" ./src/Node.cpp -o ./lib/Node.o
	g++ -c -I "./include" ./src/BinaryTree.cpp -o ./lib/BinaryTree.o
	g++ -c -I "./include" ./src/BinaryTreeList.cpp -o ./lib/BinaryTreeList.o
	g++ -c -I "./include" ./src/Stack.cpp -o ./lib/Stack.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
connect:
	g++ ./lib/Node.o ./lib/BinaryTree.o ./lib/BinaryTreeList.o ./lib/Stack.o ./lib/main.o -o ./bin/program
run:
	./bin/program