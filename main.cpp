#include <iostream>
#include <thread> 
#include <chrono>
#include <ctime>

#include "timerFunctions.cpp"
#include "printSeconds.cpp"
#include "splitFileFunctions.cpp"

int main() {
    std::clock_t start;
    start = std::clock();

    std::thread first (splitOrEnd);     // spawn new thread that calls foo()
    std::thread second (speedTimer);  // spawn new thread that calls bar(0)

    std::cout << "Start Run! \n";

    // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();              // pauses until second finishes

    printSeconds((double) ((std::clock() - start)/CLOCKS_PER_SEC));
    saveSplits(mySplits);
    // char save = 'y';
    // std::cout << "Would you like to save your splits? (y/n)\n"; 
    // std::cin >> save;
    // if (save == 'n'){
    //     std::cout << "Discarding Splits...\n";
    // }
    // else{
    //     std::cout << "Saving Splits...\n";
    // }
    return 0;
}