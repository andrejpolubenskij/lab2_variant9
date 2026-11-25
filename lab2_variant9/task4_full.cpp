// Задание 4. Парковка: полный расчёт.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    char code;
    int hours;
    int weekend;
    int lostTicket;

    cout << "Введите код транспорта (C - автомобиль, M - мотоцикл, B - автобус): ";
    cin >> code;

    cout << "Введите количество часов (1..24): ";
    cin >> hours;

    cout << "Выходной день (1 - да, 0 - нет): ";
    cin >> weekend;

    cout << "Талон потерян (1 - да, 0 - нет): ";
    cin >> lostTicket;

    if (hours < 1 || hours > 24) {
        cout << "Ошибка: количество часов должно быть от 1 до 24." << endl;
        return 1;
    }

    if (weekend != 0 && weekend != 1) {
        cout << "Ошибка: признак выходного дня должен быть 0 или 1." << endl;
        return 1;
    }

    if (lostTicket != 0 && lostTicket != 1) {
        cout << "Ошибка: признак потерянного талона должен быть 0 или 1." << endl;
        return 1;
    }

    double rate;
    double fine;
    string name;

    switch (code) {
        case 'C':
            rate = 4.0;
            fine = 50.0;
            name = "Автомобиль";
            break;
        case 'M':
            rate = 2.0;
            fine = 25.0;
            name = "Мотоцикл";
            break;
        case 'B':
            rate = 7.0;
            fine = 80.0;
            name = "Автобус";
            break;
        default:
            cout << "Ошибка: неизвестный код транспорта." << endl;
            return 1;
    }

    double cost;
    string rule;

    if (lostTicket == 1) {
        cost = fine;
        rule = "потерянный талон — фиксированный штраф";
    }
    else {
        int paidHours = hours > 8 ? 8 : hours;
        cost = paidHours * rate;

        if (weekend == 1 && code != 'M') {
            cost = cost * 1.2;
            rule = "оплата максимум 8 часов, выходная надбавка 20 %";
        }
        else if (weekend == 1) {
            rule = "оплата максимум 8 часов, для мотоцикла выходная надбавка не действует";
        }
        else {
            rule = "оплата максимум 8 часов";
        }
    }

    cout << fixed << setprecision(2);
    cout << "Тип транспорта: " << name << endl;
    cout << "Правило: " << rule << endl;
    cout << "Итог: " << cost << endl;

    return 0;
}
