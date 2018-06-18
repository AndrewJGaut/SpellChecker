#include "utility.h"
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
	//make a hashtable that will hold the probability values
	//for all strings; then, we can search the table for string 
	//that are close enough in min_edit_dist to qualify
	//as candidates for the correct spelling of the word
	unordered_map<string,int> table;
	populate_table(table, "big.txt");

	//put the dictionary into a hashset for fast lookup
	unordered_set<string> dict;
	hash_dict(dict,"dictionary.txt");


	//now, read in the test file and output the 
	//correct spelling of misspelled words
	string filename = "file_with_errors.txt";
	ifstream file(filename);

	string curr_word;
	char c;
	while(!file.eof())
	{
		//get the next string in the file
		while(file.get(c) && isalpha(c))
		{
			curr_word += c;
		}

		//now, check if it's misspelled
		if(misspelled(curr_word, dict))
		{
			//if it is, then find the correct word
			vector<Word> close_words = find_close_words(dict, curr_word);
			string correction = get_maximally_probable_word(curr_word, dict, close_words, table);
			cout << "The word " << correction << " was"
			     << " misspelled as: " << curr_word
			     << endl;

		}

		//reset curr_word
		curr_word = "";



		
	}
}
