#include "results.h"

namespace race {

    Results::~Results() {
        results_.clear();
    }

    void Results::add(Vehicle* v, double time) {
        results_.insert({ v->getName(), time });
    }

    std::set<Results::ResultLine>::iterator Results::begin() {
        return results_.begin();
    }

    std::set<Results::ResultLine>::iterator Results::end() {
        return results_.end();
    }
}