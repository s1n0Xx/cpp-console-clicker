#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <conio.h>

using namespace std;

void showUpgrades(int& score, int& clickPower, int& autoIncome, int& upgradeCost, int& autoCost) {
    while (true) {
        system("cls");
        cout << "Улучшения\n";
        cout << "Очки: " << score << "\n\n";

        cout << "1. Увеличить клик (+" << clickPower << ") Цена: " << upgradeCost << endl;
        cout << "2. Автодоход (+1/сек) Цена: " << autoCost << endl;
        cout << "0. Назад\n";

        char choice = _getch();

        if (choice == '1') {
            if (score >= upgradeCost) {
                score -= upgradeCost;
                clickPower++;
                upgradeCost *= 2;
            }
            else {
                cout << "\nНедостаточно очков!";
                system("pause");
            }
        }
        else if (choice == '2') {
            if (score >= autoCost) {
                score -= autoCost;
                autoIncome++;
                autoCost *= 2;
            }
            else {
                cout << "\nНедостаточно очков!";
                system("pause");
            }
        }
        else if (choice == '0') {
            break;
        }
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    int score = 0;
    int clickPower = 1;
    int autoIncome = 0;
    int upgradeCost = 10;
    int autoCost = 20;

    int timer = 0; 

    while (true) {
        system("cls");

        cout << "Игра\n";
        cout << "Очки: " << score
            << " | Клик: " << clickPower
            << " | Авто/сек: " << autoIncome << "\n\n";

        cout << "c — клик | u — улучшения | q — выход\n";

        if (_kbhit()) {
            char input = _getch();

            if (input == 'c') {
                score += clickPower;
            }
            else if (input == 'u') {
                showUpgrades(score, clickPower, autoIncome, upgradeCost, autoCost);
            }
            else if (input == 'q') {
                break;
            }
        }

        timer++;
        if (timer >= 10) {
            score += autoIncome;
            timer = 0;
        }

        this_thread::sleep_for(chrono::milliseconds(100)); 
    }

    return 0;
}