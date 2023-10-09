//
//  main.cpp
//  connect4- Autumn Tiede

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Player {
private:
    string _name;
    string _piece;
public:
    Player(string name, string piece){ // name and piece are arguments
        _name = name;        // constructor; initializes name / piece, sets it's value
        _piece = piece;
    };
    string getName(){
        return _name;      // getters: "get" the name / piece from private class (also allocation; putting variable in section of memory to store value
    }                      // no setters because piece value is already placed, and name will be chosen
    string getPiece(){
        return _piece;
    }
    
    void Turn(){            // empty because overridden...
    };
};                          // overriding: subclass provides different implementation for function already existing in parent class

class RedPlayer : public Player{    // inherited class
public:                             // override starts here, overriding messages for red player
    using Player::Player;
    void Turn(){                   // accessing previous function from player class
        cout <<"Red player " << getName() << ", it's your turn\n";
    };
    ~RedPlayer(){
        cout<< "Thanks for representing red team, " << getName() << "\n\n"; // destructor- shows message at end when object is destructed
    }
};

class YellowPlayer : public Player{  // inherited class
public:
    using Player::Player;            // override #2 for yellow player
    void Turn(){
        cout <<"Yellow player " << getName() << ", it's your turn\n";
    };
    ~YellowPlayer(){
        cout<< "Yellow team will always remember you, " << getName() <<"\n"; // destructor- shows message at end when object is destructed
    }
};

class Board {
public:
    string board[6][7];
    bool FullColumn = false;
    int FilledColumns;
    Board(){            // constructor to automatically fill board
        FillBoard();
    };
    ~Board(){           // destructor- called when object is destroyed (at the end)
        cout << "Do you want to play again? Press any key or type 'no': ";
    }
        
    void FillBoard(){   // filling board
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 7; j++){
                board[i][j] = "⚪️";
            }
        }
    };
    
    bool PlacePiece(string piece, int column){
        bool worked = false;
        for(int i = 5; i >= 0; i--){             // goes thru columns from bottom up
            if (board[i][column - 1] == "⚪️"){ // if spot empty, place piece
                board[i][column - 1] = piece;
                worked = true;
                break;
            }
            else if(i == 0){                  // if column full, output message
                cout << "\n************************";
                cout << "\n**This column is full**\n";
                cout << "*************************\n";
            }
        }
        return worked; // return bool value if piece was successfully placed
    };
    
    void PrintBoard(){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 7; j++){
                cout << board[i][j] + " ";
            }
            cout << "\n";
        }
        cout << "1  2   3  4  5  6  7\n\n"; // naming columns 1-7
    };
    
    bool CheckWinRow(string piece){  // check if there is four horizontally
        int count = 0;
        for (int row = 0; row < 6; row++){
            for(int column = 0; column < 7; column++){ // loop thru board array
                if (board[row][column] == piece){ // find piece, keep count of how many in a row
                    count += 1;
                    
                    if (count == 4){ // if 4, there's a win
                        return true;
                    }
                }
                else{
                    count = 0;      // otherwise, count goes back to 0
                }
            }
        }
        return false;
    };
    bool CheckWinColumn (string piece){ // check if 4 vertically
        int count = 0;
        for (int column = 0; column < 7; column ++){ // loop through columns
            for(int row = 0; row < 6; row++){
                if (board[row][column] == piece){
                    count += 1;     // count piece
                    
                    if (count == 4){
                        return true;
                    }
                }
                else{
                    count = 0;
                }
            }
        }
        return false;
    }
    
    bool CheckWinDiagonal1(string piece){ // left to right
        int count = 0;
        for(int row = 0; row < 6; row++){
            for(int column =0; column <7; column++){
                if (board[row][column] == piece){
                    count++;
                    row++; // moves diagonally downward
                    if(count == 4){
                        return true;
                    }
                }
                else{count = 0;}
            }
        }return false;
    }
    
    bool CheckWinDiagonal2(string piece){ // right to left
        int count = 0;
        for(int row = 0; row <6; row++){
            for(int column = 6; column  > -1; column--){
                if (board[row][column] == piece){
                    count++;
                    row++;              // moves diagonally downwards from right to left
                    if (count == 4){
                        return true;
                    }
                }
                else{count = 0;}
            }
        } return false;
    }
    
    bool CheckWin(string piece, string name){ // check for wins with one function...
        if(CheckWinRow(piece) || CheckWinColumn(piece) || CheckWinDiagonal1(piece) || CheckWinDiagonal2(piece)){
            PrintBoard();
            cout << name << " wins!\n"; // prints out who wins
            return true;
        }
        else{
            return false;
        }
    }
};

// for players choosing the column
int Pick(){
    int choice;
    cout << "Choose a column (1-7): ";
    cin >> choice;
    while(choice < 1 || choice > 7){
        cout << "Choose a column between 1 and 7: ";
        cin >> choice;
    }
    return choice;
    };
    
    
void Game()
{
    bool gameover = false;

    // declaring variables
    bool worked;
    int turns = 1;
    string p, name;
    Board board;
    
    // welcome message
    cout << "\nWelcome to Connect 4!" << endl;
    cout << "---------------------" << endl;

    // enter player names and give their "pieces"
    // player1
    string temp1, temp2;
    cout << "Player 1, enter your name: ";
    cin >> temp1;
    RedPlayer p1(temp1, "🔴");
    
    // player 2
    cout << "\nPlayer 2, enter your name: ";
    cin >> temp2;
    YellowPlayer p2(temp2, "🟡");
    cout << "\n\n";
    
    // loop
    while(gameover != true){
        board.PrintBoard();
        
        // counting turns, keeping track of which players turn it is
        if (turns % 2 == 0){
            p2.Turn();
            p = p2.getPiece();
            name = p2.getName();
        }
        else{
            p1.Turn();
            p = p1.getPiece();
            name = p1.getName();
        }
        // if chosen column isn't full, place piece
        worked = board.PlacePiece(p, Pick());
        if (worked == true){
            turns += 1;
            cout << "\n";
            gameover = board.CheckWin(p, name); // checking if there's a win, if yes then gameover
        }
        else{ // if column was full, pick a new place
            cout << "Choose again.\n\n";
        }
        if(turns == 43){ // if board is full and no wins, it's a tie
            cout << "It's a tie! Board is full. Game over.";
            gameover = true;
        }
        
    }
}
int main(){
    // runs game in loop, asks to play again during board deconstructor
    bool on =true;
    string answer;
    while (on){
        Game();
        cin >> answer;
        if (answer == "no"){ // if no, then end program
            break;
        }
    
    }
}
