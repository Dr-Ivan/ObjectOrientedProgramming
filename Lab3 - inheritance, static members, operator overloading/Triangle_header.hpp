#pragma once

#define _USE_MATH_DEFINES
#define EPS 1e-2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <iostream>

#include "Object_header.hpp"

// класс для треугольника
class Triangle : public Object
{
    
public:
    // создание тругольника по координатам вершин
    Triangle (const float ax, const float ay, const float bx, const float by, const float cx, const float cy);

    // создание равностороннего треугольника с центроидом в начале координат
    Triangle (const float side);

    // создание прямоугольного треугольника
    Triangle (const float sidex, const float sidey);

    // геттер поля "равносторонний" 
    bool get_equilaterality() const;

    // геттер поля "ax" 
    float get_ax() const;

    // геттер поля "ay" 
    float get_ay() const;

    // геттер поля "bx" 
    float get_bx() const;

    // геттер поля "by" 
    float get_by() const;

    // геттер поля "cx" 
    float get_cx() const;

    // геттер поля "cy" 
    float get_cy() const;

    // смещиение треугольника
    void move_triangle(const float dx, const float dy);

    // расчет координат ценитроида треугольника
    void center(float* resx, float* resy);

    // поворот треугольника на заданный угол в градусах вокруг центроида
    void rotate(const float alpha_deg);

    // масштабирование треугольника на заданный коэффициент
    void resize(const float k);

    // вывод треугольника в консоль по заданному шаблону
    void print_triangle() const;


    // добавленные методы для третьего задания

    // сравнить два треугольника
    bool operator == (const Triangle& other) const;

    // объект со случайными значениями
    static Triangle make_ramdom_triangle (const float ax_min, const float ax_max,
        const float ay_min, const float ay_max,
        const float bx_min, const float bx_max, 
        const float by_min, const float by_max,
        const float cx_min, const float cx_max,
        const float cy_min, const float cy_max);


private:

	float ax;
	float ay;
	float bx;
	float by;
	float cx;
	float cy;
	bool equilateral;
};
