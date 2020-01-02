#include <iostream>
#include <fstream>

using namespace std;

void saveSplits (std::string splits) {
	std::string filename;
	std::cout << "Enter a file name for your splits.\n";
	std::cin >> filename;
	filename.append(".splits");
	ofstream myfile;
	myfile.open (filename);
	myfile << "Splits.\n";
	myfile << splits;
	myfile.close();
}

void readSplitNames (){
	
}