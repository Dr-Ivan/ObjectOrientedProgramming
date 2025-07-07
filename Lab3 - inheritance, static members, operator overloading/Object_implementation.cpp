#include "Object_header.hpp"
#include <iostream>

const Object& Object::operator= (const Object& other) {
    if(this != &other)
    {
        this->~Object();
        new (this) Object(other);
    }
    countAll++;
    countActive++;

    return *this;
}

Object::Object()
{
    countActive++;
    countAll++;
}

Object::Object(std::string op)
{
    countActive++;
    countAll++;
    addOp(op);
}

Object::Object(const Object& ob)
{
    countAll = ob.getCountAll();
    countActive = ob.getCountActive();
}

std::vector<std::string> Object::getOperations() const
{
    return allOperations;
}

void Object::printTotalInfo()
{
    std::cout << "Количество объектов: " << getCountAll() << std::endl;
    std::cout << "Количество активных объектов: " << getCountActive() << std::endl;
    std::cout << std::endl;
}

int Object::getCountOps()
{
    return allOperations.size();
}

void Object::addOp(std::string op)
{
    allOperations.push_back(op);
}

void Object::clearOp()
{
    allOperations.clear();
}

void Object::printOp()
{
    std::cout << "Список всех операций:" << std::endl;
    for(int i = 0; i < allOperations.size(); i++)
        std::cout << "Операция номер " << i << ": "<< allOperations[i] << std::endl;
    std::cout << std::endl;
}

int Object::getCountAll() const
{
    return countAll;
}

int Object::getCountActive() const
{
    return countActive;
}

Object::~Object(){
    countActive -= countActive >= 1 ? 1:0;
}