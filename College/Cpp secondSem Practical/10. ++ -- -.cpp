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

        void operator ++(){
            ++a; ++b;
        }

        void operator --(){
            --a, --b;
        }

        void operator -(){
            a= -a, b=-b;
        }
};

main(){
    Test t(2, 3);
    ++t;
    t.show();

    --t;
    t.show();

    -t;
    t.show();
}