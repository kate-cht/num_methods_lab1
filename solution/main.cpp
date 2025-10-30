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
    std::cout << "\n=== ���������� ===" << std::endl;
    std::cout << "���������� �����: " << info.n << std::endl;
    std::cout << "���������� �� �������: " << info.B_xn << std::endl;
    std::cout << "������������ ���: " << info.MaxOLP << std::endl;
    std::cout << "�������� ����: " << info.DoublingCount << std::endl;
    std::cout << "���������� ����: " << info.ReductionCount << std::endl;
    std::cout << "������������ ���: " << info.max_hi_xi.first << " � ����� x=" << info.max_hi_xi.second << std::endl;
    std::cout << "����������� ���: " << info.min_hi_xi.first << " � ����� x=" << info.min_hi_xi.second << std::endl;
    std::cout << "������������ �������� |U-V|: " << info.maxU_V.second << " � ����� x=" << info.maxU_V.first << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // ���������: A, B, H, u0, E_border, E_error, Nmax
    double A = 4.0;      // ������ ���������
    double B = 10.0;      // ����� ���������  
    double H = 0.1;      // ��������� ���
    double u0 = 1.0;     // ��������� �������
    double E_border = 1e-6;  // ����������� �������
    double E_error = 1e-6;   // ���������� �����������
    int Nmax = 1000;     // ������������ ����� ��������

    std::cout << "=== ������� ��� �������� ����������� ===" << std::endl;
    //TestTask task1(A, B, H, u0, E_border, E_error, Nmax);
    SecondTask task1(A, B, H, u0, E_border, E_error, Nmax);
    task1.Solve_Without_Control();
    printTable(task1.get_table());
    printInfo(task1.get_info());

    std::cout << "\n\n=== ������� � ��������� ����������� ===" << std::endl;
    SecondTask task2(A, B, H, u0, E_border, E_error, Nmax);
    task2.Solve_With_Control();

    // ��� ������ � ��������� ������� ����� ������ ������
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

    // �������� ������� ������� � �������� �����
    double exact_solution = To_Find_True_Solution(B, u0);
    std::cout << "\n=== �������� ===" << std::endl;
    std::cout << "������ ������� � ����� x=" << B << ": " << exact_solution << std::endl;
    std::cout << "exp(2) = " << exp(2.0) << std::endl;

    std::list<std::vector<double>> table = task2.TABLE_INFORMATION;
    int size = (table.front()).size();
    std::cout << size << std::endl;
    for (auto it = table.begin(); it != table.end(); ++it) {
        std::cout << (*it).size() << "  " << (*it)[1] << "  " << (*it)[size - 2] << std::endl;
    }


    return 0;
}