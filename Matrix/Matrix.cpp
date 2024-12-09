#include<iostream>
#include<vector>
#include<stdexcept>
#include"Matrix.h"
using namespace std;

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

int Matrix::getRows(){
	return this->rows;
}
int Matrix::getColumns(){
	return this->columns;
}

//matrix transpose , turn the matrix into a transpose
void Matrix::transpose(){
	int new_rows = this->getColumns();
	int new_columns = this->getRows();
	std::vector<vector<int>> new_elements(new_rows,vector<int>(new_columns));
	//loop from zero to maintain the new_elements
	for(int i = 0 ; i < this->getRows() ; i++){
		for(int j = 0 ; j < this->getColumns() ; j++){
			new_elements[j][i] = this->at(i+1,j+1);
		}
	}
	this->elements = new_elements;
	this->rows = new_rows;
	this->columns = new_columns;
}

