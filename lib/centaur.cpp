#include "centaur.h"
#include "v_parameters.h"
#include <cmath>

namespace race {

    Centaur::Centaur() {
        name = "Кентавр";
    }

    double Centaur::time(double distance) {
        double moveTime = distance / CENTAUR_SPEED;
        double restCount = std::ceil(moveTime / CENTAUR_BEFORE_REST_TIME) - 1;

        return moveTime + restCount * CENTAUR_REST_TIME;
    }
}