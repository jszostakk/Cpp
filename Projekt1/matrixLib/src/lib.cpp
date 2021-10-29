#include <iostream>
#include <iomanip>
#include "../include/lib.h"

using namespace std;

int **createMatrixInt(int wiersze, int kolumny)          //prosta funkcja tworzaca macierz z elementami bedacymi intami
{
    int **matrix;

    matrix = new int *[wiersze];                        //dynamiczna alokacja
    for(int i = 0; i < wiersze; i++)
        matrix[i] = new int [kolumny];

    return matrix;                                      //funkcja zwraca macierz
}

double **createMatrixDouble(int wiersze, int kolumny)    //prosta funkcja tworzaca macierz z elementami bedacymi doublami
{
    double **matrix;

    matrix = new double *[wiersze];                        //dynamiczna alokacja
    for(int i = 0; i < wiersze; i++)
        matrix[i] = new double [kolumny];

    return matrix;                                     //funkcja zwraca macierz
}


bool insertValues(int **matrix, int wiersze, int kolumny) //funkcja umozliwiajaca wypelnianie macierzy
{
    for(int i = 0; i < wiersze; i++)                //"przeskakujemy" wiersz po wierszu
        for(int j = 0; j < kolumny; j++)            //"przeskakujemy" kolumna po kolumnie
            if(!(cin>>matrix[i][j]))                //sprawdzamy poprawnosc wpisanych danych
            {
                cout<<"Znaki nieprawidlowe"<<endl;
                return false;
            }
    return true;
}

bool insertValues(double **matrix, int wiersze, int kolumny)//funkcja umozliwiajaca wypelnianie macierzy
{
    for(int i = 0; i < wiersze; i++)                //"przeskakujemy" wiersz po wierszu
        for(int j = 0; j < kolumny; j++)            //"przeskakujemy" kolumna po kolumnie
            if(!(cin>>matrix[i][j]))                //sprawdzamy poprawnosc wpisanych danych
            {
                cout<<"Znaki nieprawidlowe"<<endl;
                return false;
            }
    return true;
}


void show(int **matrix, int wiersze, int kolumny)     //po prostu wypisywanie macierzy
{
    for(int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < kolumny; j++)
            cout << matrix[i][j];

        cout << endl;
    }
}

void show(double **matrix, int wiersze, int kolumny)     //po prostu wypisywanie macierzy
{
    for(int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < kolumny; j++)
            cout << matrix[i][j];

        cout << endl;
    }
}


int **addMatrix(int **matrixA, int **matrixB, int wiersze, int kolumny)
{
    int **result = createMatrixInt(wiersze, kolumny);

    for(int i = 0; i < wiersze; i++)
        for(int j = 0; j < kolumny; j++)
            result[i][j] = matrixA[i][j] + matrixB[i][j];   //dodajemy wartosci macierzy bedace na tych samych wspolrzednych

    return result;
}

double **addMatrix(double **matrixA, double **matrixB, int wiersze, int kolumny)
{
    double **result = createMatrixDouble(wiersze, kolumny);

    for(int i = 0; i < wiersze; i++)
        for(int j = 0; j < kolumny; j++)
            result[i][j] = matrixA[i][j] + matrixB[i][j];   //dodajemy wartosci macierzy bedace na tych samych wspolrzednych

    return result;
}


int **subtractMatrix(int **matrixA, int **matrixB, int wiersze, int kolumny)
{
    int **result = createMatrixInt(wiersze, kolumny);

    for(int i = 0; i < wiersze; i++)
        for(int j = 0; j < kolumny; j++)
            result[i][j] = matrixA[i][j] - matrixB[i][j];   //odejmujemy wartosci macierzy bedace na tych samych wspolrzednych

    return result;
}

double **subtractMatrix(double **matrixA, double **matrixB, int wiersze, int kolumny)
{
    double **result = createMatrixDouble(wiersze, kolumny);

    for(int i = 0; i < wiersze; i++)
        for(int j = 0; j < kolumny; j++)
            result[i][j] = matrixA[i][j] - matrixB[i][j];   //odejmujemy wartosci macierzy bedace na tych samych wspolrzednych

    return result;
}


int **multiplyMatrix(int **matrixA, int **matrixB, int wierszeA, int kolumnyA, int kolumnyB)
{
    int **result = createMatrixInt(wierszeA, kolumnyB);

    for(int i = 0; i < wierszeA; i++)
        for(int j = 0; j < kolumnyB; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < kolumnyA; k++)
                result[i][j] += (matrixA[i][k] * matrixB[k][j]);    //suma iloczynow wartosci w i-tym wierszu pierwszej
        }                                                           //macierzy z wartosciami w i-tej kolumnie drugiej macierzy
    return result;
}

double **multiplyMatrix(double **matrixA, double **matrixB, int wierszeA, int kolumnyA, int kolumnyB)
{
    double **result = createMatrixDouble(wierszeA, kolumnyB);

    for(int i = 0; i < wierszeA; i++)
        for(int j = 0; j < kolumnyB; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < kolumnyA; k++)
                result[i][j] += (matrixA[i][k] * matrixB[k][j]);    //suma iloczynow wartosci w i-tym wierszu pierwszej
        }                                                           //macierzy z wartosciami w i-tej kolumnie drugiej macierzy
    return result;
}


int **multiplyByScalar(int **matrix, int wiersze, int kolumny, int scalar)
{
    int **result = createMatrixInt(wiersze, kolumny);

    for(int i = 0; i < wiersze; i++)
        for(int j = 0; j < kolumny; j++)
            result[i][j] = matrix[i][j] * scalar;       //mnozenie kazdej wartosci przez skalar

    return result;
}

double **multiplyByScalar(double **matrix, int wiersze, int kolumny, double scalar)
{
    double **result = createMatrixDouble(wiersze, kolumny);

    for(int i = 0; i < wiersze; i++)
        for(int j = 0; j < kolumny; j++)
            result[i][j] = matrix[i][j] * scalar;       //mnozenie kazdej wartosci przez skalar

    return result;
}


int **transposeMatrix(int **matrix, int wiersze, int kolumny)
{
    int **result = createMatrixInt(wiersze, kolumny);

    for(int i = 0; i < wiersze; i++)
        for(int j = 0; j < kolumny; j++)
            result[i][j] = matrix[j][i];        //"odwracanie" macierzy wzgledem przekatnej

    return result;
}

double **transposeMatrix(double **matrix, int wiersze, int kolumny)
{
    double **result = createMatrixDouble(wiersze, kolumny);

    for(int i = 0; i < wiersze; i++)
        for(int j = 0; j < kolumny; j++)
            result[i][j] = matrix[j][i];        //"odwracanie" macierzy wzgledem przekatnej

    return result;
}


int **powerMatrix(int **matrix, int wiersze, int kolumny, int power)
{
    int **result = createMatrixInt(wiersze, kolumny);

    if(power == 1)                              //macierz podniesiona do potegi pierwszej jest wynikiem
    {
        for (int i = 0; i < wiersze; i++)
            for (int j = 0; j < kolumny; j++)
                result[i][j] = matrix[i][j];
        return result;
    }

    else if(power == 0)                        //macierz podniesiona do potegi zerowej daje macierz jednostkowa
    {
        for(int i = 0; i < wiersze; i++)
            for(int j = 0; j < kolumny; j++)
            {
                if(i == j)
                    result[i][j] = 1;

                else
                    result[i][j] = 0;
            }
        return result;
    }
                                                //mnozenie tej samej macierzy tyle razy ile wynosi potega
    else
        return multiplyMatrix(matrix, powerMatrix(matrix, wiersze, kolumny, power - 1), wiersze, kolumny, kolumny);
}

double **powerMatrix(double **matrix, int wiersze, int kolumny, int power)
{
    double **result = createMatrixDouble(wiersze, kolumny);

    if(power == 1)                              //macierz podniesiona do potegi pierwszej jest wynikiem
    {
        for (int i = 0; i < wiersze; i++)
            for (int j = 0; j < kolumny; j++)
                result[i][j] = matrix[i][j];
        return result;
    }

    else if(power == 0)                        //macierz podniesiona do potegi zerowej daje macierz jednostkowa
    {
        for(int i = 0; i < wiersze; i++)
            for(int j = 0; j < kolumny; j++)
            {
                if(i == j)
                    result[i][j] = 1;

                else
                    result[i][j] = 0;
            }
        return result;
    }
                                                //mnozenie tej samej macierzy tyle razy ile wynosi potega
    else
        return multiplyMatrix(matrix, powerMatrix(matrix, wiersze, kolumny, power - 1), wiersze, kolumny, kolumny);
}


int determinantMatrix(int **matrix, int wiersze)       //tylko dla macierzy kwadratowej
{
    if (wiersze == 1)
        return matrix[0][0];

    else if (wiersze == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    else
    {
        int **subMatrix;                            //wyznacznik liczony metoda LaPlace'a
        int result = 0;
        int sign = 1;

        for(int i = 0; i < wiersze; i++)
        {
            subMatrix = submatrix(matrix, 0, i, wiersze);
            result += sign * matrix[0][i] * determinantMatrix(subMatrix, wiersze - 1);
            sign = -sign;
        }

        return result;
    }
}

int **submatrix(int **matrix, int wiersze, int kolumny, int size)   //podmacierz, caly czas zmniejszana o jeden wiersz i kolumne
{
    int i = 0;
    int j = 0;

    int **result = createMatrixInt(size, size);

    for (int k = 0; k < size; k++)
        for (int l = 0; l < size; l++)
            if (l != kolumny && k != wiersze)
            {
                result[i][j++] = matrix[k][l];

                if (j == size - 1)
                {
                    j = 0;
                    i++;
                }
            }
    return result;
}


double determinantMatrix(double **matrix, int wiersze)       //tylko dla macierzy kwadratowej
{
    if (wiersze == 1)
        return matrix[0][0];

    else if (wiersze == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    else
    {
        double **subMatrix;                            //wyznacznik liczony metoda LaPlace'a
        int result = 0;
        int sign = 1;

        for(int i = 0; i < wiersze; i++)
        {
            subMatrix = submatrix(matrix, 0, i, wiersze);
            result += sign * matrix[0][i] * determinantMatrix(subMatrix, wiersze - 1);
            sign = -sign;
        }

        return result;
    }
}

double **submatrix(double **matrix, int wiersze, int kolumny, int size)   //podmacierz, caly czas zmniejszana o jeden wiersz i kolumne
{
    int i = 0;
    int j = 0;

    double **result = createMatrixDouble(size, size);

    for (int k = 0; k < size; k++)
        for (int l = 0; l < size; l++)
            if (l != kolumny && k != wiersze)
            {
                result[i][j++] = matrix[k][l];

                if (j == size - 1)
                {
                    j = 0;
                    i++;
                }
            }
    return result;
}


bool matrixIsDiagonal(int **matrix, int wiersze, int kolumny)       //sprawdzam czy macierz ma wartosci niezerowe tylko na przekatnej
{
    for(int i = 0; i < wiersze; i++)
        for(int j = 0; j < kolumny; j++)
            if(i != j && matrix[i][j] != 0)
                return false;

    return true;
}

bool matrixIsDiagonal(double **matrix, int wiersze, int kolumny)    //sprawdzam czy macierz ma wartosci niezerowe tylko na przekatnej
{
    for(int i = 0; i < wiersze; i++)
        for(int j = 0; j < kolumny; j++)
            if(i != j && matrix[i][j] != 0)
                return false;

    return true;
}


void swap(int *x, int *y)        //prosta funkcja zamiany przy pomocy zmiennej pomocniczej
{
    int t = *x;
    *x = *y;
    *y = t;
}

void swap(double *x, double *y)  //prosta funkcja zamiany przy pomocy zmiennej pomocniczej
{
    double t = *x;
    *x = *y;
    *y = t;
}


void sortRow(int *tab, int kolumny)         //sortowanie tablicy jednowymiarowej
{
    for(int i = 0; i < kolumny; i++)
        for(int j = 0; j < kolumny; j++)
            if(tab[j] > tab[j+1])
                swap(tab[j], tab[j+1]);
}

void sortRow(double *tab, int kolumny)      //sortowanie tablicy jednowymiarowej
{
    for(int i = 0; i < kolumny; i++)
        for(int j = 0; j < kolumny; j++)
            if(tab[j] > tab[j+1])
                swap(tab[j], tab[j+1]);
}


void sortRowsInMatrix(int **matrix, int wiersze, int kolumny)       //sortowanie wierszy macierzy
{
    for(int i = 0; i < wiersze; i++)
        sortRow(matrix[i], kolumny);
}

void sortRowsInMatrix(double **matrix, int wiersze, int kolumny)       //sortowanie wierszy macierzy
{
    for(int i = 0; i < wiersze; i++)
        sortRow(matrix[i], kolumny);
}


bool command(string c)                          //sprawdzenie czy komenda podana przez uzytkownika istnieje
{
    string list[12] = {"addMatrix",
                       "subtractMatrix",
                       "multiplyMatrix",
                       "multiplyByScalar",
                       "transposeMatrix",
                       "powerMatrix",
                       "determinantMatrix",
                       "matrixIsDiagonal",
                       "swap",
                       "sortRow",
                       "sortRowsInMatrix",
                       "help"};

    for(int i = 0; i < 12; i ++)
        if(c == list[i])
            return true;

    return false;
}

int checkInt()                              //sprawdzam poprawnosc wpisanej wartosci
{
    int x;
    if(!( cin >> x))
    {
        cout << "Zly format danej!" <<endl;
        return 0;
    }
    return x;
}


double checkDouble()                        //sprawdzam poprawnosc wpisanej wartosci
{
    double x;
    if(!( cin >> x))
    {
        cout << "Zly format danej!" <<endl;
        return 0;
    }
    return x;
}


string checkString()                        //sprawdzam poprawnosc wpisanej wartosci
{
    string x;
    if(!( cin >> x))
    {
        cout << "Zly format danej!" <<endl;
        return 0;
    }
    return x;
}

void help()
{
    cout<< "Kalkulator macierzy przeprowadza wybrane operacje na macierzach.\n"
        << "Wielkosci macierzy, jak i jej wartosci wybiera uzytkownik.\n\n\n"
        << "Lista funkcji:\n\n"
        << "Dodawanie macierzy - addMatrix\n\n"
        << "Odejmowanie macierzy - subtractMatrix\n\n"
        << "Mnozenie macierzy przez macierz - multiplyMatrix\n\n"
        << "Mnozenie macierzy przez skalar - multiplyByScalar\n\n"
        << "Transponowanie macierzy - transposeMatrix\n\n"
        << "Potegowanie macierzy - powerMatrix\n\n"
        << "Obliczanie wyznacznika macierzy - determinantMatrix\n\n"
        << "Sprawdzanie czy macierz jest diagonalna - martixIsDiagonal\n\n"
        << "Zamiana dwoch wartosci miejscami - swap\n\n"
        << "Sortowanie tablicy bubble sortem - sortRow\n\n"
        << "Sortowanie wszystkich wierszy w macierzy - sortRowsInMatrix\n\n"
        <<endl;

}
