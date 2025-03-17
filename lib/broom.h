#pragma once

#include "air_vehicle.h"

namespace race {

    class Broom : public AirVehicle {
    public:
        Broom();
        double time(double distance) override;
    };

}