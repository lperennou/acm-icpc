#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int tests, n , last_line, i, j, k,car;
	vector <int> waiting;
	std::vector<int> cars;
	cin >> tests;
	for(i=0; i<tests; i++)
	{
		waiting.clear();
		cars.clear();
		last_line=0;
		cin >> n;

		for(j=0; j<n; j++)
		{
			cin >> car;
			cars.push_back(car);
		}

		#ifdef TEST 
			cout << "test " << i << " : ";
			for(j=n-1; j>=0; j--)
				cout << cars[j];
			cout << endl;
		#endif

		for(j=0; j<n; j++)
		{
			car=cars[j];
			if(car == (last_line+1))
			{
				last_line=car;
				#ifdef TEST 
					cout << "car " << last_line << " in line" << endl;
				#endif
				while(!waiting.empty())
				{
					if(waiting[0] == (last_line+1))
					{
						last_line+=1;
						waiting.erase(waiting.begin());
						#ifdef TEST 
							cout << "car " << last_line << " in line" << endl;
						#endif
					}
					else
						break;
				}
			}
			else if(waiting.empty())
			{
				waiting.push_back(car);
				#ifdef TEST 
					cout << "car " << car << " in intersection" << endl;
				#endif
			}
			else if(car > waiting[waiting.size()-1])
			{
				waiting.push_back(car);
				#ifdef TEST 
					cout << "car " << car << " in intersection" << endl;
				#endif

			}
			else
			{
				cout << "NO" << endl;
				break;
			}
		}
		if((j==n) && (waiting.empty()))
			cout << "YES" << endl;

	}
	return 0;
}