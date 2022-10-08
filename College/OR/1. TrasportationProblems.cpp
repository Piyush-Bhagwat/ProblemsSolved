#include<iostream>
#include<vector>
#include<utility>
using namespace std;

#define INT_MAX = 1000;
#define INT_MIN = -1000;

class Problem{// Magic is happening here
    private:
    int row, col;
    int rowAvil, colAvil;
    int ans=0;

    vector<vector<int>> data;

    vector<int> sPenalty;
    vector<int> dPenalty;

    vector<vector<int>> dataCopy;
  
    vector<pair<pair<int, int>, int>> allocationVec;


    public:
        int getSupply(int pos){
            return data[pos][col-1];
        }

        void setSupply(int pos, int valToSub){
            data[pos][col-1]  -=valToSub;
        }

        int getDemand(int pos){
            return data[row-1][pos];
        }

        void setDemand(int pos, int valToSub){
            data[row-1][pos] -= valToSub;
        }
        
        int getAllocations(int r,int c){ //get the allocation the pirticular cell
            return min(getSupply(r), getDemand(c));
        }

        int getRemaint(int r, int c){
            return max(getSupply(r), getDemand(c));
        }

        void display(){ //Displays the problem
            cout<<endl;
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    if(i == row-1 && j == col-1) continue;
                    if(j == col-1) cout<<" | ";

                    if(data[i][j] == -1){
                        cout<<"XX ";
                        continue;
                    }
                    if(data[i][j] < 10){
                        cout<<"0";
                    }

                    cout<<data[i][j]<<" ";
                }

                cout<<endl;
                if(i == row-2){
                    for(int j=0; j<col; j++){
                        cout<<"---";
                    }
                    cout<<endl;
                }
            }
            cout<<endl;
        }     

        void input(){ //To get the input of all the data;
            cout<<"enter the size of grid(row, col): ";
            cin>>row>>col;

            rowAvil = row;
            colAvil = col;

            row++; col++;

            cout<<"enter data: "<<endl;
            for(int i=0; i<(row-1); i++){
                data.push_back(vector<int> ());
                cout<<i<<". row: ";
                for(int j=0; j<col-1; j++){
                    int num;
                    cin>>num;
                    data[i].push_back(num);
                }
             
            }

            cout<<"enter supply: "<<endl;
            for(int i=0; i<(row-1); i++){
                int num;
                cin>>num;
                data[i].push_back(num);
            }

            cout<<"Enter Demand: "<<endl;
            data.push_back(vector<int>());
            for(int i=0; i<(col-1); i++){
                int num;
                cin>>num;
                
                data[row-1].push_back(num);
            }

            data[row-1].push_back(-1);

            supplyDemandAdjust();
            cout<<endl;
            dataCopy = data;
        }

        void supplyDemandAdjust(){ //Add dumy row/col if required
            int supply=0, demand=0;
            cout<<endl;
            
            for(int i=0; i<row-1; i++){
                supply += data[i][col-1];
            }
            for(int i=0; i<col-1; i++){
                demand += data[row-1][i];

            }

            if(supply == demand){
                cout<<"This problem is Balanced as supply("<<supply<<") = Demand("<<demand<<"). "<<endl;
                return;
            }

            if(demand<supply){
                int toAdd = supply - demand;
                for(int i=0; i<row; i++){
                    data[i].push_back(data[i][col-1]);
                    
                    if(i == row-1){
                        data[i][col-1] = toAdd;
                        continue;
                    }
                    data[i][col-1] = 0;
                }
                
                col++; colAvil++;
                cout<<"The demand("<<demand<<") < Supply("<<supply<<") so we have added a dummy column. To adjust Demand by "<<toAdd<<endl;
            }
            else if(supply<demand){
                int toAdd = demand - supply;

                data.push_back(vector<int> ());
                row++; rowAvil++;

                for(int i=0; i<col; i++){
                    data[row-1].push_back(data[row-2][i]);

                    if(i == col-1){
                        data[row-2][i] = toAdd;
                        continue;
                    }
                    data[row-2][i] = 0;
                }

                cout<<"The Supply("<<supply<<") < Demand("<<demand<<") so we have added a dummy row. To adjust supply by "<<toAdd<<endl;
            }
        }

        pair<int, int> getNWC(){ //get the northWestCorner cell
            int r=-1, c=-1;

            for(int i=0; i<(row-1); i++){
                for(int j=0; j<(col-1); j++){
                    if(data[i][j] != -1){
                        return make_pair(i, j);
                    }
                }
            }
            return make_pair(r, c);
        }

        void deleteCol(int c){
            for(int i=0; i<row; i++){
                data[i][c]=-1;
            }
        }

        void deleteRow(int r){
            for(int i=0; i<col; i++){
                data[r][i]=-1;
            }
        }

        void operation(int r, int c){ //Main operation on indivual Cells
            int Allocation = getAllocations(r, c);
            ans += (Allocation * data[r][c]);

            setDemand(c, Allocation);
            setSupply(r, Allocation);

            if(getSupply(r) == 0){
                rowAvil--;
                deleteRow(r);
            }
            if(getDemand(c) == 0){
                colAvil--;
                deleteCol(c);
            }

            pair<int, int> pos(r, c);
            
            allocationVec.push_back(make_pair(pos, Allocation));
        }
     
        void NorthWestMethod(){ //Repeat the Opration in NWM method
            while(true){
                pair<int,int> NWC = getNWC();
                int r = NWC.first, c= NWC.second; 
                operation(r, c);
                display();
                if(r==(row-2) && c==(col-2)) break;
            }
        }

        pair<int, int> LCMCell(){
            int min = INT_MAX;
            int prevAlloc;
            int prevRemai;
            int r, c;
            for(int i=0; i<row-1; i++){
                for(int j=0; j<col-1; j++){
                    if(data[i][j]==-1) continue;

                    if(data[i][j] < min){
                        r=i; c=j;
                        min = data[i][j];
                        prevAlloc = getAllocations(i, j);
                        prevRemai = getRemaint(i, j);
                    }
                    else if(data[i][j] == min){
                        if(prevAlloc < getAllocations(i, j)){
                            r=i; c=j;
                            min = data[i][j];
                            prevAlloc = getAllocations(i, j); 
                            prevRemai = getRemaint(i, j);
                        }
                        else if (prevAlloc == getAllocations(i, j)){
                            if(getRemaint(i, j)<prevRemai){
                                r=i; c=j;
                                min = data[i][j];
                                prevAlloc = getAllocations(i, j); 
                                prevRemai = getRemaint(i, j);
                            }
                        }
                    }
                }
            }

            return make_pair(r, c);
        }
        
        bool isFinished(){ //Returns true if the problem is solved 
            for(int i=0; i<row-1; i++){
                for(int j=0; j<col-1; j++){
                    if(data[i][j] != -1) return false;
                }
            }

            return true;
        }

        void leastCostMethod(){
            while(!isFinished()){
                pair<int, int> pos = LCMCell();
                int r = pos.first, c= pos.second;
                operation(r, c);
                display();
            }

        }

        void showAnswer(){
            cout<<"Allocations: "<<endl;
            for(int i=0; i<allocationVec.size(); i++){
                pair<int, int> pos = allocationVec[i].first;
                int allo = allocationVec[i].second;

                cout<<"X("<<pos.first+1<<","<<pos.second+1<<"): "<<allo<<"\t";
                if((i+1)%3 == 0) cout<<endl;
            }
            cout<<endl;
            cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"The final is "<<ans<<endl;
            cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
        }

        int getColMinima(int c){ //return the pos of the least element in the column
            int min = INT_MAX;
            int r = 0;
            int prevAlloc;
            int preRemain;
            for(int i=0; i<row-1; i++){
                if(data[i][c] == -1) continue;

                if(data[i][c]<min){
                    min = data[i][c];
                    prevAlloc = getAllocations(i, c);
                    preRemain = getRemaint(i, c);
                    r = i;
                }   
                else if(data[i][c]==min){ // select the max Allocations
                    if(getAllocations(i, c) > prevAlloc){
                        min = data[i][c];
                        prevAlloc = getAllocations(i, c);
                        preRemain = getRemaint(i, c);
                        r = i;
                    }
                    else if(getAllocations(i, c)==prevAlloc){ // if allocations are same select with less remainder
                        if(getRemaint(i, c) < preRemain){
                            min = data[i][c];
                            prevAlloc = getAllocations(i, c);
                            preRemain = getRemaint(i, c);
                            r = i;
                        }
                    }
                }
            }
            return r;
        } 

        int getRowMinima(int r){// return the pos of the least element ii the row
            int min = INT_MAX;
            int c = 0;
            int prevAlloc;
            int preRemain;

            for(int i=0; i<col-1; i++){
                if(data[r][i] == -1) continue;

                if(data[r][i]<min){
                    min = data[r][i];
                    prevAlloc = getAllocations(r, i);
                    preRemain = getRemaint(r, i);
                    c = i;
                }   
                else if(data[r][i]==min){ 
                    if(getAllocations(r, i) > prevAlloc){// select the max Allocations
                        min = data[r][i];
                        prevAlloc = getAllocations(r, i);
                        preRemain = getRemaint(r, i);
                        c = i;
                    }
                    else if(getAllocations(r, i)==prevAlloc){ // if allocations are same select with less remainder
                        if(getRemaint(r, i) < preRemain){
                            min = data[r][i];
                            prevAlloc = getAllocations(r, i);
                            preRemain = getRemaint(r, i);
                            c = i;
                        }
                    }
                }
            }
            return c;
        } 

        void columnMinima(){
            for(int i=0; i<col-1; i++){
                while(data[row-1][i] != -1){
                    int r = getColMinima(i);
                    operation(r, i);
                    display();
                }
            }
        }   

        void rowMinima(){
            for(int i=0; i<row-1; i++){
                while(data[i][col-1] != -1){
                    int c = getRowMinima(i);
                    operation(i, c);
                    display();
                }
            } 
        }

        void repete(){//resets the object for reuseing the same data
            data = dataCopy;
            ans = 0;
            allocationVec.clear();
            colAvil = col-1;
            rowAvil=row-1;
        }

        //Penalty Method Starts Here

        bool allSameCol(int c, int val){ //Returns true if the Column have all same values
            for(int i=0; i<row-1; i++){
                if(data[i][c] == -1) continue;
                if(data[i][c] != val) return false;
            }
            return true;
        }   
       
        bool allSameRow(int r, int val){//Return true if row have all same values
            for(int i=0; i<col-1; i++){
                if(data[r][i] == -1) continue;
                if(data[r][i] != val) return false;
            }
            return true;
        }

        void supplyPenalty(int r){ //fills up the supply penalty
            if(data[r][col-1] == -1){
                sPenalty.push_back(-1);
                return;
            }

            int min1= INT_MAX, min2=INT_MAX;
            for(int i=0; i<col-1; i++){
                if(data[r][i] == -1) continue;
                if(data[r][i]<min1){
                    min1=data[r][i];
                }
            }

            if(allSameRow(r, min1)){
                sPenalty.push_back(0);
                return;
            }

            for(int i=0; i<col-1; i++){
                if(data[r][i] == -1) continue;
                if(min1<data[r][i] && data[r][i]<min2 && !(min1 == data[r][i])){
                    min2 = data[r][i];
                }
            }
            sPenalty.push_back(min2-min1);
        } 

        void demandPenalty(int c){ //fills up the demand penulty
            if(data[row-1][c] == -1){
                dPenalty.push_back(-1);
                return;
            }
            int min1= INT_MAX, min2=INT_MAX;
            for(int i=0; i<row-1; i++){
                if(data[i][c] == -1) continue;
                if(data[i][c]<min1){
                    min1=data[i][c];
                }
            }

            if(allSameCol(c, min1)){
                dPenalty.push_back(0);
                return;
            }

            for(int i=0; i<row-1; i++){
                if(data[i][c] == -1) continue;
                if(min1<data[i][c] && data[i][c]<min2 && !(min1 == data[i][c])){
                    min2 = data[i][c];
                }
            }
            dPenalty.push_back(min2-min1);
        }

        pair<char, int> getPenalty(){ // returns the maxPenulty
            int maxPen = INT_MIN;
            int prevAlloc;
            int curAllo;

            int val;
            char wt;

            cout<<"supply: ";
            for(int i=0; i<row-1; i++){
                curAllo = getAllocations(getRowMinima(i), i);
                supplyPenalty(i);
                if(sPenalty[i] == -1) cout<<"X ";
                else cout<<sPenalty[i]<<" ";

                if(sPenalty[i]>maxPen){
                    maxPen = sPenalty[i];
                    prevAlloc = curAllo;
                    val = i; wt = 's';
                }
                else if(sPenalty[i] == maxPen){
                    if(curAllo > prevAlloc){
                        maxPen = sPenalty[i];
                        prevAlloc = curAllo;
                        val = i; wt = 's';
                    }
                }
            }  

            cout<<endl<<"Demand: ";
            for(int i=0; i<col-1; i++){
                curAllo = getAllocations(i, getColMinima(i));
                demandPenalty(i);
                if(dPenalty[i] == -1) cout<<"X ";
                else cout<<dPenalty[i]<<" ";

                if(dPenalty[i]>maxPen){
                    maxPen = dPenalty[i];
                    prevAlloc = curAllo;
                    val = i; wt = 'd';
                }
                else if(dPenalty[i] == maxPen){
                    if(curAllo > prevAlloc){
                        maxPen = dPenalty[i];
                        prevAlloc = curAllo;
                        val = i; wt = 'd';
                    }
                }
            }
            cout<<endl;

            cout<<"Max Penalty is: "<<wt<<maxPen<<endl;
            return make_pair(wt, val);
        }
        
        void VAB(){
            while(rowAvil > 1 && colAvil>1){
                sPenalty.clear();
                dPenalty.clear();
                pair<char, int> penInfo = getPenalty();
                char wh = penInfo.first; int pos = penInfo.second;
                // cout<<wh<<pos<<" ";

                if(wh == 'd'){
                    int r = getColMinima(pos);
                    operation(r, pos);
                    display();   
                }
                else if(wh == 's'){
                    int c = getRowMinima(pos);
                    operation(pos, c);
                    display(); 
                } 
            }
            leastCostMethod();

        }

        void solve(){
            int ch;

            repete:
            cout<<endl<<"Which Method to use 1.NorthWest, 2.LeastCostMethod, 3.Column Minima, 4.RowMinima, 5. PenaultyMethod, 6.ToQuit  : ";
            cin>>ch;
            switch (ch)
            {
            case 1:
                cout<<"North-West Corner Method: "<<endl;
                NorthWestMethod();
                showAnswer();
                repete();
                goto repete;
                break;
            case 2:
                cout<<"Least Cost Method: "<<endl;
                leastCostMethod();
                showAnswer();
                repete();
                goto repete;
                break;

            case 3:
                cout<<"Column Minima: "<<endl;
                columnMinima();
                showAnswer();
                repete();
                goto repete;
                break;
                
            case 4:
                cout<<"Row minima: "<<endl;
                rowMinima();
                showAnswer();
                repete();
                goto repete;
                break;

            case 5:
                cout<<"Penalty Method: "<<endl;
                VAB();
                showAnswer();
                repete();
                goto repete;
                break;

            case 6:
                break;

            default:
                cout<<"not valid"<<endl;
                goto repete;
                break;
            }
        }
};

main(){
    Problem one; 

    one.input();

    one.display();

    one.solve();

} 
