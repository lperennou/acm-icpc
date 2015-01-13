#include <iostream>
#include <map>

using namespace std;

void permute( int & x1, int & y1, int & x2, int & y2)
{
	int tmp;
	if(x2 < x1)
	{
		tmp=x2;
		x2=x1;
		x1=tmp;
	}
	if(y2 < y1)
	{
		tmp=y2;
		y2=y1;
		y1=tmp;	
	}
}

int main()
{
	int n,c,i,color,x1,y1,x2,y2,j,k,count, dataset=0;
	int table[201][201];
	while(cin >> n)
	{
		if(n==0)
			break;
		dataset++;
		cin >> c;
		for(j=-100; j<100; j++)
			for(k=-100; k<100; k++)
				table[j+100][k+100]=-1;
		count=0;
		for(i=0; i<n; i++){
			cin >> color;
			cin >> x1;
			cin >> y1;
			cin >> x2;
			cin >> y2;
			permute(x1, y1, x2, y2);
			for(j=x1; j<x2; j++)
				for(k=y1; k<y2; k++)
					table[j+100][k+100]=color;
		}
		for(j=-100; j<100; j++)
			for(k=-100; k<100; k++)
				if(table[j+100][k+100]==c)
					count++;
		cout << "The area of color " << c <<" in dataset " << dataset << " is: " << count << endl;
	}
}