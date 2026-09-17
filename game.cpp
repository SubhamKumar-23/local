#include <iostream>
#include <ctime>

char getUserchoice();
void showUserChoice(char choice);
char computedChoice();
void Winner(char player,char computer);

int main(){
    std::cout << "\n************************\n";
    std::cout << "\nROCK-PAPER-SCISSOR GAME\n";
    char player = getUserchoice();
    std:: cout <<"You chose";
    showUserChoice(player);
    std:: cout << "Computer chose";
    char computer = computedChoice();
    showUserChoice(computer);
    Winner(player,computer);
}

char getUserchoice(){
    char choice;
    do{
        std::cout << "\n************************\n";
        std::cout << "\nEnter 'r' for ROCK\n";
        std::cout << "Enter 'p' for PAPER\n";
        std::cout << "Enter 's' for SCISSOR\n";
        std::cout << "Enter your choice\n";
        std::cin >> choice;
        if(choice!='r' && choice!='p' && choice!='s')
            std::cout << "\nInvalid Input\n";
    }while(choice!='r' && choice!='p' && choice!='s');

    return choice;
}

void showUserChoice(char choice){
    switch(choice){
        case 'r':
            std::cout << " ROCK\n";
            break;
        case 'p':
            std::cout << " PAPER\n";
            break;
        case 's':
            std::cout << " Scissor\n";
            break;
    }
}

char computedChoice(){
    srand(time(NULL));
    char cchoice;
    int guess = rand() %3 +1;
    switch(guess){
        case 1:
            cchoice = 'r';
            break;
        case 2:
            cchoice = 'p';
            break;
        case 3:
            cchoice = 's';
            break;
    }
    return cchoice;
}

void Winner(char player , char computer){
    if(player == 'r' && computer == 's')
        std::cout << "You win!";
    else if(player == 'p' && computer == 's')
        std::cout << "You Lose!";
    else if(player == 's' && computer == 'r')
        std::cout << "You Lose!";
    else if(player == 'r' && computer == 'p')
        std::cout << "You Lose!";
    else if(player == 's' && computer == 'p')
        std::cout << "You win!";
    else if(player == 'p' && computer == 'r')
        std::cout << "You win!";
    else 
        std:: cout << "Its a draw!";
    std::cout << std::endl;

}
