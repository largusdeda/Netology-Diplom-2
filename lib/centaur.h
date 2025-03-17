#pragma once

#include "ground_vehicle.h"

namespace race {

    class Centaur : public GroundVehicle {
    public:
        Centaur();
        double time(double distance) override;
    };

}