//
// Created by student on 08.11.21.
//

#ifndef PROJECT_POJAZD_H
#define PROJECT_POJAZD_H

class Pojazd
{
private:
    string rejestracja, nazwa, marka, *lista;
    int iloscMiejsc;

public:
    Pojazd();
    void setRejestracja ( string rejestracja );

    void setNazwa ( string nazwa );

    void setMarka ( string marka );

    void setLista ( string *lista );

    void setIloscMiejsc ( int iloscMiejsc );
};
#endif //PROJECT_POJAZD_H
