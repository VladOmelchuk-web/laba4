#include <Windows.h>
#include <iostream>
using namespace std;

void division(float)
{
    cout << "Введите два числа: \n";
    int a, b;
    cin >> a >> b;
    cout << "Результат равен: " << a / b;
}
void multiplication(float)
{
    cout << "Введите два числа: \n";
    int a, b;
    cin >> a >> b;
    cout << "Результат равен: " << a*b;
}
void sum(float)
{
    cout << "Введите два числа: \n";
    int a, b;
    cin >> a >> b;
    cout << "Результат равен: " << a + b;
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    void (*P[3])(float) = { division,multiplication,sum };
    cout << "1.Деление двух чисел\n";
    cout << "2.Умножение двух чисел\n";
    cout << "3.Сумма двух чисел\n";
    cout << "  Какую из трех функций выбрать?\n ";
    int i;
    cin >> i;
    i--;
    (*P[i])(i);
    return 0;
}
