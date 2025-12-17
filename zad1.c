#include <stdio.h>

/* 
 * Inace se ovako pise kao da se zna koje funkcije/metode postoje
 * da se ne cita kod tih funkcija ali mozete i vi pisati 
 * gore citavu funkciju a ne ispod main()
 * Personal bias ukratko
 */
int prost(int x);

int main()
{
    int n;
    do
    {
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    int a[100]; // nmg napisati a[n] jer mi kompaljer ispisuje gresku al de probajte n umjesto 100
                // kod vas mozda radi ako nije vsc

    // Ucitavanje
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Provjera i ispis
    for(int i = 0; i < n; i++)
    {
        if(prost(a[i]))
        {
            printf("%d ", a[i]);
        }
    }

    return 0;
}

int prost(int x)
{
    // Ako je 1 ili manje prost je lol
    if(x <= 1)
    {
        return 0;
    }

    // Provjera za prost
    for(int i = 2; i * i <= x; i++)
    {
        // Ako je djeljiv onda nije prost
        if(x % i == 0)
            return 0;
    }

    return 1;
}














//moguca modifikacija
int savrsen(int n)
{
    int s=0;

    for(int i=1;i<=n/2;i++)
        if(n%i==0)
            s+=i;

    return s==n;
}

int suma_djelilaca(int n)
{
    int s=0;

    for(int i=1;i<=n;i++)
        if(n%i==0)
            s+=i;

    return s;
}

int prvi_veci_prost(int n)
{
    for(int i=n+1;;i++)
        if(prost(i))
            return i;
}

int armstrong(int n)
{
    int t=n, cifre=0, s=0;

    while(t)
    {
        cifre++;
        t/=10;
    }

    t=n;
    while(t)
    {
        int c=t%10, p=1;
        for(int i=0;i<cifre;i++)
            p*=c;
        s+=p;
        t/=10;
    }

    return s==n;
}