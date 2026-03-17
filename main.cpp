#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int score = 0;
    int clickPower = 1;
    int autoIncome = 0;
    int upgradeCost = 10;
    int autoCost = 20;
    char input;

    cout << "c — клик | u — улучшение | a — авто | q — выход\n";

    while (true) {
        system("cls");

        score += autoIncome;

        cout << "Очки: " << score
            << " | Клик: " << clickPower
            << " | Авто: " << autoIncome << endl;

        cout << "Введите команду: ";
        cin >> input;

        if (input == 'c') {
            score += clickPower;
        }
        else if (input == 'u') {
            if (score >= upgradeCost) {
                score -= upgradeCost;
                clickPower++;
                upgradeCost *= 2;
                cout << "Улучшение куплено!\n";
            }
            else {
                cout << "Недостаточно очков!\n";
            }
        }
        else if (input == 'a') {
            if (score >= autoCost) {
                score -= autoCost;
                autoIncome++;
                autoCost *= 2;
                cout << "Автодоход увеличен!\n";
            }
            else {
                cout << "Недостаточно очков!\n";
            }
        }
        else if (input == 'q') {
            break;
        }
    }

    return 0;
}