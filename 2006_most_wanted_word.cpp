#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
	string input, word, max_word;
	int i,max;
	stringstream ss;
	std::map<string, int> m;

	while(getline(cin, input, '#'))
	{
		max=0;		
		for(i=0; i<input.length(); i++)
		{
			if((input[i]<'A') || ((input[i]>'Z') && (input[i]<'a')) || (input[i]>'z'))
				input[i]=' ';
			else
				if((input[i]>='A') && (input[i]<='Z'))
					input[i]+=32;
		}
		ss.clear (); 	//clears internal state (error flags)
		ss.str ("");	//clears string associated wisth ss
		ss << input;	//associates a string to ss
		while(ss >> word)
		{
			m[word]++;
			if(m[word]>max)
			{
				max=m[word];
				max_word=word;
			}
		}
		if(max==0)
			break;

		cout << right << setw(4) << max << " " << max_word << endl;
		m.clear();		
	}
	return 0;	
} 
