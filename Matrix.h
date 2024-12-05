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
		void check_index(int& row , int& column);
	public:
		Matrix(int rows , int columns);
		int get(int row , int column);
		void print() const;
		void set(int row , int column , int value);
		Matrix operator+(Matrix& matrix2);
		void operator=(Matrix& matrix);
};
