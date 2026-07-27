#include <stdio.h>
#include <math.h>

#define N 4

int cholesky(double A[N][N], double L[N][N])
{
    int i, j, k;

    /* Initialisation de L à 0 */
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            L[i][j] = 0.0;

    for (i = 0; i < N; i++)
    {
        /* Calcul de l'élément diagonal */
        double sum = 0.0;
        for (k = 0; k < i; k++)
            sum += L[i][k] * L[i][k];

        double diag = A[i][i] - sum;

        /* Vérifie que la matrice est définie positive */
        if (diag <= 0.0)
            return 0;

        L[i][i] = sqrt(diag);

        /* Calcul des éléments sous la diagonale */
        for (j = i + 1; j < N; j++)
        {
            sum = 0.0;
            for (k = 0; k < i; k++)
                sum += L[j][k] * L[i][k];

            L[j][i] = (A[j][i] - sum) / L[i][i];
        }
    }

    return 1;
}

void print_matrix(double M[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%8.4f ", M[i][j]);
        printf("\n");
    }
}

int main(void)
{
    double A[N][N] =
    {
        {1, 1, 1, 1},
        {1, 5, 5, 5},
        {1, 5,14,14},
        {1, 5,14,15}
    };
    

    double L[N][N];

    if (cholesky(A, L))
    {
        printf("Matrice L :\n");
        print_matrix(L);
    }
    else
    {
        printf("La matrice n'est pas definie positive.\n");
    }

    return 0;
}