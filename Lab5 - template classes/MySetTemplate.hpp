#pragma once
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstring>

enum SetTypes {
    simpleSet,
    multiSet
};

struct Vec2 {
    float x;
    float y;

    bool operator==(const Vec2& other) const {
        return std::abs(x - other.x) < 1e-6 && std::abs(y - other.y) < 1e-6;
    }
};

template<typename T>
class MySet {
private:
    int type;  
    T* content;
    int size;
    int capacity;

    void expand() {
        capacity *= 2;
        T* newContent = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newContent[i] = content[i];
        }
        delete[] content;
        content = newContent;
    }

public:
    MySet(SetTypes setType = simpleSet) : type(setType), size(0), capacity(4) {
        content = new T[capacity];
    }

    MySet(const MySet& other) : type(other.type), size(other.size), capacity(other.capacity) {
        content = new T[capacity];
        for (int i = 0; i < size; ++i) {
            content[i] = other.content[i];
        }
    }

    MySet& operator=(const MySet& other) {
        if (this != &other) {
            delete[] content;
            type = other.type;
            size = other.size;
            capacity = other.capacity;
            content = new T[capacity];
            for (int i = 0; i < size; ++i) {
                content[i] = other.content[i];
            }
        }
        return *this;
    }

    ~MySet() {
        delete[] content;
    }

    
    MySet& operator+(const T& element) {
        if (type == simpleSet && getRepetitions(element) > 0) {
            return *this; 
        }

        if (size == capacity) {
            expand();
        }
        content[size++] = element;
        return *this;
    }

    MySet& operator-(const T& element) {
        for (int i = 0; i < size; ++i) {
            if (content[i] == element) {
                for (int j = i; j < size - 1; ++j) {
                    content[j] = content[j + 1];
                }
                --size;
                break;
            }
        }
        return *this;
    }

    bool operator[](const T& element) const {
        return getRepetitions(element) > 0;
    }

    int getLength() const {
        return size;
    }

    int getRepetitions(const T& element) const {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (content[i] == element) {
                ++count;
            }
        }
        return count;
    }

    bool operator==(const MySet& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (getRepetitions(content[i]) != other.getRepetitions(content[i])) {
                return false;
            }
        }
        return true;
    }

    bool operator<(const MySet& other) const {
        for (int i = 0; i < size; ++i) {
            if (getRepetitions(content[i]) > other.getRepetitions(content[i])) {
                return false;
            }
        }
        return true;
    }

    bool operator>(const MySet& other) const {
        return other < *this;
    }

    int getSizeInBytes() const {
        return sizeof(T) * size;
    }

    friend std::ostream& operator<<(std::ostream& os, const MySet& set) {
        os << "This set has " << set.size << " elements: ";
        os << "{ ";
        for (int i = 0; i < set.size; ++i) {
            os << set.content[i];
            if (i < set.size - 1) {
                os << ", ";
            }
        }
        os << " }";
        return os;
    }
};



template<>
class MySet<const char*> {
private:
    int setType;
    const char** content;
    int size;
    int capacity;

    void expand() {
        capacity *= 2;
        const char** newContent = new const char*[capacity];
        for (int i = 0; i < size; ++i) {
            newContent[i] = content[i];
        }
        delete[] content;
        content = newContent;
    }

public:
    MySet(int type) : setType(type), size(0), capacity(4) {
        content = new const char*[capacity];
    }

    MySet(const MySet& other) : setType(other.setType), size(other.size), capacity(other.capacity) {
        content = new const char*[capacity];
        for (int i = 0; i < size; ++i) {
            content[i] = strdup(other.content[i]); 
        }
    }

    MySet& operator=(const MySet& other) {
        if (this != &other) {
            for (int i = 0; i < size; ++i) {
                delete[] content[i];
            }
            delete[] content;

            setType = other.setType;
            size = other.size;
            capacity = other.capacity;
            content = new const char*[capacity];
            for (int i = 0; i < size; ++i) {
                content[i] = strdup(other.content[i]); 
            }
        }
        return *this;
    }

    ~MySet() {
        for (int i = 0; i < size; ++i) {
            delete[] content[i];  
        }
        delete[] content;
    }

    MySet& operator+(const char* element) {
        if (size == capacity) {
            expand();
        }
        content[size++] = strdup(element);  
        return *this;
    }

    MySet& operator-(const char* element) {
        for (int i = 0; i < size; ++i) {
            if (strcmp(content[i], element) == 0) {
                delete[] content[i]; 
                for (int j = i; j < size - 1; ++j) {
                    content[j] = content[j + 1];
                }
                --size;
                break;
            }
        }
        return *this;
    }

    bool operator[](const char* element) const {
        return getRepetitions(element) > 0;
    }

    int getLength() const {
        return size;
    }

    int getRepetitions(const char* element) const {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (strcmp(content[i], element) == 0) {
                ++count;
            }
        }
        return count;
    }

    int getSizeInBytes() const {
        int total = 0;
        for (int i = 0; i < size; ++i) {
            if (content[i]) {
                total += std::strlen(content[i]);
            }
        }
        return total;
    };
    

    friend std::ostream& operator<<(std::ostream& os, const MySet& set) {
        os << "{ ";
        for (int i = 0; i < set.size; ++i) {
            os << set.content[i];
            if (i < set.size - 1) {
                os << ", ";
            }
        }
        os << " }";
        return os;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Vec2& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}