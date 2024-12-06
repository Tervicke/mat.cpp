#include<iostream>
#include<vector>
#include<stdexcept>
#include"Matrix.h"

using namespace std;
int main(){
	Matrix m1(2,2);
	m1.at(1,1) = 1;
	m1.at(1,2) = 2;
	m1.at(2,1) = 3;
	m1.at(2,2) = 4;
	m1.print();

	Matrix m2(2,2);
	m2.at(1,1) = 1;
	m2.at(1,2) = 2;
	m2.at(2,1) = 3;
	m2.at(2,2) = 4;
	m2.print();

	Matrix m3 = m1 + m2;
	m3.print();
	return 0;
}
