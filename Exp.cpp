#include <iostream>
#include<vector>
using namespace std;

int display(vector<int> a){
    int n = a.size();
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
	int T;
	// cin>>T;
    
	
	// for(int t=1; t<=T; t++){
	    int n;
	    cin>>n;
	    
	    vector<int> a;
        vector<int> b{1, 2, 3, 4, 5, 6};
	    
	    for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
	        a.push_back(temp);
	    }
	    
        int count=0;
        // for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                if(a[i]==0) continue;
                int temp = a[i]^a[i+1]; 
                
                a[i] = temp;
                b.erase(i);
                display(a);
                count++;
                // break;
            }
        // }0
        cout<<count<<endl;

	// }
	return 0;
}
