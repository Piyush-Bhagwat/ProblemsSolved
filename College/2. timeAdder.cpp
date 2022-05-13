#include<iostream>
#include<iostream>

using namespace std;

class Time{
    private:
        int hr, min, day;
    public:
        Time(){ //initalize the time
            hr = min = 0;
            day = -1;
        }

        Time(int x, int y, int z = -1){ //initialise the time
            hr = x;
            min = y;
            day = z;
        }

        void convertTime(){ //fixes the time which go beyond the limits
            if(min>=60){ //fixes mins
                hr += min/60;
                min = min%60;
            }

            if(hr>12){// fixes hours
                day += hr/12;
                hr = hr%12;
            }

            if(day>=2){ //fixes am pm
                day = day%2;
            }
        }

        void show(){ //displays the time in proper way
            convertTime();
            
            if(hr == 0) cout<<"12";
            else if(hr<9) cout<<"0"<<hr; //adds 0 if hr is less than 9 (01, 02)
            else cout<<hr;
            cout<<":";
            
            if(min ==0) cout<<"00";
            else if(min<10) cout<<"0"<<min; //adds o is mins are less than 9
            else cout<<min;

            if(day == 0) cout<<" am"<<endl;
            else if(day == 1) cout<<" pm"<<endl;
        }

        void add(Time x){ // add function
            hr+=x.hr;
            min+=x.min;
            day+=x.day;
        }

        Time operator +(Time x){ //add operator
            Time t;
            t.hr = hr + x.hr;
            t.min = min + x.min;
            t.day = day + x.day;
            return t;
        }
};

main(){
    Time a(1, 20, 1), b(7, 50, 0), c;
    c = a+b;
    a.show();
    cout<<"+"<<endl;
    b.show();
    cout<<"="<<endl;
    c.show();
}