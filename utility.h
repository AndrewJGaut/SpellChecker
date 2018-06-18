
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

std::vector<std::string> find_close_words(std::string str);

void populate_table(std::unordered_map<std::string, Word>& table, std::string filename);

//void sorted_vector_insert(std::vector<string>& v, int val);

//void print_mat(int mat[][NUM_COLS], const int NUM_ROWS, const int NUM_COLS);

#endif
