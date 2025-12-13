#include <stdio.h>

typedef struct
{
    int n;
    int koef[100]; // koeficijent, tj svaki clan niza je svoj koeficijent clan 0 = x^0, clan 1 = x^1, clan 2 = x^2... clan n = x^n
} POLINOM;

POLINOM citaj();
POLINOM saberi(POLINOM pol1, POLINOM pol2);
POLINOM pomnozi(POLINOM pol1, POLINOM pol2);
void ispisi(POLINOM pol);

int main()
{
    POLINOM p1 = citaj();
    POLINOM p2 = citaj();

    POLINOM s = saberi(p1, p2);
    POLINOM m = pomnozi(p1, p2);

    ispisi(s);
    ispisi(m);

    return 0;
}

POLINOM citaj()
{
    POLINOM p;
    
    // Definisano da moze n < 100
    do
    {
        scanf("%d", &p.n);
    } while (p.n > 100);
    
    for(int i = 0; i <= p.n; i++)
    {
        scanf("%d", &p.koef[i]);
    }

    return p;
}

POLINOM saberi(POLINOM pol1, POLINOM pol2)
{
    POLINOM rez;

    // Sabiramo do n, tj koji polinom ima vise clanova jer mi pravimo drugi niz pa da
    // mozemo imat sve clanove u tom novom nizu
    // polinom1 > polinom2
    if(pol1.n > pol2.n)
        rez.n = pol1.n;
    else
        rez.n = pol2.n;

    for(int i = 0; i <= rez.n; i++)
    {
        int temp_koef1, temp_koef2;

        // Ako polinom1 ima manje clanova od polinom2 mi moramo da stavimo te clanove
        // sto polinom1 nema kao 0 da bi se moglo sabrat normalno
        if(i <= pol1.n)
            temp_koef1 = pol1.koef[i];
        else
            temp_koef1 = 0;

        // isto vazi i za polinom2 ako je < od polinom1
        if(i <= pol2.n)
            temp_koef2 = pol2.koef[i];
        else
            temp_koef2 = 0;



        /* MOZE SE I OVAKO DA BUDE LJEPSE
         * int temp_koef1 = (i <= pol1.n) ? pol1.koef[i] : 0;
         * int temp_koef2 = (i <= pol2.n) ? pol2.koef[i] : 0;  
        */

        rez.koef[i] = temp_koef1 + temp_koef2;
    }


    return rez;
}

POLINOM pomnozi(POLINOM pol1, POLINOM pol2)
{
    POLINOM rez;

    rez.n = pol1.n + pol2.n;

    // Stavljamo da su sve 0 za rez polinom
    for(int i = 0; i <= rez.n; i++)
    {
        rez.koef[i] = 0;
    }

    // Mnozi
    for(int i = 0; i <= pol1.n; i++)
    {
        for(int j = 0; j <= pol2.n; j++)
        {
            rez.koef[i + j] += pol1.koef[i] * pol2.koef[j]; // neka formula
        }
    }

    return rez;
}

void ispisi(POLINOM pol)
{
    for(int i = pol.n; i >= 0; i--)
    {
        printf("%d", pol.koef[i]);

        if(i > 0)
        {
            printf("x^%d + ", i);
        }
    }
    printf("\n");
}
