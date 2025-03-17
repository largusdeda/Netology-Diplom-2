#include <string>
#include "vehicle.h"

namespace race {

    double Vehicle::time(double distance) {
        return 0;
    }

    bool Vehicle::operator<(const Vehicle& a) {
        return name < a.name;
    }

    std::string Vehicle::getName() {
        return name;
    }

}