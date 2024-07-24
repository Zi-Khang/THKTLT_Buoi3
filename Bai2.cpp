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

//4.
int timPTMaxTamGiacTrenDCC(int a[MAX][MAX], int n) {
	int maxVal = a[0][0];
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (a[i][j] > maxVal) {
				maxVal = a[i][j];
			}
		}
	}
	return maxVal;
}

//6. 
void sapXepDCCTang(int a[MAX][MAX], int n) {
	int temp[MAX];
	for (int i = 0; i < n; ++i) {
		temp[i] = a[i][i];
	}

	sort(temp, temp + n);

	for (int i = 0; i < n; ++i) {
		a[i][i] = temp[i];
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

	//4
	int Max = timPTMaxTamGiacTrenDCC(a, n);
	cout << "Phan tu Max thuoc tam giac tren DCC: " << Max << endl;

	//6
	sapXepDCCTang(a, n);
	cout << "Sap xep duong cheo chinh tang dan tu tren xuong: " << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	getch();
}