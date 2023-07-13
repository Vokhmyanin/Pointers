#include<iostream>
using namespace std;
//#define POINTER_BASICS
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTER_BASICS
	int a = 2;
	int* pa = &a; //pointer to "a"
	cout << a << endl; //вывод значения переменной "а" на экран
	cout << &a << endl;// взятие адреса переменной "а" прямо при выводе
	cout << pa << endl;//вывод адреса переменной "а" , хранящегося в указателе "ра"
	cout << *pa << endl; //разименовываем указатель "ра" и получаем значение переменной "a"

	int* pb;
	int b = 3;
	pb = &b;
	cout << *pb << endl;
#endif

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}