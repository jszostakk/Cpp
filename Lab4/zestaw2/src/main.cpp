#include <iostream>
#include "../include/Prostopadloscian.h"
#include "../include/Kula.h"
#include "../include/FunkcjaKwadratowa.h"
#include "../include/Student.h"

using namespace std;

void zad1()
{
    Prostopadloscian x;
    int a, b, c;
    cin >> a >> b >> c;
    x.setA(a);
    cout << x.getA() << endl;
    x.setB(b);
    cout << x.getB() << endl;
    x.setH(c);
    cout << x.getB() << endl;

    cout << x.pole ( a ,b , c ) << endl;
}

void zad2()
{
    Kula x;
    int r;
    cin >> r;
    x.setR ( r );
    cout << x.getR () << endl;

    cout << x.volume ( r );
}

void zad3()
{
    FunkcjaKwadratowa x;
    int a, b, c;

    cin >> a;
    x.setA ( a );
    cout << x.getA () << endl;

    cin >> b;
    x.setB ( b );
    cout << x.getB () << endl;

    cin >> c;
    x.setC ( c );
    cout << x.getC () << endl;

    x.equasion ( a, b, c );
}

void zad4()
{
    Student x;
    string name, surname;
    int album, questions, answers;

    cout << "Name: \n";
    cin >> name;
    cout << "Surname: \n";
    cin >> surname;
    cout << "Album Number: \n";
    cin >> album;
    cout << "Number of questions: \n";
    cin >> questions;
    cout << "Number of correct answers: \n";
    cin >> answers;

    x.setName ( name );
    x.setSurname ( surname );
    x.setAlbum ( album );
    x.setQuestions ( questions );
    x.setAnswers ( answers );

    x.percentage ( questions, answers );
}

int main()
{
    //zad1();
    //zad2();
    //zad3();
    //zad4();
}