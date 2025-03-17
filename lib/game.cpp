#include "game.h"

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

    void Game::registration() {
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

        std::cout << "Регистрация (минимум 2 участника):" << std::endl;
        std::cout << "1. Ботинки-вездеходы" << std::endl;
        std::cout << "2. Верблюд" << std::endl;
        std::cout << "3. Верблюд-скороход" << std::endl;
        std::cout << "4. Кентавр" << std::endl;
        std::cout << "5. Метла" << std::endl;
        std::cout << "6. Орёл" << std::endl;
        std::cout << "7. Ковёр-самолёт" << std::endl;
        std::cout << "0. Закончить регистрацию" << std::endl;

        int choice_num{ -1 };
        while (vehicles.size() < 2 || choice_num != 0) {
            if (!vehicles.empty()) {
                int line{ 1 };
                std::cout << "Зарегистрированные транспортные средства:" << std::endl;
                for (auto& v : vehicles) {
                    std::cout << line++ << ". " << v->getName() << std::endl;
                }
            }

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
                vehicles.insert(new AllTerrainBoots());
                std::cout << "Ботинки-вездеходы успешно зарегистрирован!" << std::endl;
                break;
            case r::CAMEL:
                vehicles.insert(new Camel());
                std::cout << "Верблюд успешно зарегистрирован!" << std::endl;
                break;
            case r::CAMEL_RUNNER:
                vehicles.insert(new CamelRunner());
                std::cout << "Верблюд-быстроход успешно зарегистрирован!" << std::endl;
                break;
            case r::CENTAUR:
                vehicles.insert(new Centaur());
                std::cout << "Кентавр успешно зарегистрирован!" << std::endl;
                break;
            case r::BROOM:
                vehicles.insert(new Broom());
                std::cout << "Метла успешно зарегистрирован!" << std::endl;
                break;
            case r::EAGLE:
                vehicles.insert(new Eagle());
                std::cout << "Орёл успешно зарегистрирован!" << std::endl;
                break;
            case r::CARPET:
                vehicles.insert(new MagicCarpet());
                std::cout << "Ковёр-самолёт успешно зарегистрирован!" << std::endl;
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