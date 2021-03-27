#include "Life.h"

Life::Life(int width, int length) {
    this->width = width;
    this->length = length;
    this->array.resize(this->length, vector<int>(this->width));
}

void Life::generate_population() {
    default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, 1);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            array[i][j] = dist(engine);
        }
    }
}

void Life::generate_neighb_pos_arr(vector<int> &pos, int i, bool w) const {
    if (i - 1 >= 0) {
        pos.push_back(i - 1);
    }
//    else {
//        pos.push_back(width - 1);
//    }
    pos.push_back(i);
    if (w) {
        if (i + 1 < width) {
            pos.push_back(i + 1);
        }
//        else {
//            pos.push_back(0);
//        }
    } else {
        if (i + 1 < length) {
            pos.push_back(i + 1);
        }
//        else {
//            pos.push_back(0);
//        }
    }
}

bool Life::run_step() {
    vector<vector<int>> newArray(this->length, vector<int>(this->width, 0));
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            int counter = 0;
            vector<int> posI;
            vector<int> posJ;
            generate_neighb_pos_arr(posI, i, false);
            generate_neighb_pos_arr(posJ, j, true);
            for (int y : posI) {
                for (int x : posJ) {
                    if (i == y && j == x)continue;
                    if (array[y][x] == 1)counter++;
                }
            }
            if (array[i][j] == 1 && (counter == 2 || counter == 3)) {
                newArray[i][j] = 1;
            } else if (array[i][j] == 0 && counter == 3) {
                newArray[i][j] = 1;
            }
        }
    }
    if (array == newArray)return true;
    array = newArray;
    return false;
}

void Life::print_current_population() {
    usleep(200000);
    string returnToStartCur = "\x1b[" + to_string(length) + "A";
    cout << returnToStartCur;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            if (array[i][j] == 1) {
                cout << "0 ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}
