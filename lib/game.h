#pragma once

#include <vector>
#include "vehicle.h"
#include "ground_vehicle.h"
#include "air_vehicle.h"
#include "allterrain_boots.h"
#include "camel.h"
#include "camel_runner.h"
#include "centaur.h"
#include "magic_carpet.h"
#include "eagle.h"
#include "broom.h"
#include "results.h"
#include "game_status.h"

namespace race {
    class Game {

    private:
        enum class RaceType
        {
            GROUND = 1,
            AIR = 2,
            BOTH = 3
        };
        enum class Registration
        {
            BOOTS = 1,
            CAMEL = 2,
            CAMEL_RUNNER = 3,
            CENTAUR = 4,
            BROOM = 5,
            EAGLE = 6,
            CARPET = 7,
            EXIT = 0
        };

        RaceType raceType{};
        double distance{};
        std::vector<Vehicle*> vehicles;

    public:
        GameStatus play();

    private:
        void greetUser();
        double inputDistance();
        RaceType chooseRaceType();
        void registration();
        void printRegVehicles(std::vector<Vehicle*> &vehicles);
        bool isRegistered(std::vector<Vehicle*>& vehicles, std::string name);
        Results execRace();
        void showResults(Results results);
        void cleanRegistrationList();
        GameStatus wannaPlayMore();
    };
}
