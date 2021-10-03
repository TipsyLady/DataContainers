#include <iostream>
using namespace std;

void elevator(int level)
{
	if (level == 0) return;
	cout << level << endl;
	elevator(level - 1); //рекурсивный вызов
	cout << level << endl;

}
int factorial(int Data)
{
	/*if (Data == 0)return 1;
	return Data * factorial(Data - 1);*/
	return Data == 0 ? 1 : Data * factorial(Data - 1);
}

double power(double a, int n)
{
	/*if (n == 0) return 1;*/
	return n == 0 ? 1 : n > 0 ? a * power(a, n - 1) : 1 / a * power(a, n + 1);
}

//#define RECURSION_BASICS
//#define FACTORIAL
#define POWER
void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef RECURSION_BASICS
	//cout << "Hello, world! ";
//main(); //рекурсивный вызов функции main
	int n;
	cout << "¬ведите номер этажа: "; cin >> n;
	elevator(n);
#endif // RECURSION_BASICS

#ifdef FACTORIAL
	int n;
	cout << "¬ведите число дл€ вычислени€ факториала: "; cin >> n;
	cout << "‘акториал числа " << n << " равен: " << factorial(n);
#endif // FACTORIAL

	int n;
	int a;
	cout << "¬ведите основание степени: " << endl; cin >> a;
	cout << "¬ведите степень числа: " << endl; cin >> n;
	cout << "„исло " << a << " в степени " << n << " равно " << power(a, n) << endl;

	main();
}