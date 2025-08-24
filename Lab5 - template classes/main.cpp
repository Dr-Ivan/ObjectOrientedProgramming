#include <iostream>
#include <cstring>

#include "MySetTemplate.hpp"

int main() {
    MySet<int> simpleSet(SetTypes::simpleSet);
    simpleSet + 1;
    simpleSet + 2;
    simpleSet + 2; 
    simpleSet + 3;
    
    std::cout << "SimpleSet: " << simpleSet << std::endl;
    std::cout << "Is there 2 in simpleSet? " << (simpleSet[2] ? "Yes" : "No") << std::endl;
    std::cout << "Size of simpleSet: " << simpleSet.getLength() << std::endl;
    simpleSet - 2;
    std::cout << "SimpleSet with removed 2: " << simpleSet << std::endl;
    MySet<int> anotherSet(simpleSet);
    anotherSet + 1;
    std::cout << "anotherSet: " << anotherSet << std::endl;
    std::cout << "Is simpleSet subset of anotherSet? " << (simpleSet < anotherSet ? "Yes" : "No") << std::endl;
    std::cout << std::endl;


    MySet<int> multiSet(SetTypes::multiSet);
    multiSet + 1;
    multiSet + 2;
    multiSet + 2; 
    multiSet + 3;
    
    std::cout << "MultiSet: " << multiSet << std::endl;
    std::cout << "Repetitions of 2 in multiSet: " << multiSet.getRepetitions(2) << std::endl;
    std::cout << "Is there 2 in multiSet? " << (multiSet[2] ? "Yes" : "No") << std::endl;
    std::cout << "Length of multiSet: " << multiSet.getLength() << std::endl;
    multiSet - 2;
    std::cout << "MultiSet with removed 2: " << multiSet << std::endl;
    std::cout << "Is multiSet a subset of simpleSet? " << (multiSet < simpleSet ? "Yes" : "No") << std::endl;
    MySet<int> anotherMultiSet(multiSet);
    std::cout << "anotherMultiSet: " << anotherMultiSet << std::endl;
    std::cout << "multiSet == anotherMultiSet? " << (multiSet == anotherMultiSet ? "Yes" : "No") << std::endl;
    std::cout << std::endl;


    MySet<const char*> charSet(SetTypes::simpleSet);
    const char* str1 = "Hello";
    const char* str2 = "World";
    const char* str3 = "Hello";

    charSet + str1;
    charSet + str2;
    charSet + str3; 

    std::cout << "CharSet: " << charSet << std::endl;
    std::cout << "Repetitions of 'Hello' in charSet: " << charSet.getRepetitions(str1) << std::endl;
    std::cout << "Size of charSet in bytes: " << charSet.getSizeInBytes() << " bytes" << std::endl;
    std::cout << std::endl;

    return 0;
}
