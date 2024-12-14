#include<iostream>
#include<vector>
#include<stdexcept>
#include"Matrix/Matrix.h"
using namespace std;

int main(){

    Matrix m(2, 2);
		m.at(1,1) = 1;
		m.at(1,2) = 2;
		m.at(2,1) = 3;
		m.print();
		Matrix m1(2,2);
		Matrix m2(2,2);
		m2 = m * m;
		cout << "------------------- \n";
		m2.print();
		cout << "------------------- \n";
		//gpt generated test cases
		// Testing a 3x3 matrix squared
		Matrix m3(3, 3);
		m3.at(1, 1) = 1; m3.at(1, 2) = 2; m3.at(1, 3) = 3;
		m3.at(2, 1) = 4; m3.at(2, 2) = 5; m3.at(2, 3) = 6;
		m3.at(3, 1) = 7; m3.at(3, 2) = 8; m3.at(3, 3) = 9;
		cout << "3x3 Matrix (m3):\n";
		m3.print();

		Matrix m3Squared = m3 * m3;
		cout << "\n3x3 Matrix Squared (m3 * m3):\n";
		m3Squared.print();
		cout << "-------------------\n";

		// Testing a 3x2 and 2x3 matrix multiplication
		Matrix m4(3, 2);
		m4.at(1, 1) = 1; m4.at(1, 2) = 2;
		m4.at(2, 1) = 3; m4.at(2, 2) = 4;
		m4.at(3, 1) = 5; m4.at(3, 2) = 6;
		cout << "3x2 Matrix (m4):\n";
		m4.print();

		Matrix m5(2, 3);
		m5.at(1, 1) = 7; m5.at(1, 2) = 8; m5.at(1, 3) = 9;
		m5.at(2, 1) = 10; m5.at(2, 2) = 11; m5.at(2, 3) = 12;
		cout << "\n2x3 Matrix (m5):\n";
		m5.print();

		Matrix m6 = m4 * m5;
		cout << "\nResult of 3x2 * 2x3 Matrix (m4 * m5):\n";
		m6.print();
		cout << "-------------------\n";

		// Testing a 2x3 and 3x2 matrix multiplication
		Matrix m7 = m5 * m4;
		cout << "Result of 2x3 * 3x2 Matrix (m5 * m4):\n";
		m7.print();
		
    return 0;
}
