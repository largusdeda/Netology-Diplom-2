#pragma once

#include <iostream>

namespace race {
    class Vehicle {
    protected:
        std::string name;

    public:
        virtual double time(double distance);

        bool operator<(const Vehicle& a);
        std::string getName();
    };

}