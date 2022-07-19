#include<iostream>
#include<conio.h>
using namespace std;

class Fibbo{
    private:
        int n;

    public:
        void read(){
            cout<<"Length of series: ";
            cin>>n;
        }

        void print(){
            int a=0, b=1;

            cout<<a<<' '<<b<<' ';

            for(int i=2; i<n; i++){
                int c=a+b;
                a=b;
                b=c;

                cout<<c<<' ';
            }
        }

};

main(){
    Fibbo f;
    f.read();
    f.print();
}