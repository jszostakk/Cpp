#include <iostream>

using namespace std;


int dziel(int a, int b){
    if (a%b!=0)
        throw invalid_argument("Wynik niecalkowity");

    if(b=0)
        throw invalid_argument("Nie dziel przez 0");

    if(a<b)
        throw invalid_argument("Dzielna mniejsza od dzielnika");

    return a/b;
}

int zad1(){
    int a,b;
    cout<<"Podaj liczby"<<endl;
    cin>>a>>b;

    try{
        cout<<dziel(a,b)<<endl;
    }

    catch(invalid_argument& e){
        cerr<<e.what()<<endl;
        return -1;
    }
    return a/b;
}

int main(){
    zad1();

    return 0;
}