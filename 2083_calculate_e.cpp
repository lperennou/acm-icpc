#include <iostream>

using namespace std;

int fact(int n)
{
	if (n==0)
		return 1;
	else
		return n*fact(n-1);
}

double exp(int n)
{
	if(n==0)
		return 1.0/fact(n);
	else
		return 1.0/fact(n)+exp(n-1);
}

int main()
{
	int i;
	cout << "n e" << endl;
	cout << "- -----------" << endl;
	//cout << fixed;
	cout.precision(10);
	for(i=0; i<10; i++)
		cout << i << " " << exp(i) << endl;
	return 0;
}