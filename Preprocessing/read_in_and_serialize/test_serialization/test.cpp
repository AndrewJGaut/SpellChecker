#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/map.hpp>
#include <fstream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
	//unordered_map<int, int> words;
	map<int, int> words;
	words[1] = 5;
	words[2] = 6;
	
	ofstream outfile("serialized_frequencies.dat");
	boost::archive::binary_oarchive bin_arch(outfile);
	bin_arch << words;
}
