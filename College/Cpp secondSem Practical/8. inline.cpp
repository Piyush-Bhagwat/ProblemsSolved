#include<iostream>
#include<conio.h>
using namespace std;

class Circle{
    private: 
        int r;
    public:
        Circle(int a){
            r=a;
        }

        inline float getArea(){
            return r*r*3.14;
        }

        void show(){
            float area = getArea();
            cout<<"Area is: "<<area;
        }
};

main(){
    Circle c(4);
    c.show();
}