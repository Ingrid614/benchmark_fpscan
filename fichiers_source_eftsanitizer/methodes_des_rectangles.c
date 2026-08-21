#include <stdio.h>
#include <math.h>

double f(double x) {
    return sin(x); 
}

int main(int argc, char *argv[]) {
    double a = 0.0;
    double b = 6.283185307179586; // 2 * pi
    int n = 100; // Nombre des rectangles
    double longueur = (b - a) / n;
    double aire_inf = 0.0, aire_sup = 0.0;

    for (int k = 0; k < n; k++) {
        aire_inf += longueur * f(a + k * longueur);
        aire_sup += longueur * f(a + (k + 1) * longueur);
    }

    printf("Aire inférieure: %.20e\n", aire_inf);
    printf("Aire supérieure: %.20e\n", aire_sup);

    return 0;
}