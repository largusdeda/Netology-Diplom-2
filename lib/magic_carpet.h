#pragma once

#include "air_vehicle.h"

namespace race {

    class MagicCarpet : public AirVehicle {
    public:
        MagicCarpet();
        double time(double distance) override;
    };

}