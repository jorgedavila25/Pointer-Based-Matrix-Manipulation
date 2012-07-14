#include <iostream>
#include <cstdlib>

using namespace std; 

#include "Matrix.h"
#include "Matrix.cpp"

using MatrixTemplate::Matrix;


int main()
{
	Matrix <int> initiate;
	initiate.testingMatrix();
	
	return 0;
}
