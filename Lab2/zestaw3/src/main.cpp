#include <iostream>
#include <algorithm>

using namespace std;

// ===================================================== ZAD1

float f(int *a, int *b){
    return(float((*a+*b))/2);
}

void zad1(){
    int l1, l2;
    int *L2;
    int *L1;
    cout<<"Wpisz obie"<<endl;
    cin>>l1>>l2;
    L1=&l1;
    L2=&l2;
    // cout<<L1<<endl;
    cout<<"Srednia:"<<f(L1,L2)<<endl;
}

// ===================================================== ZAD2


void wyswietltablice(int *t, int r){
    for(int i = 0;i<r;i++)
            cout<<t[i]<<" ";
}

void spr(int *t, int r){
    for(int i = 0;i<r;i++){
        if(t[i]>0)
            cout<<t[i]<<" ";
    }
}

void zad2(){
    int *t, r;
    cout<<"Wpisz rozmiar"<<endl;
    cin>>r;
    t=new int[r];
    for(int i = 0;i<r;i++){
        cin>>t[i];
    }
    spr(t,r);
    delete[] t;
}

// ===================================================== ZAD3

void sort(int *t, int r){
        int i, j;
        for (i = 0; i < r-1; i++)
            for (j = 0; j < r-i-1; j++)
                if (t[j] > t[j+1])
                    swap(t[j], t[j+1]);
}

void zad3()
{
    int *t, r;
    cout<<"Wpisz rozmiar"<<endl;
    cin>>r;
    t=new int[r];
    for(int i = 0;i<r;i++){
        cin>>t[i];
    }
    wyswietltablice(t,r);
    sort(t,r);
    wyswietltablice(t,r);
    delete[] t;
}

// ===================================================== ZAD4

void funkcja(int x, int *w){
    *w = x;
}

void zad4(){
    int z = 6, *y, x=9;
    y = &z;
    cout<<"przed:\nz="<<z<<"\nx="<<x<<endl;
    funkcja(x,y);
    cout<<"po:\nz="<<z<<"\nx="<<x<<endl;
}

int main(){
    //zad1();
    //zad2();
    //zad3();
    //zad4();

    return 0;
}