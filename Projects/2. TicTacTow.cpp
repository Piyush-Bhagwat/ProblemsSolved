#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Game{
    private:
        char board[3][3] = {{'n', 'n', 'n'},
                            {'n', 'n', 'n'},
                            {'n', 'n', 'n'}};
        
        char player = 'x';

    public:
        void displayBoard()
        {
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        char getPlayer(){
            return player;
        }

        void changePlayer(){
            if(player == 'x'){
                player = 'o';
            }
            else{
                player = 'x';
            }
        }

        bool slotAvailable(int row, int col){
            if(board[row][col] == 'n'){
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
               if(board[i][0] != 'n'){
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
               if(board[0][i] != 'n'){
                if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
                    return 1;
                }
               }
            }
            return 0;
        }

        bool digSame(){
           
            if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 'n'){
                return 1;
            }

            if(board[2][0] == board[1][1] && board[0][2] == board[1][1] && board[2][0] != 'n'){
                return 1;
            }

            return 0;
        }
};

void instructions(){
    cout<<"First Player is always'x'"<<endl;
    cout<<"Enter postion between 1 to 9"<<endl;
    cout<<"Enter 0 to end game"<<endl;
}

int getInput(Game g){
    cout<<g.getPlayer()<<" your turn: ";
    int move;
    cin>>move;
    return move;
}

bool quit(int n){
    return n==0 ? 1 : 0;
}

bool won(Game g){
    if(g.rowSame()|| g.colSame() || g.digSame()){ // ){
        return 1;
    }
    return 0;
}


main()
{
    Game p;
    p.displayBoard();

    instructions();

    while(true){
        char curInp = getInput(p);

        if(quit(curInp)){
            cout<<"Game Over!";
            break;
        }

        if(!p.write(curInp)){
            continue;
        }
        
        p.displayBoard();

        if(won(p)){
            cout<<p.getPlayer()<<" Won the game!"<<endl;
            break;
        }
        
        p.changePlayer();
    }

    return 0;
}