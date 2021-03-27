#include "Life.h"

int main(int argc, char *argv[]) {
    Life *life = new Life(stoi(argv[1]), stoi(argv[2]));
    cout << string(stoi(argv[2]), '\n');
    cout.flush();
    life->generate_population();
    life->print_current_population();
    while (true) {
        if (life->run_step())break;
        life->print_current_population();
    }
    delete life;
    return 0;
}
