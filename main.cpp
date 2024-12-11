#include<iostream>
#include<vector>
#include<stdexcept>
#include"Matrix/Matrix.h"
using namespace std;

int main(){
    // 2x2 Matrix
    Matrix m1(2, 2);
    m1.at(1, 1) = 1;
    m1.at(1, 2) = 2;
    m1.at(2, 1) = 3;
    m1.at(2, 2) = 4;
    cout << "Determinant of 2x2 matrix: " << m1.determinant() << endl;  // Should be -2

    // 3x3 Matrix
    Matrix m2(3, 3);
    m2.at(1, 1) = 1;
    m2.at(1, 2) = 2;
    m2.at(1, 3) = 3;
    m2.at(2, 1) = 0;
    m2.at(2, 2) = 4;
    m2.at(2, 3) = 5;
    m2.at(3, 1) = 1;
    m2.at(3, 2) = 0;
    m2.at(3, 3) = 6;
    cout << "Determinant of 3x3 matrix: " << m2.determinant() << endl;  // Should be 12

    // 4x4 Matrix
    Matrix m3(3, 3);
    m3.at(1, 1) = 1;
    m3.at(1, 2) = 2;
    m3.at(1, 3) = 3;
    //m3.at(1, 4) = 4;
    m3.at(2, 1) = 5;
    m3.at(2, 2) = 6;
    m3.at(2, 3) = 7;
    //m3.at(2, 4) = 8;
    m3.at(3, 1) = 9;
    m3.at(3, 2) = 10;
    m3.at(3, 3) = 11;
		m3.resize(4,4);
		m3.print();
    //cout << "Determinant of 4x4 matrix: " << m3.determinant() << endl;  // Should be 0
		
		Matrix m4 = createIdentityMatrix(3);
		m4.print();

    return 0;
}
