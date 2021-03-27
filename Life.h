#ifndef TEST_LIFE_H
#define TEST_LIFE_H

#include <random>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <chrono>

using namespace std;

class Life {
private:
    int width;
    int length;
    vector<vector<int>> array;
public:
    Life(int, int);

    void generate_population();

    bool run_step();

    void print_current_population();

    void generate_neighb_pos_arr(vector<int> &, int, bool) const;
};


#endif //TEST_LIFE_H
