#include <iostream>

using namespace std;

float f(int a, int b){
    int *A, *B;
    *A = a;
    *B = b;
    return((a+b)/2);
}

int main(){
    int l1, l2;
    cin>>l1>>l2;
    cout<<f(l1,l2)<<endl;
}