#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int toInt(char s){ //to convert char to int
    return int(s)-48;
}

string WordToStr(string &s, int i){
	
	string units[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
	string teens[] = {"", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
	string tens[] = {"", "ten ", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
	string places[] = {"", "", "hundred and ", "thousand ", "", "lakhs ", "", "crore ", "", "arab "};

	int curChar = toInt(s[i]);

	if(i==0){
		
		return units[curChar];
	}
	if(i<0){
		return "";
	}

	string previ = "";

	if(i==1){

		if(curChar==1){
			i = i-1;
			curChar = toInt(s[i]);
			if(curChar == 0) previ = tens[1] + previ;
			else previ = teens[curChar] + previ;
		}
		else{
			previ = WordToStr(s, i-1);
			previ = tens[curChar] + previ;
		}
	}
	
	previ = WordToStr(s, i-1);
	previ = places[i] + previ;
	if(i==2){
		previ = units[curChar] + previ;
	}
	return previ;
}


main()
{
	string a ="318";
	cout<<a<<endl;
	reverse(a.begin(), a.end());

	cout<<WordToStr(a, a.length()-1)<<endl;
	
	return 0;
}