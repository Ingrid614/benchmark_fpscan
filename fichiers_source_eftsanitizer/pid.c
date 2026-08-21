#include <stdio.h>
#include <math.h>

#define N 100000

int main() {

    /* Gains PID */
    double Kp = 1e8;
    double Ki = 1e6;
    double Kd = 1e4;

    /* Pas de temps */
    double dt = 1e-6;

    /* Variables PID */
    double integral = 0.0;
    double previous_error = 0.0;
    double derivative;
    double error;
    double output;

    /* Simulation */

    for (int i = 0; i < N; i++) {

        /* erreur oscillante amortie */

        error = exp(-0.00005 * i) * sin(0.01 * i);

        /* terme intégral */

        integral += Ki * error * dt;

        /* terme dérivé */

        derivative = Kd * (error - previous_error) / dt;

        /* sortie */

        output = Kp * error + integral + derivative;

        previous_error = error;
    }

    printf("%.17g\n", integral);
    printf("%.17g\n", output);

    return 0;
}