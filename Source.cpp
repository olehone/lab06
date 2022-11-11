#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];;
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int Sum(int* a, const int size, int i)
{
	if (i < size)
	{
		if (a[i] < 0 || a[i] % 2 == 1)
		{
			return a[i] + Sum(a, size, i + 1);

		}
		else
			return Sum(a, size, i + 1);
	}
	else
	{
		return 0;
	}
}
int Substitute(int* a, const int size, int i, int number)
{
	if (i < size)
	{
		if (a[i] < 0 || a[i] % 2 == 1)
		{
			a[i] = 0;
			return Substitute(a, size, i + 1, number + 1);

		}
		else
			return Substitute(a, size, i + 1, number);
	}
	else
	{
		return number;
	}
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 24;
	int a[n];
	int Low = -50;
	int High = 15;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "S =" << Sum(a, n, 0) << endl;
	cout << "Number =" << Substitute(a, n, 0, 0) << endl;
	Print(a, n, 0);
	return 0;
}