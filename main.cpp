#include<iostream>
#include<vector>
#include<stdexcept>
#include"Matrix.h"

using namespace std;
int main(){
	Matrix m1(2,2);
	m1.set(1,1,1);
	m1.print();

	Matrix m2(2,2);
	m2.set(1,1,2);
	m2.print();

	Matrix m3 = m1 + m2;
	m3.print();
	return 0;
}
