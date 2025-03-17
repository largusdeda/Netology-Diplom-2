#include "camel_runner.h"
#include "v_parameters.h"
#include <cmath>

namespace race {

    CamelRunner::CamelRunner() {
        name = "Верблюд-скороход";
    }

    double CamelRunner::time(double distance) {
        double moveTime = distance / CAMEL_RUNNER_SPEED;
        double restCount = std::ceil(moveTime / CAMEL_RUNNER_BEFORE_REST_TIME) - 1;
        if (restCount > 0) {
            moveTime += CAMEL_RUNNER_FIRST_REST_TIME;
        }
        if (--restCount > 0) {
            moveTime += CAMEL_RUNNER_SECOND_REST_TIME;
            moveTime += --restCount * CAMEL_RUNNER_STANDART_REST_TIME;
        }
        return moveTime;
    }
}