#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int score = 0;
    char input;

    std::cout << "Нажми 'c' чтобы кликать, 'q' чтобы выйти\n";

    while (true) {
        std::cin >> input;

        if (input == 'c') {
            score++;
            std::cout << "Очки: " << score << std::endl;
        }
        else if (input == 'q') {
            break;
        }
    }

    return 0;
}