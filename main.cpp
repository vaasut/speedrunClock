#include <iostream>
#include <thread> 
#include <chrono>
#include <ctime>

#include "timerFunctions.cpp"
#include "printSeconds.cpp"
#include "splitFileFunctions.cpp"

int main() {
    std::clock_t start;
    std::string filename;
    start = std::clock();
    double finalTime;

    std::thread first (splitOrEnd);
    std::thread second (speedTimer);

    std::cout << "Start Run! \n";

    // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();             // pauses until second finishes

    finalTime = (double) (std::clock() - start)/ (double) CLOCKS_PER_SEC;
    printSeconds((int) finalTime);
    std::cout << "Enter a file name for your splits.\n";
    std::cin >> filename;
    saveSplits(mySplits,finalTime,filename);
    return 0;
}