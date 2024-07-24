#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <conio.h>
using namespace std;

const int MAX = 100;

//1
void hamTaoVaXuatMaTran(int a[MAX][MAX], int m, int n, int minVal, int maxVal) {
	//Tao ma tran
	srand(time(0));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = minVal + rand() % (maxVal - minVal + 1);
		}
	}

	//Xuat ma tran
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

//2
void tongGTTungDong(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += a[i][j];
		}
		cout << "Dong " << i << ": " << sum << "\n";
	}
	cout << endl;
}

//3
void maxOfColumns(int a[MAX][MAX], int m, int n) {
	for (int j = 0; j < n; j++) {
		int maxVal = a[0][j];
		for (int i = 1; i < m; i++) {
			if (a[i][j] > maxVal) {
				maxVal = a[i][j];
			}
		}
		cout << "Cot " << j << ": " << maxVal << "\n";
	}
	cout << endl;
}

//4
void xuatPTDuongBien(int a[MAX][MAX], int m, int n) {
	//Tren
	cout << "Duong bien tren: " << endl;
	for (int j = 0; j < n; ++j) {
		cout << a[0][j] << " ";
	}
	cout << endl;

	//Duoi
	cout << "Duong bien duoi: " << endl;
	for (int j = 0; j < n; ++j) {
		cout << a[m - 1][j] << " ";
	}
	cout << endl;

	//Trai
	cout << "Duong bien ben trai: " << endl;
	for (int i = 0; i < m; ++i) {
		cout << a[i][0] << " ";
	}
	cout << endl;

	//Phai
	cout << "Duong bien ben phai: " << endl;
	for (int i = 0; i < m; ++i) {
		cout << a[i][n - 1] << " ";
	}
	cout << endl;
}

//5
void xuatPTCucDai(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			bool isLocalMax = true;
			for (int k = -1; k <= 1; k++) {
				for (int l = -1; l <= 1; l++) {
					if (k == 0 && l == 0)
						continue;
					int ni = i + k, nj = j + l;
					if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[ni][nj] >= a[i][j]) {
						isLocalMax = false;
						break;
					}
				}
				if (!isLocalMax)
					break;
			}
			if (isLocalMax)
				cout << a[i][j] << " ";
		}
	}
	cout << endl;
}
int main() {
	int m = 5, n = 5, minVal = 0, maxVal = 10;
	int a[MAX][MAX];

	//Bai1
	cout << "Tao va xuat cac phan tu ma tran ngau nhien: " << endl;
	hamTaoVaXuatMaTran(a, m, n, minVal, maxVal);

	//Bai2
	cout << "\nTinh va xuat tong gia tri tung dong: \n";
	tongGTTungDong(a, m, n);

	//Bai3
	cout << "Xuat phan tu lon nhat tren tung cot: \n";
	maxOfColumns(a, m, n);

	//Bai4
	cout << "Xuat cac phan tu thuoc cac duong bien: " << endl;
	xuatPTDuongBien(a, m, n);

	//Bai5
	cout << "\nCac phan tu cuc dai: ";
	xuatPTCucDai(a, m, n);

	getch();
}