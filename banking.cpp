#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main(){
    int choice=0;
    double amount = 12345;
    do{
    std::cout << "*********************************\n";
    std::cout << "     Enter your choice(number)\n";
    std::cout << "*********************************\n";
    std::cout << "1. Show balance\n";
    std::cout << "2. Withdraw\n";
    std::cout << "3. Deposit\n";
    std::cout << "4. Exit\n";
    std::cin >> choice;
    std::cin.clear();
    //std::cin.ignore(1000,'\n');
    fflush(stdin);

    switch (choice){
        case 1:
            showBalance(amount);
        break;
        case 2:
            amount-=withdraw(amount);
            showBalance(amount);
        break;
        case 3:
            amount+=deposit();
            showBalance(amount);
        break;
        case 4:
            std::cout << "Thank you for banking with us!!!\n";
        break;
        default:
            std::cout << "Invalid choice\n";
        }
    }while(choice!=4);
}

void showBalance(double balance){
    std::cout<<"Your Balance amount is: " << std::fixed << std::setprecision(2) << balance << std::endl;
}

double deposit(){
    double amt = 0;
    std::cout << "Enter amt to be deposited \n";
    std::cin >> amt;
    if(amt > 0)
        return amt; 
    else
        std::cout << "Invalid amt";
    return 0;
}

double withdraw(double balance){
    double amt=0;
    std::cout << "Enter amt to be withdrawn\n";
    std::cin >> amt;
    if(amt < 0 && balance-amt >=0)
        return amt;
    else 
        std::cout << "Invalid amt\n";
    return 0;
}

