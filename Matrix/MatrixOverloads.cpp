#include"Matrix.h"
#include<stdexcept>
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

//scaler multiply matrix * scaler 
Matrix Matrix::operator*(double scaler){
	Matrix resultMatrix(this->getRows(),this->getColumns());
	for(int i = 1 ; i <= this->getRows() ; i++){
		for(int j = 1 ; j <= this->getColumns() ; j++){
			resultMatrix.at(i,j) = this->at(i,j) * scaler;
		}
	}
	return resultMatrix;
}

//friend function to implement scaler * matrix
Matrix operator*(double scaler , Matrix& matrix){
	return (matrix * scaler);
}

//scaler divide matrix * scaler 
Matrix Matrix::operator/(double scaler){
	Matrix resultMatrix(this->getRows(),this->getColumns());
	for(int i = 1 ; i <= this->getRows() ; i++){
		for(int j = 1 ; j <= this->getColumns() ; j++){
			resultMatrix.at(i,j) = this->at(i,j) / scaler;
		}
	}
	return resultMatrix;
}

//friend function to implement scaler / matrix
Matrix operator/(double scaler , Matrix& matrix){
	return (matrix / scaler);
}

bool Matrix::operator==(Matrix& matrix2){
	try{
		verifyEqualDimension(*this,matrix2);
	}catch(const std::runtime_error& e){
		return false;
	}
	for(int i = 1 ; i <= this->getRows() ; i++){
		for(int j = 1 ; j <= this->getColumns() ; j++){
			if(this->at(i,j) != matrix2.at(i,j)){
				return false;
			}
		}
	}
	return true;
}
Matrix Matrix::operator*(Matrix& m2){
	if(this->getColumns() != m2.getRows()){
		throw runtime_error("Invalid Matrix multiplication");
	}
	int rows = this->getRows();
	int cols = m2.getColumns();
	Matrix result(rows , cols);
	int ans;	 // to calculate the ans at each position 
	
	//looping through the result matrix to set every element
	for(int i = 1 ; i <= rows ; i++ ){
		for(int j = 1 ; j <= cols ; j++){
			ans = 0;
			for(int k = 1 ; k <= m2.getRows() ; k++){ // using either m2.getRows()  or this->getColumns() will work since they are equal....
				ans += this->at(i,k) * m2.at(k,j);
			}
			result.at(i,j) = ans; 
		}
	}
	return result;
}
