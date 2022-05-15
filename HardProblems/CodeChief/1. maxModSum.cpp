/*You are given an array A containing N integers, and a positive integer M. Find the maximum value of
Ai+Aj+((Ai−Aj)modM)
across all pairs 1≤i,j≤N.

Note that xmodM refers to the smallest non-negative integer obtained as the remainder 
upon dividing x by M. For example, 4mod3=1 and (−10)mod3=2.
*/


#include <iostream>
using namespace std;

int main() {
	
    int n, m;
    cin>>n>>m;
    
    int a[n];
    int larEle = -1000; //a[j] should be the largest ele of the array
    for(int i=0; i<n; i++){
        cin>>a[i];
        larEle = max(larEle, a[i]); //to save the largesrr ele
    }
    
    int ans=0;
    for(int i=0; i<n; i++){
        int temp = a[i] + larEle + ((a[i]- larEle)%m + m)%m; //we have dont %m twice cause if (a[i]-larele) becomes 0 then the mod will also be 0 so doing it mod again will fix this
        ans = max(ans, temp);
    }
    cout<<ans<<endl;
	return 0;
}
