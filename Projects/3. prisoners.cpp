#include<bits/stdc++.h>
using namespace std;

int size = 100;
main(){
    srand(time(NULL));//getting random seed for rand()

    vector<int> boxes(size, -1);
    bool prisoners[size];

    for(int i=0; i<size; i++){
        while(true){
            int r = rand()%100;
            if(boxes[r]!=-1){
                continue;
            }
            boxes[r]=i;
            break;
        }
    }

    for(int i=0; i<size; i++){
        int val = boxes[i];
        int j;
        for(j=0; j<50; j++){
            if(val == i){
                break;
            }
            val = boxes[val];
        }

        if(j==50){
            prisoners[i] = false;
        }
        else{
            prisoners[i] = true;
        }
    }
    int i;
    for(i=0; i<size; i++){
        if(prisoners[i]==0){
            cout<<"Execute!";
            break;
        }
    }

    if(i==size){
        cout<<"All free!";
    }
}