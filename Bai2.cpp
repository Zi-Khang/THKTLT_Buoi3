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

int main() {
	int n = 5, minVal = 0, maxVal = 10;
	int a[MAX][MAX];

	//1
	cout << "Tao va xuat ma tran vuong ngau nhien: " << endl;
	taoXuatMaTranVuong(a, n, minVal, maxVal);


	getch();
}