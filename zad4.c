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

int main()
{
    ARTIKAL a[100]; // ja stavio 100 jer mi se dalo
    int n = citaj(a); // Dato je u zadatku da se ucitava broj n koji govori koliko artikala ima i on nam vraca taj broj n
    
    sortiraj(a, n);

    pisi(a, n);

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











// moguce
void filtriraj_cijena(ARTIKAL a[], int n, double min)
{
    for(int i = 0; i < n; i++)
        if(a[i].cijena >= min)
            printf("%d %s\n", a[i].identifikator, a[i].naziv);
}

// sortira po nečemu drugom
// if(a[i].cijena > a[j].cijena)
// if(a[i].cijena * a[i].kolicina > a[j].cijena * a[j].kolicina)
// if(strcmp(a[i].naziv, a[j].naziv) > 0) (vjr nece ovo jer je strcmp sto nije radjeno)

int nadji_po_id(ARTIKAL a[], int n, int id)
{
    for(int i = 0; i < n; i++)
        if(a[i].identifikator == id)
            return i;
    return -1;
}

int najskuplji(ARTIKAL a[], int n)
{
    int max = 0;
    for(int i = 1; i < n; i++)
        if(a[i].cijena > a[max].cijena)
            max = i;
    return max;
}

void povecaj_cijenu(ARTIKAL a[], int n, double procenat)
{
    for(int i = 0; i < n; i++)
        a[i].cijena *= (1 + procenat / 100);
}