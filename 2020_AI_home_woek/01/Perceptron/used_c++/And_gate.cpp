#include <iostream>
using namespace std;
const int n = 2;
const int n1 = 1;
void array_multiplication(float arr[], float arr2[], float arr3[], int n);
int  AND(float arr[], int arrayn, float n);
int main()
{
	int And;
	float bias = -0.7;
	float a[n] = { 0.5,0.5 };
	float b[n] = { 1,1 };
	float c[n1] = { 0 };

	array_multiplication(a, b, c, n);
	And = AND(c, n1, bias);
	cout << And << endl;

}
void array_multiplication(float arr[], float arr2[], float arr3[], int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr3[i] += (arr[i] * arr2[j]);
}
int AND(float arr[], int arrayn, float n)
{
	float tmp = 0;
	for (int i = 0; i < arrayn; i++)
		tmp = arr[i] + n;

	if (tmp <= 0)
		return 0;
	else
		return 1;
}
