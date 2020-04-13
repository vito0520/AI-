#include <iostream>
using namespace std;
const int n = 2;
const int n1 = 1;
void array_multiplication(float arr[], float arr2[], float arr3[], int n);
int  NOT(float arr[], int arrayn);
int  OR(float arr[], int arrayn, float n);
int  AND(float arr[], int arrayn, float n);
int main()
{
	int s1,s2 ,s3,s4, Or, Xnor;
	float bias = -0.7;
	float orBias = -0.2;
	float a[n] = { 0.5,0.5 };
	float b[n] = {0, 1};

	float c[n1] = { 0 }; //space
	float c2[n1] = { 0 };//space
	float c3[n1] = { 0 };//space
	float c4[n1] = { 0 };//space
	array_multiplication(a, b, c, n);

	s1 = NOT(c, n1);
	s2 = NOT(c, n1);
	float d[n] = { s1,s2 };
	//for (int i = 0; i < n; i++)
		//cout << d[i] << "\t";


	array_multiplication(a, d, c2, n);
	//for (int i = 0; i < n1; i++)
		//cout << c2[i] << "\n";
	s3 = AND(c2,n1,bias);
	//cout << s3 << endl;


	array_multiplication(a, b, c3, n);
	s4 = AND(c3,n1,bias);
	//cout << s4 << endl;
	float e[n] = { s3,s4 };
	//for (int i = 0; i < n; i++)
		//cout << e[i] << endl;

	array_multiplication(a, e, c4, n);
	Xnor = OR(c4, n1, orBias);
	cout << Xnor << endl;

}
void array_multiplication(float arr[], float arr2[], float arr3[], int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr3[i] += arr[i] * arr2[j];
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
