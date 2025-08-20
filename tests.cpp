//
// Created by ulhuq on 20-08-2025.
//

#include "tests.h"

#include <cassert>
#include <iostream>

using namespace std;

int add (int a, int b) {
    return a + b;
}

int main() {
    assert(add(2, 3) == 5);
    cout << "All tests passed!" << endl;
    return 0;`

}