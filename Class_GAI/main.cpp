#include <iostream>
#include <Windows.h>
#include <vector>
#include "Node.h"
#include <string>
#include "GaiDatabase.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);

    GaiDatabase database;
    database.addZalet("A123BC-40", "Превышение скорости");
    database.addZalet("X789YZ-97", "Неправильная парковка");
    database.addZalet("A123BC-197", "Проезд на красный свет");
    database.addZalet("A123DE-98", "Не пристёгнутый ремень");
    database.addZalet("A123DE-98", "Проезд на красный свет");
    database.addZalet("D456EF-77", "Использование телефона во время движения");

    cout << "Полная база данных ГАИ:" << endl;
    database.showDatabase();
    cout << endl;

    cout << "Данные по номеру A123BC-40:" << endl;
    database.showByNomer("A123BC-40");
    cout << endl;

    cout << "Данные по диапазону номеров от A123BC-40 до X789YZ-97:" << endl;
    database.showByRange("A123BC-40", "X789YZ-97");

    return 0;
}