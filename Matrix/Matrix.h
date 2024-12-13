#pragma once
//Matrix class 
#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;
class Matrix{
	private:
		int rows;
		int columns;
		vector<vector<double>> elements;
		void verifyIndex(int& row , int& column);
	public:
		Matrix(int rows , int columns);
		int get(int row , int column);
		void print();
		double& at(int row , int column);

		Matrix operator+(Matrix& matrix2);
		Matrix operator-(Matrix& matrix);
		Matrix& operator=(Matrix& matrix);
		Matrix operator*(double scaler);
		friend Matrix operator*(double scaler ,Matrix& matrix);

		Matrix operator/(double scaler);
		friend Matrix operator/(double scaler ,Matrix& matrix);

		bool  operator==(Matrix& matrix);
		
		int getRows();
		int getColumns();

		void transpose();
		double determinant();
		void resize(int row , int col);

};


//util function def MatrixUtils.cpp
void verifyEqualDimension(Matrix& m1 , Matrix& m2);
void verifySquareMatrix(Matrix& m1);
Matrix& getMinorMatrix(Matrix& m , int row , int col);
double getDeterminant(int size , Matrix& m);
Matrix createIdentityMatrix(int n);
