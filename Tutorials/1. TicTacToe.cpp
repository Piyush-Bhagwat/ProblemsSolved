//TicTacToe AI
//Started on 30jun22

#include<bits/stdc++.h>
using namespace std;

class TicTac{
    private:
        char board[3][3];
        char defaultChar = '_', curPlayer = 'X';
        char winner;
        int move;
        
    public:
        TicTac(){ //Constructor: initalize empty board
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    board[i][j] = defaultChar;
                }
            }
            move = 0;
        }

        void display(){ //display board
           for(int i=0; i<3; i++){
            cout<<"| ";
                for(int j=0; j<3; j++){
                    cout<<board[i][j]<<" | ";
                }
                cout<<endl<<endl;
            } 
            cout<<endl;
        }
        
        char getAt(int r, int c){
            return board[r][c];
        }

        int getInput(){ //get input form player
            cout<<curPlayer<<" your turn: ";
            int move; cin>>move;
            return move;
        }

        int getMove(){
            return move;
        }

        char getCurPlayer(){
            return curPlayer;
        }

        char getWinner(){ 
            return winner;
        }

        char getDefChar(){
            return defaultChar;
        }

        void setAt(int r, int c, char k){
            board[r][c]=k;
        }

        bool isSlotAvailable(int n){
            int row = (n-1)/3;
            int col = (n-1)%3;

            return (board[row][col] == defaultChar);
        }

        bool write(int n){ //writes on the board
            if(!(n>=1 && n<=9)){
                cout<<"Enter btn 1-9"<<endl;
                return 0;
            }
            int row = (n-1)/3;
            int col = (n-1)%3;

            if(!isSlotAvailable(n)) {
                cout<<"Space already Occupied!"<<endl;
                return 0;
            }

            board[row][col] = curPlayer;
            move++;
            return 1;
        }

        int rowSame(){

            for(int i=0; i<3; i++){
                if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
                    if(board[i][1] != defaultChar){
                        return i;
                    }
                }
            }
            return -1;
        }

        int colSame(){

            for(int i=0; i<3; i++){
                if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
                    if(board[1][i] != defaultChar){
                        return i;
                    }
                }
            }
            return -1;
        }

        bool digSame(){
            if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
                if(board[1][1] != defaultChar){
                    return true;
                }
            }

            if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
                if(board[1][1] != defaultChar){
                    return true;
                }
            }

            return false;
        }

        bool isWon(){ //returns true if someone won the game
            if(rowSame()!=-1 || colSame()!=-1 || digSame()){
                winner = curPlayer;
                return true;
            }
            
            return false;
        }

        bool isFilled(){ //tells if the board is compleatly filled
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(board[i][j] == '_'){
                        return 0;
                    }
                }
            }
            return 1;
        }

        void switchPlayers(){ //switches between player
            if(curPlayer == 'X'){
                curPlayer = 'O';
            }
            else {
                curPlayer = 'X';
            }
        }

};

class AIPlayer{ 
    private:
        char player='O';
        char opponent = 'X';
        int row, col;
    public:
        void setPlayer(char p){ //Sets AI Players 
            if(p == 'X'){
                player = 'X';
                opponent = 'O';
            }
            else if(p == 'O'){
                player = 'O';
                opponent = 'X';
            }
        }

        void switchPlayer(){
            swap(player, opponent);
        }

        int evaluate(TicTac t){ //Sets score for the board
            int r = t.rowSame();
            int c = t.colSame();

            if(r!=-1){
                if(t.getAt(r, 1)==opponent){
                    return -10;
                }
                else return 10;
            }

            if(c!=-1){
                if(t.getAt(1, c)==opponent){
                    return -10;
                }
                else return 10;
            }

            if(t.digSame()){
                if(t.getAt(1, 1)==opponent){
                    return -10;
                }
                else return 10;
            }

            return 0;
        }
        
        int minimax(TicTac t, int depth, bool isAI){ //Finds the score of the given board
            int score = evaluate(t);

            if(score==10){
                return score - depth;
            }
            if(score == -10){
                return score + depth;
            }

            if(t.isFilled()){
                return 0;
            }

            if(isAI){
                int best = -1000;

                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        if(t.getAt(i, j) == t.getDefChar()){
                            t.setAt(i, j, player);

                            best = max(best, minimax(t, depth+1, !isAI));

                            t.setAt(i, j, t.getDefChar()); 
                            
                        }
                    }
                }

                return best;
            }

            else{
                int best = 1000;

                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        if(t.getAt(i, j) == t.getDefChar()){
                            t.setAt(i, j, opponent);

                            int temp =  minimax(t, depth+1, !isAI);

                            best = min(best, temp);

                            t.setAt(i, j, t.getDefChar());   
                        }
                    }
                }
                return best;
            }
        }
        
        void bestMove(TicTac t){ //go through all available moves and finds the best one
            row = -1; col = -1;
            int best = -1000;

            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(t.getAt(i, j) == t.getDefChar()){
                        t.setAt(i, j, player);

                        int move = minimax(t, 0, false);

                        t.setAt(i, j, t.getDefChar());

                        if(move>best){
                            row = i;
                            col = j;
                            best = move;
                        }
                    }
                }
            }
        }

        int makeMove(TicTac t){ //converts row col to postion and return it
            if(t.getMove() < 3){
                randomG:
                int  r;
                srand(time(0));
                r = rand();

                int move = (r%9) + 1;
                // return move;
                if(t.isSlotAvailable(move)){
                    return move;
                }
                else{
                    goto randomG;
                }

            }
            bestMove(t);
            int r, c;

            for(int i=1; i<=9; i++){
                r = (i-1)/3;
                c = (i-1)%3;

                if(r==row && c==col){
                    return i;
                }
            }
        }
};

void instructions(){
    cout<<"Welcome to TicTacToe"<<endl;
    cout<<"X will play first"<<endl;
}

void pvsp(TicTac g){
    while(true){
        int curMove = g.getInput();

        if(!g.write(curMove)){
            continue;
        }

        g.display();

        if(g.isWon()){
            cout<<g.getWinner()<<" won the Match"<<endl;
            break;
        }

        if(g.isFilled()){
            cout<<"Match Tie!";
            break;
        }

        g.switchPlayers();
    }
}

void vsAI(TicTac g){
    AIPlayer ai;

    char humanPlayer;

    selection:
    cout<<"What do you wanna play(X or O): ";
    cin>>humanPlayer;

    if(humanPlayer == 'x' or humanPlayer== 'X'){
        ai.setPlayer('O');
        humanPlayer = 'X';
    }

    else if(humanPlayer == 'o' or humanPlayer== 'O'){
        ai.setPlayer('X');
        humanPlayer = 'O';
    }

    else{
        cout<<"Choose betn X or O"<<endl;
        goto selection;
    }

    while(true){
        int curMove;
        if(g.getCurPlayer() == humanPlayer){
            curMove = g.getInput();
        }
        else{
            curMove = ai.makeMove(g);
            cout<<"AI choose "<<curMove<<endl;
        }

        if(!g.write(curMove)){
            continue;
        }

        g.display();

        if(g.isWon()){
            cout<<g.getWinner()<<" won the Match"<<endl;
            break;
        }

        if(g.isFilled()){
            cout<<"Match Tie!";
            break;
        }

        g.switchPlayers();
    }
}

void AIvsAI(TicTac g){
    AIPlayer ai;

    while(true){
        int curMove;

        curMove = ai.makeMove(g);
        cout<<g.getCurPlayer()<<" choose "<<curMove<<endl;
        
        if(!g.write(curMove)){
            continue;
        }

        g.display();

        if(g.isWon()){
            cout<<g.getWinner()<<" won the Match"<<endl;
            break;
        }

        if(g.isFilled()){
            cout<<"Match Tie!";
            break;
        }

        g.switchPlayers();
        ai.switchPlayer();
    }
}

main(){
    TicTac g;
    int mode;

    ModeSelect:
    cout<<"enter 1(PvP) 2(PvAI) 3(AIvsAI): ";
    cin>>mode;

    if(mode == 1){
        pvsp(g);
    }
    else if(mode == 2){
        vsAI(g);
    }
    else if(mode == 3){
        AIvsAI(g);
    }
    else{
        cout<<"1 or 2 or 3🙂"<<endl;
        goto ModeSelect;
    }
}