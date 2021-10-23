#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

// ======================================================= ZAD1


int losuj(int a, int b){
    int przedzial = b-a;
    srand(time(NULL));
    return((rand()%przedzial)+a);             // Zakladam ze a<b
}

void zad1(){
    int a, b;
    cout<<"wpisz zakres"<<endl;
    cin>>a>>b;
    cout<<losuj(a,b)<<endl;
}

// ======================================================= ZAD2

void wyswietltablice(int *t, int r){
    for(int i = 0;i<r;i++)
        cout<<t[i]<<" ";
    }

void zad2(){
    srand(time(NULL));

    int *t, r;
    cout<<"Wpisz rozmiar"<<endl;
    cin>>r;
    t=new int[r];
    for(int i = 0;i<r;i++)
        t[i] = (rand()%99)+1;

    int max = t[0];
    for(int i = 0; i < r ; i++)
        if (t[i]>max)
            max = t[i];

    wyswietltablice(t,r);
    cout<<"\nMax: "<<max<<endl;
}

// ======================================================= ZAD3

void odwroc(int *t, int r){
    for(int i = 0; i<(r/2); i++)
        swap(t[i],t[r-i-1]);
}

void zad3(){
    srand(time(NULL));

    int *t, r;
    cout<<"Wpisz rozmiar"<<endl;
    cin>>r;
    t=new int[r];
    for(int i = 0;i<r;i++)
        t[i] = (rand()%99)+1;

    wyswietltablice(t,r);
    odwroc(t,r);
    cout<<endl;
    wyswietltablice(t,r);
}

int main(){
    //zad1();
    //zad2();
    //zad3();
}