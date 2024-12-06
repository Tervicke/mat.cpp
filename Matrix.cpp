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

//verify the given index
void Matrix::verifyIndex(int& row , int& col){
	if(row > this->getRows() || col > this->getColumns()){
		throw out_of_range("The Index " + to_string(row) + "is out of bounds of range for the matrix with " + to_string(this->rows));
	}	
	//decrease by 1 to ensure the next function uses them correctly
	row--;col--;
}

//set the matrix variable
int& Matrix::at(int row , int col){
	verifyIndex(row,col);
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
	this->verifyIndex(row,col);
	return elements[row][col];
}	

//overload the + operator to perform addition
Matrix Matrix::operator+(Matrix& matrix2){
	Matrix resultMatrix(matrix2.getRows(),matrix2.getColumns());
	for(int i = 1 ; i <= matrix2.getRows() ; i++){
		for(int j = 1 ; j <= matrix2.getColumns() ; j++){
			resultMatrix.at(i,j) = this->at(i,j) + matrix2.at(i,j);
		}
	}
	return resultMatrix;
}

void Matrix::operator=(Matrix& matrix){
	if(this == &matrix){
		return; //handle self assigment by returining without changing anything
	}

	if(this->getRows() != matrix.getRows() || this->getColumns() != matrix.getColumns()){
		cout << "to  be implemeneted exeption\n";
		exit(1);
	}

	for(int i = 1 ; i <= matrix.getRows() ; i++){
		for(int j = 1 ; j <= matrix.getColumns() ; j++){
			this->at(i,j) = matrix.at(i,j);
		}
	}
}
int Matrix::getRows(){
	return this->rows;
}
int Matrix::getColumns(){
	return this->columns;
}
