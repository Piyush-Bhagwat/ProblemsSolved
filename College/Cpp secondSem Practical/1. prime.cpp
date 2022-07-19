#include<iostream>
#include<conio.h>
using namespace std;

class Prime{
    private:
        int n;
    public:
        void read(){
            cout<<"Enter Number: ";
            cin>>n;
        }

        int isPrime(){
            for(int i=2; i*i<n; i++){
                if(n%i == 0){
                    return 0;
                }
            }
            return 1;
        }

        void show(){
            if(isPrime()){
                cout<<n<<" is prime";
            }
            else{
                cout<<n<<" is not prime";
            }
        }
};

main()
{
    Prime p;
    p.read();
    p.show();
    return 0;
}