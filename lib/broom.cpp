#include "broom.h"
#include "v_parameters.h"
#include "reduce_ratio.h"

namespace race {

    Broom::Broom() {
        name = "Метла";
    }

    double Broom::time(double distance) {
        int percents = static_cast<int>(distance) / 1000 * BROOM_REDUCE_PER_1000;
        distance *= reduceRatio(percents);
        return distance / BROOM_SPEED;
    }

}