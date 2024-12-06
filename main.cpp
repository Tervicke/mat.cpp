#include<iostream>
#include<vector>
#include<stdexcept>
#include"Matrix/Matrix.h"

using namespace std;
int main(){
	Matrix m1(2,2);
	m1.at(1,1) = 12;
	m1.at(1,2) = 12;
	m1.at(2,1) = 12;
	m1.at(2,2) = 12;

	Matrix m2(2,2);
	m2.at(1,1) = 13;
	m2.at(1,2) = 13;
	m2.at(2,1) = 13;
	m2.at(2,2) = 13;
	
	Matrix m3 = m1 - m2;
	m3.print();
	return 0;
}
