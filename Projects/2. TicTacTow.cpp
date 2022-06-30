//X Human
//O AI

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

        char getAt(int r, int c){
            return board[r][c];
        }

        void setAt(int r, int c, char k){
            board[r][c] = k;
        }

        void displayBoard()
        {
            int count=1;
            for(int i=0; i<3; i++){
                cout<<"|";
                for(int j=0; j<3; j++){
                    if(board[i][j] == defaultChar){
                        cout<<count;
                    }
                    else{
                        cout<<board[i][j];
                    }
                    cout<<" | ";
                    count++;
                }
                cout<<endl<<endl;
            }
            cout<<endl;
        }

        char getPlayer(){
            return player;
        }

        char defChar(){
            return defaultChar;
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

        bool isBoardFilled(){

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
        char player='O', opponent='X';
        int boardScore, row, col;

    public:
        void setPlayer(char p){
            if(p == 'X'){
                player = 'X';
                opponent = 'O';
            }
            else if (p == 'O'){
                player = 'O';
                opponent='X';
            }
        }

        int evaluate(Game g){
            //for col
            if(g.digSame()){
                if(g.getAt(1,1) == opponent){
                    return -10;
                }
                else if(g.getAt(1, 1) == player){
                    return 10;
                }
            }

            //for row
            for(int i=0; i<3; i++){
                if(g.getAt(i, 0) == g.getAt(i, 1) && g.getAt(i, 1) == g.getAt(i, 2)){
                    if(g.getAt(i, 1) == opponent) {
                        return -10;
                    }
                    else if(g.getAt(i, 1) == player){
                        return 10;
                    }
                }
            }

            //for col
            for(int i=0; i<3; i++){
                if(g.getAt(0, i)==g.getAt(1, i) && g.getAt(1, i)==g.getAt(2, i)){
                    if(g.getAt(0, i)==opponent){
                        return -10;
                    }
                    else if(g.getAt(0, i)==player){
                        return 10;
                    }
                }
            }
            return 0;
        }
        
        int minimax(Game g, int depth, bool aiTurn){
            int score = evaluate(g);

            if(score == 10){
                return score - depth;
            }
            if(score == -10){
                return score + depth;
            }

            if(g.isBoardFilled()){
                return 0;
            }

            if(aiTurn){
                int best = -10000;
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        if(g.getAt(i, j) == g.defChar()){
                            g.setAt(i, j, player);

                            best = max(best, minimax(g, depth+1, !aiTurn));

                            g.setAt(i, j, g.defChar());
                        }
                    }
                }
                return best;
            }
            else{
                int best = 10000;
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        if(g.getAt(i, j) == g.defChar()){
                            g.setAt(i, j, opponent);

                            best = min(best, minimax(g, depth+1, !aiTurn));

                            g.setAt(i, j, g.defChar());
                        }
                    }
                }
            }

        }

        void bestMove(Game g){
           row = -1, col = -1; 
           int best = -10000;

            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(g.getAt(i, j) == g.defChar()){
                        g.setAt(i, j, player);

                        int moveVal = minimax(g, 0, false);

                        g.setAt(i, j, g.defChar());

                        if(moveVal>best){
                            row = i;
                            col = j;
                            best = moveVal;
                        }
                    }
                }
            }
        }

        int makeMove(Game g){
            bestMove(g);
            int tr, tc;

            for(int i=1; i<=9; i++){
                tr = (i-1)/3;
                tc = (i-1)%3;

                if(row==tr && col==tc){
                    return i;
                }
                
            }
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
            curInp = a.makeMove(p);
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

        if(p.isBoardFilled()){
            cout<<"Match Tie";
            break;
        }
        
        p.changePlayer();
    }

    return 0;
}