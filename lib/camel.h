#pragma once

#include "ground_vehicle.h"

namespace race {
    class Camel : public GroundVehicle {
    public:
        Camel();
        double time(double distance) override;
    };
}