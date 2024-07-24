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

int main() {
	int m = 5, n = 5, minVal = 0, maxVal = 10;
	int a[MAX][MAX];

	//Bai1
	cout << "Tao va xuat cac phan tu ma tran ngau nhien: " << endl;
	hamTaoVaXuatMaTran(a, m, n, minVal, maxVal);


	getch();
}