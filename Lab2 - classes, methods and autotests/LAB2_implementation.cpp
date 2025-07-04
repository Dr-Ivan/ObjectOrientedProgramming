#include "LAB2_header.hpp"

#define _USE_MATH_DEFINES
#define EPS 1e-2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

// проверка равенства вещественных чисел
bool equal_float(float a, float b){
	return (abs(a - b) < EPS);
};



// создание тругольника по координатам вершин
Triangle::Triangle (float ax, float ay, float bx, float by, float cx, float cy){
    this->ax = ax;
    this->ay = ay;
    this->bx = bx;
    this->by = by;
    this->cx = cx;
    this->cy = cy;
    this->equilateral = (bool) (equal_float(pow((bx-ax), 2) + pow((by-ay), 2), pow((cx-ax), 2) + pow((cy-ay), 2)) &&
                            equal_float(pow((bx-cx), 2) + pow((by-cy), 2), pow((cx-ax), 2) + pow((cy-ay), 2)));
};

// создание равностороннего треугольника с центроидом в начале координат
Triangle::Triangle (const float side){
    float ax = -side/2;
    float ay = -side*sqrt(3)/6;
    float bx = side/2;
    float by = -side*sqrt(3)/6;
    float cx = 0;
    float cy = side*sqrt(3)/3;
    
    this->ax = ax;
    this->ay = ay;
    this->bx = bx;
    this->by = by;
    this->cx = cx;
    this->cy = cy;
    this->equilateral = true;
};


// создание прямоугольного треугольника
Triangle::Triangle (const float sidex, const float sidey){
    this->ax = 0;
    this->ay = 0;
    this->bx = sidex;
    this->by = 0;
    this->cx = 0;
    this->cy = sidey;
    this->equilateral = false;
};

// геттер поля "равносторонний" 
bool Triangle::get_equilaterality(){
    return this->equilateral;
};

// сравнить два треугольника
bool Triangle::operator == (Triangle& other){
    return (equal_float(this->ax, other.ax) && equal_float(this->ay, other.ay)
        && equal_float(this->bx, other.bx) && equal_float(this->by, other.by)
        && equal_float(this->cx, other.cx) && equal_float(this->cy, other.cy));
};

// смещиение треугольника
void Triangle::move_triangle(float dx, float dy){
    this->ax += dx;
    this->ay += dy;
    this->bx += dx;
    this->by += dy;
    this->cx += dx;
    this->cy += dy;
};

// расчет координат ценитроида треугольника
void Triangle::center(float* resx, float* resy){
    *resx = (float)(this->ax + this->bx + this->cx)/3;
    *resy = (float)(this->ay + this->by + this->cy)/3;
};

// поворот треугольника на заданный угол в градусах вокруг центроида
void Triangle::rotate(const float alpha_deg){
    float center_x, center_y;
    this->center(&center_x, &center_y);
    
    float alpha_rad = alpha_deg * M_PI / 180;
    
    float ax = center_x + (this->ax - center_x) * cos(alpha_rad) - (this->ay - center_y) * sin(alpha_rad);
    float ay = center_y + (this->ax - center_x) * sin(alpha_rad) + (this->ay - center_y) * cos(alpha_rad);
    float bx = center_x + (this->bx - center_x) * cos(alpha_rad) - (this->by - center_y) * sin(alpha_rad);
    float by = center_y + (this->bx - center_x) * sin(alpha_rad) + (this->by - center_y) * cos(alpha_rad);
    float cx = center_x + (this->cx - center_x) * cos(alpha_rad) - (this->cy - center_y) * sin(alpha_rad);
    float cy = center_y + (this->cx - center_x) * sin(alpha_rad) + (this->cy - center_y) * cos(alpha_rad);
    
    this->ax = ax;
    this->ay = ay;
    this->bx = bx;
    this->by = by;
    this->cx = cx;
    this->cy = cy;	
};

// масштабирование треугольника на заданный коэффициент
void Triangle::resize(const float k){
    this->ax *= k;
    this->ay *= k;
    this->bx *= k;
    this->by *= k;
    this->cx *= k;
    this->cy *= k;
};


// вывод треугольника в консоль по заданному шаблону
void Triangle::print_triangle(){
    float px1, py1, px2, py2, px3, py3;
    if (this->ay > this->by){
        if (this->ay > this->cy){
            px1 = this->ax;
            py1 = this->ay;
            if (this->bx < this->cx){
                px2 = this->bx;
                py2 = this->by;
                px3 = this->cx;
                py3 = this->cy;
            } else{
                px2 = this->cx;
                py2 = this->cy;
                px3 = this->bx;
                py3 = this->by;
            };
        } else {
            px1 = this->cx;
            py1 = this->cy;
            
            if (this->bx < this->ax){
                px2 = this->bx;
                py2 = this->by;
                px3 = this->ax;
                py3 = this->ay;
            } else{
                px2 = this->ax;
                py2 = this->ay;
                px3 = this->bx;
                py3 = this->by;
            };
            
        };	
    }else{
        if (this->by > this->cy){
            px1 = this->bx;
            py1 = this->by;
            if (this->ax < this->cx){
                px2 = this->ax;
                py2 = this->ay;
                px3 = this->cx;
                py3 = this->cy;
            } else{
                px2 = this->cx;
                py2 = this->cy;
                px3 = this->ax;
                py3 = this->ay;	
            };
        } else {
            px1 = this->cx;
            py1 = this->cy;
            
            if (this->bx < this->ax){
                px2 = this->bx;
                py2 = this->by;
                px3 = this->ax;
                py3 = this->ay;
            } else{
                px2 = this->ax;
                py2 = this->ay;
                px3 = this->bx;
                py3 = this->by;	
            };
            
        };	
        
    }
    
    
    printf("\t(%.2f, %.2f)\n", px1, py1);
    printf("(%.2f, %.2f)\t(%.2f, %.2f)\n", px2, py2,px3, py3);
    auto res = this->equilateral? "Равносторонний": "Неравносторонний";
    std::cout << res;
    std::cout << "\n\n";
}
