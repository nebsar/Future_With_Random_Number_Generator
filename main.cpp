/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 10, 2018, 6:33 PM
 */

#include <cstdlib>
#include <random>
#include <set>
#include <iostream>
#include <algorithm>
#include <future>

using namespace std;

set<int> make_sorted_random(const size_t num_elems) {
    set<int> retval;
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> dis(0, num_elems - 1);

    generate_n(inserter(retval, retval.end()), num_elems, [&]() {
        return dis(gen);
    });

    throw runtime_error("Hello World");

    return retval;
}

int main(int argc, char** argv) {

    auto f1 = async(launch::async, make_sorted_random, 1000000);
    auto f2 = async(launch::async, make_sorted_random, 1000000);

    try {
        f1.get();
    } catch (const exception& e) {
        cout << "f1 threw exception:   " << e.what() << endl;
    }

    cout << f1.get().size() << ' ' << f2.get().size() << endl;

    return 0;
}

