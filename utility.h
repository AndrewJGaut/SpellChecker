
#ifndef UTILITY_H
#define UTILITY_H 

#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include "Word.h"

//uses dynamic programming
int min_edit_dist(std::string str1, std::string str2);

int min(int a, int b, int c);

std::vector<Word> find_close_words(std::string str);

std::string get_maximally_probable_word(std::vector<Word>& words, std::unordered_map<std::string,int>& table);

void populate_table(std::unordered_map<std::string, int>& table, std::string filename);

//void sorted_vector_insert(std::vector<string>& v, int val);

//void print_mat(int mat[][NUM_COLS], const int NUM_ROWS, const int NUM_COLS);

#endif
