#include <iostream>

void drawBoard(char *spaces);
void playerMove(char *spaces,char player);
void computerMove(char *spaces,char computer);
int checkWinner(char *spaces,char computer,char player);
int count = 0;
int main(){
    char board[9];
    char player= ' ',computer;
    bool running=true;

    for(int i=0;i<=8;i++)
        board[i] = ' ';
    
    std::cout << "*************TICTAKTOE*************\n";

    while(player!='x' && player!='o'){
        std::cout << "Do u want to play \'o\' or \'x\' \n";
        std::cin >> player;
        std::tolower(player);
    }
    player == 'x' ? computer = 'o': computer = 'x';
    std::cout << "*************BOARD*************\n";
    drawBoard(board);
    while(running){
        playerMove(board,player);
        computerMove(board,computer);
        drawBoard(board);
        if(checkWinner(board,computer,player)==1){ std::cout << "You win!!!"; break;} 
        if(checkWinner(board,computer,player)==0){ std::cout <<"You Lose";break;}
        if(count==8){
            std::cout << "DRAW!!!";
            break;
        }
    }
    
}
void drawBoard(char *spaces){
    std::cout << "     |      |     \n";
    std::cout << "  "<<spaces[0]<<"  |  "<<spaces[1]<<"   |  "<<spaces[2]<<"  \n";
    std::cout << "     |      |     \n";
    std::cout << "----- ----- -----\n";
    std::cout << "     |      |     \n";
    std::cout << "  "<<spaces[3]<<"  |  "<<spaces[4]<<"   |  "<<spaces[5]<<"  \n";
    std::cout << "     |      |     \n";
    std::cout << "----- ----- ------\n";
    std::cout << "     |      |     \n";
    std::cout << "  "<<spaces[6]<<"  |  "<<spaces[7]<<"   |  "<<spaces[8]<<"  \n";
    std::cout << "     |      |     \n";
}
void playerMove(char *spaces,char player){
    int choice;
    do{
        std::cout << "Please Enter choice (1-9)";
        std::cin >> choice;
        choice--;
        if(choice < 0 || choice > 8)
            continue;
        if(spaces[choice] != ' ')
            continue;
        break;
    }while(true);
    spaces[choice] = player;
    count++;
}
void computerMove(char *spaces,char computer){
    srand(time(0));
    int choice;
    do{
        choice = rand()%9;
        if(spaces[choice] != ' ') continue;
        else break;
    }while(true);
    spaces[choice] = computer;
    count++;
}
int checkWinner(char *spaces,char computer,char player){
    //rows
        if(spaces[0]==spaces[1] && spaces[1]==spaces[2] && spaces[0]!=' ')
            {if(spaces[0]==player)return 1;else return 0;}
        if(spaces[3]==spaces[4] && spaces[4]==spaces[5]&& spaces[3]!=' ')
            {if(spaces[3]==player)return 1;else return 0;}
        if(spaces[6]==spaces[7] && spaces[7]==spaces[8]&& spaces[6]!=' ')
            {if(spaces[6]==player)return 1;else return 0;}
        
        //columns
        if(spaces[0]==spaces[3] && spaces[0]==spaces[6]&& spaces[0]!=' ')
            {if(spaces[0]==player)return 1;else return 0;}
        if(spaces[1]==spaces[4] && spaces[1]==spaces[7]&& spaces[1]!=' ')
            {if(spaces[1]==player)return 1;else return 0;}
        if(spaces[2]==spaces[5] && spaces[2]==spaces[8]&& spaces[2]!=' ')
            {if(spaces[2]==player)return 1;else return 0;}
        
        //diagonals
        if(spaces[0]==spaces[4] && spaces[0]==spaces[8]&& spaces[0]!=' ')
            {if(spaces[0]==player)return 1;else return 0;}
        if(spaces[2]==spaces[4] && spaces[2]==spaces[6]&& spaces[2]!=' ')
            {if(spaces[2]==player)return 1;else return 0;}
    
    return 2;
}
