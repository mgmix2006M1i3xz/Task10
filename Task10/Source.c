#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI            3.14159265358979323846

double fa(double x) {
    double y;
    if (x <= 3) {
        y = x * x - 3 * x + 9; // x^2 - 3x + 9
    }
    else {
        y = 1.0 / (x * x * x + 3); // 1 / (x^3 + 3)
    }
    return y;
}

double fb(double x) {
    double y;
    // pow(x, 2) возводит x в квадрат, sin() вычисляет синус, exp() - экспоненту
    y = x * exp(sin(pow(x, 2)));
    return y;
}

int word1() {
    double x;
    int choice;

    printf("Введите значение x: ");
    scanf("%lf", &x);

    // 4. Меню для выбора расчета
    printf("\nВыберите действие:\n");
    printf("1 - Вычислить fa(x)\n");
    printf("2 - Вычислить fb(x)\n");
    printf("3 - Вычислить произведение fa(x) * fb(x)\n");
    printf("4 - Вычислить разность квадратов fa(x)^2 - fb(x)^2\n");
    printf("5 - Вычислить удвоенную сумму 2 * (fa(x) + fb(x))\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    printf("\nРезультаты:\n");
    // 2. Вывод значений функций
    printf("fa(x) = %lf, fb(x) = %lf\n", fa(x), fb(x));

    // 3 и 4. Вывод результатов операций в зависимости от выбора
    switch (choice) {
    case 1:
        printf("Значение fa(x) = %lf\n", fa(x));
        break;
    case 2:
        printf("Значение fb(x) = %lf\n", fb(x));
        break;
    case 3:
        printf("Произведение: %lf\n", fa(x) * fb(x));
        break;
    case 4:
        printf("Разность квадратов: %lf\n", pow(fa(x), 2) - pow(fb(x), 2));
        break;
    case 5:
        printf("Удвоенная сумма: %lf\n", 2 * (fa(x) + fb(x)));
        break;
    default:
        printf("Неверный выбор.\n");
    }

    return 0;
}

    // 2) Собственная функция (сумма N членов ряда)
    double arcsin_n(double x, int N) {
    double sum = x; // Первый член ряда
    double term = x; // Текущий член

    for (int k = 1; k <= N; k++) {
        // Вычисление следующего члена по рекуррентной формуле
        term = term * (pow(2 * k - 1, 2) * x * x) / ((2 * k) * (2 * k + 1));
        sum += term;
    }
    return sum;
}

// 3) Собственная функция (с заданной точностью eps)
double arcsin_eps(double x, double eps) {
    double sum = x;
    double term = x;
    int k = 1;

    // Пока модуль текущего члена больше точности
    while (fabs(term) > eps) {
        term = term * (pow(2 * k - 1, 2) * x * x) / ((2 * k) * (2 * k + 1));
        sum += term;
        k++;
    }
    return sum;
}

int word2() {
    double x, eps;
    int N;

    printf("Введите x (|x| < 1): ");
    scanf("%lf", &x);
    printf("Введите N (количество членов ряда): ");
    scanf("%d", &N);
    printf("Введите точность eps (например, 0.000001): ");
    scanf("%lf", &eps);

    // 1) Стандартная функция
    double std_res = asin(x);
    // 2) По количеству членов
    double n_res = arcsin_n(x, N);
    // 3) С точностью
    double eps_res = arcsin_eps(x, eps);

    // 4) Сравнение результатов
    printf("\nРезультаты вычисления arcsin(%lf):\n", x);
    printf("1) Стандартная библиотека: %lf\n", std_res);
    printf("2) Ряд (N=%d членов):    %lf (Отклонение: %e)\n", N, n_res, fabs(std_res - n_res));
    printf("3) Ряд (точность %lf):   %lf (Отклонение: %e)\n", eps, eps_res, fabs(std_res - eps_res));

    return 0;
}

// Вычисление площади прямоугольника
float area_rectangle(float a, float b) {
    return a * b;
}

// Рисование прямоугольника
void draw_rectangle(int a, int b, char symbol) {
    printf("\nРисуем прямоугольник %dx%d:\n", a, b);
    for (int i = 0; i < a; i++) {       // Цикл строк (высота)
        for (int j = 0; j < b; j++) {   // Цикл столбцов (ширина)
            // Рисуем контур
            if (i == 0 || i == a - 1 || j == 0 || j == b - 1) {
                printf("%c", symbol);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// --- Функции для работы с КРУГОМ ---

// Вычисление площади круга
float area_circle(float r) {
    return M_PI * r * r; // M_PI из math.h
}

// Рисование круга (упрощенное, вписанное в квадрат)
void draw_circle(int r, char symbol) {
    printf("\nРисуем круг радиусом %d:\n", r);
    // Упрощенный алгоритм для консоли
    for (int y = r; y >= -r; y--) {
        for (int x = -r; x <= r; x++) {
            // Уравнение окружности: x^2 + y^2 <= r^2
            if (x * x + y * y <= r * r) {
                printf("%c", symbol);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Функция сравнения двух кругов по площади
int compare_round(int r1, int r2) {
    float s1 = area_circle(r1);
    float s2 = area_circle(r2);
    if (s1 > s2) return 1;
    if (s1 < s2) return -1;
    return 0; // Равны
}

int word3() {
    int choice;

    printf("Выберите фигуру:\n1 - Прямоугольник\n2 - Круг\nВаш выбор: ");
    scanf("%d", &choice);

    if (choice == 1) {
        float a, b;
        char sym;
        printf("Введите стороны прямоугольника (a и b) и символ: ");
        scanf("%f %f %c", &a, &b, &sym); // Вводить через пробел: 5 10 *

        printf("Площадь: %.2f\n", area_rectangle(a, b));
        draw_rectangle((int)a, (int)b, sym); // Приводим float к int для циклов

    }
    else if (choice == 2) {
        float r;
        char sym;
        printf("Введите радиус круга и символ: ");
        scanf("%f %c", &r, &sym);

        printf("Площадь: %.2f\n", area_circle(r));
        draw_circle((int)r, sym);

        // Демонстрация функции сравнения
        int r2;
        printf("Введите второй радиус для сравнения: ");
        scanf("%d", &r2);
        int cmp = compare_round((int)r, r2);
        if (cmp == 1) printf("Первый круг больше.\n");
        else if (cmp == -1) printf("Второй круг больше.\n");
        else printf("Круги равны по площади.\n");

    }
    else {
        printf("Неверный ввод.\n");
    }

    return 0;
}


int main() {

    setlocale(LC_ALL, "Rus");
    word1();
    word2();
    word3();

    return 0;
}