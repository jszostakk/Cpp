#include <iostream>
#include <cstring>
#include "lib.h"

using namespace std;

int main (int argc, char *argv[])
{
    string order = argv[1];

    if (order == "help")
        help();

    else if (command(order))                                    //sprawdzam poprawnosc komendy
    {
        cout<<"Wpisz typ zmiennej (int/double):"<<endl;
        string type = checkString();

        if (type == "int")
        {
            if (order == "addMatrix" || order == "subtractMatrix")     //obie operacje, bo potrzebuja takich samych argumentow
            {
                int **matrixA, **matrixB, wiersze, kolumny, **result;  //deklaracja potrzebnych komponentow

                cout << "Wpisz ilosc wierszy" << endl;
                wiersze = checkInt();

                cout << "Wpisz ilosc kolumn" << endl;
                kolumny = checkInt();

                matrixA = createMatrixInt(wiersze, kolumny);
                matrixB = createMatrixInt(wiersze, kolumny);        //tworze obie macierze bazujac na podanych argumentach

                cout << "Wprowadz wartosci pierwszej macierzy: " << endl;
                insertValues(matrixA, wiersze, kolumny);

                cout << "Wprowadz wartosci drugiej macierzy: " << endl;
                insertValues(matrixB, wiersze, kolumny);

                cout << "Macierz pierwsza: " << endl;
                show(matrixA, wiersze, kolumny);

                cout << "Macierz druga: " << endl;
                show(matrixB, wiersze, kolumny);

                if ( order == "addMatrix" )                                       //tutaj juz rozdzielam przypadki na dodawanie
                {
                    result = addMatrix(matrixA, matrixB, wiersze, kolumny);
                    cout << "Macierz wynikowa: " << endl;
                    show(result, wiersze, kolumny);
                }

                else if (order == "addMatrix")                                  //i odejmowanie
                {
                    result = subtractMatrix(matrixA, matrixB, wiersze, kolumny);
                    cout << "Macierz wynikowa: " << endl;
                    show(result, wiersze, kolumny);
                }

                delete[] matrixA;                                               //czyszcze uzyte macierze
                delete[] matrixB;
                delete[] result;
            }

            else if (order == "multiplyMatrix")
            {
                int **matrixA, **matrixB, wierszeA, kolumnyA, kolumnyB, **result;  //deklaracja potrzebnych komponentow

                cout << "Podaj ilosc wierszy pierwszej macierzy: " << endl;
                wierszeA = checkInt();

                cout << "Podaj ilosc kolumn pierwszej macierzy: " << endl;
                kolumnyA = checkInt();

                cout << "Podaj ilosc kolumn drugiej macierzy: " << endl;
                kolumnyB = checkInt();

                matrixA = createMatrixInt ( wierszeA, kolumnyA);
                matrixB = createMatrixInt ( kolumnyA, kolumnyB);        //tworze obie macierze bazujac na podanych argumentach

                cout << "Wprowadz wartosci pierwszej macierzy: " << endl;
                insertValues(matrixA, wierszeA, kolumnyA);

                cout << "Wprowadz wartosci drugiej macierzy: " << endl;
                insertValues(matrixB, kolumnyA, kolumnyB);

                cout << "Macierz pierwsza: " << endl;
                show(matrixA, wierszeA, kolumnyA);

                cout << "Macierz druga: " << endl;
                show(matrixB, kolumnyA, kolumnyB);

                result = multiplyMatrix(matrixA, matrixB, wierszeA, kolumnyA, kolumnyB);
                cout << "Macierz wynikowa: " << endl;
                show(result, wierszeA, kolumnyB);

                delete[] matrixA;                                               //czyszcze uzyte macierze
                delete[] matrixB;
                delete[] result;
            }

            else if ( order == "multiplyByScalar")
            {
                int **matrix, **result, wiersze, kolumny, scalar;  //deklaracja potrzebnych komponentow

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                cout << "Podaj skalar: " << endl;
                scalar = checkInt();

                matrix = createMatrixInt ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                result = multiplyByScalar ( matrix, wiersze, kolumny, scalar);
                cout << "Macierz wynikowa: " << endl;
                show(result, wiersze, kolumny);

                delete[] matrix;
                delete[] result;
            }

            else if ( order == "transposeMatrix")
            {
                int **matrix, wiersze, kolumny, **result;   //deklaracja potrzebnych komponentow

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                matrix = createMatrixInt ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                result = transposeMatrix( matrix, wiersze, kolumny);
                cout << "Macierz wynikowa: " << endl;
                show(result, wiersze, kolumny);

                delete[] matrix;
                delete[] result;
            }

            else if ( order == "powerMatrix")
            {
                int **matrix, wiersze, kolumny, power, **result;   //deklaracja potrzebnych komponentow

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                if ( wiersze != kolumny )
                {
                    cout << "Wyznacznik tylko dla macierzy kwadratowej" << endl;
                    return 0;
                }

                cout << "Podaj potege: " << endl;
                power = checkInt();

                matrix = createMatrixInt ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                result = powerMatrix( matrix, wiersze, kolumny, power);
                cout << "Macierz wynikowa: " << endl;
                show(result, wiersze, kolumny);

                delete[] matrix;
                delete[] result;
            }

            else if ( order == "determinantMatrix" )
            {
                int **matrix, wiersze, kolumny, result;  //deklaracja potrzebnych komponentow

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                matrix = createMatrixInt ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                result = determinantMatrix ( matrix, wiersze );
                cout << "Wyznacznik: " << result << endl;

                delete[] matrix;
            }

            else if ( order == "matrixIsDiagonal" )
            {
                int **matrix, wiersze, kolumny, result;  //deklaracja potrzebnych komponentow

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                matrix = createMatrixInt ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                if ( result == matrixIsDiagonal ( matrix, wiersze, kolumny ) )
                    cout << "Podana macierz jest diagonalna." << endl;
                else
                    cout << "Podana macierz nie jest diagonalna. " <<endl;

                delete[] matrix;
            }

            else if ( order == "swap" )
            {
                int x, y;  //deklaracja potrzebnych komponentow

                cout << "Podaj pierwsza wartosc: " << endl;
                x = checkInt();

                cout << "Podaj druga wartosc: " << endl;
                y = checkInt();

                cout << "Wartosci przed zamiana:\n" << "x = " << x << "\ny = " << y << endl;
                swap ( x, y );
                cout << "Wartosci po zamianie:\n" << "x = " << x << "\ny = " << y << endl;
            }

            else if ( order == "sortRow" )
            {
                int kolumny;  //deklaracja potrzebnych komponentow

                cout << "Podaj wielkosc tablicy: " << endl;
                kolumny = checkInt();
                int *t = new int[kolumny];   //dynamicznie alokuje tablice

                cout << "Wprowadz wartosci tablicy: " << endl;
                for ( int i = 0; i < kolumny; i++)
                    t[i] = checkInt();

                cout << "Tablica przed sortem: " << endl;
                for ( int i = 0; i < kolumny; i++)
                    cout << t[i] << " ";

                sortRow ( t, kolumny );
                cout << "Tablica po sorcie: " << endl;
                for ( int i = 0; i < kolumny; i++)
                    cout << t[i] << " ";

                delete[] t;
            }

            else if ( order == "sortRowsInMatrix")
            {
                int **matrix, wiersze, kolumny;   //deklaracja potrzebnych komponentow

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                matrix = createMatrixInt ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                sortRowsInMatrix ( matrix, wiersze, kolumny );
                cout << "Macierz po sorcie: " << endl;
                show(matrix, wiersze, kolumny);

                delete[] matrix;
            }
        }

        else if (type == "double")
        {
            if (order == "addMatrix" || order == "subtractMatrix")     //obie operacje, bo potrzebuja takich samych argumentow
            {
                double **matrixA, **matrixB, **result;  //deklaracja potrzebnych komponentow
                int wiersze, kolumny;

                cout << "Wpisz ilosc wierszy" << endl;
                wiersze = checkInt();

                cout << "Wpisz ilosc kolumn" << endl;
                kolumny = checkInt();

                matrixA = createMatrixDouble(wiersze, kolumny);
                matrixB = createMatrixDouble(wiersze, kolumny);        //tworze obie macierze bazujac na podanych argumentach

                cout << "Wprowadz wartosci pierwszej macierzy: " << endl;
                insertValues(matrixA, wiersze, kolumny);

                cout << "Wprowadz wartosci drugiej macierzy: " << endl;
                insertValues(matrixB, wiersze, kolumny);

                cout << "Macierz pierwsza: " << endl;
                show(matrixA, wiersze, kolumny);

                cout << "Macierz druga: " << endl;
                show(matrixB, wiersze, kolumny);

                if ( order == "addMatrix" )                                       //tutaj juz rozdzielam przypadki na dodawanie
                {
                    result = addMatrix(matrixA, matrixB, wiersze, kolumny);
                    cout << "Macierz wynikowa: " << endl;
                    show(result, wiersze, kolumny);
                }

                else if (order == "addMatrix")                                  //i odejmowanie
                {
                    result = subtractMatrix(matrixA, matrixB, wiersze, kolumny);
                    cout << "Macierz wynikowa: " << endl;
                    show(result, wiersze, kolumny);
                }

                delete[] matrixA;                                               //czyszcze uzyte macierze
                delete[] matrixB;
                delete[] result;
            }

            else if (order == "multiplyMatrix")
            {
                double **matrixA, **matrixB, **result;  //deklaracja potrzebnych komponentow
                int wierszeA, kolumnyA, kolumnyB;

                cout << "Podaj ilosc wierszy pierwszej macierzy: " << endl;
                wierszeA = checkInt();

                cout << "Podaj ilosc kolumn pierwszej macierzy: " << endl;
                kolumnyA = checkInt();

                cout << "Podaj ilosc kolumn drugiej macierzy: " << endl;
                kolumnyB = checkInt();

                matrixA = createMatrixDouble ( wierszeA, kolumnyA);
                matrixB = createMatrixDouble ( kolumnyA, kolumnyB);        //tworze obie macierze bazujac na podanych argumentach

                cout << "Wprowadz wartosci pierwszej macierzy: " << endl;
                insertValues(matrixA, wierszeA, kolumnyA);

                cout << "Wprowadz wartosci drugiej macierzy: " << endl;
                insertValues(matrixB, kolumnyA, kolumnyB);

                cout << "Macierz pierwsza: " << endl;
                show(matrixA, wierszeA, kolumnyA);

                cout << "Macierz druga: " << endl;
                show(matrixB, kolumnyA, kolumnyB);

                result = multiplyMatrix(matrixA, matrixB, wierszeA, kolumnyA, kolumnyB);
                cout << "Macierz wynikowa: " << endl;
                show(result, wierszeA, kolumnyB);

                delete[] matrixA;                                               //czyszcze uzyte macierze
                delete[] matrixB;
                delete[] result;
            }

            else if ( order == "multiplyByScalar")
            {
                double **matrix, **result, scalar;  //deklaracja potrzebnych komponentow
                int wiersze, kolumny;

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                cout << "Podaj skalar: " << endl;
                scalar = checkDouble();

                matrix = createMatrixDouble ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                result = multiplyByScalar ( matrix, wiersze, kolumny, scalar);
                cout << "Macierz wynikowa: " << endl;
                show(result, wiersze, kolumny);

                delete[] matrix;
                delete[] result;
            }

            else if ( order == "transposeMatrix")
            {
                double **matrix, **result;   //deklaracja potrzebnych komponentow
                int wiersze, kolumny;

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                matrix = createMatrixDouble ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                result = transposeMatrix( matrix, wiersze, kolumny);
                cout << "Macierz wynikowa: " << endl;
                show(result, wiersze, kolumny);

                delete[] matrix;
                delete[] result;
            }

            else if ( order == "powerMatrix")
            {
                double **matrix, **result;   //deklaracja potrzebnych komponentow
                int wiersze, kolumny, power;

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                if ( wiersze != kolumny )
                {
                    cout << "Wyznacznik tylko dla macierzy kwadratowej" << endl;
                    return 0;
                }

                cout << "Podaj potege: " << endl;
                power = checkInt();

                matrix = createMatrixDouble ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                result = powerMatrix( matrix, wiersze, kolumny, power);
                cout << "Macierz wynikowa: " << endl;
                show(result, wiersze, kolumny);

                delete[] matrix;
                delete[] result;
            }

            else if ( order == "determinantMatrix" )
            {
                double **matrix, result;  //deklaracja potrzebnych komponentow
                int wiersze, kolumny;

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                matrix = createMatrixDouble ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                result = determinantMatrix ( matrix, wiersze);
                cout << "Wyznacznik: " << result << endl;

                delete[] matrix;
            }

            else if ( order == "matrixIsDiagonal" )
            {
                double **matrix;  //deklaracja potrzebnych komponentow
                int wiersze, kolumny, result;

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                matrix = createMatrixDouble ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                if ( result == matrixIsDiagonal ( matrix, wiersze, kolumny ) )
                    cout << "Podana macierz jest diagonalna." << endl;
                else
                    cout << "Podana macierz nie jest diagonalna. " <<endl;

                delete[] matrix;
            }

            else if ( order == "swap" )
            {
                double x, y;  //deklaracja potrzebnych komponentow

                cout << "Podaj pierwsza wartosc: " << endl;
                x = checkDouble();

                cout << "Podaj druga wartosc: " << endl;
                y = checkDouble();

                cout << "Wartosci przed zamiana:\n" << "x = " << x << "\ny = " << y << endl;
                swap ( x, y );
                cout << "Wartosci po zamianie:\n" << "x = " << x << "\ny = " << y << endl;
            }

            else if ( order == "sortRow" )
            {
                int kolumny;  //deklaracja potrzebnych komponentow

                cout << "Podaj wielkosc tablicy: " << endl;
                kolumny = checkInt();
                double *t = new double[kolumny];   //dynamicznie alokuje tablice

                cout << "Wprowadz wartosci tablicy: " << endl;
                for ( int i = 0; i < kolumny; i++)
                    t[i] = checkDouble();

                cout << "Tablica przed sortem: " << endl;
                for ( int i = 0; i < kolumny; i++)
                    cout << t[i] << " ";

                sortRow ( t, kolumny );
                cout << "Tablica po sorcie: " << endl;
                for ( int i = 0; i < kolumny; i++)
                    cout << t[i] << " ";

                delete[] t;
            }

            else if ( order == "sortRowsInMatrix")
            {
                double **matrix;   //deklaracja potrzebnych komponentow
                int wiersze, kolumny;

                cout << "Podaj ilosc wierszy macierzy: " << endl;
                wiersze = checkInt();

                cout << "Podaj ilosc kolumn macierzy: " << endl;
                kolumny = checkInt();

                matrix = createMatrixDouble ( wiersze, kolumny );

                cout << "Wprowadz wartosci macierzy: " << endl;
                insertValues(matrix, wiersze, kolumny);

                cout << "Macierz: " << endl;
                show(matrix, wiersze, kolumny);

                sortRowsInMatrix ( matrix, wiersze, kolumny );
                cout << "Macierz po sorcie: " << endl;
                show(matrix, wiersze, kolumny);

                delete[] matrix;
            }

        }

    }

    else
    {
        cout << "Podana komenda nie istnieje.\n" << endl;
        help();
    }

    return 0;
}