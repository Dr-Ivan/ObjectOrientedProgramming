#ifndef LAB2_H // защита от повторного включения
#define LAB2_H

#define _USE_MATH_DEFINES
#define EPS 1e-2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <iostream>

// класс для треугольника
class Triangle
{
    
public:
    // создание тругольника по координатам вершин
    Triangle (float ax, float ay, float bx, float by, float cx, float cy);

    // создание равностороннего треугольника с центроидом в начале координат
    Triangle (const float side);

    // создание прямоугольного треугольника
    Triangle (const float sidex, const float sidey);

    // геттер поля "равносторонний" 
    bool get_equilaterality();

    // сравнить два треугольника
    bool operator == (Triangle& other);

    // смещиение треугольника
    void move_triangle(float dx, float dy);

    // расчет координат ценитроида треугольника
    void center(float* resx, float* resy);

    // поворот треугольника на заданный угол в градусах вокруг центроида
    void rotate(const float alpha_deg);

    // масштабирование треугольника на заданный коэффициент
    void resize(const float k);

    // вывод треугольника в консоль по заданному шаблону
    void print_triangle();

private:

	float ax;
	float ay;
	float bx;
	float by;
	float cx;
	float cy;
	bool equilateral;
};

#endif