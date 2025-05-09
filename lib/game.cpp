﻿#include "game.h"

namespace race {

    GameStatus Game::play() {
        greetUser();
        raceType = chooseRaceType();
        distance = inputDistance();
        registration();
        showResults(execRace());
        cleanRegistrationList();
        return wannaPlayMore();
    }

    void Game::greetUser() {
        std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
    }

    double Game::inputDistance() {
        int distance{ 0 };
        while (distance <= 0) {
            std::cout << "Укажите длину дистанции (должна быть положительна): ";
            std::cin >> distance;
        }
        return distance;
    }

    Game::RaceType Game::chooseRaceType() {
        std::cout << "1. Гонка для наземного транспорта" << std::endl;
        std::cout << "2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;

        int choice{ 0 };
        while (choice < 1 || choice > 3) {
            std::cout << "Выберите тип гонки (1 - 3): ";
            std::cin >> choice;
        }
        return RaceType(choice);
    }

    void Game::printRegVehicles(std::vector<Vehicle*>& vehicles) {
        bool is_first{ true };
        for (auto& v : vehicles) {
            if (is_first) {
                std::cout << v->getName();
                is_first = false;
            }
            else std::cout << ", " << v->getName();
        }
        std::cout << std::endl;
    }

    bool Game::isRegistered(std::vector<Vehicle*>& vehicles, std::string name) {
        for (auto& v : vehicles) {
            if (v->getName() == name) {
                return true;
            }
        }
        return false;
    }

    void Game::registration() {
        int choice_num{ -1 };
        while (vehicles.size() < 2 || choice_num != 0) {
            switch (raceType) {
            case RaceType::AIR:
                std::cout << "Гонка для воздушного транспорта. ";
                break;
            case RaceType::GROUND:
                std::cout << "Гонка для наземного транспорта. ";
                break;
            case RaceType::BOTH:
                std::cout << "Гонка для наземного и воздушного транспорта. ";
                break;
            }
            std::cout << "Расстояние: " << distance << std::endl;

            if (!vehicles.empty()) {
                int line{ 1 };
                std::cout << "Зарегистрированные транспортные средства: ";
                printRegVehicles(vehicles);
            }

            std::cout << "Регистрация (минимум 2 участника):" << std::endl;
            std::cout << "1. Ботинки-вездеходы" << std::endl;
            std::cout << "2. Верблюд" << std::endl;
            std::cout << "3. Верблюд-скороход" << std::endl;
            std::cout << "4. Кентавр" << std::endl;
            std::cout << "5. Метла" << std::endl;
            std::cout << "6. Орёл" << std::endl;
            std::cout << "7. Ковёр-самолёт" << std::endl;
            std::cout << "0. Закончить регистрацию" << std::endl;

            std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
            std::cin >> choice_num;

            Registration choice = static_cast<Registration>(choice_num);
            using r = Registration;
            if (raceType == RaceType::AIR && choice >= r::BOOTS && choice < r::BROOM
                || raceType == RaceType::GROUND && choice > r::CENTAUR && choice <= r::CARPET) {
                std::cout << "Попытка зарегистрировать неправильный тип транспорта!" << std::endl;
                continue;
            }
            if (choice_num < 0 || choice_num > 7) {
                std::cout << "Неверный пункт меню!" << std::endl;
                continue;
            }
            if (vehicles.size() < 2 && choice == r::EXIT) {
                std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства!" << std::endl;
                continue;
            }

            switch (choice) {
            case r::BOOTS:
                if (!isRegistered(vehicles, "Ботинки-вездеходы")) {
                    vehicles.push_back(new AllTerrainBoots());
                    std::cout << "Ботинки-вездеходы успешно зарегистрирован!" << std::endl;
                }
                else {
                    std::cout << "Ботинки - вездеходы уже зарегистрирован!" << std::endl;
                }
                break;
            case r::CAMEL:
                if (!isRegistered(vehicles, "Верблюд")) {
                    vehicles.push_back(new Camel());
                    std::cout << "Верблюд успешно зарегистрирован!" << std::endl;
                }
                else {
                    std::cout << "Верблюд уже зарегистрирован!" << std::endl;
                }
                break;
            case r::CAMEL_RUNNER:
                if (!isRegistered(vehicles, "Верблюд-быстроход")) {
                    vehicles.push_back(new CamelRunner());
                    std::cout << "Верблюд-быстроход успешно зарегистрирован!" << std::endl;
                }
                else {
                    std::cout << "Верблюд-быстроход уже зарегистрирован!" << std::endl;
                }
                break;
            case r::CENTAUR:
                if (!isRegistered(vehicles, "Кентавр")) {
                    vehicles.push_back(new Centaur());
                    std::cout << "Кентавр успешно зарегистрирован!" << std::endl;
                }
                else {
                    std::cout << "Кентавр уже зарегистрирован!" << std::endl;
                }
                break;
            case r::BROOM:
                if (!isRegistered(vehicles, "Метла")) {
                    vehicles.push_back(new Broom());
                    std::cout << "Метла успешно зарегистрирован!" << std::endl;
                }
                else {
                    std::cout << "Метла уже зарегистрирован!" << std::endl;
                }
                break;
            case r::EAGLE:
                if (!isRegistered(vehicles, "Орёл")) {
                    vehicles.push_back(new Eagle());
                    std::cout << "Орёл успешно зарегистрирован!" << std::endl;
                }
                else {
                    std::cout << "Орёл уже зарегистрирован!" << std::endl;
                }
                break;
            case r::CARPET:
                if (!isRegistered(vehicles, "Ковёр-самолёт")) {
                    vehicles.push_back(new MagicCarpet());
                    std::cout << "Ковёр-самолёт успешно зарегистрирован!" << std::endl;
                }
                else {
                    std::cout << "Ковёр-самолёт уже зарегистрирован!" << std::endl;
                }
                break;
            }
        }
    }

    Results Game::execRace() {
        Results results;
        for (auto& v : vehicles) {
            results.add(v, v->time(distance));
        }
        return results;
    }

    void Game::showResults(Results results) {
        std::cout << "Результаты гонки:" << std::endl;
        int lineCount = 1;
        for (auto& item : results) {
            std::cout << lineCount++ << ". " << item.name << ". Время: " << item.time << std::endl;
        }
    }

    void Game::cleanRegistrationList() {
        for (auto& v : vehicles) {
            delete v;
        }
        vehicles.clear();
    }

    GameStatus Game::wannaPlayMore() {
        std::cout << "Хотите сыграть ещё?" << std::endl;
        std::cout << "1. Провести ещё одну гонку" << std::endl;
        std::cout << "2. Выйти" << std::endl;

        int choice{ 0 };
        while (choice < 1 || choice > 2) {
            std::cout << "Выберите действие: ";
            std::cin >> choice;
        }
        return static_cast<GameStatus>(choice);
    }
}