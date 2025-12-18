#include <stdio.h>
#include <string.h>

typedef struct
{
    int identifikator;
    char naziv[20];
    double cijena;
    double kolicina;
} ARTIKAL;

int citaj(ARTIKAL a[]);
void sortiraj(ARTIKAL a[], int n);
void pisi(ARTIKAL a[], int n);
ARTIKAL najskuplji(ARTIKAL a[], int n);

int main()
{
    ARTIKAL a[100]; // ja stavio 100 jer mi se dalo
    int n = citaj(a); // Dato je u zadatku da se ucitava broj n koji govori koliko artikala ima i on nam vraca taj broj n
    
    sortiraj(a, n);

    pisi(a, n);

    // Ja msm da se moglo ovako ali codeblocks je retardiran pa nece
    /* ARTIKAL max = najskuplji(a, n);
     * printf("\nID: %d\nNaziv: %s\nCijena: %.2lf\nKolicina: %.2lf\n", max.identifikator, max.naziv, max.cijena, max.kolicina);
    */
    printf("\nNajskuplji artikal je:\n");
    ARTIKAL niz[1];
    niz[0] = najskuplji(a, n);
    pisi(niz, 1);

    return 0;
}

int citaj(ARTIKAL a[])
{
    // Taj broj artikala sto sam rekao u main() komentar
    int n;
    do
    {
        scanf("%d", &n);
    }while (n <= 0);
    
    // Unos podataka za artikal
    for(int i = 0; i < n; i++)
    {
        // Izgleda retardirano al jbg takvi su uslovi u zadatku
        // identifikator je prirodan broj
        do
        {
            scanf("%d", &a[i].identifikator);
        } while(a[i].identifikator <= 0);

        // naziv je string
        scanf("%s", a[i].naziv);

        // cijena je realan broj
        do
        {
            scanf("%lf", &a[i].cijena);
        } while(a[i].cijena < 0); // ne moze cijena biti u minusu, odose pare u kurac za market

        // kolicina je realan broj
        do
        {
            scanf("%lf", &a[i].kolicina);
        } while(a[i].kolicina < 0); // ne mozes imat -1 jabuka npr kao wtf
    }

    return n;
}

void sortiraj(ARTIKAL a[], int n)
{
    // klasican sort
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[i].identifikator > a[j].identifikator)
            {
                ARTIKAL temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void pisi(ARTIKAL a[], int n)
{
    double ukupna_cijena = 0;

    printf("===== ==================== ====== ====== ========\n");
    printf("ID    NAZIV                CIJENA   KOL.  UKUPNO\n");
    printf("===== ==================== ====== ====== ========\n");

    for(int i = 0; i < n; i++)
    {
        double cijena_artikla = a[i].cijena * a[i].kolicina;
        ukupna_cijena += cijena_artikla;

        printf("%-5d %-20s %5.2lf  %5.2lf %8.2lf\n", a[i].identifikator, a[i].naziv, a[i].cijena, a[i].kolicina, cijena_artikla);
    }

    printf("=================================================\n");
    printf("                                    UKUPNO: %.2lf\n", ukupna_cijena); // zabolje me kurac za 37 razmaka (da jesam brojo)
    printf("=================================================\n");
}

ARTIKAL najskuplji(ARTIKAL a[], int n)
{
    int max = 0;
    for(int i = 1; i < n; i++)
        if(a[i].cijena > a[max].cijena)
            max = i;
    return a[max];
}
