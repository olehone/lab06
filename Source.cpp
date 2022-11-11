#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* &a, const int size, const int Low, const int High, int i)
{
	if (i == 0)
		a = new int[size];
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);

}
void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int Find1(int* a, const int size, int i)
{
	if (a[i] == 0)
		return i;
	if (i < size - 1)
		return Find1(a, size, i + 1);
	else
		return -1;
}
int Find2(int* a, const int size, int i)
{
	if (a[i] == 0)
		return i;
	if (i >= 0)
		return Find2(a, size, i -1);
	else
		return -1;
}
int Prod(int* a, const int size, int i, int prd)
{
	if (i % 2 == 0 && i != 0)
		prd *= a[i];
	if (i < size - 1)
		return Prod(a, size, i + 1, prd);
	else
		return prd;
	}
int Sum(int* a, const int size, int i, int S)
{
	if (i <= Find2(a, size, size)&& i >= Find1(a, size, 0))
		S += a[i];
	if (i < size - 1)
		return Sum(a, size, i + 1, S);
	else
		return S;
}
void Sort(int* a, const int size, int i, int j) // метод обміну (бульбашки)
{
	if (a[j] < a[j + 1]) // якщо порушено порядок
	{ // - обмін елементів місцями
		int tmp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = tmp;
	}
	if (j < size - i - 1) // j - номер поточного елемента
		Sort(a, size, i, j + 1); // перехід до наступного елемента

	if (i < size - 1) // i - лічильник ітерацій
		Sort(a, size, i + 1, 0); // перехід до наступної ітерації
}
int main()
{
	int n;
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	cout << "n = ";
	cin >> n;
	cout << endl;
	int* a;
	int Low = -10;
	int High = 10;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "Product = " << Prod(a, n, 0, 1) << endl;
	if (Find1(a, n, 0) == -1 || Find2(a, n, n) == -1)
		cout << "There are no two zeros in the array, Sum = 0" << endl;
	else
		cout << "Sum = " << Sum(a, n, 0, 0) << endl;
	Sort(a, n, 1, 0);
	Print(a, n, 0);
	delete[] a;
	return 0;
}