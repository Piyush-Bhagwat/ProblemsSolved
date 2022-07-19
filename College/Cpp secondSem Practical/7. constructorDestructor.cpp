#include<iostream>
#include<conio.h>
using namespace std;

class test{
    private:
        static int c;
    public:
        test(){
            cout<<"Created  ";
            cout<<"Total present: "<<c++<<endl;
        }

        ~test(){
            cout<<"Destroyed!  ";
            cout<<"total present: "<<c--<<endl;
        }
};
int test::c;

main(){
    test a;
    test b;
    {
        test c;
    }
}