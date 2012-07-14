/*
 *  Matrix.cpp
 *  Jorge Davila
 */

#include "Matrix.h"
#include <iostream>
#include <cstdlib>

using namespace std;

namespace MatrixTemplate{

	template<class T>
	Matrix<T>::Matrix()// constructor
	{
		rows = 0;
		cols = 0;
		matrixObject = NULL;
	}
	template<class T>
	Matrix<T>::Matrix(int a, int b)// constructor w/ parameters
	{
		rows = a;
		cols = b;

		matrixObject = new arrayPointer[rows];
		for (int i = 0; i< rows; i++) // creating the actual matrix with the given information
			matrixObject[i] = new T[cols];

	}
	template<class T>
	Matrix<T>::Matrix(const Matrix& matrix2)//Copy Constructor
	{

		if (this != &matrix2)
		{
		  this->matrixObject=new arrayPointer[matrix2.rows];

		  for (int i = 0; i< matrix2.rows; i++) // creating the actual matrix with the given information
		    this->matrixObject[i] = new T[matrix2.cols];

		  this->rows = matrix2.rows;
		  this->cols = matrix2.cols;

		  for (int i = 0; i < matrix2.rows; i++)
		    {
		      for(int j = 0; j < matrix2.cols; j++)
			{
			  this->matrixObject[i][j] = matrix2.matrixObject[i][j];
			}
		    }

		}
	}
	template<class T>
	Matrix<T>::~Matrix()//destructor
	{
		if ((rows != 0)&&( cols != 0))
		{
			for(int i = 0; i < rows; i++)
			{
				delete[]matrixObject[i];
			}
				delete[] matrixObject;
		}
	}
	template<class T>
	T Matrix <T>::numRows()//returns the # of rows of type T
	{
		return rows;
	}
	template<class T>
	T Matrix <T>::numColumns()//returns the # of columns of type T
	{
		return cols;
	}
	template<class T>
	Matrix<T> Matrix<T>::operator *(const Matrix& matrix2) // * overload
	{
		Matrix <int> product(this->rows, matrix2.cols); //creating an object named product passing paramaters

		if((this->cols) != (matrix2.rows))
			cout << "invalid. cannot perform this task" << endl;
		else {

			/*							*
			 *	Multiplcation Algorithm	*
			 *							*/
			int sum = 0;
			for (int i= 0; i < this->rows; i++)
			{
				for (int j = 0; j < matrix2.cols; j++)
				{
					sum = 0;
					for (int k= 0; k < this->cols; k++)
					{
						sum = (sum + (this->matrixObject[i][k]*matrix2.matrixObject[k][j]));
					}
					product.matrixObject[i][j] = sum;
				}
			}

		}
		return product;
	}
	template<class T>
	Matrix<T> Matrix<T>::operator +(const Matrix& matrix1)// addition overload
	{

		if ((this->rows)==(matrix1.rows) && (this->cols)==(matrix1.cols))
		{
			Matrix <int> sum(matrix1.rows, matrix1.cols);

			for (int i = 0; i < sum.rows; i++)
			{
				for(int j = 0; j < sum.cols; j++)
					sum.matrixObject[i][j] = ((this->matrixObject[i][j])+(matrix1.matrixObject[i][j]));
			}

			return sum;
		}else {
			cout << "ERROR" << endl;
			return *this;
		}



	}

	template<class T>
	Matrix<T> Matrix<T>::operator =(const Matrix& matrix2) //assignment overload
	{
	    if (this != &matrix2)
		{

			for(int i = 0; i < rows; i++) // deallocating memory loop
			{
				delete[] this->matrixObject[i];//deallocating memory
			}
				delete[] this->matrixObject; //deallocatoin memory

			this->matrixObject=new arrayPointer[matrix2.rows]; // allocating memory

			for (int i = 0; i< matrix2.rows; i++) // creating the actual matrix with the given information
				this->matrixObject[i] = new T[matrix2.cols];

			this->rows = matrix2.rows;//assigning the # of rows
			this->cols = matrix2.cols;//assigning the # of cols

			for (int i = 0; i < matrix2.rows; i++)
			{
				for(int j = 0; j < matrix2.cols; j++)
				{
					this->matrixObject[i][j] = matrix2.matrixObject[i][j]; //copying the product of the previous two matrices into this
				}
			}

		}
		return *this;
	}

	template<class T>
	const Matrix<T> Matrix<T>::operator +=(const Matrix& matrix2)const //the += operator overload
	{

		Matrix <int> sum(this->rows, this->cols);

		for (int i = 0; i < sum.rows; i++)
		{
			for(int j = 0; j < sum.cols; j++)
				sum.matrixObject[i][j] = ((this->matrixObject[i][j])+(matrix2.matrixObject[i][j]));
		}
		for (int i = 0; i < sum.rows; i++)
		{
			for(int j = 0; j < sum.cols; j++)
				this->matrixObject[i][j] = sum.matrixObject[i][j];
		}

		return *this;
	}
	template<class T>
	T * Matrix<T>::operator[](int index)
	{

		return matrixObject[index];
	}
	template<class T>
	const T* Matrix<T>::operator[](int index)const
	{
		return matrixObject[index];
	}

	template<class T>
	void Matrix<T>::testingMatrix()//tests the matrix
	{
		Matrix<int> a;
		Matrix<int> b;
		Matrix<int> c;

		cout << "a.numRows(): " << a.numRows() << endl;
		cout << "a.numCols(): "<< a.numColumns() << endl;

		cin >> a;
		cout <<"A: " << endl;
		cout << a << endl;

		cin >> b;
		cout <<"B: " << endl;
		cout << b << endl;

		c=a*b;

		cout << "C: " << endl;
		cout << c << endl;

		cout << "B + C: " << endl;
		cout << b + c <<endl;


		Matrix<int> d(5*b);
		cout << "D: " << endl;
		cout << d << endl;

		cout <<"D+=C: " << endl;
		d+=c;
		cout << d << endl;

		cout << "a[0][0]: " << a[0][0] << endl;
		cout << "a[1][2]: " << a[1][2] << endl;

		cout << "D = A + B" << endl;
		d = a + b;
	}

}


