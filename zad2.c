#include <stdio.h>

void ucitaj(int a[][10], int m, int n);
void ispisi(int a[][10], int m, int n);
void pomnozi(int a[][10], int b[][10], int c[][10], int m1, int n1, int m2, int n2);

int main()
{
    int m1, n1, m2, n2;
    scanf("%d %d", &m1, &n1);
    scanf("%d %d", &m2, &n2);

    int a[10][10], b[10][10], c[10][10]; // ista prica ko 1. zadatak nmg stavit m1 n1, m2 n2
    
    // Ako kolona prve matrice != redu druge onda se ne mogu mnoziti
    if(n1 != m2)
    {
        printf("Ne mogu se mnoziti\n");
        return 0;
    }

    ucitaj(a, m1, n1);
    ucitaj(b, m2, n2);

    pomnozi(a, b, c, m1, n1, m2, n2);

    ispisi(c, m1, n2);

    return 0;
}

void ucitaj(int a[][10], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void ispisi(int a[][10], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void pomnozi(int a[][10], int b[][10], int c[][10], int m1, int n1, int m2, int n2)
{
    for(int i = 0; i < m1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            // Da ne bude neka random vrijednost stavi se da je c[i][j] = 0
            c[i][j] = 0;
            for(int k = 0; k < n1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
