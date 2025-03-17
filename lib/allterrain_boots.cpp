#include "allterrain_boots.h"
#include "v_parameters.h"
#include <cmath>

namespace race {

    AllTerrainBoots::AllTerrainBoots() {
        name = "Ботинки-вездеходы";
    }

    double AllTerrainBoots::time(double distance) {
        double moveTime = distance / BOOTS_SPEED;
        double restCount = std::ceil(moveTime / BOOTS_BEFORE_REST_TIME) - 1;
        if (restCount > 0) {
            moveTime += BOOTS_FIRST_REST_TIME;
            moveTime += --restCount * BOOTS_STANDART_REST_TIME;
        }
        return moveTime;
    }

}