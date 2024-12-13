#include<iostream>
#include<vector>
#include<stdexcept>
#include"Matrix/Matrix.h"
using namespace std;

int main(){

    Matrix m3(3, 3);
    m3.at(1, 1) = 1.1;
    m3.at(1, 2) = 2.2;
    m3.at(1, 3) = 3.3;
    m3.at(2, 1) = 5.5;
    m3.at(2, 2) = 6.6;
    m3.at(2, 3) = 7.7;
    m3.at(3, 1) = 9.9;
    m3.at(3, 2) = 10.10;
    m3.at(3, 3) = 11.11;
		m3.print();
		m3.swapColumns(1,3);
		m3.print();

    return 0;
}
