Домашнее задание к работе номер 10

Условие задачи: Составьте программу, которая для заданной пользователем фигуры (например, прямоугольника или круга) предлагает меню выбора одной из операций: рассчитать площадь; вывести определение фигуры; нарисовать фигуру.
Для каждой операции реализуйте отдельную функцию (площади, вывода текста, рисования). Предусмотреть функцию сравнения двух кругов по площади.

1. Алгоритм и блок-схема.
   
Алгоритм:

Начало.
Вывод главного меню (1 - Прямоугольник, 2 - Круг, 3 - Сравнить круги).
Ввод выбора фигуры.
Если выбрана фигура (1 или 2):
a. Вывод меню действий (1 - Площадь, 2 - Определение, 3 - Рисовать).
b. Ввод действия.
c. В зависимости от действия вызывается соответствующая функция (area_..., print_def_..., draw_...).
d. Вывод результата.
Если выбрано сравнение (3): запрос двух радиусов, вызов функции compare_round, вывод разницы.
Конец.

Блок-схема:

<img width="1655" height="847" alt="image" src="https://github.com/user-attachments/assets/b80889e2-0079-4c18-8723-440bec8c3068" />


2. Реализация программы

#include <stdio.h>
#include <math.h>
#include <locale.h>

#define PI 3.14159265

// --- ФУНКЦИИ ДЛЯ ПРЯМОУГОЛЬНИКА ---
float area_rectangle(float a, float b) {
    return a * b;
}

void print_def_rectangle() {
    printf("\nПрямоугольник — это четырехугольник, у которого все углы прямые.\n");
}

void draw_rectangle(int a, int b, char sym) {
    printf("\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (i == 0 || i == a - 1 || j == 0 || j == b - 1) printf("%c", sym);
            else printf(" ");
        }
        printf("\n");
    }
}

// --- ФУНКЦИИ ДЛЯ КРУГА ---
float area_round(float r) {
    return PI * r * r;
}

void print_def_round() {
    printf("\nКруг — это множество точек плоскости, удаленных от центра на расстояние не больше радиуса.\n");
}

void draw_round(char sym, int r) {
    printf("\n");
    for (int y = r; y >= -r; y--) {
        for (int x = -r; x <= r; x++) {
            if (x * x + y * y <= r * r) printf("%c", sym);
            else printf(" ");
        }
        printf("\n");
    }
}

// --- ФУНКЦИЯ СРАВНЕНИЯ (Возвращает разницу площадей) ---
float compare_round(int a, int b) {
    float s1 = area_round(a);
    float s2 = area_round(b);
    if (s1 > s2) return s1 - s2;
    if (s2 > s1) return s2 - s1;
    return 0;
}

// --- ГЛАВНАЯ ФУНКЦИЯ ---
int main() {
    setlocale(LC_ALL, "RUS");
    int fig_choice, act_choice;
    float a, b, r;
    char sym;

    printf("Выберите фигуру:\n1 - Прямоугольник\n2 - Круг\n3 - Сравнить два круга\nВаш выбор: ");
    scanf("%d", &fig_choice);

    if (fig_choice == 1) {
        printf("\nДействия:\n1 - Площадь\n2 - Определение\n3 - Нарисовать\nВаш выбор: ");
        scanf("%d", &act_choice);
        if (act_choice == 1) {
            printf("Введите стороны a и b: "); scanf("%f %f", &a, &b);
            printf("Площадь = %.2f\n", area_rectangle(a, b));
        } else if (act_choice == 2) {
            print_def_rectangle();
        } else if (act_choice == 3) {
            printf("Введите высоту, ширину и символ: "); scanf("%f %f %c", &a, &b, &sym);
            draw_rectangle((int)a, (int)b, sym);
        }
    } 
    else if (fig_choice == 2) {
        printf("\nДействия:\n1 - Площадь\n2 - Определение\n3 - Нарисовать\nВаш выбор: ");
        scanf("%d", &act_choice);
        if (act_choice == 1) {
            printf("Введите радиус R: "); scanf("%f", &r);
            printf("Площадь = %.2f\n", area_round(r));
        } else if (act_choice == 2) {
            print_def_round();
        } else if (act_choice == 3) {
            printf("Введите радиус и символ: "); scanf("%f %c", &r, &sym);
            draw_round(sym, (int)r);
        }
    }
    else if (fig_choice == 3) {
        int r1, r2;
        printf("Введите два радиуса: "); scanf("%d %d", &r1, &r2);
        float diff = compare_round(r1, r2);
        if (diff == 0) printf("Круги равны.\n");
        else printf("Разница площадей: %.2f\n", diff);
    }
    return 0;
}

3. Результаты работы программы
   
Случай 1 (Площадь прямоугольника):
Выберите фигуру:
1 - Прямоугольник
2 - Круг
3 - Сравнить два круга
Ваш выбор: 1
Действия:
1 - Площадь
2 - Определение
3 - Нарисовать
Ваш выбор: 1
Введите стороны a и b: 4 5
Площадь = 20.00

Случай 2 (Сравнение кругов):
Выберите фигуру:
1 - Прямоугольник
2 - Круг
3 - Сравнить два круга
Ваш выбор: 3
Введите два радиуса: 5 3
Разница площадей: 50.27

4. Информация о разработчике
Митин Михаил Александрович, бТИИ-261
