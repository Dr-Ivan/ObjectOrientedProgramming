#pragma once

#include <vector>
#include <string>

class Object
{
    protected:
        static inline unsigned countAll {};
        static inline unsigned countActive {};

        std::vector<std::string> allOperations;

    public:

        Object(const Object& ob);
        Object();
        Object(std::string op);

        std::vector<std::string> getOperations() const;

        void printTotalInfo();

        void addOp(std::string op);

        void clearOp();

        int getCountOps();

        void printOp();

        int getCountAll() const;
        int getCountActive() const;

        const Object& operator= (const Object& other);

        ~Object();
};