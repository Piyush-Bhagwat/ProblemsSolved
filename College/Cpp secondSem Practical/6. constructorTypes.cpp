#include<iostream>
#include<conio.h>
using namespace std;

class test{
    private:
        int a, b;
    public:
        test(){
            a=0; b=0;
        }

        test (int x, int y){
            a=x, b=y;
        }

        test(test &x){
            a= x.a;
            b= x.b;
        }

        void show(){
            cout<<"a: "<<a<<'\t'<<"b: "<<b<<endl;
        }
};


main(){
    test a;
    a.show();
    
    test b(6, 7);
    b.show();

    test c=b;
    c.show();
}