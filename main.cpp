#include <iostream>
#include <vector>
#include <stdexcept>
#include "Matrix/Matrix.h"

using namespace std;

int main() {
    // Matrix with rank 2 (3x3)
    cout << "Test Case 1: Matrix with rank 2 (3x3)" << endl;
    Matrix m1(3, 3);
    m1.at(1, 1) = 4;
		m1.at(2,2) = 1;
		m1.at(3,3) = 0;
    m1.print();
		cout << verifyDiagonalMatrix(m1) << endl;
    return 0;
}

