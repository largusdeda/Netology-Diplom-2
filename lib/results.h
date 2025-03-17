#pragma once

#include <iostream>
#include <set>
#include "vehicle.h"

namespace race {
    class Results {
    private:
        struct ResultLine {
            std::string name;
            double time;

            bool operator<(const ResultLine& a) const {
                return time < a.time;
            }
        };
        std::set<ResultLine> results_;

    public:
        ~Results();

        void add(Vehicle* v, double time);
        std::set<ResultLine>::iterator begin();
        std::set<ResultLine>::iterator end();

    };
}