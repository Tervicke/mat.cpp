#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;
class Matrix{

	private:
		int rows;
		int columns;
		vector<vector<int>> elements;
		void check_index(int& row , int& col){
			if(row < 1 || rows < row){
				throw out_of_range("The Index " + to_string(row) + "is out of bounds of range for the matrix with " + to_string(this->rows));
			}
			if(col < 1 || columns < col){
				throw out_of_range("The Index " + to_string(col) + "is out of bounds of range for the matrix with " + to_string(this->columns));
			}
			//if no exception thrown decrease the row and column to match the 0-based indexing for further use
			row--;
			col--;
		}
	public:
			int get(int row , int col) { //returns only a copy of the int without the refrence so the only way to change is it to use .set 
				check_index(row,col);
        return elements[row][col];
			}	

			Matrix(int rows , int columns){
				this->rows = rows;
				this->columns = columns;
				elements = vector<vector<int>>(rows,vector<int>(columns,0)); // Matrix set to NULL matrix by default
			}

			void print(){
				for(auto& v : elements){
					for(auto& e: v){
						cout << e << " ";
					}
					cout << endl;
				}
			}

			void set(int row , int col , int value){
				check_index(row,col);
				elements[row][col] = value;
			}

};
int main(){
	Matrix m(3,3);
	try{
		cout << m.get(1,1) << endl;
	}
	catch(const out_of_range& e){
		cout << e.what() <<endl;
	}
	m.print();
	m.set(1,1,500);
	m.print();
	return 0;
}
