// Задание 1. Стоимость парковки по диапазонам.

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int hours;

    cout << "Введите количество часов парковки (1..24): ";
    cin >> hours;

    if (hours < 1 || hours > 24) {
        cout << "Ошибка: количество часов должно быть от 1 до 24." << endl;
        return 1;
    }

    // Без циклов: три диапазона часов.
    double cost;

    if (hours == 1) {
        cost = 3.0;
    }
    else if (hours <= 5) {
        cost = 3.0 + (hours - 1) * 2.0;
    }
    else {
        cost = 3.0 + 4 * 2.0 + (hours - 5) * 1.5;
    }

    cout << fixed << setprecision(2);
    cout << "Стоимость парковки: " << cost << endl;

    return 0;
}
