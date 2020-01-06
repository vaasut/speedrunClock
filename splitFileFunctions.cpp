#include <iostream>
#include <fstream>

using namespace std;

void saveSplits (std::string splits,double finalTime, std::string filename) { // saves splits to file
	filename.append(".splits");
	ofstream myfile;
	myfile.open (filename);
	myfile << "Splits.\n";
	myfile << splits;
	myfile << "Final Time: ";
	myfile << finalTime;
	myfile.close();
}