// test.cpp: a test file for functions
#include <vector>
#include "utility.h"
#include <string>
#include <iostream>
using namespace std;


void test_min_edit_dist();

int main()
{
	test_min_edit_dist();
}


void test_min_edit_dist()
{
	int val;
	string test_str = "assert";

	vector<string> test_cases = {"assert", "assrt", "", "yes", "wiser"};
	vector<int> answers =  {0, 1, 6, 5, 3};

	for(int i = 0; i < answers.size(); i++)
	{
		val = min_edit_dist(test_str, test_cases[i]);
		if(val != answers[i])
		{
			cout << "FAILED TEST #" << i
				<< " with test_str: " << test_str
				<< " and test_case: " << test_cases[i]
				<< "; val: " << val << " != answer: " << answers[i]
				<< endl;
		}
		else
		{
			cout << "PASSED test #" << i << endl;
		}
	}

}

