#include<iostream>
#include<vector>
#include<stdexcept>
#include"Matrix.h"
using namespace std;

Matrix::Matrix(int rows , int columns){
	this->rows = rows;
	this->columns = columns;
	this->elements = vector<vector<double>>(rows,vector<double>(columns,0.0)); // Matrix set to NULL matrix by default
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
double& Matrix::at(int row , int col){
	verifyIndex(row,col);
	return this->elements[row][col];
}

//print the matrix on the console
void Matrix::print() {
    cout << "{" << endl; // Start the matrix
    for (size_t i = 0; i < elements.size(); ++i) {
        cout << "  [ ";
        for (size_t j = 0; j < elements[i].size(); ++j) {
            cout << elements[i][j];
            if (j < elements[i].size() - 1) cout << " , "; // Add a comma between elements
        }
        cout << " ]";
        if (i < elements.size() - 1) cout << ","; // Add a comma between rows
        cout << endl;
    }
    cout << "}" << endl; // End the matrix
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
	std::vector<vector<double>> new_elements(new_rows,vector<double>(new_columns));
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
//wrapper for the internal getdeterminant method
double Matrix::determinant(){
	verifySquareMatrix(*this); // verify if square matrix
	return getDeterminant(this->getRows() , *this );
}

void Matrix::resize(int row , int col){
	this->rows = row; 
	this->columns = col;
	this->elements.resize(row,vector<double>(col,0));
	for(auto& v : this->elements){
		v.resize(col,0);
	}
}

void Matrix::swapRows(int row1, int row2){
	//verify the row1
	if(row1 <= 0 || row1 > this->getRows() ){ 
		string error = "Not a valid row " + to_string(row1) + "for the Matrix with rows " + to_string(this->getRows());
		throw runtime_error(error);
	}
	//verify the row2
	if(row2 <= 0 || row2 > this->getRows() ){ 
		string error = "Not a valid row " + to_string(row1) + "for the Matrix with rows " + to_string(this->getRows());
		throw runtime_error(error);
	}
	row1--;
	row2--;
	vector<double> temp = this->elements[row1];
	this->elements[row1] = this->elements[row2];
	this->elements[row2] = temp;
}
void Matrix::swapColumns(int col1 , int col2){
	//verify the col1
	if(col1 <= 0 || col1 > this->getColumns() ){ 
		string error = "Not a valid column" + to_string(col1) + "for the Matrix with columns" + to_string(this->getColumns());
		throw runtime_error(error);
	}
	//verify the col2 
	if(col2 <= 0 || col2> this->getColumns() ){ 
		string error = "Not a valid column" + to_string(col2) + "for the Matrix with columns" + to_string(this->getColumns());
		throw runtime_error(error);
	}
	col1--;
	col2--;
	for(int i =0 ;i < this->getRows() ; i++){
		double temp = this->elements[i][col1];
		this->elements[i][col1] = this->elements[i][col2];
		this->elements[i][col2] = temp;
	}
}
void Matrix::invert(){
	verifySquareMatrix(*this);
	int det = this->determinant();

	if(det == 0) {
		string error = "Cannot invert a singular Matrix (determinant = 0)";
		throw runtime_error(error);
	}
	int rows = this->getRows();
	int cols = this->getRows();
	double cofactor;
	double sign;
	Matrix minorMatrix(rows - 1 , cols - 1);	 // make a temp minor matrix to use the set minor matrix
	Matrix resultMatrix(rows , cols);

	for(int i = 1 ; i <= rows ; i++){
		for(int j = 1 ; j <= cols ; j++){
			setMinorMatrix(*this,i,j,minorMatrix);
			sign = ((i+j) % 2 == 0) ? 1 : -1;
			cofactor = sign * minorMatrix.determinant();
			resultMatrix.at(j,i) = cofactor; //find the cofactor and set it on the interchanged row col form;
		}
	}
	cout << det << endl;
	resultMatrix = resultMatrix / det;
	*this = resultMatrix; // set the original matrix to the new result matrix
}
//computes trace of the matrix
double Matrix::trace(){
	verifySquareMatrix(*this);
	double trace = 0.0;
	for(int i = 1; i <= this->getRows() ; i++){
		trace += this->at(i,i);
	}
	return trace;
}
