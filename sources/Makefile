#Matrix.make
# example working make file for use of the class Account
# files: source files:  main.cpp Matrix.cpp
#        header file:  Matrix.h
# executable file: Matrix
#

# first define target file : Matrix
#              dependencies are the object files that build the program

make all: main.o Matrix.o
	g++ -o prog1 main.cpp Matrix.cpp

# now define how each object file is a target and list dependencies and how
#  to build that object file if any dependencies change

main.o: main.cpp Matrix.h
	g++ -c main.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -c Matrix.cpp

#Clean obj files

clean:
	(rm -f *.o;)
# that's all


