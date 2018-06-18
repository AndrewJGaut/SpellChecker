#include "Word.h"

Word::Word(std::string word, int min_edit_dist, int frequency, double probability)
{
	this->word = word;
	this->min_edit_dist = min_edit_dist;
	this->frequency = frequency;
	this->probability = probability;
}

std::string Word::get_word()
{
	return word;
}

int Word::get_freq()
{
	return frequency;
}

double Word::get_probability()
{
	return probability;
}

void Word::increment_freq()
{
	frequency++;
}

void Word::calc_probability()
{
	if(min_edit_dist == 0)
	{
		probability =100;
	}
	else
	{
		probability = (frequency/min_edit_dist);
	}
}
