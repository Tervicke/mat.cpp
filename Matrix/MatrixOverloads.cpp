#include"Matrix.h"

Matrix Matrix::operator+(Matrix& matrix2){
	verifyEqualDimension(matrix2 , *this);
	Matrix resultMatrix(matrix2.getRows(),matrix2.getColumns());
	for(int i = 1 ; i <= matrix2.getRows() ; i++){
		for(int j = 1 ; j <= matrix2.getColumns() ; j++){
			resultMatrix.at(i,j) = this->at(i,j) + matrix2.at(i,j);
		}
	}
	return resultMatrix;
}

Matrix Matrix::operator-(Matrix& matrix2){
	verifyEqualDimension(matrix2 , *this);
	Matrix resultMatrix(matrix2.getRows(),matrix2.getColumns());
	for(int i = 1 ; i <= matrix2.getRows() ; i++){
		for(int j = 1 ; j <= matrix2.getColumns() ; j++){
			resultMatrix.at(i,j) = this->at(i,j) - matrix2.at(i,j);
		}
	}
	return resultMatrix;
}

Matrix& Matrix::operator=(Matrix& matrix){
	if(this == &matrix){
		return *this; //handle self assigment by returining without changing anything
	}
	verifyEqualDimension(*this , matrix);
	for(int i = 1 ; i <= matrix.getRows() ; i++){
		for(int j = 1 ; j <= matrix.getColumns() ; j++){
			this->at(i,j) = matrix.at(i,j);
		}
	}
	return *this;
}

//scaler multiply matrix * scaler 
Matrix Matrix::operator*(int scaler){
	Matrix resultMatrix(this->getRows(),this->getColumns());
	for(int i = 1 ; i <= this->getRows() ; i++){
		for(int j = 1 ; j <= this->getColumns() ; j++){
			resultMatrix.at(i,j) = this->at(i,j) * scaler;
		}
	}
	return resultMatrix;
}

//friend function to implement scaler * matrix
Matrix operator*(int scaler , Matrix& matrix){
	return (matrix * scaler);
}

//scaler divide matrix * scaler 
Matrix Matrix::operator/(int scaler){
	Matrix resultMatrix(this->getRows(),this->getColumns());
	for(int i = 1 ; i <= this->getRows() ; i++){
		for(int j = 1 ; j <= this->getColumns() ; j++){
			resultMatrix.at(i,j) = this->at(i,j) / scaler;
		}
	}
	return resultMatrix;
}

//friend function to implement scaler / matrix
Matrix operator/(int scaler , Matrix& matrix){
	return (matrix / scaler);
}
