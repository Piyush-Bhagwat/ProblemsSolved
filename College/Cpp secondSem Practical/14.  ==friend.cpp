#include<iostream>
#include<conio.h>
using namespace std;

class Test{
    private:
        int a, b;
    public:
        Test(){}

        Test(int x, int y){
            a=x;
            b=y;
        }

        void show(){
            cout<<"a: "<<a<<'\t'<<"b: "<<b<<endl;
        }

        friend int operator ==(Test c, Test d);   
};

int operator ==(Test c, Test f){
    if(c.a==f.a && c.b==f.b){
        return 1;
    }
    else return 0;
}

main(){
    Test a(3, 4), b(5, 3);

    cout<<(a==b);
}