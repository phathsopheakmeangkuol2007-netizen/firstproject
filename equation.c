#include <stdio.h>
#include <math.h>

void solve_quadratic(double a, double b, double c) {
    if (a == 0) {
        printf("Not a quadratic equation (a cannot be 0).\n");
        return;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        // Two distinct real roots
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two real roots: x1 = %.4f, x2 = %.4f\n", x1, x2);
    } 
    else if (discriminant == 0) {
        // One real root (repeated)
        double x = -b / (2 * a);
        printf("One real root: x = %.4f\n", x);
    } 
    else {
        // Two complex roots
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-discriminant) / (2 * a);
        printf("Two complex roots: x1 = %.4f + %.4fi, x2 = %.4f - %.4fi\n",
               realPart, imagPart, realPart, imagPart);
    }
}

int main() {
    double a, b, c;

    printf("Enter coefficients a, b, c (for ax^2 + bx + c = 0): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    solve_quadratic(a, b, c);

    return 0;
}