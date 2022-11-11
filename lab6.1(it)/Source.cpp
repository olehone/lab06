#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}
void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}
int Sum(int* a, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if (a[i] < 0 || a[i] % 2 == 1)
		{
			S += a[i];
		}
	return S;
}
int Substitute(int* a, const int size)
{
	int number = 0;
	for (int i = 0; i < size; i++)
		if (a[i] < 0 || a[i] % 2 == 1)
		{
			a[i] = 0;
			number++;
		}
	return number;
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 24;
	int a[n];
	int Low = -50;
	int High = 15;
	Create(a, n, Low, High);
	Print(a, n);
	cout << "S =" << Sum(a, n) << endl;
	cout << "Number =" << Substitute(a, n) << endl;
	Print(a, n);
	return 0;
}
