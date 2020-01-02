int stop = 0;
std::string mySplits;

void splitOrEnd(){
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

void speedTimer(){
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
            std::cout << "Split Time: " << tempTime << '\n';
            split = std::clock();
            stop = 0;
            mySplits.append("Split: " + std::to_string(tempTime) + "\n");
        }
        if (duration == 1){
            interval = std::clock();
            std::cout << "time elapsed: "<< (int) (interval - start) / (int) CLOCKS_PER_SEC <<'\n';
        }
    }
}
