#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Game{
    private:
        char board[3][3];
        char player = 'X';
        char defaultChar = '_';


    public:

        Game(){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    board[i][j] = defaultChar;
                }
            }
        }

        void displayBoard()
        {
            int count=1;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(board[i][j] == defaultChar){
                        cout<<count<<" ";
                    }
                    else{
                        cout<<board[i][j]<<" ";
                    }
                    count++;
                }
                cout<<endl;
            }
            cout<<endl;
        }

        char getPlayer(){
            return player;
        }

        void changePlayer(){
            if(player == 'X'){
                player = 'O';
            }
            else{
                player = 'X';
            }
        }

        bool slotAvailable(int row, int col){
            if(board[row][col] == defaultChar){
                return 1;
            }

            cout<<"You cant place it there!"<<endl;
            return 0;
        }

        bool write(int pos){
            if(pos>9 || pos<1){
                return 0;
            }
            int row = (pos-1)/3;
            int col = (pos-1)%3;
            if(!slotAvailable(row, col)){
                return 0;
            }

            board[row][col] = player;

            return 1;
        }

        bool rowSame(){
            bool flag;

            for(int i=0; i<3; i++){
               if(board[i][0] != defaultChar){
                if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
                    return 1;
                }
               }
            }
            return 0;
        }

        bool colSame(){
            bool flag;

            for(int i=0; i<3; i++){
               if(board[0][i] != defaultChar){
                if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
                    return 1;
                }
               }
            }
            return 0;
        }

        bool digSame(){
           
            if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != defaultChar){
                return 1;
            }

            if(board[2][0] == board[1][1] && board[0][2] == board[1][1] && board[2][0] != defaultChar){
                return 1;
            }

            return 0;
        }

        int getInput(){
            cout<<player<<" your turn: ";
            int move;
            cin>>move;
            return move;
        }

        bool quit(int n){
            return n==0 ? 1 : 0;
        }

        bool won(){
            if(rowSame()|| colSame() || digSame()){ // ){
                return 1;
            }
            return 0;
        }

        bool matchTie(){

            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(board[i][j] == defaultChar){
                        return 0;
                    }
                }
            }

            return 1;
        }

};


class AIplayer{
    private:

    public:

    int makeMove(){

        int sth = rand()%9 + 1;

    }
};


void instructions(){
    cout<<"First Player is always'x'"<<endl;
    cout<<"Enter postion between 1 to 9"<<endl;
    cout<<"Enter 0 to end game"<<endl;
}



main()
{
    Game p;
    AIplayer a;
    p.displayBoard();

    instructions();

    int curInp;
    while(true){
        if(p.getPlayer() == 'X'){

            curInp = p.getInput();
        }
        else{
            curInp = a.makeMove();
            cout<<"Computer moved "<<curInp<<endl;
        }

        if(p.quit(curInp)){
            cout<<"Game Over!";
            break;
        }
        if(!p.write(curInp)){
            continue;
        }

        p.displayBoard();

        if(p.won()){
            cout<<p.getPlayer()<<" Won the game!"<<endl;
            break;
        }

        if(p.matchTie()){
            cout<<"Match Tie";
            break;
        }
        
        p.changePlayer();
    }

    return 0;
}