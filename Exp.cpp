#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void deleteAtPos(int ar[], int pos, int &size){

	for(int i=pos; i<size; i++){
		ar[i] = ar[i+1];
	}
	size--;
}

void deleteEle(int ar[], int key, int &size){
	for(int i=0; i<size; i++){
		if(ar[i] == key){
			deleteAtPos(ar, i, size);
		}
	}
}
main()
{
	int ar[10] = {1, 3, 4, 3, 5};
	int n = 5;

	deleteEle(ar, 3, n);

	for(int i=0; i<n; i++){
		cout<<ar[i]<<" ";
	}
	return 0;
}