#include "magic_carpet.h"
#include "v_parameters.h"
#include "reduce_ratio.h"

namespace race {
    MagicCarpet::MagicCarpet() {
        name = "Ковёр-самолёт";
    }

    double MagicCarpet::time(double distance) {
        double redRatio{};
        if (distance < 1000) {
            redRatio = reduceRatio(CARPET_REDUCE_LESS_1000);
        }
        else if (distance < 5000) {
            redRatio = reduceRatio(CARPET_REDUCE_LESS_5000);
        }
        else if (distance < 10000) {
            redRatio = reduceRatio(CARPET_REDUCE_LESS_10000);
        }
        else {
            redRatio = reduceRatio(CARPET_REDUCE_MOREEQ_10000);
        }
        return distance * redRatio / CARPET_SPEED;
    }
}