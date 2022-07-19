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

        friend Test operator +(Test c, Test d);
        friend Test operator -(Test c, Test d);

        
};

Test operator +(Test c, Test d){
    Test t;
    t.a= c.a + d.a;
    t.b = c.b + d.b;
    return t;
}

Test operator -(Test c, Test d){
    Test t;
    t.a= c.a - d.a;
    t.b = c.b - d.b;
    return t;
}

main(){
    Test a(2, 8), b(4, 0), c(0, 0);

    c = a+b;
    c.show();

    c = b-a;
    c.show();
    return 0;
}