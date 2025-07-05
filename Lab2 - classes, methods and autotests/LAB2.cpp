#include "LAB2_header.hpp"
#include "Tester_header.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    Tester tester;

    tester.test_center(Triangle{1,2,3,4,5,6}, 3, 4);
    tester.test_center(Triangle{10}, 0, 0);
    tester.test_center(Triangle{21, 15}, 7, 5);

    tester.test_rotation(Triangle{1, 2, 3, 4, 5, 6}, 90, Triangle{5, 2, 3, 4, 1, 6});
    tester.test_rotation(Triangle{10}, 180, Triangle{5, 2.886, -5, 2.886, 0, -5.773});
    tester.test_rotation(Triangle{21, 15}, 360, Triangle{21, 15});

    tester.test_move(Triangle{1, 2, 3, 4, 5, 6}, 10, 12, Triangle{11, 14, 13, 16, 15, 18});
    tester.test_move(Triangle{10}, 1, 2, Triangle{-4, -0.886, 6, -0.886, 1, 7.773});
    tester.test_move(Triangle{21, 15}, -10, -5, Triangle{-10, -5, 11, -5, -10, 10});

    tester.test_resize(Triangle{1, 2, 3, 4, 5, 6}, 2, Triangle{2, 4, 6, 8, 10, 12});
    tester.test_resize(Triangle{10}, 0.5, Triangle{-2.5, -1.443, 2.5, -1.443, 0, 2.886});
    tester.test_resize(Triangle{21, 15}, 3, Triangle{0, 0, 63, 0, 0, 45});


    // провальные тесты
    tester.test_resize(Triangle{21, 15}, 2, Triangle{0, 0, 63, 0, 0, 45});
    tester.test_move(Triangle{21, 15}, 10, -5, Triangle{-10, -5, 11, -5, -10, 10});
    tester.test_rotation(Triangle{21, 15}, 36, Triangle{21, 15});
    tester.test_center(Triangle{20, 15}, 7, 5);

    tester.print_statistics();

    return 0;
};
