#include <iostream>
using namespace std; 

int main() {
	srand(0);
	int A[4][4];
	int B[4][4];
	int C[4];
	int min = 10000000;
	int p=0, m=0, m_j = 0;
	cout << "input the matrix (4x4): " << endl;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			A[i][j] = rand() %300;
		} 
	}

	cout << "inital matrix" << endl;
	for (int i = 0; i < 4; ++i) {
		min = A[i][0];
		for (int j = 0; j < 4; ++j) {
			cout << A[i][j] << " ";
			p = A[i][0];
			B[i][j] = A[i][j];
			if (min > A[i][j]) {
				min = A[i][j];
				m_j = j;
			}
		}
		C[i] =  m_j;
		B[i][0] = min;
		B[i][m_j] = p;
		cout << endl;
	}

	cout << "transformed matrix: " << endl;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 4; ++i) {
		cout << "element adress: " << &A[i][C[i]] << endl;
	}

	return 0;
}