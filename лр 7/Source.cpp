#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

// ���� Employee ��� ����� �������� ���� �� ��������� ������ ����������
class Employee {
private:
    int workedHours;      // ʳ������ ������������� �����
    double hourlyRate;    // ��������� ������

public:
    // ����������� �����, ���� �������� ������� ����� � ��������� ������
    Employee(int hours, double rate) : workedHours(hours), hourlyRate(rate) {}

    // ����� ��� ��������� ������� ������������� �����
    int getWorkedHours() const {
        return workedHours;
    }

    // ����� ��� ��������� ��������� ������
    double getHourlyRate() const {
        return hourlyRate;
    }

    // ����� ��� ���������� �������� ����������
    double calculateSalary() const {
        return workedHours * hourlyRate;
    }
};

int main() {
    srand(time(nullptr)); // ����������� ���������� ���������� �����

    const int numEmployees = 5; // ʳ������ ����������
    vector<::unique_ptr<Employee>> employees; // ��������� ��� ��������� ����������

    // ��������� ���������� ������� ����� �� ������ ��� ������� ����������
    for (int i = 0; i < numEmployees; ++i) {
        int hours = rand() % 161; // ��������� ������� �����: �� 0 �� 160
        double rate = static_cast<double>(rand() % 20001) / 100.0; // ��������� ������: �� 0.0 �� 200.0
        employees.push_back(make_unique<Employee>(hours, rate)); // ��������� ���������� �� ����������
    }

    double totalCompanyExpense = 0.0; // ������� ������� ������ �� ������ �����

    // ��������� ���������� ��� ������� ���������� �� ��������� ������ ������
    for (const auto& employee : employees) {
        cout << "Employee: " << employee->getWorkedHours()
            << " hours, Rate: $" << employee->getHourlyRate()
            << "/hour, Salary: $" << employee->calculateSalary() << '\n';
        totalCompanyExpense += employee->calculateSalary(); // ��������� �������� �� ��������� ������
    }

    // ��������� ��������� ������ ������
    cout << "Total company expense: $" << totalCompanyExpense << '\n';

    return 0; // ���������� ��������
}
