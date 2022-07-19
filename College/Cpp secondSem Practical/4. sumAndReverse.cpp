#include<iostream>
#include<conio.h>
using namespace std;

class SumAndRev{
    private:
        int n, sum=0, rev=0;
    public:
        void read(){
            cout<<"enter a num: ";
            cin>>n;
        }
        void sumnRev(){
            while(n>0){
                int curDig = n%10;
                sum+=curDig;
                rev = rev*10 + curDig;
                n=n/10;
            }
        }

        void show(){
            sumnRev();
            cout<<"Reverse is: "<<rev<<endl;
            cout<<"Sum of Dig is: "<<sum;
        }
};

main(){
    SumAndRev s;
    s.read();
    s.show();
}