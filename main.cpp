#include "utility.h"
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	//make a hashtable that will hold the probability values
	//for all strings; then, we can search the table for string 
	//that are close enough in min_edit_dist to qualify
	//as candidates for the correct spelling of the word
	unordered_map<string,int> table;
	populate_table(table, "big.txt");

}
