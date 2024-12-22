#include<stdexcept>
#include<math.h>
#include"Matrix.h"
//verify the square matrix for determinant calculation mostly
void verifySquareMatrix(Matrix& m){
	if(m.getRows() != m.getColumns()){
		string error = "Not a Square Matrix of " + to_string(m.getRows()) + "x" + to_string(m.getColumns());
		throw std::runtime_error(error);
	}
}

//verify if two dimensions are equal for addition , substraction etc .
void verifyEqualDimension(Matrix& m1 , Matrix& m2){ //throws runtime error if dimension MisMatched
	if(m1.getRows() != m2.getRows() || m1.getColumns() != m2.getColumns()){
		string error = "MisMatched Dimensions for Matrix " + to_string(m1.getRows()) + "x" + to_string(m1.getColumns()) + " and " + to_string(m2.getRows()) + "x" + to_string(m2.getColumns());
		throw std::runtime_error(error);
		exit(1);
	}
}
//get the minor matrix by removing the row and column
void setMinorMatrix(Matrix& m , int row , int col , Matrix& minorMatrix){
	//verifySquareMatrix(m);
	int row_index = 1;
	int col_index = 1;
	for(int i = 1 ; i <= m.getRows() ; i++){
		if(row == i){ continue; } //skip the row 
		col_index = 1;
		for(int j = 1 ; j <= m.getColumns() ; j++){
			if(col == j){continue;} // skip the column
			minorMatrix.at(row_index,col_index) = m.at(i,j);
			col_index++;
		}
		row_index++;
	}
}
//wraper function over the Matrix::determinant();
double getDeterminant(int size , Matrix& m){
	int determinant = 0;
	Matrix minorMatrix(m.getRows() - 1 , m.getColumns() - 1);
	int sign = 1; //changes the sign after every iteration of the loop alternative to pow(1,i-1);
	if(size > 2){
		size--;
		for(int i = 1 ; i <= m.getRows() ; i++){
			setMinorMatrix(m,1,i,minorMatrix); //sets the minorMatrix to the minor matrix 
			determinant += sign * (m.at(1,i) * getDeterminant(size , minorMatrix) );
			sign *= -1;
		}
	}else{
    determinant = m.at(1,1) * m.at(2,2) - m.at(1,2) * m.at(2,1);
	}
	return determinant;
}

Matrix createIdentityMatrix(int n){
	Matrix identityMatrix(n,n);
	for(int i = 1 ; i <= n ; i++){
		identityMatrix.at(i,i) = 1;
	}
	return identityMatrix;
}
void reduceToREF(Matrix& m){
	int rows = m.getRows();
	int cols = m.getColumns();

	for(int k = 1 ; k <= std::min(rows,cols) ; k++){
		double pivot = m.at(k,k);
		//if pivot is 0 try to swap rows to make it non zero;
		if(pivot == 0){

			for(int i = k + 1 ; i <= rows ; i++){
				if(m.at(i,k) != 0 ){ // check for potential pivots
					m.swapRows(k,i);
					break;
				}
			}

		}
		pivot = m.at(k,k); // update the pivot to ensure the new (swapped row pivot is being used)
		if(pivot == 0){ continue; } // pivot is 0 and no rows can be swapped
		//if non zero pivot ensured then

		for(int i = k + 1 ; i <= rows ; i++){
			double pivot = m.at(i,k)  / m.at(k,k) ; //the pivot that is divided by the the next col
			for(int j = k ; j <= cols ; j++){
				m.at(i,j) -= m.at(k,j) * pivot;
			}
		}

	}

}
//returns true if the matrix is diagonal else returns false
bool verifyDiagonalMatrix(Matrix m){
	//try to catch the runtime error thrown by the verifySquareMatrix and return false if it catches the error
	//every diagonal matrix has to be a square matrix
	try {
		verifySquareMatrix(m); 
	}catch(const std::runtime_error &e){
		return false;
	}
	for(int i = 1 ; i <= m.getRows(); i++){
		for(int j = 1 ; j <= m.getColumns() ; j++){
			if(m.at(i,j) != 0 && i != j){
				return false;
			}
		}
	}
	return true;
}
//get the norm / magnitude of a particular column 
double getNormOfCol(Matrix m,int col){
	if(col <= 0 || col > m.getColumns()){
		string error = "Not a valid column";
		throw runtime_error(error);
	}
	int ans = 0; // calculate the sum;
	for(int i = 1 ;  i <= m.getRows();i++){
		ans+= m.at(i,col) * m.at(i,col); // square and sum
	}
	return sqrt(ans);
}
