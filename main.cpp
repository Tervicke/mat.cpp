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
		m1 = m;
		m2 = 3 * m;
		m.print();
		cout << "------------------- \n";
		m1.print();
		cout << "------------------- \n";
		m2.print();
		cout << "------------------- \n";
    return 0;
}
