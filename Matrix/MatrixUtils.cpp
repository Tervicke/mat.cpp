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
void convertToREF(Matrix& m){
	//only changes 1 row
	m.print();
	for(int k = 1 ; k <= m.getColumns(); k++){
		
		//for one column only
		for(int i = 1 ; i <= m.getRows()-1 ; i++){
			double pivot = (m.at(i+1,k) == 0) ? 0 : m.at(k,k) / m.at(i+1,k);	
			cout << "pivot " << m.at(k,k) << " / " << m.at(i+1,k) << " " << pivot << endl;
			if(pivot != 0){
				for(int j = 1 ; j <= m.getColumns() ; j++){ 
					m.at(i+1,j) = m.at(i+1,j) * pivot - m.at(k,j);
				}
			}
			m.print();
		}
	}

}
