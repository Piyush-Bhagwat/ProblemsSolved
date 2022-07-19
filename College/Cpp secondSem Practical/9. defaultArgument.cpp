#include<iostream>
#include<conio.h>
using namespace std;

float intreast(int p=1, int n=1, int r=1){
    return (p*n*r)/100.0;
}

main(){
    cout<<intreast(4,3)<<endl;
    cout<<intreast(2,3,4)<<endl;
    cout<<intreast()<<endl;
}