#include <iostream>
#include <string>
#include <cstring>
#include "../include/math_operations.h"

void print_help() {
    std::cout << "Калькулятор - программа для выполнения базовых арифметических операций\n\n";
    std::cout << "Использование: calculator <операция> <операнд1> <операнд2>\n";
    std::cout << "Доступные операции:\n";
    std::cout << "  add      - сложение (a + b)\n";
    std::cout << "  sub      - вычитание (a - b)\n";
    std::cout << "  mul      - умножение (a * b)\n";
    std::cout << "  div      - деление (a / b) с выводом целой части и остатка\n";
    std::cout << "  author   - информация об авторе\n";
    std::cout << "  help     - эта справка\n\n";
    std::cout << "Пример: calculator add 5 3\n\n";
    std::cout << get_author_info() << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    std::string operation = argv[1];

    if (operation == "help") {
        print_help();
        return 0;
    }

    if (operation == "author") {
        std::cout << get_author_info() << "\n";
        return 0;
    }

    if (argc != 4) {
        std::cerr << "Ошибка: неверное количество аргументов\n";
        print_help();
        return 1;
    }

    int a = std::stoi(argv[2]);
    int b = std::stoi(argv[3]);

    if (operation == "add") {
        std::cout << "Результат: " << add(a, b) << "\n";
    } else if (operation == "sub") {
        std::cout << "Результат: " << subtract(a, b) << "\n";
    } else if (operation == "mul") {
        std::cout << "Результат: " << multiply(a, b) << "\n";
    } else if (operation == "div") {
        if (b == 0) {
            std::cerr << "Ошибка: деление на ноль\n";
            return 1;
        }
        DivisionResult result = divide(a, b);
        std::cout << "Целая часть: " << result.quotient << "\n";
        std::cout << "Остаток: " << result.remainder << "\n";
    } else {
        std::cerr << "Ошибка: неизвестная операция\n";
        print_help();
        return 1;
    }

    return 0;
}