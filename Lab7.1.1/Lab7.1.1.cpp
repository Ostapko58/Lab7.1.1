#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void CalcAndReplace(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -8;
	int High = 42;
	const int rowCount = 8;
	const int colCount = 7;
	int a[rowCount][colCount];
	int* pa[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		pa[i] = a[i];
	}

	Create(pa, rowCount, colCount, Low, High);
	Print(pa, rowCount, colCount);
	int S = 0;
	int k = 0;
	CalcAndReplace(pa, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(pa, rowCount, colCount);

	return 0;

}

void Create(int *a[], const int rowCount, const int colCount, const int Low,const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int *a[], const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void CalcAndReplace(int* a[],const int rowCount,const int colCount,int&S,int&k)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			if (a[i][j] > 0 || !(i % 2 == 0 && j % 2 == 0))
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
		}
	}
}