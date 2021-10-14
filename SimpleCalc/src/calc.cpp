#include <iostream>
#include "../include/calc.h"

using namespace std;

void help(){
    cout<<"Wpisz:\nadd, by dodac\nsubstract, by odjac\nvolume, by obliczyc objetosc graniastoslupa"<<endl;
}

int add(){
    cout<<"Wpisz obie liczby, by je dodac:\n"<<endl;
    int a,b;
    cin>>a>>b;
    return(a+b);
}

int subtract(){
    cout<<"Wpisz obie liczby, by je odjac:\n"<<endl;
    int a,b;
    cin>>a>>b;
    return(a-b);
}

float volume(){
    cout<<"Wpisz w kolejnosci: obie dlugosci podstaw, wysokosc trapezu, oraz wysokosc graniastosupa :\n"<<endl;
    int a,b,h,H;
    cin>>a>>b>>h>>H;
    return(((a+b)*h/2)*H);
}
