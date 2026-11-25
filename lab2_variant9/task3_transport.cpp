// Задание 3. Ставка по виду транспорта.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    char code;
    int hours;

    cout << "Введите код транспорта (C - автомобиль, M - мотоцикл, B - автобус): ";
    cin >> code;

    cout << "Введите количество часов (1..24): ";
    cin >> hours;

    if (hours < 1 || hours > 24) {
        cout << "Ошибка: количество часов должно быть от 1 до 24." << endl;
        return 1;
    }

    double rate;
    string name;

    switch (code) {
        case 'C':
            rate = 4.0;
            name = "Автомобиль";
            break;
        case 'M':
            rate = 2.0;
            name = "Мотоцикл";
            break;
        case 'B':
            rate = 7.0;
            name = "Автобус";
            break;
        default:
            cout << "Ошибка: неизвестный код транспорта." << endl;
            return 1;
    }

    // Дольше 8 часов расчёт ограничивается стоимостью 8 часов.
    int paidHours = hours > 8 ? 8 : hours;
    double cost = paidHours * rate;

    cout << fixed << setprecision(2);
    cout << "Тип транспорта: " << name << endl;
    cout << "Сумма: " << cost << endl;

    return 0;
}
