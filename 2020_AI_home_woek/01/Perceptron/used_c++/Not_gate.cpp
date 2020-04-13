#include <iostream>
using namespace std;
const int n = 2;
const int n1 = 1;
void array_multiplication(float arr[], float arr2[], float arr3[], int n);
int  NOT(float arr[], int arrayn);
int main()
{
	int Not;
	float a[n] = { 0.5,0.5 };
	float b[n] = { 0,1 };
	float c[n1] = { 0 };

	array_multiplication(a, b, c, n);
	Not = NOT(c, n1);
	cout << Not << endl;

}
void array_multiplication(float arr[], float arr2[], float arr3[], int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr3[i] += (arr[i] * arr2[j]);
}
int NOT(float arr[], int arrayn)
{
	float tmp = 0;
	for (int i = 0; i < arrayn; i++)
		tmp = arr[i];

	if (tmp <= 0)
		return 1;
	else
		return 0;
}
