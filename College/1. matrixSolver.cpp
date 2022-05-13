#include<iostream>
using namespace std;

class Matrix {
    private:
        float a[3][3] = {0, 2, -1, 2, 3, -2, 0, 2, -2}, 
        b[3] = {1, 2, 3};
        bool er = false;
    public:

        void read(){ //To get the input
            cout<<"Enter Values for Matrix a from left to right: "<<endl;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cout<<"a["<<i+1<<", "<<j+1<<"] = ";
                    cin>>a[i][j];
                }
            }

            cout<<"Now for matrix b: "<<endl;

            for(int i=0; i<3; i++){
                cout<<"b["<<i+1<<"] = ";
                cin>>b[i];
            }
            cout<<endl;
        }

        void display(){ //To display current Matrix
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<" = "<<b[i]<<endl;
            }
            cout<<endl;
        }

        void rowExc(int r1, int r2){ //Exchanges 2 row
            int temp = b[r1];
            b[r1] = b[r2];
            b[r2] = temp;

            for(int i=0; i<3; i++){
                temp = a[r1][i];
                a[r1][i] = a[r2][i];
                a[r2][i] = temp; 
            }
            cout<<"R"<<r1+1<<" <-> "<<"R"<<r2+1<<endl;
            display();
        }

        void rowDiv(int r, float val){ //Divides a Row by a num
            if(a[r][r] == 1) return;

            for(int i=0; i<3; i++){
                a[r][i] = a[r][i]/val;
            }

            b[r] = b[r]/val;

            cout<<"R"<<r+1<<" = R"<<r+1<<"/"<<val<<endl;
            display();
        }

        void rowSub(int r1, int r2, float val){ //Substract a Row by Other Row with a Constant
            if(val == 0) return;
            for(int i =0; i<3; i++){
                a[r1][i] = a[r1][i] - a[r2][i] * val;
            }
            b[r1] = b[r1]-b[r2]*val;

            cout<<"R"<<r1+1<<" = R"<<r1+1<<" - R"<<r2+1<<"*"<<val<<endl;
            display();
        }

        void error(){ //Used when problem cannot be solved further
            cout<<"Sorry this problem cannot be solved!"<<endl;
            er = true;
        }

        int checkOne(int c){ //to check if we have 1 in the column
            for(int i=c+1; i<3; i++){
                if(a[i][c] == 1){
                    return i;
                }                
            }
            return -1;
        }

        void excForOne(int r1){ //If we have one in the colomn we exchange it with diagonal ele
            if(a[r1][r1] == 1) return;

            int r2 = checkOne(r1);
            if (r2 == -1) return;

            rowExc(r1, r2);
        }

        void removeZero(int c){ //To remove 0 from diagonal ele
            if(a[c][c] != 0) return;
            for(int i=c+1; i<3; i++){
                if(a[i][c] != 0){ 
                rowExc(c, i);
                return;
                }
            }
            error();
        }

        void solve(){ //Main driver func to solve the matrix
            for(int i=0; i<3; i++){
                excForOne(i);
                removeZero(i);
                if(er) break;
                rowDiv(i, a[i][i]);

                for(int j=0; j<3; j++){
                    if(j==i) continue;
                    rowSub(j ,i, a[j][i]);
                }
                if(er) break;
            }
        }

        void displayAns(){ // to display the final ans
            cout<<"The Final Answers: ";
            if (!er) cout<<"x = "<<b[0]<<", y = "<<b[1]<<", z = "<<b[2];
            else cout<<"No answers to this question";

            cout<<endl;
                    
        }
};

main(){
    Matrix m;
    m.read();

    cout<<"the given Matrix: "<<endl;
    m.display();

    m.solve();

    m.displayAns();
}
