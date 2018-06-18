#include <algorithm>
#include <fstream>
#include <iostream>
#include "utility.h"
#include "Word.h"
using namespace std;

int min(int a, int b, int c)
{
	if(a < b && a < c)
	{
		return a;
	}
	if(b < a && b < c)
	{
		return b;
	}
	if(c < a && c < b)
	{
		return c;
	}
}

int min_edit_dist(std::string str1, std::string str2)
{
	const int NUM_ROWS = str1.length()+1;
	const int NUM_COLS = str2.length()+1;
	int distances[str1.length()+1][str2.length()+1];

	//initialize the '0' column and row of the distancesrix 
	//just the number of edits needed to convert std::string to null std::string
	for(int row = 0; row < NUM_ROWS; row++)
	{
		distances[row][0] = row;
	}
	for(int col = 0; col < NUM_COLS; col++)
	{
		distances[0][col] = col;
	}

	//dynamic programming
	//memoize the values into a matrix
	//use the values already in the matrix to compute the other values
	for(int row = 1; row < NUM_ROWS; row++)
	{
		for(int col = 1; col < NUM_COLS; col++)
		{
			if(str1[row-1] == str2[col-1])
			{
				distances[row][col] = distances[row-1][col-1];
			}
			else
			{

				distances[row][col] = ( 
					min(distances[row-1][col-1],
						distances[row][col-1],
						distances[row-1][col])
					+ 1);

			}
		}
	}

	return distances[str1.length()][str2.length()];
}

//PROBLEM: NEED A WORDFREQ OBJECT TO INSERT THAT HAS WORD AND FREQUENCY
/*
void sorted_vector_insert(vector<string>& v, int val)
{
	for(int i = 0; i < v.size(); i++)
	{
		if(val <= v[i])
		{
			//sort vector
			v.push_back(-5); //garbage value
			int j = v.size()-1;
			while(j > i)
			{
				v[j] = v[j-1];
			}
			v[i] = val;
			return;
		}
	}
}*/

//put the dictionary into a hashset
void hash_dict(unordered_set<string>& dict, string filename)
{
	ifstream dict_stream(filename);

	string line;
	while(getline(dict_stream, line) && line.length() > 0)
	{
		line = line.substr(0, line.length()-1);
		dict.insert(line);
	}


}

std::vector<Word> find_close_words(const unordered_set<string>& dict, std::string str)
{
	vector<Word> words;
	unordered_set<string>::iterator i;
	for(i = dict.begin(); i != dict.end(); ++i)
	{
		int dist = min_edit_dist(str, *i);
		if(dist == 0)
		{
			//the word isn't mispelled
			return vector<Word>();
		}
		if(dist <= 2)
		{
			//it might be what the misspelled word should be
			//so, add it to our words vector
			words.push_back(Word(*i,dist));

		}

	}

	return words;
}

/*
//DEBUGGING!!
	for(int row = 0; row < NUM_ROWS; row++)
	{
		std::cout << "| ";
		for(int col = 0; col < NUM_COLS; col++)
		{
			std::cout << distances[row][col] << " ";
		}
		std::cout << std::endl;
	}
*/


string get_maximally_probable_word(std::string misspelled_word, const std::unordered_set<std::string>& dict, std::vector<Word>& words, unordered_map<string,int>& table)
{
	words = find_close_words(dict, misspelled_word);
	
	//here, loop through words vector and find word with
	//highest probability to make guess
	double max_probability = -1;
	string max_prob_word = "";
	for(int i = 0; i < words.size(); i++)
	{
		int curr_freq = table[words[i].get_word()];
		words[i].set_freq(curr_freq);
		words[i].calc_probability();
		if(words[i].get_probability() > max_probability)
		{
			max_probability = words[i].get_probability();
			max_prob_word = words[i].get_word();
		}
	}

	return max_prob_word;

}

void populate_table(std::unordered_map<std::string, int>& table, std::string filename)
{
	string curr;
	char c;

	ifstream file(filename);

	//Read in the file and add to the hashtableas we go
	//if the word is already in the table the just 
	//incrememnt its frequency
	//if the word isn't already in the table then add
	//it with a frequency of 1
	while(!file.eof())
	{
		curr = "";
		while(file.get(c) && isalpha(c))
		{
			curr += c;
		}
		if(table.find(curr) != table.end())
		{
			table.insert(pair<string,int>(curr, 1));
		}
		else
		{
			//increment the frequency
			int curr_freq = table[curr];
			table[curr] = curr_freq + 1;
		}
	}
	file.close();

}

bool misspelled(std::string str, const std::unordered_set<std::string>& dict)
{
	return (dict.find(str) != dict.end());
}
















