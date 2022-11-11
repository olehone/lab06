#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* &a, const int size, const int Low, const int High)
{
	a = new int[size];
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}
void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}
int Find1(int*a, const int size)
{
	for (int i = 0; i < size; i++)
		if (a[i] == 0)
			return i;
	return -1;
}
int Find2(int* a, const int size)
{
	for (int i = size - 1; i >= 0; i--)
		if (a[i] == 0)
			return i;
	return -1;
}
int Prod(int* a, const int size)
{
	int p = 1;
	for (int i = 0; i < size; i++)
		if (i % 2 == 0&&i != 0)
		{
			p *= a[i];
		}
	return p;
}
int Sum(int* a, const int size)
{
	int start = Find1(a, size);
	int finish = Find2(a, size);
	int S = 0;
	for (int i = start; i < finish; i++)
		{
			S += a[i];
		}
	return S;
}
void Sort(int* a, const int size) // ����� ������
{
	for (int i = 0; i < size - 1; i++) // ������ ������� �������������� �������
	{
		int max = a[i]; // ����� ���������� �������� 
		int imax = i; // �������������� �������
		for (int j = i + 1; j < size; j++)
			if (max < a[j])
			{
				max = a[j];
				imax = j;
			}
		a[imax] = a[i]; // ���� ������ ���������� �� �������
		a[i] = max; // �������� �������������� �������
	}
}
int main()
{
	int n = 100;
	srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����
	cout << "n = "; 
	cin >> n;
	cout << endl;
	int* a;
	int Low = -5;
	int High = 5;
	Create(a, n, Low, High);
	Print(a, n);
	cout << "Product = " << Prod(a, n) << endl;
	if (Find1(a, n) == -1 || Find2(a, n) == -1)
		cout << "There are no two zeros in the array, Sum = 0" << endl;
	else
		cout << "Sum = " << Sum(a, n) << endl;
	Sort(a, n);
	Print(a, n);
	delete[] a;
	return 0;
}