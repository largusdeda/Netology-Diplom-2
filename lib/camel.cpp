#include "camel.h"
#include "v_parameters.h"
#include <cmath>

namespace race {

    Camel::Camel() {
        name = "Верблюд";
    }

    double Camel::time(double distance) {
        double moveTime = distance / CAMEL_SPEED;
        double restCount = std::ceil(moveTime / CAMEL_BEFORE_REST_TIME) - 1;
        if (restCount > 0) {
            moveTime += CAMEL_FIRST_REST_TIME;
            moveTime += --restCount * CAMEL_STANDART_REST_TIME;
        }
        return moveTime;
    }
}