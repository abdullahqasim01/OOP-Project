#include <iostream>
#include <ctime>
using namespace std;

int getMonth(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1 + ltm->tm_mon;
}

int getDay(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return ltm->tm_mday;
}

int getYear(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1900 + ltm->tm_year;
}