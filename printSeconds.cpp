void printSeconds(int seconds){
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