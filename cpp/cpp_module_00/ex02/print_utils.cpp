#include <iostream>
#include <ctime>
#include "print_utils.hpp"

void print_timestamp() {
    time_t time_now;
    tm *tm;
    char buf[20];

    std::time(&time_now);
    tm = std::localtime(&time_now);
    std::strftime(buf, 20, "[%Y%m%d_%H%M%S] ", tm);
    std::cout << buf;
}

void print_index(int idx) {
    std::cout << "index:" << idx << ';';
}

void print_amount(int amount) {
    std::cout << "amount:" << amount << ';';
}

void print_deposits(int deposits) {
    std::cout << "deposits:" << deposits << ';';
}

void print_withdrawals(int withdrawals) {
    std::cout << "withdrawals:" << withdrawals;
}
