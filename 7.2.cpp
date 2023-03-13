#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

void CreateRows(int** a, const int n, int Low, int High, int rowNo);
void CreateRow(int** a, const int rowNo, const int n, int Low, int High, int colNo);
void PrintRows(int** a, const int n, int rowNo);
void PrintRow(int** a, const int rowNo, const int n, int colNo);
void Sort(int** a, const int n, int index);
void Change(int** a, const int row1, const int row2, const int n);

int main()
{
	srand((unsigned)time(NULL));

	int Low = 16;
	int High = 100;

	int n = 4;

	int **a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	CreateRows(a, n, Low, High, 0);
	PrintRows(a, n, 0);
	Sort(a, n, 0);
	PrintRows(a, n, 0);

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void CreateRows(int** a, const int n, int Low, int High, int rowNo)
{
		CreateRow(a, rowNo, n, Low, High,0);
		if (rowNo < n - 1)
			CreateRows(a, n, Low, High, rowNo + 1);
}
void CreateRow(int** a, const int rowNo, const int n, int Low, int High,int colNo)
{
		a[rowNo][colNo] = Low * rand() % (High - Low + 1);
		if (colNo < n - 1)
			CreateRow(a, rowNo, n, Low, High, colNo + 1);
}
void PrintRows(int** a, const int n, int rowNo)
{
	PrintRow(a, rowNo, n, 0);
	if (rowNo < n - 1)
		PrintRows(a,n, rowNo + 1);
	else
		cout << endl;

}
void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < n - 1)
		PrintRow(a, rowNo, n, colNo + 1);
	else
		cout << endl;
}

void Sort(int** a, const int n, int index)
{
	if (index == n - 1)
	{
		return;
	}

	if ((a[index][index] < a[index + 1][index + 1]))
	{
		Change(a, index, index + 1, n);
	}
	else
	{
		Sort(a, n, index + 1);
		return;
	}

	Sort(a, n, 0);
}


void Change(int** a, const int row1, const int row2, const int n)
{
	int tmp;
	tmp = a[row1][row1];
	a[row1][row1] = a[row2][row2];
	a[row2][row2] = tmp;

}
