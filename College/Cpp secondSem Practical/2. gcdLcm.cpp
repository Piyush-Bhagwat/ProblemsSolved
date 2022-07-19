#include<iostream>
#include<conio.h>
using namespace std;

class LcmGcd{
    private:
        int a, b;
    public:
        void read(){
            cout<<"Enter 2 numbers: ";
            cin>>a>>b;
        }

        int gcd(){

            int m=a, n=b;

            while(m!=n){
                if(m>n){
                    m-=n;
                }
                else{
                    n-=m;
                }
            }

            return m;
        }

        int lcm(){
            return (a*b)/gcd();
        }

        void show(){
            cout<<"GCD is "<<gcd()<<endl;
            cout<<"LCM is "<<lcm();
        }
};

main(){
    LcmGcd l;
    l.read();
    l.show();
}