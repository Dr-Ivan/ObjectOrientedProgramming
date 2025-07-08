#pragma once

#include "Triangle_header.hpp"
#include <iostream>

using namespace std;

class Tester {
    public:
        void print_statistics();
    
        void test_center(Triangle t, float x, float y);
    
        void test_rotation(Triangle t, float deg, Triangle res);
    
        void test_move(Triangle t, float x, float y, Triangle res);
    
        void test_resize(Triangle t, float k, Triangle res);

        // Новые тесты
        void test_random_triangle(const float ax_min, const float ax_max,
            const float ay_min, const float ay_max,
            const float bx_min, const float bx_max, 
            const float by_min, const float by_max,
            const float cx_min, const float cx_max,
            const float cy_min, const float cy_max);

        void test_count_all(const Object& obj, const int res);

        void test_count_active(const Object& obj, const int res);

        void test_operations_order(const Object& obj, const std::vector<std::string>& res);

        void test_clear_operations(Object& obj, const int res);
    
    private:
        int total_tests = 0;
        int test_successful = 0;
        int test_failed = 0;
    };
