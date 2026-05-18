/*
 * Лабораторная работа №1
 * Студент: Валиев Марсель (номер: 6)
 * Вариант: 7
 * Задание: 22 (Корни квадратного уравнения )
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c;

    printf("Solve quadratic equation ax^2 + bx + c = 0\n");
    printf("Enter coefficients a, b, c (separated by spaces): ");

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        fprintf(stderr, "Error: please enter three numbers.\n");
        return 1;
    }

    // Handle the case when it is not a quadratic equation (a == 0)
    if (fabs(a) < 1e-12) {   // treat a == 0 with tolerance
        if (fabs(b) < 1e-12) {
            if (fabs(c) < 1e-12) {
                printf("Infinite solutions (identity).\n");
            } else {
                printf("No solution (contradiction).\n");
            }
        } else {
            double x = -c / b;
            printf("Linear equation, one root: x = %.6f\n", x);
        }
        return 0;
    }

    // Discriminant
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("No real roots (discriminant < 0).\n");
    } else if (fabs(discriminant) < 1e-12) {   // discriminant ≈ 0
        double x = -b / (2 * a);
        printf("One double root: x = %.6f\n", x);
    } else {
        double sqrt_d = sqrt(discriminant);
        double x1 = (-b - sqrt_d) / (2 * a);
        double x2 = (-b + sqrt_d) / (2 * a);
        printf("Two real roots:\n");
        printf("x1 = %.6f\n", x1);
        printf("x2 = %.6f\n", x2);
    }

    return 0;
}