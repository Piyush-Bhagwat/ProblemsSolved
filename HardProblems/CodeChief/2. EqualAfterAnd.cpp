/* question
You are given an array A=[A1,A2,…,AN], consisting of N integers. In one move, you can take two adjacent numbers Ai and Ai+1, 
delete them, and then insert the number Ai∧Ai+1 at the deleted position. Here, ∧ denotes bitwise AND. Note that after this operation, 
the length of the array decreases by one.

Formally, as long as |A|>1 (where |A| denotes the current length of A), you can pick an index 1≤i<|A| and transform A 
into [A1,A2,…,Ai−1,Ai∧Ai+1,Ai+2,…,A|A|].

Find the minimum number of moves required to make all numbers in the resulting array equal.
*/

/* Explanation
    And of two same num is the num itself
    so if we and A1^A2^...^An we will get a num x

    in the arry there will be groups whose and will give ans x 

    so the ans will be n-noOfGroups

    https://youtu.be/maLsZ6LoeBw
*/


#include <iostream>
using namespace std;

int main() {

    int n;
    cin>>n;
    
    int a[n];
    int totalAnd=(1>>30)-1; //this is 2^30-1, this number has all bits set to one.. so if we do x and this num we get x;
    for(int i=0; i<n; i++){
        cin>>a[i];
        totalAnd &= a[i]; //totalAnd = totalAnd ^ a[i]
    }
    
    int grpCnt=0; //group count
    int curAnd = (1>>30)-1; //will temp store the and of groups
    
    for(int i=0; i<n-1; i++){
        curAnd &= a[i]; //finding groups 
        
        if(curAnd==totalAnd){
            grpCnt++;
            curAnd = (1>>30)-1; //if we found a group then we reset the curAnd
        }
    }
    
    cout<<n-grpCnt<<endl;
	
	return 0;
}
