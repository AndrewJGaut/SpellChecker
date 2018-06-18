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

std::vector<string> find_close_words(std::string str)
{
	ifstream dict("dictionary.txt");
	vector<string> words;
	string line;
	getline(dict, line);
	while(line.length() > 0 && getline(dict, line))
	{
		line = line.substr(0, line.length()-1);
		int dist = min_edit_dist(str, line);
		if(line == "assert/r")
		{
			int y = 6;
		}
		if(dist == 0)
		{
			//the word isn't mispelled
			return vector<string>();
		}
		if(dist <= 1)
		{
			//it might be what the misspelled word should be
			//so, add it to our words vector
			words.push_back(line);

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

void populate_table(std::unordered_map<std::string, Word>& table, std::string filename)
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
			Word w = Word(curr);
			table.insert(pair<string,Word>(curr, w));
		}
		else
		{
			table[curr].increment_freq();
		}
	}
	file.close();

}
















