#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <conio.h>

using namespace std;

const int MAX = 100;

//1
void taoXuatMaTranVuong(int a[MAX][MAX], int n, int minVal, int maxVal) {
	srand(time(0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = minVal + rand() % (maxVal - minVal + 1);
		}
	}

	//Xuat ma tran
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

//2.
void xuatPTDCC(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i][i] << " ";
	}
	cout << endl;
}

//3
void xuatPTSSDCC(int a[MAX][MAX], int n) {
	//Tren
	for (int k = 1; k < n; ++k) {
		for (int i = 0, j = k; j < n; ++i, ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	//Duoi
	for (int k = 1; k < n; ++k) {
		for (int i = k, j = 0; i < n; ++i, ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n = 5, minVal = 0, maxVal = 10;
	int a[MAX][MAX];

	//1
	cout << "Tao va xuat ma tran vuong ngau nhien: " << endl;
	taoXuatMaTranVuong(a, n, minVal, maxVal);

	//2
	cout << "Cac phan tu tren duong cheo chinh: ";
	xuatPTDCC(a, n);

	//3
	cout << "\nCac phan tu thuoc duong cheo song song voi duong cheo chinh: " << endl;
	xuatPTSSDCC(a, n);

	getch();
}