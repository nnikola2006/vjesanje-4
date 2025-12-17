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
    printf("\n");
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
    } while (p.n < 0 || p.n >= 100);
    
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

    // Smanjuje do prvog najvece eksponenta koji nije 0
    while (rez.n > 0 && rez.koef[rez.n] == 0)
        rez.n--;

    return rez;
}

POLINOM pomnozi(POLINOM pol1, POLINOM pol2)
{
    POLINOM rez;

    // Kolicina eksponenata za niz u kojem se mnoze (formula)
    rez.n = pol1.n + pol2.n;
    if (rez.n >= 100) // jer je opseg od 0-99
        rez.n = 99;


    // Stavljamo da su sve 0 za rez polinom
    for(int i = 0; i <= rez.n; i++)
        rez.koef[i] = 0;

    // Mnozi
    for(int i = 0; i <= pol1.n; i++)
    {
        for(int j = 0; j <= pol2.n; j++)
        {
            if(i + j < 100) // jer granica eksponenti je do 100 
                rez.koef[i + j] += pol1.koef[i] * pol2.koef[j]; // neka formula
        }
    }

    // smanjuje sve do prvog najvece eksponenta koji nije 0
    while (rez.n > 0 && rez.koef[rez.n] == 0)
        rez.n--;
    
    return rez;
}

void ispisi(POLINOM pol)
{
    int prvi = 1;

    for(int i = pol.n; i >= 0; i--)
    {
        // ako je koeficijent eksponenta = 0 ne ispisuje
        if(pol.koef[i] == 0) 
            continue;

        // jer ispred prvog clana ne smije imat + pa se stavlja ovaj uslov
        if(!prvi)
            printf(" + ");
        
        if(i == 0)
            printf("%d", pol.koef[i]);
        else if(i == 1)
            printf("%dx", pol.koef[i]);
        else
            printf("%dx^%d", pol.koef[i], i);
        first = 0;
    }

    // Ako su svi koeficijenti = 0 onda ispise 0 
    if (prvi)
        printf("0");
}









// modifikacija? (ako treba ovo onda morate stavit prototip funkcije iznad main()
// tj. POLINOM podijeli(POLINOM a, POLINOM b);
POLINOM podijeli(POLINOM a, POLINOM b)
{
    POLINOM q;
    POLINOM temp = a;

    // Ako je stepen djeljenika manji od djelitelja
    if (a.n < b.n)
    {
        q.n = 0;
        q.koef[0] = 0;
        return q;
    }

    q.n = a.n - b.n;

    // inicijalizacija količnika
    for (int i = 0; i <= q.n; i++)
        q.koef[i] = 0;

    while (temp.n >= b.n)
    {
        int stepen = temp.n - b.n;
        int koef = temp.koef[temp.n] / b.koef[b.n];

        q.koef[stepen] = koef;

        // oduzimanje: temp = temp - koef * b * x^stepen
        for (int i = 0; i <= b.n; i++)
            temp.koef[i + stepen] -= koef * b.koef[i];

        // smanji stepen temp-a
        while (temp.n > 0 && temp.koef[temp.n] == 0)
            temp.n--;
    }

    return q;
}

// moguca isto
POLINOM izvod(POLINOM p)
{
    POLINOM r;

    if (p.n == 0)
    {
        r.n = 0;
        r.koef[0] = 0;
        return r;
    }

    r.n = p.n - 1;

    for (int i = 1; i <= p.n; i++)
        r.koef[i - 1] = i * p.koef[i];

    return r;
}

// takodje
int jednaki(POLINOM a, POLINOM b)
{
    if (a.n != b.n)
        return 0;

    for (int i = 0; i <= a.n; i++)
        if (a.koef[i] != b.koef[i])
            return 0;

    return 1;
}

// znas pricu
double vrijednost(POLINOM p, double x)
{
    double s = 0;
    double xp = 1;

    for (int i = 0; i <= p.n; i++)
    {
        s += p.koef[i] * xp;
        xp *= x;
    }

    return s;
}

// dosta
POLINOM oduzmi(POLINOM a, POLINOM b)
{
    POLINOM r;

    r.n = (a.n > b.n) ? a.n : b.n;

    for (int i = 0; i <= r.n; i++)
    {
        int ka = (i <= a.n) ? a.koef[i] : 0;
        int kb = (i <= b.n) ? b.koef[i] : 0;

        r.koef[i] = ka - kb;
    }

    // ukloni vodeće nule
    while (r.n > 0 && r.koef[r.n] == 0)
        r.n--;

    return r;
}