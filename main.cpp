#include "utility.h"
#include <iostream>
using namespace std;

int main()
{
	//min_edit_dist("azced", "abcdef");
	//cout << min_edit_dist("azced", "abcdef") << endl; 

	vector<string> words = find_close_words("assrt");
	for(int i = 0; i < words.size(); i++)
	{
		cout << words[i] << endl;
	}
}
