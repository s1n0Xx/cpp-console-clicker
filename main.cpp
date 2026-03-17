#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int score = 0;
    int clickPower = 1;
    int upgradeCost = 10;
    char input;

    cout << "c — клик | u — улучшение | q — выход\n";

    while (true) {
        cin >> input;

        if (input == 'c') {
            score += clickPower;
        }
        else if (input == 'u') {
            if (score >= upgradeCost) {
                score -= upgradeCost;
                clickPower++;
                upgradeCost *= 2;
                cout << "Улучшение куплено! Сила клика: " << clickPower << endl;
            }
            else {
                cout << "Недостаточно очков!\n";
            }
        }
        else if (input == 'q') {
            break;
        }

        cout << "Очки: " << score << " | Сила клика: " << clickPower << endl;
    }

    return 0;
}