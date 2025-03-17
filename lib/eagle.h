#pragma once

#include "air_vehicle.h"

namespace race {

    class Eagle : public AirVehicle {
    public:
        Eagle();
        double time(double distance) override;
    };

}