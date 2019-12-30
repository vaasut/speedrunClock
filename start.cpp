#include <iostream>
#include <thread> 
#include <chrono>
#include <ctime>  
int go = 0;


void splitOrEnd(){
    char ch = 'a';
    while (true){
        std::cin >> ch;
        if (ch == 's'){
            go = 1;
        }
        else if (ch == 'e'){
            go = 2;
            return;
        }
    }
}

void speedTimer(){
    std::clock_t start;
    std::clock_t interval;
    int duration;
    start = std::clock();
    interval = std::clock();
    while (go != 2){
        duration = (std::clock() - interval) / (int) CLOCKS_PER_SEC;
        if (duration == 1){
            interval = std::clock();
            if (go == 1){
                std::cout << "Split Time: " << (int) (interval - start) / (int) CLOCKS_PER_SEC << '\n';
                start = std::clock();
                go = 0;
            }
            else{
                std::cout << "time elapsed: "<< (int) (interval - start) / (int) CLOCKS_PER_SEC <<'\n';
            } 
        }
    }
}

void secondsToTime(int seconds){
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int print_seconds = seconds % 60;
    if (hours < 10){
        std::cout << "Final Time: 0" << hours << ":";
    }
    else{
        std::cout << "Final Time: " << hours << ":";
    }
    if (minutes < 10){
        std::cout << "0" << minutes << ":";
    }
    else{
        std::cout << minutes << ":";
    }
    if (print_seconds < 10){
        std::cout << "0" << print_seconds << "\n";
    }
    else{
        std::cout << print_seconds << "\n";
    }
}

int main() {
    std::clock_t start;
    start = std::clock();

    std::thread first (splitOrEnd);     // spawn new thread that calls foo()
    std::thread second (speedTimer);  // spawn new thread that calls bar(0)

    std::cout << "Start Run! \n";

    // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes


    secondsToTime((int) ((std::clock() - start)/CLOCKS_PER_SEC));
    return 0;
}