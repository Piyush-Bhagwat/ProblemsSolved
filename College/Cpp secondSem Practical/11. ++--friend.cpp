#include<iostream>
#include<conio.h>
using namespace std;

class Test{
    private:
        int a, b;
    public:
        Test(int x, int y){
            a=x;
            b=y;
        }

        void show(){
            cout<<"a: "<<a<<'\t'<<"b: "<<b<<endl;
        }

        friend void operator ++(Test &m);
        friend void operator --(Test &m);
        friend void operator -(Test &m);
};

void operator ++(Test &m){
    ++m.a; ++m.b;
}

void operator --(Test &m){
    --m.a, --m.b;
}

void operator -(Test &m){
    m.a= -m.a, m.b=-m.b;
}

main(){
    Test t(2, 3);
    ++t;
    t.show();

    --t;
    t.show();

    -t;
    t.show();
}