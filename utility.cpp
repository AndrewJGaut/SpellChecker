#include <algorithm>
#include <iostream>
#include "utility.h"

int min(int a, int b, int c)
{
	if(a < b && a <= c)
	{
		return a;
	}
	if(b < a && b <= c)
	{
		return b;
	}
	if(c < a && c <= b)
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
