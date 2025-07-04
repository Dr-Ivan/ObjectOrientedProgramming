#include "LAB2_header.hpp"
#include "Tester_header.hpp"
#include <iostream>

using namespace std;


void Tester::print_statistics(){
    cout << endl;
    cout << "-----Статистика-----" << endl;
    cout <<"Запущено тестов: "<< this->total_tests << endl;
    cout <<"Успешных тестов: "<< this->test_successful << endl;
    cout <<"Провальных тестов: "<< this->test_failed << endl;
    cout << endl;
};

void Tester::test_center(Triangle t, float x, float y) {
    // act
    float center_x, center_y;
    t.center(&center_x, &center_y);

    // assert
    cout << "==================" << endl;
    cout << "Тест вычисления центроида треугольника" << endl;
    cout << "Исходные данные: " << endl;
    t.print_triangle();
    cout << "Ожидаемый результат: x = " << x << " y = " << y <<  endl;
    cout << "Результат операции: x = " << center_x << " y = " << center_y <<  endl;
    if(center_x == x & center_y == y) {
        cout << "Тест пройден" << endl;
        this->test_successful++;
    } else {
        cout << "Тест не пройден" << endl;
        this->test_failed++;
    }
    cout << "==================" << endl;
    cout << endl;
    total_tests++;
};

void Tester::test_rotation(Triangle t, float deg, Triangle res) {
    // act
    Triangle t_copy = t;
    t.rotate(deg);

    // assert
    cout << "==================" << endl;
    cout << "Тест поворота треугольника" << endl;
    cout << "Исходные данные: " << endl;
    t_copy.print_triangle();
    cout << "Ожидаемый результат: " << endl;
    res.print_triangle();
    cout << "Результат операции: " <<  endl;
    t.print_triangle();

    if(t == res) {
        cout << "Тест пройден" << endl;
        this->test_successful++;
    } else {
        cout << "Тест не пройден" << endl;
        this->test_failed++;
    }
    cout << "==================" << endl;
    cout << endl;
    total_tests++;
};

void Tester::test_move(Triangle t, float x, float y, Triangle res) {
    // act
    Triangle t_copy = t;
    t.move_triangle(x, y);

    // assert
    cout << "==================" << endl;
    cout << "Тест перемещения треугольника" << endl;
    cout << "Исходные данные: " << endl;
    t_copy.print_triangle();
    cout << "Ожидаемый результат: " << endl;
    res.print_triangle();
    cout << "Результат операции: " <<  endl;
    t.print_triangle();

    if(t == res) {
        cout << "Тест пройден" << endl;
        this->test_successful++;
    } else {
        cout << "Тест не пройден" << endl;
        this->test_failed++;
    }
    cout << "==================" << endl;
    cout << endl;
    total_tests++;
};

void Tester::test_resize(Triangle t, float k, Triangle res) {
    // act
    Triangle t_copy = t;
    t.resize(k);

    // assert
    cout << "==================" << endl;
    cout << "Тест масштабирования треугольника" << endl;
    cout << "Исходные данные: " << endl;
    t_copy.print_triangle();
    cout << "Ожидаемый результат: " << endl;
    res.print_triangle();
    cout << "Результат операции: " <<  endl;
    t.print_triangle();

    if(t == res) {
        cout << "Тест пройден" << endl;
        this->test_successful++;
    } else {
        cout << "Тест не пройден" << endl;
        this->test_failed++;
    }
    cout << "==================" << endl;
    cout << endl;
    total_tests++;
};