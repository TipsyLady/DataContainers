#include <iostream>
using namespace std;

void elevator(int level)
{
	if (level == 0) return;
	cout << level << endl;
	elevator(level - 1); //����������� �����
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
//main(); //����������� ����� ������� main
	int n;
	cout << "������� ����� �����: "; cin >> n;
	elevator(n);
#endif // RECURSION_BASICS

#ifdef FACTORIAL
	int n;
	cout << "������� ����� ��� ���������� ����������: "; cin >> n;
	cout << "��������� ����� " << n << " �����: " << factorial(n);
#endif // FACTORIAL

	int n;
	int a;
	cout << "������� ��������� �������: " << endl; cin >> a;
	cout << "������� ������� �����: " << endl; cin >> n;
	cout << "����� " << a << " � ������� " << n << " ����� " << power(a, n) << endl;

	main();
}