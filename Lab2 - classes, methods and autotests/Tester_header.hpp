#ifndef TESTER_H // защита от повторного включения
#define TESTER_H

#include "LAB2_header.hpp"
#include <iostream>

using namespace std;

class Tester {
    public:
        void print_statistics();
    
        void test_center(Triangle t, float x, float y);
    
        void test_rotation(Triangle t, float deg, Triangle res);
    
        void test_move(Triangle t, float x, float y, Triangle res);
    
        void test_resize(Triangle t, float k, Triangle res);
    
	
    private:
        int total_tests = 0;
        int test_successful = 0;
        int test_failed = 0;
    };

#endif