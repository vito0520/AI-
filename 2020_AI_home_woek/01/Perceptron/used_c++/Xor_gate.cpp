#include <iostream>
using namespace std;
const int n = 2;
const int n1 = 1;
void array_multiplication(float arr[], float arr2[], float arr3[], int n);
int  OR(float arr[], int arrayn, float n);
int  AND(float arr[], int arrayn, float n);
int  NAND(float arr[], int arrayn, float n);
int main()
{
	int Nand,Or,Xor;
	float bias = -0.7;
	float orBias = -0.2;
	float a[n] = { 0.5,0.5 };
	float b[n] = { 1,1}; 

	float c[n1] = { 0 }; //space
	float c2[n1] = { 0 };//space


	array_multiplication(a, b, c, n);
	Nand = NAND(c, n1, bias);
	Or = OR(c, n1, orBias);
	//cout << Nand << "," << Or << endl;

	float d[n] = {Nand,Or};


	array_multiplication(a, d, c2, n);


	Xor = AND(c2, n1, bias);
	cout << Xor << endl;

}
void array_multiplication(float arr[], float arr2[], float arr3[], int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr3[i] += arr[i] * arr2[j];
}
int AND(float arr[], int arrayn, float n)
{
	float tmp = 0;
	for (int i = 0; i < arrayn; i++)
		tmp = arr[i] +n;

	if (tmp <= 0)
		return 0;
	else
		return 1;
}
int OR(float arr[], int arrayn, float n)
{
	float tmp = 0;
	for (int i = 0; i < arrayn; i++)
		tmp = arr[i] + n;

	if (tmp <= 0)
		return 0;
	else
		return 1;
}
int NAND(float arr[], int arrayn, float n)
{
	float tmp = 0;
	for (int i = 0; i < arrayn; i++)
		tmp = arr[i] + n;

	if (tmp <= 0)
		return 1;
	else
		return 0;
}
