#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// determinant of Hilbert's matrix

void hilbert()
{
    printf("The determinant of Hilbert's matrix\n");
    printf("The gradual loss of accuracy is pointed out.\n");
    printf("One can see that the value of the determinant is significant even if it is very \"small\".\n\n");

    double amat[11][11];

    for (int i = 1; i <= 11; i++)
    {
        for (int j = 1; j <= 11; j++)
        {
            amat[i-1][j-1] = 1.0 / (double)(i + j - 1);
        }
    }

    double det = 1.0;

    int i;

    for (i = 1; i <= 10; i++)
    {
        double pivot = amat[i-1][i-1];

        printf("Pivot double %d = %.17e\n", i, pivot);

        det = det * pivot;

        double aux = 1.0 / pivot;

        for (int j = i + 1; j <= 11; j++)
        {
            amat[i-1][j-1] = amat[i-1][j-1] * aux;
        }

        for (int j = i + 1; j <= 11; j++)
        {
            aux = amat[j-1][i-1];

            for (int k = i + 1; k <= 11; k++)
            {
                amat[j-1][k-1] =
                    amat[j-1][k-1]
                    - aux * amat[i-1][k-1];
            }
        }
    }

    double pivot = amat[i-1][i-1];

    det = det * pivot;

    printf("Pivot double %d = %.17e\n", i, pivot);
    printf("Determinant = %.17e\n", det);

    printf("\n");
}

int main()
{
    hilbert();
    return EXIT_SUCCESS;
}