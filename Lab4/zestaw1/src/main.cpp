#include <iostream>

using namespace std;

struct samochod
{
    string marka, model, kolor;
    int rok;
};

void zad1()
{
    samochod x[4] = {{"Mazda", "MX-5", "szary", 2016},
                     {"Ford", "Mustang", "czerwony", 1995},
                     {"Volvo", "S40", "srebrny", 2006},
                     {"Fiat", "Multipla", "niebieski", 2001}};

    for ( int i = 0; i < 4; i ++)
        cout << x[i].marka << "\t" << x[i].model << "\t" << x[i].kolor << "\t" << x[i].rok << endl;
}

struct samochod2
{
    string marka, model, kolor;
    int rok, moc;
};

void zad2()
{
    samochod2 x[4] = {{"Mazda", "MX-5", "szary", 2016, 160},
                     {"Ford", "Mustang", "czerwony", 1995, 218},
                     {"Volvo", "S40", "srebrny", 2006, 120},
                     {"Fiat", "Multipla", "niebieski", 2001, 105}};

    for ( int i = 0; i < 4; i ++)
        cout << x[i].marka << "\t" << x[i].model << "\t" << x[i].kolor << "\t" << x[i].rok << "\t" << x[i].moc << "KM"<< endl;
}

struct licz
{
    string marka;
    int ile = 0;
};

int check ( samochod2 *t, int ilosc)
{
    int result;
    licz tab[ilosc];

    for ( int i = 0; i < ilosc; i++)
    {
        for ( int j = 0; j < ilosc; j ++)
        {
            if ( t[i].marka == t[j].marka)
            {
                tab[i].marka = t[i].marka;
                tab[i].ile++;
            }
        }
    }

    for ( int i = 0; i < ilosc; i++)
    {
        if (tab[i].marka != tab[i + 1].marka)
            cout << tab[i].marka << " w ilosci " << tab[i].ile << endl;
    }
}

void zad3()
{
    samochod2 x[4] = {{"Mazda", "MX-5", "szary", 2016, 160},
                      {"Ford", "Mustang", "czerwony", 1995, 218},
                      {"Volvo", "S40", "srebrny", 2006, 120},
                      {"Fiat", "Multipla", "niebieski", 2001, 105}};
    check ( x, 4);
}

int main()
{
    //zad1();
    //zad2();
    zad3();
}