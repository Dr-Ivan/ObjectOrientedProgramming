#include "Triangle_header.hpp"
#include "Tester_header.hpp"
#include <iostream>


using namespace std;

float random_number1(float min_value, float max_value) {
        return min_value + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max_value - min_value))));
    };

int main(int argc, char *argv[]) {
    Tester tester;

    


    // старые тесты
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
    // tester.test_resize(Triangle{21, 15}, 2, Triangle{0, 0, 63, 0, 0, 45});
    // tester.test_move(Triangle{21, 15}, 10, -5, Triangle{-10, -5, 11, -5, -10, 10});
    // tester.test_rotation(Triangle{21, 15}, 36, Triangle{21, 15});
    // tester.test_center(Triangle{20, 15}, 7, 5);

    
    // новые тесты
    tester.test_random_triangle(10,15,
        10,22,
        12,25,
        20,32,
        10,24,
        21,35);
    tester.test_count_all(Object(), 23);
    tester.test_count_active(Object(), 1);
    Object obj_with_operations = Object("Op1");
    tester.test_count_active(Object(), 2);
    tester.test_operations_order(obj_with_operations, {"Op1"});
    tester.test_clear_operations(obj_with_operations, 0);
    

    tester.print_statistics();

    return 0;
};
