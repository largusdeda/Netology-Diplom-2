#pragma once

#include "ground_vehicle.h"

namespace race {

    class CamelRunner : public GroundVehicle {
    public:
        CamelRunner();
        double time(double distance) override;
    };

}