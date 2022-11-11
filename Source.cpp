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
int Substitute(int* a, const int size)
{
	int number = 0;
	for (int i = 0; i < size; i++)
		if (a[i] % 2 == 1|| a[i] % 2 == -1)
		{
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
	cout << "Number =" << Substitute(a, n) << endl;
	return 0;
}