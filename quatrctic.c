// BY: Menagkuol bros smos
//quadratic equation ax² + bx + c = 0
#include <stdio.h>
#include <math.h>

typedef enum {
    TWO_REAL_ROOTS,
    ONE_REAL_ROOT,
    COMPLEX_ROOTS,
    NOT_QUADRATIC
} RootType;

typedef struct {
    RootType type;
    double real1, imag1;
    double real2, imag2;
} QuadraticResult;

QuadraticResult solve_quadratic(double a, double b, double c) {
    QuadraticResult result = {0};

    if (a == 0.0) {
        result.type = NOT_QUADRATIC;
        return result;
    }

    double discriminant = b * b - 4.0 * a * c;

    if (discriminant > 0.0) {
        result.type = TWO_REAL_ROOTS;
        result.real1 = (-b + sqrt(discriminant)) / (2.0 * a);
        result.real2 = (-b - sqrt(discriminant)) / (2.0 * a);
    } else if (discriminant == 0.0) {
        result.type = ONE_REAL_ROOT;
        result.real1 = result.real2 = -b / (2.0 * a);
    } else {
        result.type = COMPLEX_ROOTS;
        result.real1 = result.real2 = -b / (2.0 * a);
        result.imag1 = sqrt(-discriminant) / (2.0 * a);
        result.imag2 = -result.imag1;
    }

    return result;
}

void print_result(QuadraticResult r) {
    switch (r.type) {
        case TWO_REAL_ROOTS:
            printf("Two real roots:\n  x1 = %.6f\n  x2 = %.6f\n", r.real1, r.real2);
            break;
        case ONE_REAL_ROOT:
            printf("One repeated root:\n  x = %.6f\n", r.real1);
            break;
        case COMPLEX_ROOTS:
            printf("Two complex roots:\n  x1 = %.6f + %.6fi\n  x2 = %.6f - %.6fi\n",
                   r.real1, r.imag1, r.real2, r.imag1);
            break;
        case NOT_QUADRATIC:
            printf("Error: 'a' cannot be zero (not a quadratic equation).\n");
            break;
    }
}

int main(void) {
    double a, b, c;

    printf("Solve: ax^2 + bx + c = 0\n");
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter c: ");
    scanf("%lf", &c);

    printf("\nEquation: %.4gx^2 + %.4gx + %.4g = 0\n", a, b, c);
    print_result(solve_quadratic(a, b, c));

    return 0;
}