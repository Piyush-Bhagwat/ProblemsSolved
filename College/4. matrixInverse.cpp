#include<iostream>
using namespace std;

class Matrix{
    private:
        float a[3][3] = {1, 1, 1, 3, 3, 4, 2, 1, 3}; 
        float cof[3][3], inv[3][3];
    public:
        void getData(){
            cout<<"Enter the matrix: "<<endl;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cout<<"a("<<i+1<<", "<<j+1<<"): ";
                    cin>>a[i][j];
                }
            }
        }

        void displayArr(){
            
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        void displayCof(){
            
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cout<<cof[i][j]<<" ";
                }
                cout<<endl;
            }
        }

          void displayInv(){
            
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cout<<inv[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        int Determinant(){
            float tempRes, result = 0;
            for(int i=0; i<3; i++){
                tempRes=0;

                int j=0, k=2;
                while(j<3 && k>=0){
                    if(j==i) j++;
                    if(k==i) k--;

                    if(j>k) tempRes -= (a[1][j]*a[2][k]);
                    else tempRes += (a[1][j]*a[2][k]);

                    j++; k--;
                }

                if(i == 1) tempRes *= -a[0][i];
                else tempRes *= a[0][i];

                result += tempRes;

            }
            return result;
        }

        float solve2x2(float ar[4]){
            
            return (ar[0]*ar[3] - ar[1]*ar[2]);
        }

        void transpose(){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    int k=0;
                    float mini[4];

                    for(int m=0; m<3; m++){
                        if(m==i) continue;
                        for(int n=0; n<3; n++){
                            if(n==j) continue;
                            mini[k] = a[m][n];
                            k++;
                        }
                    }

                    if((i+j+2)%2 == 0) cof[j][i] = solve2x2(mini);
                    else cof[j][i] = -solve2x2(mini);
                }
            }
        }

        void findInv(float n){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    inv[i][j] = cof[i][j] * n;
                }
            }
        }

        void solve(){
            cout<<"The matrix is: "<<endl;
            displayArr();

            float D = Determinant();
            cout<<"|A| = "<<D<<endl;
            if(D==0){
                cout<<"Cant get answer"<<endl;
                return;
            }

            transpose();
            cout<<"Transpose is: "<<endl;
            displayCof();

            findInv(1/D);
            cout<<"Inverse is: "<<endl;
            displayInv();
        }

};

main(){
    Matrix m;
    // m.getData();
    m.solve();

}