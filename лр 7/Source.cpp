#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

// Клас Employee для обліку робочого часу та погодинної оплати працівника
class Employee {
private:
    int workedHours;      // Кількість відпрацьованих годин
    double hourlyRate;    // Погодинна оплата

public:
    // Конструктор класу, який ініціалізує кількість годин і погодинну оплату
    Employee(int hours, double rate) : workedHours(hours), hourlyRate(rate) {}

    // Гетер для отримання кількості відпрацьованих годин
    int getWorkedHours() const {
        return workedHours;
    }

    // Гетер для отримання погодинної оплати
    double getHourlyRate() const {
        return hourlyRate;
    }

    // Метод для обчислення зарплати працівника
    double calculateSalary() const {
        return workedHours * hourlyRate;
    }
};

int main() {
    srand(time(nullptr)); // Ініціалізація генератора випадкових чисел

    const int numEmployees = 5; // Кількість працівників
    vector<::unique_ptr<Employee>> employees; // Контейнер для зберігання працівників

    // Генерація випадкових значень годин та ставок для кожного працівника
    for (int i = 0; i < numEmployees; ++i) {
        int hours = rand() % 161; // Випадкова кількість годин: від 0 до 160
        double rate = static_cast<double>(rand() % 20001) / 100.0; // Випадкова ставка: від 0.0 до 200.0
        employees.push_back(make_unique<Employee>(hours, rate)); // Додавання працівника до контейнера
    }

    double totalCompanyExpense = 0.0; // Загальні витрати компанії на оплату праці

    // Виведення інформації про кожного працівника та підрахунок витрат компанії
    for (const auto& employee : employees) {
        cout << "Employee: " << employee->getWorkedHours()
            << " hours, Rate: $" << employee->getHourlyRate()
            << "/hour, Salary: $" << employee->calculateSalary() << '\n';
        totalCompanyExpense += employee->calculateSalary(); // Додавання зарплати до загальних витрат
    }

    // Виведення загальних витрат компанії
    cout << "Total company expense: $" << totalCompanyExpense << '\n';

    return 0; // Завершення програми
}
