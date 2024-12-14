#include<iostream>
#include<vector>
#include<stdexcept>
#include"Matrix/Matrix.h"
using namespace std;

int main(){

    Matrix m(3, 3);
		m.at(1,1) = 1;
		m.at(1,2) = 2;
		m.at(2,1) = 3;
		m.at(3,2) = 12;
		m.at(3,1) = 8;
		m.at(2,3) = 2;
		m.print();
    return 0;
}
