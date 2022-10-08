#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Calculator{
    private:
        string num;
        string intPart, fractPart;
        string from, to;
        int method;
    
    public:

    void breakNum(){ //Breaks the number to its positive and negative part
        int ptPos;
        int i=0;
        while(i<num.length()){
            if(num[i] == '.'){
                ptPos = i;
                break;
            }
            intPart.push_back(num[i]);
            i++;
        }

        if(i==num.length()){
            fractPart.push_back('0');
            return;
        }

        for(i=ptPos+1; i<num.length(); i++){
            fractPart.push_back(num[i]);
        }
    }

    void input(){
        cout<<"bin, dec, oct, hex"<<endl;
        cout<<"From: ";
        cin>>from;

        cout<<"To: ";
        cin>>to;

        if(!checkNS()){
            cout<<"Enter valid Number sys"<<endl;
            return;
        }

        cout<<"Enter the "<<from<<" number: ";
        cin>>num;
        
        if(!checkNumInput()){
            cout<<"Enter valid "<<from<<" number"<<endl;
            return;
        }
        
        breakNum();
        getMethod();
        

    }
    
    void getMethod(){ //calculates which method to use with from and to
        if(to == "dec"){
            if(from == "bin") method = 1;
            else if(from == "oct") method = 2;
            else if(from == "hex") method = 3;
        }
        else if(from == "dec"){
            if(to == "bin") method = 4;
            if(to == "oct") method = 5;
            if(to == "hex") method = 6;
        }
    }

    int chToInt(char c){ //Convert the character to number also the hexa values
        if(c=='a') return 10;
        else if(c=='b') return 11;
        else if(c=='c') return 12;
        else if(c=='d') return 13;
        else if(c=='e') return 14;
        else if(c=='f') return 15;
        else return (c - '0');
    }

    int toInt(char c){
        return (c - '0');
    }

    bool checkNS(){ //checks the 'from' and 'to' var
        if((to=="bin" || to=="oct" || to=="hex" || to=="dec") && (from=="bin" || from=="oct" || from=="hex" || from=="dec")) {
            return true;
        }
        return false;
    }

    bool checkNumInput(){
     
        if(from == "bin"){
            for(int i=0; i<num.length(); i++){
                if(num[i] == '.') continue;
                if(toInt(num[i]) != 1 && toInt(num[i]) != 0){
                    return false;
                }
            }
            return true;
        }
        
        if(from == "oct"){
            for(int i=0; i<num.length(); i++){
                if(num[i] == '.') continue;
                if(!(0 <= toInt(num[i]) && toInt(num[i]) < 8)){
                    return false;
                }
            }
            return true;
        }

        if(from == "hex"){
            for(int i=0; i<num.length(); i++){
                if(num[i] == '.') continue;
                if(!(0 <= chToInt(num[i]) && chToInt(num[i]) < 16)){
                    return false;
                }
            }
            return true;
        }

        if(from == "dec"){
            for(int i=0; i<num.length(); i++){
                if(num[i] == '.') continue;
                if(isalpha(num[i])){
                    return false;
                }
            }
            return true;
        }
    }

    void toDecimal(int base){//converts bin, oct, hex to Decimal
        int ans=0;
        reverse(intPart.begin(), intPart.end());
        
        for(int i=0; i<intPart.length(); i++){ //Handaling positive part
            int cur = chToInt(tolower(intPart[i]));
            ans += (cur * pow(base, i));  
        }

        for(int i=0; i<fractPart.length(); i++){ //handaling negative part
            int cur = chToInt(tolower(fractPart[i]));
            ans += (cur * pow(base, -(i+1)));
        }

        getAnswer(ans);
    }

    char intToCh(int n){
        if(n==10) return 'A';
        if(n==11) return 'B';
        if(n==12) return 'C';
        if(n==13) return 'D';
        if(n==14) return 'E';
        if(n==15) return 'F';
        return (n+'0');
    }

    void fromDecimal(int base){
        int p = stoi(intPart);
        int remainder;
        string ans = "";

        while(p != 0){ //get the Intergal part
            remainder = p%base;
            p = p/base;
            ans.push_back(intToCh(remainder));
        }
        reverse(ans.begin(), ans.end());

        float n =stoi(fractPart);
        if(n!=0){ //get the fractional part if it exist
            ans.push_back('.');
            n = n / pow(10, fractPart.length());

            for(int i=1; i<=5; i++){
                n = n*base;
                ans.push_back(intToCh(floor(n)));
                n = n - floor(n);
            }
        }
        getAnswer(ans);

    }

    void solve(){
        if(!checkNumInput() || !checkNS()){
            return;
        }
        switch (method)
        {
        case 1:
            toDecimal(2);
            break;
        case 2:
            toDecimal(8);
            break;
        case 3:
            toDecimal(16);
            break;
        case 4:
            fromDecimal(2);
            break;
        case 5:
            fromDecimal(8);
            break;
        case 6:
            fromDecimal(16);
            break;
        default:
            break;
        }
    }

    void getAnswer(int ans){
        cout<<"----------------------------------------"<<endl;
        cout<<"The answer is "<<ans<<endl;
        cout<<"----------------------------------------"<<endl;
    }
   
    void getAnswer(string ans){
        cout<<"----------------------------------------"<<endl;
        cout<<"The answer is "<<ans<<endl;
        cout<<"----------------------------------------"<<endl;
    }

};

main()
{
    Calculator c;
    c.input();

    c.solve();
    return 0;
}