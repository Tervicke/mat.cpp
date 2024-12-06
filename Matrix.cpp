#include<iostream>
#include<vector>
#include<stdexcept>
#include"Matrix.h"
using namespace std;

//Matrix constructor
Matrix::Matrix(int rows , int columns){
	this->rows = rows;
	this->columns = columns;
	this->elements = vector<vector<int>>(rows,vector<int>(columns,0)); // Matrix set to NULL matrix by default
}

//check the index
void Matrix::check_index(int& row , int& col){
	if(row < 1 || rows < row){
		throw out_of_range("The Index " + to_string(row) + "is out of bounds of range for the matrix with " + to_string(this->rows));
	}	
	//decrease by 1 to ensure the next function uses them correctly
	row--;col--;
}

//set the matrix variable
int& Matrix::at(int row , int col){
	check_index(row,col);
	return this->elements[row][col];
}

//print the matrix on the console
void Matrix::print() const {
	for(auto& v : elements){
		for(auto& e: v){
			cout << e << " ";
		}
		cout << endl;
	}
}

//get the value at a particular row and col
int Matrix::get(int row , int col) { //returns the refrence to the elements pointer to change it  
	this->check_index(row,col);
	return elements[row][col];
}	

//overload the + operator to perform addition
Matrix Matrix::operator+(Matrix& matrix2){
	Matrix resultMatrix(matrix2.rows,matrix2.columns);
	for(int i = 1 ; i <= matrix2.rows ; i++){
		for(int j = 1 ; j <= matrix2.columns ; j++){
			resultMatrix.at(i,j) = this->at(i,j) + matrix2.at(i,j);
		}
	}
	return resultMatrix;
}

void Matrix::operator=(Matrix& matrix){
	if(this == &matrix){
		return; //handle self assigment by returining without changing anything
	}

	if(this->rows != matrix.rows || this->columns != matrix.columns){
		cout << "to  be implemeneted exeption\n";
		exit(1);
	}

	for(int i = 1 ; i <= matrix.rows ; i++){
		for(int j = 1 ; j <= matrix.columns ; j++){
			this->at(i,j) = matrix.at(i,j);
		}
	}
}
