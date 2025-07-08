#include "Triangle_header.hpp"
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

// Новые тесты
void Tester::test_random_triangle(const float ax_min, const float ax_max,
    const float ay_min, const float ay_max,
    const float bx_min, const float bx_max, 
    const float by_min, const float by_max,
    const float cx_min, const float cx_max,
    const float cy_min, const float cy_max)
    {
        // act
        Triangle t = Triangle::make_ramdom_triangle(
            ax_min, ax_max,
            ay_min, ay_max,
            bx_min, bx_max, 
            by_min, by_max,
            cx_min, cx_max,
            cy_min, cy_max);

        // assert
        cout << "==================" << endl;
        cout << "Тест создания случайного треугольника" << endl;

        cout << "Исходные данные: " << endl;
        cout << ax_min << " " << ax_max << " " <<  ay_min << " " << ay_max << " " << bx_min << " " << bx_max  << " " << by_min << " " << by_max  << " " << cx_min << " " << cx_max << " " << cy_min << " " << cy_max << endl;
        cout << "Результат операции: " <<  endl;
        t.print_triangle();

        if( ax_min <= t.get_ax() && ax_max >= t.get_ax() &&
            ay_min <= t.get_ay() && ay_max >= t.get_ay() && 
            bx_min <= t.get_bx() && bx_max >= t.get_bx() &&
            by_min <= t.get_by() && by_max >= t.get_by() &&
            cx_min <= t.get_cx() && cx_max >= t.get_cx() &&
            cy_min <= t.get_cy() && cy_max >= t.get_cy()) {
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

void Tester::test_count_all(const Object& obj, const int res){
    // act
    int count = obj.getCountAll();

    // assert
    cout << "==================" << endl;
    cout << "Тест подсчета всех объектов" << endl;
    cout << "Ожидаемый результат: " << res << endl;
    cout << "Результат операции: " << count <<  endl;

    if(count == res) {
        std::cout << "Тест пройден" << std::endl;
        this->test_successful++;
    } else {
        cout << "Тест не пройден" << endl;
        this->test_failed++;
    }
    cout << "==================" << endl;
    cout << endl;
    total_tests++;
};

void Tester::test_count_active(const Object& obj, const int res){
    // act
    int count = obj.getCountActive();

    // assert
    cout << "==================" << endl;
    cout << "Тест подсчета активных объектов" << endl;
    cout << "Ожидаемый результат: " << res << endl;
    cout << "Результат операции: " << count <<  endl;

    if(count == res) {
        std::cout << "Тест пройден" << std::endl;
        this->test_successful++;
    } else {
        cout << "Тест не пройден" << endl;
        this->test_failed++;
    }
    cout << "==================" << endl;
    cout << endl;
    total_tests++;
};

void Tester::test_operations_order(const Object& obj, const std::vector<std::string>& res){
    // act
    vector<string> operations = obj.getOperations();

    // assert
    cout << "==================" << endl;
    cout << "Тест истории операций" << endl;

    if(operations == res) {
        std::cout << "Тест пройден" << std::endl;
        this->test_successful++;
    } else {
        cout << "Тест не пройден" << endl;
        this->test_failed++;
    }
    cout << "==================" << endl;
    cout << endl;
    total_tests++;
};

void Tester::test_clear_operations(Object& obj, const int res){
    // act
    obj.clearOp();
    int count = obj.getCountOps();

    // assert
    cout << "==================" << endl;
    cout << "Тест удаления истории операций" << endl;

    if(count == res) {
        std::cout << "Тест пройден" << std::endl;
        this->test_successful++;
    } else {
        cout << "Тест не пройден" << endl;
        this->test_failed++;
    }
    cout << "==================" << endl;
    cout << endl;
    total_tests++;
};
