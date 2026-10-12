#include <iostream>
#include <Windows.h>
#include "Angle.h"

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::cout << "--- Перевірка роботи статичної бібліотеки AngleLib ---\n" << std::endl;

    Angle a1;
    a1.Read();
    std::cout << "\nПерший кут: ";
    a1.Display();

    Angle a2;
    a2.Read();
    std::cout << "\nДругий кут: ";
    a2.Display();

    std::cout << "\nПерший кут у радіанах: " << a1.toRadians() << " рад" << std::endl;
    std::cout << "Синус першого кута: " << a1.getSine() << std::endl;

    int cmp = a1.compare(a2);
    if (cmp == 0) {
        std::cout << "Кути рівні." << std::endl;
    }
    else if (cmp > 0) {
        std::cout << "Перший кут більший за другий." << std::endl;
    }
    else {
        std::cout << "Перший кут менший за другий." << std::endl;
    }

    std::cout << "\nЗбільшуємо перший кут на величину другого:" << std::endl;
    a1.add(a2);
    std::cout << "Результат (a1): ";
    a1.Display();

    std::cout << "Зменшуємо перший кут на величину другого:" << std::endl;
    a1.subtract(a2);
    std::cout << "Результат (a1): ";
    a1.Display();

    return 0;
}