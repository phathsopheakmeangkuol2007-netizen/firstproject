#include <stdio.h>
#include <math.h>

// Returns number of real roots found (0, 1, or 2)
int solveQuadratic(double a, double b, double c, double *root1, double *root2) {
    if (a == 0) {
        // Not actually quadratic — handle as linear: bx + c = 0
        if (b == 0) {
            return 0; // No solution (or infinite if c == 0 too)
        }
        *root1 = -c / b;
        return 1;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double sqrtD = sqrt(discriminant);
        *root1 = (-b + sqrtD) / (2 * a);
        *root2 = (-b - sqrtD) / (2 * a);
        return 2;
    } else if (discriminant == 0) {
        *root1 = -b / (2 * a);
        return 1;
    } else {
        return 0; // Complex roots, no real solutions
    }
}

int main(void) {
    double a, b, c, root1, root2;

    printf("Enter coefficients a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    int numRoots = solveQuadratic(a, b, c, &root1, &root2);

    switch (numRoots) {
        case 2:
            printf("Two real roots: x1 = %.4f, x2 = %.4f\n", root1, root2);
            break;
        case 1:
            printf("One real root: x = %.4f\n", root1);
            break;
        case 0:
            printf("No real roots.\n");
            break;
    }

    return 0;
}