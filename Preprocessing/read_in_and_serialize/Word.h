#ifndef WORD_H
#define WORD_H

#include <string>
#include <boost/archive/tmpdir.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/string.hpp> 

class Word
{
	public:
		Word(std::string word = "", int frequency = 1);

		//getters
		std::string get_word();
		int get_freq();

		//modifiers
		void increment_freq();

		//for serialization of words hashtable in seralizer.cpp
		void serialize(Archive& ar, const unsigned int version);

	private:
		std::string word;
		int frequency;
};





#endif
