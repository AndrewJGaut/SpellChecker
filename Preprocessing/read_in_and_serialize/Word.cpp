#include "Word.h"


Word::Word(std::string word, int frequency)
{
	this->word = word;
	this->frequency = frequency;
}

std::string Word::get_word()
{
	return word;
}

int Word::get_freq()
{
	return frequency;
}

void Word::increment_freq()
{
	frequency++;
}

void serialize(Archive& ar, const unsigned int version)
{
	ar << word;
	ar << " ";
	arr << to_string(frequency);
}
