int stop = 0;
std::string mySplits;

void splitOrEnd(){ //takes user inputs to either split or stop the clock
    char ch;
    while (true){
        std::cin >> ch;
        if (ch == '.'){ //end
            stop = 2;
            return;
        }
        else { //split
            stop = 1;
        }
    }
}

void speedTimer(){ //clock function that prints times, and stores splits to save later
    std::clock_t start;
    std::clock_t split;
    std::clock_t interval;
    int duration;
    double tempTime;
    start = std::clock();
    split = std::clock();
    interval = std::clock();

    while (stop != 2){
        duration = (std::clock() - interval) / CLOCKS_PER_SEC;
        if (stop == 1){
            tempTime = (double) (std::clock() - split) / (double) CLOCKS_PER_SEC;
            stop = 0;
            std::cout << "Split Time: " << tempTime << '\n';
            mySplits.append("Split: " + std::to_string(tempTime) + '\n');
            split = std::clock();
        }
        if (duration == 1){
            interval = std::clock();
            std::cout << "time elapsed: "<< (int) (interval - start) / (int) CLOCKS_PER_SEC <<'\n';
        }
    }
    tempTime = (double) (std::clock() - split) / (double) CLOCKS_PER_SEC;
    mySplits.append("Split: " + std::to_string(tempTime) + '\n');
}