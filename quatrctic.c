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
    double real1, imag1;  // First root
    double real2, imag2;  // Second root
} QuadraticResult;

QuadraticResult solve_quadratic(double a, double b, double c) {
    QuadraticResult result = {0};

    if (a == 0.0) {
        result.type = NOT_QUADRATIC;
        return result;
    }

    double discriminant = b * b - 4.0 * a * c;

    if (discriminant > 0.0) {
        // Two distinct real roots
        result.type = TWO_REAL_ROOTS;
        result.real1 = (-b + sqrt(discriminant)) / (2.0 * a);
        result.real2 = (-b - sqrt(discriminant)) / (2.0 * a);
    } else if (discriminant == 0.0) {
        // One repeated real root
        result.type = ONE_REAL_ROOT;
        result.real1 = result.real2 = -b / (2.0 * a);
    } else {
        // Two complex conjugate roots
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

// Example usage
int main(void) {
    // x^2 - 5x + 6 = 0  → roots: 3, 2
    print_result(solve_quadratic(1, -5, 6));

    // x^2 - 2x + 1 = 0  → root: 1 (repeated)
    print_result(solve_quadratic(1, -2, 1));

    // x^2 + x + 1 = 0   → complex roots
    print_result(solve_quadratic(1, 1, 1));

    return 0;
}