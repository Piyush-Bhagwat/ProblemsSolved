#include<iostream>
using namespace std;

class Equations{
    private:
        float e1[3], e2[3];
        float x, y;
    public:

        void read(){ //to read the equations
            cout<<"Enter Equations in a, b, c format: "<<endl;
            cout<<"Enter eq1: ";
            for(int i=0; i<3; i++){
                cin>>e1[i];
            }
            cout<<"Enter eq2: ";
            for(int i=0; i<3; i++){
                cin>>e2[i];
            }
        }

        void calcY(){ //Calculates Y
            float e3[3];
            float a1= e1[0], a2= e2[0];

            for(int i=0; i<3; i++){
                e3[i] = (e1[i]*a2) - (e2[i]*a1);
            }

            y = e3[2]/e3[1];
        }

        void calcX(){ //Calculates X
            x = (e1[2]-e1[1]*y)/e1[0];
        }

        void show(){ //Displays the answerw
            calcY();
            calcX();

            cout<<"x: "<<x<<", y: "<<y;
        }
};

main(){
    Equations a;
    a.read();
    a.show();
}