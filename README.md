
# Mat.cpp
## A matrix library written in c++ for educational purposes
# Matrix Library

## Overview
This library provides a `Matrix` class with various operations for matrix manipulation, including addition, subtraction, multiplication, inversion, and more. Utility functions for matrix computations are also included.

## Class: `Matrix`
### **Private Members**
- `int rows`: Number of rows in the matrix.
- `int columns`: Number of columns in the matrix.
- `vector<vector<double>> elements`: Stores matrix elements.
- `void verifyIndex(int& row, int& column)`: Ensures the given indices are within valid bounds.

### **Public Methods**

#### **Constructor**
- `Matrix(int rows, int columns)`: Initializes a matrix with given dimensions.
  ```cpp
  Matrix mat(3, 3);
  ```

#### **Element Access**
- `int get(int row, int column)`: Returns the value at a specific position.
  ```cpp
  int val = mat.get(1, 2);
  ```
- `double& at(int row, int column)`: Provides a reference to an element.
  ```cpp
  mat.at(0, 1) = 5.0;
  ```
- `void set(vector<vector<double>> elements)`: Sets matrix elements and adjusts size.
  ```cpp
  mat.set({{1, 2}, {3, 4}});
  ```
- `vector<double> getCol(int col)`: Returns a column as a vector.
  ```cpp
  vector<double> colVec = mat.getCol(1);
  ```
- `void setCol(int col, vector<double> colvec)`: Replaces a column with a new vector.
  ```cpp
  mat.setCol(1, {5, 6, 7});
  ```

#### **Basic Operations**
- `void print()`: Prints the matrix.
  ```cpp
  mat.print();
  ```
- `Matrix operator+(Matrix& matrix2)`: Adds two matrices.
  ```cpp
  Matrix sum = mat1 + mat2;
  ```
- `Matrix operator-(Matrix& matrix)`: Subtracts two matrices.
  ```cpp
  Matrix diff = mat1 - mat2;
  ```
- `Matrix operator*(Matrix& m2)`: Multiplies two matrices.
  ```cpp
  Matrix product = mat1 * mat2;
  ```
- `Matrix operator*(double scaler)`: Multiplies a matrix by a scalar.
  ```cpp
  Matrix scaled = mat * 2.0;
  ```
- `Matrix operator/(double scaler)`: Divides a matrix by a scalar.
  ```cpp
  Matrix divided = mat / 2.0;
  ```
- `bool operator==(Matrix& matrix)`: Checks if two matrices are equal.
  ```cpp
  bool isEqual = (mat1 == mat2);
  ```

#### **Matrix Properties**
- `int getRows()`: Returns number of rows.
  ```cpp
  int rows = mat.getRows();
  ```
- `int getColumns()`: Returns number of columns.
  ```cpp
  int cols = mat.getColumns();
  ```
- `void transpose()`: Transposes the matrix.
  ```cpp
  mat.transpose();
  ```
- `double determinant()`: Computes determinant.
  ```cpp
  double det = mat.determinant();
  ```
- `void resize(int row, int col)`: Resizes the matrix.
  ```cpp
  mat.resize(4, 4);
  ```
- `void swapRows(int row1, int row2)`: Swaps two rows.
  ```cpp
  mat.swapRows(0, 1);
  ```
- `void swapColumns(int col1, int col2)`: Swaps two columns.
  ```cpp
  mat.swapColumns(0, 1);
  ```
- `void invert()`: Computes the inverse of the matrix.
  ```cpp
  mat.invert();
  ```
- `double trace()`: Computes trace of the matrix.
  ```cpp
  double tr = mat.trace();
  ```
- `int rank()`: Computes the rank of the matrix.
  ```cpp
  int r = mat.rank();
  ```
- `vector<double> getEigenValues()`: Returns eigenvalues.
  ```cpp
  vector<double> eigenvalues = mat.getEigenValues();
  ```

## Utility Functions (Defined in `MatrixUtils.cpp`)
- `void verifyEqualDimension(Matrix& m1, Matrix& m2)`: Ensures matrices have the same dimensions.
  ```cpp
  verifyEqualDimension(mat1, mat2);
  ```
- `void verifySquareMatrix(Matrix& m1)`: Ensures a matrix is square.
  ```cpp
  verifySquareMatrix(mat);
  ```
- `void setMinorMatrix(Matrix& m, int row, int col, Matrix& minorMatrix)`: Creates a minor matrix.
  ```cpp
  setMinorMatrix(mat, 1, 1, minorMat);
  ```
- `double getDeterminant(int size, Matrix& m)`: Computes determinant.
  ```cpp
  double det = getDeterminant(3, mat);
  ```
- `Matrix createIdentityMatrix(int n)`: Returns an identity matrix.
  ```cpp
  Matrix identity = createIdentityMatrix(3);
  ```
- `void reduceToREF(Matrix& m)`: Converts to Row Echelon Form (REF).
  ```cpp
  reduceToREF(mat);
  ```
- `bool verifyDiagonalMatrix(Matrix m)`: Checks if a matrix is diagonal.
  ```cpp
  bool isDiagonal = verifyDiagonalMatrix(mat);
  ```
- `double getNormOfCol(Matrix m, int col)`: Computes the norm of a column.
  ```cpp
  double norm = getNormOfCol(mat, 1);
  ```
- `void gramSchmidt(Matrix m, Matrix& result)`: Applies Gram-Schmidt orthogonalization.
  ```cpp
  gramSchmidt(mat, result);
  ```

## License
This project is open-source and free to use.

## Todo

### Basic Operations:
- [x] Implement matrix creation (e.g., from an array or zeros)
- [x] Implement matrix printing (output in a readable format)
- [x] Implement matrix addition (element-wise)
- [x] Implement matrix subtraction (element-wise)
- [x] Implement matrix scalar multiplication (multiply each element by a constant)
- [x] Implement matrix scalar division (divide each element by a constant)
- [x] Implement matrix transposition (swap rows and columns)
- [x] Implement matrix equality check (compare if two matrices are equal)
- [x] Implement matrix resizing (expand or shrink the matrix)
- [x] Implement matrix determinant calculation (for small square matrices, e.g., 2x2 and 3x3)

### Intermediate Operations:
- [x] Implement matrix multiplication (standard matrix product)
- [x] Implement matrix inversion (for invertible square matrices)
- [x] Implement matrix rank (using Gaussian elimination or similar techniques)
- [x] Implement matrix trace (sum of diagonal elements)
- [x] Implement matrix diagonalization (for certain square matrices)
- [x] Implement matrix identity creation (returning an identity matrix of size n)
- [x] Implement matrix row and column operations (e.g., swapping rows/columns, scaling rows/columns)
- [x] Implement Matrix eigen values (for smaller square matrix such as 2 , 3, 4)
