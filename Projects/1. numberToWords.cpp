#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<math.h>
using namespace std;

int toInt(char s){ //to convert char to int
    return int(s)-48;
}

void printNumberInWord(int s){ //The main converting function

    if(s==0){
        cout<<"zero";
        return;
    }

    string n = to_string(s);

    reverse(n.begin(),n.end()); //we need to reverse string or else we cant fix the postions
    int noDig = n.length();

    string units[10] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
    string teens[] = {"", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
    string tens[] = {"", "ten ", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
    string places[] = {"", "", "hundred and ", "thousand ", "", "lakhs "};
    
    
    for(int i=noDig-1; i>=0; i--){
        int curDig = toInt(n[i]);
       
        if(curDig == 0 && ((i==3 && n[4]=='0') || i==2)) continue; //if we get zero we print nothing

        if(i==1 || i==4 || i==6){
            if(curDig == 1){ //if we have 1 in tens place then we print from teens
                int oldDig = curDig;
                i--; //as we write elevel which is cobination of two num we decrease i once more
                curDig = toInt(n[i]);
                if(curDig == 0) cout<<tens[oldDig]; //if we get 0 then we print ten
                else cout<<teens[curDig]; 
            }
            else cout<<tens[curDig];
        }

        else{
            cout<<units[curDig]; //this handles all the places where we want to print unit nombers, one two etc
        }
        
        cout<<places[i]; //this will smartly print thousand and hundred
             
    }
}

main(){
    int n;
    cin>>n;

    printNumberInWord(n);

}