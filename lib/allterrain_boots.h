#pragma once

#include "ground_vehicle.h"

namespace race {

    class AllTerrainBoots : public GroundVehicle {
    public:
        AllTerrainBoots();
        double time(double distance) override;
    };

}