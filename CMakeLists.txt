cmake_minimum_required(VERSION 3.22.0)

project(race_sim LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(lib SHARED 
		lib/vehicle.h
		lib/vehicle.cpp

		lib/air_vehicle.h
		lib/broom.h
		lib/broom.cpp
		lib/eagle.h
		lib/eagle.cpp
		lib/magic_carpet.h
		lib/magic_carpet.cpp

		lib/ground_vehicle.h
		lib/allterrain_boots.h
		lib/allterrain_boots.cpp
		lib/camel.h
		lib/camel.cpp
		lib/camel_runner.h
		lib/camel_runner.cpp
		lib/centaur.h
		lib/centaur.cpp

		lib/game.h
		lib/game.cpp
		lib/game_status.h
		lib/reduce_ratio.h
		lib/reduce_ratio.cpp
		lib/results.h
		lib/results.cpp
		lib/v_parameters.h
)

include_directories(lib)

add_executable(Race_Simulator main.cpp)
target_link_libraries(Race_Simulator lib)