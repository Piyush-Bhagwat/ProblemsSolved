#include<iostream>
#include<conio.h>
using namespace std;

class palindrome{
    private:
        string s;
    public:
        void read(){
            cout<<"Enter a word: ";
            cin>>s;
        }

        void show(){
            string orig = s;
            int i=0, j=s.length()-1;

            while(i<j){
                char temp = s[i];
                s[i]=s[j];
                s[j] = temp;
                i++; j--;
            }

            if(s == orig){
                cout<<orig<<" is palindrome";
            }
            else{
                cout<<orig<<" is not palindrome";
            }
        }
};

main(){
    palindrome p;
    p.read();
    p.show();
}