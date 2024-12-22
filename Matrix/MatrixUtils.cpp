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



//some utility functions for gramScmidt()
//------- start 
void normalise(vector<double>& v){
	//get the magnitude
	//update the vector by dividing each element with the magnitude
	double magnitude = 0;
	for(double e : v){
		magnitude += e * e;
	}
	magnitude = sqrt(magnitude); //take the square root after adding all the squares
	for(double& e : v){
		e = e / magnitude;
	}
}

//returns the magnitude / norm of the vector
double norm(vector<double>& v){
	double magnitude = 0;
	for(auto& e : v){
		magnitude += e * e;
	}
	return sqrt(magnitude);
}
vector<double> GetProjection(vector<double> u , vector<double> v){
	//projection of u on v onto u is given by proj = ( (v dot product u ) / (u dot product u) ) * vector u
	//get the dot product of v and u
	double dotProductVU = 0;
	for(int i = 0 ; i < u.size() ; i++){
		dotProductVU += v[i] * u[i];
	}
	//get the dot product of u and u 
	double dotProductUU = 0; 
	for(int i = 0 ; i < u.size() ; i++){
		dotProductUU += u[i] * u[i];
	}
	//check if 0
	if(dotProductUU < 1e-9 ){
		cout << dotProductUU << endl;
		throw runtime_error("cannot project unto a zero vector");
	}
	//get the scaler and then multiply it to every element in the u vector
	double scaler = dotProductVU / dotProductUU;

	//scale the u vector
	vector<double> projection(u.size());
	for(int i = 0 ; i < u.size() ; i++ ){
		projection[i] = u[i] * scaler;
	}

	return projection;
}
vector<double> substractVectors(const vector<double>& a, const vector<double>& b) {

    if (a.size() != b.size()) {
        throw std::invalid_argument("Vectors must be of the same size for subtraction.");
    }

    vector<double> result(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        result[i] = a[i] - b[i];
    }

    return result;
}

//------- end
//

void gramSchmidt(Matrix m , Matrix& result){
	//resize the result
	result.resize(m.getRows() , m.getColumns());
	
	//here a1,...an is the pure column of the matrix , u1 , un is the projected and updated vector which is normal to each other and q2 is the result col 
	for(int i = 1 ; i <= m.getColumns() ; i++){
		
		//directly insert the first column by just normalising it
		vector<double> ai = m.getCol(i);
		if(i == 1){ 
			normalise(ai);
			result.setCol( i , ai );
			continue;
		}
		
		//update the a2 to obtain u2 
		//first substract the projection of q1 in a2 and then get a2 and then calculate it again

		vector<double> updated_column = ai;

		for(int j = 1 ; j < i ; j++){ //substract all the projection of previous vectors 
			vector<double> projection = GetProjection(result.getCol(j) , updated_column);
			updated_column = substractVectors(updated_column, projection);
		}

		normalise(updated_column);
		for(int i = 0 ; i < updated_column.size() ; i++){
			cout << updated_column[i] << " ";
		}
		cout << endl;
		cout << norm(updated_column) << endl;
		if(updated_column.empty() || norm(updated_column) <1e-9 ){
			throw std::runtime_error("Gram-Schmidt failed: Dependent or zero column detected.");
		}

		result.setCol(i,updated_column);
	}

}
