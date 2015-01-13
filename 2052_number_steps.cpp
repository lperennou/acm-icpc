#include <iostream>

using namespace std;

int main(){
	int n, x, y, i;

	cin >> n;
	for(i=0; i<n; i++)
	{
		cin >> x;
		cin >> y;

		if(x==y) //upper line
		{
			if((x%2)==0)
				cout << 2*x << endl;
			else
				cout << 2*x - 1 << endl;
		}
		else if((y+2) == x) // lower line
		{
			if((x%2)==0)
				cout << 2*x - 2 << endl;
			else
				cout << 2*x - 3 << endl;
		}
		else
			cout << "No Number" << endl;
	}

}



