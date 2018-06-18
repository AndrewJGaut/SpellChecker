#include <fstream>
#include <cctype>
#include <string>
#include <unordered_map> //hashtable
#include <utility> //for pair, for hashtable
#include "Word.h"
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/map.hpp>

using namespace std;

int main()
{
	string filename = "big.txt";
	string curr;
	char c;
	unordered_map<string, Word> words;

	ifstream file(filename);

	//Read in the file and add to the hashtable as we go
	//if the word is already in the table, the just 
	//incrememnt its frequency
	//if the word isn't already in the table, then add
	//it with a frequency of 1
	while(!file.eof())
	{
		curr = "";
		while(file.get(c) && isalpha(c))
		{
			curr += c;
		}
		if(words.find(curr) != words.end())
		{
			Word w = Word(curr);
			words.insert(pair<string,Word>(curr, w));
		}
		else
		{
			words[curr].increment_freq();
		}
	}
	file.close();



	//Serialize the hashtable
	//use Boost api
	ofstream outfile("serialized_frequencies.dat");
	boost::archive::binary_oarchive bin_arch(outfile);
	bin_arch << words;
	outfile.close();


}













