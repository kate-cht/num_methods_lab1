#include <iostream>
#include <iomanip>
#include "TestTask.h"
#include "FirstTask.h"
#include "SecondTask.h"
#include <locale>

void printTable(const std::list<std::vector<double>>& table) {
    std::cout << std::string(80, '-') << std::endl;
    std::cout << std::setw(5) << "i" << std::setw(12) << "x" << std::setw(12) << "V"
        << std::setw(12) << "h" << std::setw(12) << "U" << std::setw(12) << "|U-V|" << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    for (const auto& row : table) {
        if (row.size() >= 6) {
            std::cout << std::setw(5) << std::fixed << std::setprecision(0) << row[0]
                << std::setw(12) << std::fixed << std::setprecision(6) << row[1]
                << std::setw(12) << row[2] << std::setw(12) << row[3]
                << std::setw(12) << row[4] << std::setw(12) << row[5] << std::endl;
        }
    }
}

void printInfo(const TestTask::Info& info) {
    std::cout << "\n=== РЕЗУЛЬТАТЫ ===" << std::endl;
    std::cout << "Количество шагов: " << info.n << std::endl;
    std::cout << "Расстояние до границы: " << info.B_xn << std::endl;
    std::cout << "Максимальная ОЛП: " << info.MaxOLP << std::endl;
    std::cout << "Удвоений шага: " << info.DoublingCount << std::endl;
    std::cout << "Уменьшений шага: " << info.ReductionCount << std::endl;
    std::cout << "Максимальный шаг: " << info.max_hi_xi.first << " в точке x=" << info.max_hi_xi.second << std::endl;
    std::cout << "Минимальный шаг: " << info.min_hi_xi.first << " в точке x=" << info.min_hi_xi.second << std::endl;
    std::cout << "Максимальная разность |U-V|: " << info.maxU_V.second << " в точке x=" << info.maxU_V.first << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Параметры: A, B, H, u0, E_border, E_error, Nmax
    double A = 4.0;      // начало интервала
    double B = 10.0;      // конец интервала  
    double H = 0.1;      // начальный шаг
    double u0 = 1.0;     // начальное условие
    double E_border = 1e-6;  // окрестность границы
    double E_error = 1e-6;   // допустимая погрешность
    int Nmax = 1000;     // максимальное число итераций

    std::cout << "=== РЕШЕНИЕ БЕЗ КОНТРОЛЯ ПОГРЕШНОСТИ ===" << std::endl;
    //TestTask task1(A, B, H, u0, E_border, E_error, Nmax);
    SecondTask task1(A, B, H, u0, E_border, E_error, Nmax);
    task1.Solve_Without_Control();
    printTable(task1.get_table());
    printInfo(task1.get_info());

    std::cout << "\n\n=== РЕШЕНИЕ С КОНТРОЛЕМ ПОГРЕШНОСТИ ===" << std::endl;
    SecondTask task2(A, B, H, u0, E_border, E_error, Nmax);
    task2.Solve_With_Control();

    // Для метода с контролем таблица имеет другой формат
    auto table2 = task2.get_table();
    if (!table2.empty()) {
        std::cout << std::string(100, '-') << std::endl;
        std::cout << std::setw(5) << "i" << std::setw(10) << "x" << std::setw(12) << "V"
            << std::setw(12) << "V2" << std::setw(12) << "V-V2" << std::setw(12) << "OLP"
            << std::setw(10) << "h" << std::setw(8) << "red" << std::setw(8) << "dbl"
            << std::setw(12) << "U" << std::setw(12) << "|U-V|" << std::endl;
        std::cout << std::string(100, '-') << std::endl;

        for (const auto& row : table2) {
            for (size_t j = 0; j < row.size(); ++j) {
                std::cout << std::setw(j == 0 ? 5 : 12) << std::fixed << std::setprecision(6) << row[j];
            }
            std::cout << std::endl;
        }
    }

    printInfo(task2.get_info());

    // Проверка точного решения в конечной точке
    double exact_solution = To_Find_True_Solution(B, u0);
    std::cout << "\n=== ПРОВЕРКА ===" << std::endl;
    std::cout << "Точное решение в точке x=" << B << ": " << exact_solution << std::endl;
    std::cout << "exp(2) = " << exp(2.0) << std::endl;

    std::list<std::vector<double>> table = task2.TABLE_INFORMATION;
    int size = (table.front()).size();
    std::cout << size << std::endl;
    for (auto it = table.begin(); it != table.end(); ++it) {
        std::cout << (*it).size() << "  " << (*it)[1] << "  " << (*it)[size - 2] << std::endl;
    }


    return 0;
}