#include<iostream>
#include<vector>
#include<stdexcept>
#include"Matrix/Matrix.h"
using namespace std;
int main(){
	Matrix m1(3,3);
	m1.at(1,1) = 1;
	m1.at(1,2) = 2;
	m1.at(2,1) = 3;
	m1.at(2,2) = 4;

	m1.print();
	verifySquareMatrix(m1);
	Matrix minor = getMinorMatrix(m1,3,3);
	minor.print();
	return 0;
}
