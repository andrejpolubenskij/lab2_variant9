// Задание 2. Потерянный талон и выходной день.

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int hours;
    int weekend;
    int lostTicket;

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

    double cost;

    if (lostTicket == 1) {
        cost = 50.0;
    }
    else {
        // Первые 8 часов по 3, сверх 8 часов время не увеличивает стоимость.
        int paidHours = hours > 8 ? 8 : hours;
        cost = paidHours * 3.0;

        if (weekend == 1) {
            cost = cost * 1.2;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Стоимость парковки: " << cost << endl;

    return 0;
}
