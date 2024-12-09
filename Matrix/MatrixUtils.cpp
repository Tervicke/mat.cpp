#include<stdexcept>
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
Matrix getMinorMatrix(Matrix& m , int row , int col){
	verifySquareMatrix(m);
	Matrix minormatrix(m.getRows() - 1 , m.getColumns() -1);
	int row_index = 1;
	int col_index = 1;
	cout << "kfjal" << endl;
	for(int i = 1 ; i <= m.getRows() ; i++){
		if(row == i){ continue; } //skip the row 
		col_index = 1;
		for(int j = 1 ; j <= m.getColumns() ; j++){
			if(col == j){continue;} // skip the column
			minormatrix.at(row_index,col_index) = m.at(i,j);
			col_index++;
		}
		row_index++;
	}
	return minormatrix;
}

