#include <iostream>
#include <vector>
#include <stdexcept>
#include "Matrix/Matrix.h"

using namespace std;

int main() {
    Matrix A(0, 0);
    A.set({{-2, -4, 2}, {-2,1,2}, {4,2,5}});
    A.print();
		vector<double> eigenvalues = A.getEigenValues();
		for(int i = 0 ; i < eigenvalues.size() ; i++){
			cout << eigenvalues[i] << ' ';
		}
		return 0;
}
