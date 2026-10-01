/*
    Выполнил: Губин Константин

    Назначение программы:
        Демонстрация и тестирование пяти классов (инкапсуляция в C++):
            Bell             (задание 1) — попеременные звуки "ding"/"dong";
            OddEvenSeparator (задание 2) — разделение чисел на чётные/нечётные;
            Table            (задание 3) — двумерная таблица целых чисел;
            Complex          (задание 4) — комплексное число;
            Stock            (задание 5) — склад коробок.

    Ввод:  с клавиатуры через меню (приглашения выводятся на экран).
           Входных файлов нет.
    Вывод: результаты работы выбранного задания выводятся на экран.
*/

#include <iostream>
#include <limits>
#include <string>
#include <locale>

#include "Bell.h"
#include "OddEvenSeparator.h"
#include "Table.h"
#include "Complex.h"
#include "Stock.h"

// Очистка потока ввода после ошибки
static void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Ввод целого числа с проверкой формата («защита от дурака»)
static int readInt(const std::string& prompt) {
    int x;
    while (true) {
        std::cout << prompt;
        if (std::cin >> x) return x;
        std::cout << "Ошибка: нужно целое число. Повторите ввод.\n";
        clearInput();
    }
}

// Ввод целого числа с проверкой нижней границы
static int readIntMin(const std::string& prompt, int minValue) {
    int x = readInt(prompt);
    while (x < minValue) {
        std::cout << "Значение не может быть меньше " << minValue << ".\n";
        x = readInt(prompt);
    }
    return x;
}

// Ввод вещественного числа с проверкой формата
static double readDouble(const std::string& prompt) {
    double x;
    while (true) {
        std::cout << prompt;
        if (std::cin >> x) return x;
        std::cout << "Ошибка: нужно число. Повторите ввод.\n";
        clearInput();
    }
}

// ===================== Задание 1 =====================

static void taskBell() {
    std::cout << "\n=== Задание 1. Класс Bell ===\n";
    Bell bell;
    int n = readIntMin("Сколько раз позвонить (>=0)? ", 0);
    std::cout << "Результат:\n";
    for (int i = 0; i < n; ++i) bell.sound();
}

// ===================== Задание 2 =====================

static void taskSeparator() {
    std::cout << "\n=== Задание 2. Класс OddEvenSeparator ===\n";
    OddEvenSeparator sep;
    int n = readIntMin("Сколько чисел добавить (>=0)? ", 0);

    std::cout << "Введите " << n << " целых чисел (через Enter):\n";
    for (int i = 0; i < n; ++i)
        sep.add_number(readInt("  Число: "));

    std::cout << "Чётные:   "; sep.even();
    std::cout << "Нечётные: "; sep.odd();
}

// ===================== Задание 3 =====================

static void taskTable() {
    std::cout << "\n=== Задание 3. Класс Table ===\n";
    int rows = readIntMin("Число строк (>=1): ", 1);
    int cols = readIntMin("Число столбцов (>=1): ", 1);

    Table t(rows, cols);
    std::cout << "Таблица после создания:\n";
    t.print();

    int count = readInt("Сколько ячеек заполнить? ");
    while (count < 0 || count > rows * cols) {
        std::cout << "Недопустимое число (0.." << rows * cols << ").\n";
        count = readInt("Сколько ячеек заполнить? ");
    }

    for (int i = 0; i < count; ++i) {
        int r = readInt("Строка: ");
        while (r < 0 || r >= rows) {
            std::cout << "Неверная строка (0.." << rows - 1 << ").\n";
            r = readInt("Строка: ");
        }
        int c = readInt("Столбец: ");
        while (c < 0 || c >= cols) {
            std::cout << "Неверный столбец (0.." << cols - 1 << ").\n";
            c = readInt("Столбец: ");
        }
        int v = readInt("Значение: ");
        t.set_value(r, c, v);
    }

    std::cout << "\nИтоговая таблица:\n";
    t.print();
    std::cout << "n_rows = " << t.n_rows()
        << ", n_cols = " << t.n_cols() << std::endl;
    std::cout << "Среднее арифметическое = " << t.average() << std::endl;
}

// ===================== Задание 4 =====================

static void taskComplex() {
    std::cout << "\n=== Задание 4. Класс Complex ===\n";
    std::cout << "Введите два комплексных числа.\n";

    double a = readDouble("z1.re = ");
    double b = readDouble("z1.im = ");
    double c = readDouble("z2.re = ");
    double d = readDouble("z2.im = ");

    Complex z1(a, b), z2(c, d);

    // Контрольный вывод введённых данных
    std::cout << "\n--- Введённые числа ---\n";
    std::cout << "z1 = "; z1.Print(); std::cout << "\n";
    std::cout << "z2 = "; z2.Print(); std::cout << "\n";

    // Формы записи
    std::cout << "\n--- Формы записи ---\n";
    std::cout << "z1 алг.:   "; z1.Print();     std::cout << "\n";
    std::cout << "z1 триг.:  "; z1.TrigPrint(); std::cout << "\n";
    std::cout << "z1 показ.: "; z1.ExpPrint();  std::cout << "\n";
    std::cout << "z2 алг.:   "; z2.Print();     std::cout << "\n";
    std::cout << "z2 триг.:  "; z2.TrigPrint(); std::cout << "\n";
    std::cout << "z2 показ.: "; z2.ExpPrint();  std::cout << "\n";

    // Модуль и аргумент
    std::cout << "\n--- Модуль и аргумент ---\n";
    std::cout << "|z1| = " << z1.Abs()
        << ", arg(z1) = " << z1.Arg() << " рад\n";
    std::cout << "|z2| = " << z2.Abs()
        << ", arg(z2) = " << z2.Arg() << " рад\n";

    // Арифметика
    std::cout << "\n--- Арифметика ---\n";
    std::cout << "z1 + z2 = "; z1.Add(z2).Print(); std::cout << "\n";
    std::cout << "z1 - z2 = "; z1.Sub(z2).Print(); std::cout << "\n";
    std::cout << "z1 * z2 = "; z1.Mult(z2).Print(); std::cout << "\n";

    try {
        std::cout << "z1 / z2 = "; z1.Div(z2).Print(); std::cout << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка деления: " << e.what() << std::endl;
    }

    // Set/Get
    std::cout << "\n--- Демонстрация Set/Get ---\n";
    Complex z3;
    std::cout << "z3 (по умолчанию) = "; z3.Print(); std::cout << "\n";
    z3.SetRe(3.0);
    z3.SetIm(-4.0);
    std::cout << "z3 после Set(3, -4) = "; z3.Print(); std::cout << "\n";
    std::cout << "GetRe() = " << z3.GetRe()
        << ", GetIm() = " << z3.GetIm() << std::endl;
    std::cout << "|z3| = " << z3.Abs() << " (ожидается 5)\n";
}

// ===================== Задание 5 =====================

static void taskStockMenu() {
    std::cout << "\n=== Задание 5. Класс Stock ===\n";
    Stock stock;

    while (true) {
        std::cout << "\n  Подменю Stock:\n"
            "    1 - Добавить коробку\n"
            "    2 - Выдать по грузоподъёмности\n"
            "    3 - Выдать по объёму\n"
            "    4 - Показать склад\n"
            "    5 - Автотест на чистом складе\n"
            "    0 - Выход в главное меню\n";
        int ch = readInt("  Ваш выбор: ");

        if (ch == 0) return;

        switch (ch) {
        case 1: {
            int w = readIntMin("Грузоподъёмность w (>=0): ", 0);
            int v = readIntMin("Объём v (>=0): ", 0);
            stock.Add(w, v);
            std::cout << "Коробка добавлена.\n";
            break;
        }
        case 2: {
            int mw = readIntMin("min_w = ", 0);
            int r = stock.GetByW(mw);
            if (r == -1) std::cout << "Подходящей коробки нет.\n";
            else         std::cout << "Выдана коробка #" << r << "\n";
            break;
        }
        case 3: {
            int mv = readIntMin("min_v = ", 0);
            int r = stock.GetByV(mv);
            if (r == -1) std::cout << "Подходящей коробки нет.\n";
            else         std::cout << "Выдана коробка #" << r << "\n";
            break;
        }
        case 4: stock.PrintState(); break;
        case 5: {
            // Автоматический тест на отдельном складе
            Stock s;
            std::cout << "\nДобавим: (1,1),(2,2),(3,3),(1,5),(1,6)\n";
            s.Add(1, 1); s.Add(2, 2); s.Add(3, 3);
            s.Add(1, 5); s.Add(1, 6);
            s.PrintState();

            std::cout << "GetByW(2) -> " << s.GetByW(2) << " (ожидается 1)\n";
            std::cout << "GetByW(2) -> " << s.GetByW(2) << " (ожидается 2)\n";
            std::cout << "GetByW(2) -> " << s.GetByW(2) << " (ожидается -1)\n";
            std::cout << "GetByW(1) -> " << s.GetByW(1) << " (ожидается 4)\n";
            std::cout << "GetByW(1) -> " << s.GetByW(1) << " (ожидается 3)\n";
            s.PrintState();
            std::cout << "GetByV(1) -> " << s.GetByV(1) << " (ожидается 0)\n";
            std::cout << "GetByV(1) -> " << s.GetByV(1) << " (ожидается -1)\n";
            break;
        }
        default: std::cout << "Нет такого пункта.\n";
        }
    }
}

int main() {
    while (true) {
        std::cout << "\n========= Главное меню =========\n"
            "  1 - Задание 1. Bell\n"
            "  2 - Задание 2. OddEvenSeparator\n"
            "  3 - Задание 3. Table\n"
            "  4 - Задание 4. Complex\n"
            "  5 - Задание 5. Stock\n"
            "  0 - Выход\n";
        int choice = readInt("Ваш выбор: ");

        switch (choice) {
        case 1: taskBell();        break;
        case 2: taskSeparator();   break;
        case 3: taskTable();       break;
        case 4: taskComplex();     break;
        case 5: taskStockMenu();   break;
        case 0: std::cout << "До свидания!\n"; return 0;
        default: std::cout << "Нет такого пункта.\n";
        }
    }
}