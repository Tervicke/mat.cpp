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
		vector<vector<int>> elements;
		void verifyIndex(int& row , int& column);
	public:
		Matrix(int rows , int columns);
		int get(int row , int column);
		void print() const;
		int& at(int row , int column);
		Matrix operator+(Matrix& matrix2);
		Matrix& operator=(Matrix& matrix);
		int getRows();
		int getColumns();
};
