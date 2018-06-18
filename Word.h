#ifndef WORD_H
#define WORD_H

#include <string>

class Word
{
	public:
		Word(std::string word = "", int min_edit_dist = 0, int frequency = 1, double probability = 0);

		//getters
		std::string get_word();
		int get_freq();
		double get_probability();

		//modifiers
		void increment_freq();
		void calc_probability(); //we need this function because
		//we don't want to calculate the probability for all
		//words; just the ones that are close in min_edit_dist
		//to the desired word


	private:
		std::string word;
		int min_edit_dist;
		int frequency;
		double probability;
};





#endif
