#include "eagle.h"
#include "v_parameters.h"
#include "reduce_ratio.h"


namespace race {

    Eagle::Eagle() {
        name = "Орёл";
    }

    double Eagle::time(double distance) {
        distance *= reduceRatio(EAGLE_REDUCE);
        return distance / EAGLE_SPEED;
    }

}