#include "utility.h"
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	vector<string> words = find_close_words("dadd");
	//DEBUGGING
	for(int i = 0; i < words.size(); i++)
	{
		cout << words[i] << endl;
	}

	//make a hashtable that will hold the probability values
	//for all strings; then, we can search the table for string 
	//that are close enough in min_edit_dist to qualify
	//as candidates for the correct spelling of the word
	unordered_map<string,Word> table;
	populate_table(table, "big.txt");

	//here, loop through words vector and find word with
	//highest probability to make guess
	double max_probability = -1;
	string max_prob_word = "";
	for(int i = 0; i < words.size(); i++)
	{
	}
	

}
