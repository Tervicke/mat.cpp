#include <iostream>
#include <vector>
#include <stdexcept>
#include "Matrix/Matrix.h"

using namespace std;

int main() {
    // Matrix with rank 2 (3x3)
		cout << "Test Case: Full-Rank Matrix (3x3)" << endl;
    Matrix m1(0, 0);
    m1.set({{1, 1, 0}, {1,1,-1}, {1,-1,2},{1,-1,1}});
    m1.print();

    // Result matrix to hold orthonormal basis
    Matrix result(3, 3);

    // Perform Gram-Schmidt process
    try {
        gramSchmidt(m1, result);
        cout << "Resulting Orthonormal Basis:" << endl;
        result.print();
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
