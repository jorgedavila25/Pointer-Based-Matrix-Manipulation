/*
 *  Matrix.h
 *  Jorge Davila
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
using namespace std;

namespace MatrixTemplate{

	template<class T>
	class Matrix
	{
	public:
		Matrix();
		Matrix(int, int);
		Matrix(const Matrix&);
		~Matrix();
		T numRows();
		T numColumns();
		Matrix operator *(const Matrix&);
		Matrix operator +(const Matrix&);
		Matrix operator =(const Matrix&);
		const Matrix operator +=(const Matrix&) const;
		T * operator[](int index);
		const T* operator[](int index) const;
		void testingMatrix();
		friend ostream & operator<<(ostream& stream, const Matrix& matrix1)
		{
			for ( int i = 0; i < matrix1.rows; i++ )
			{
				for ( int j = 0; j < matrix1.cols; j++ )
				{
					stream << " " << matrix1.matrixObject[i][j];
				}
					stream << endl;
			}

			return stream;
		}
		friend istream & operator>>(istream& stream, Matrix& matrix2)
		{
			cout << "Enter info for the matrix" << endl;
			stream >> matrix2.rows;
			stream >> matrix2.cols;

			matrix2.matrixObject = new arrayPointer[matrix2.rows];
			for (int i = 0; i< matrix2.rows; i++) // creating the actual matrix with the given information
				matrix2.matrixObject[i] = new T[matrix2.cols];

			for (int i = 0; i < matrix2.rows; i++)
			{
				for(int j = 0; j < matrix2.cols; j++)
					stream >> matrix2.matrixObject[i][j];
			}
			cout << endl;

			return stream;

		}
		friend Matrix operator *(T val, const Matrix& matrix2)
		{
			Matrix <int> product(matrix2.rows, matrix2.cols); //creating an object named product passing paramaters

			for (int i = 0; i < product.rows; i++)
			{
				for(int j = 0; j < product.cols; j++)
					product.matrixObject[i][j] = (matrix2.matrixObject[i][j]*5);
			}

			return product;
		}


	private:
		typedef T* arrayPointer;
		arrayPointer *matrixObject;
		T rows;
		T cols;

	};
}


#endif


