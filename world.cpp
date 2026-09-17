#include <ctime>
#include <iostream>

namespace hello{
    int x = 1;
}
namespace hi{
    int x = 3;
} 

using str = std::string;

//standard info pgrm
/*int main(){
    str name;
    int age;
    double lucky;

    int a;
    std::cin >> a ;

    std::cout<<"Enter your name";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Enter your age";
    std::cin >> age;
    std::cout <<"Enter your lucky decimal";
    std::cin >> lucky;

    std::cout<<"\n\nHello " << name <<"! \n" << "You are " << age << " years old \n" << "Your lucky number is " << lucky;
}*/

//Find the hypotenuse of the triangle
/*int main(){
    double l,b,h;
    std::cout << "Enter the length and base";
    std::cin >> l >> b;
     
    h = sqrt(pow(l,2) + pow(b,2));

    std::cout << "The hypotenuse is = " << h ;
}*/

//Simple Calculator
/*int main(){
    double num1,num2;
    char a;
    std::cout<<"*********CALCULATOR********* \n";
    std::cout<<"Enter two numbers ";
    std::cin >> num1 >> num2;
    std::cout<<"Enter the action u want to perform (+,-,/,*) \n";
    std::cin>> a;
    switch(a){
        case '+':
            std::cout << "The sum of " << num1 << " and " << num2 <<" is " << (num1+num2);
        break;
        case '-':
            std::cout << "The difference of " << num1 << " and " << num2 <<" is " << (num1-num2);
        break;
        case '*':
            std::cout << "The product of " << num1 << " and " << num2 <<" is " << (num1*num2);
        break;
        case '/':
            std::cout <<"The quotient when " << num1 << " is divided by " << num2 << " is " << (double)(num1/num2);
        break;
        default:
            std::cout <<"Invlaid input";
    }
    std::cout<<"\n****************************";
}*/


//Number guessing game
/*int main(){
    srand(time(NULL));
    int guess,num,tries=0;
    num = rand()%10;
    do{
        std::cout << "Enter guess number";
        std::cin >> guess;
        tries++;
        if(num==guess){std::cout << "You have taken " << tries << " tries to guess the number \n"; return 0;}
    }while(num!=guess);
}*/

void bubble_sort(int arr[] , int size){
    int i,j,temp;
    for(i=0;i<size;i++)
        for(j=0;j<size-i-1;j++){
            if(arr[j] < arr[j+1]){
                temp = arr[j];
                arr [j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
}

void linear_sort(int arr[], int size){
    int i,j;
    for(i=0;i<size;i++){
        int min = i;
        for(j=i;j<size;j++){
            if(arr[min] > arr[j])
                min = j;
        }
        std::swap(arr[min],arr[i]);
    }
}

int main(){
    int number[5];
    int i=0,size;
    for(;i<=4;i++)
        std::cin >> number[i];
    size = sizeof(number) / sizeof(number[0]);
    linear_sort(number,size);
    for(int num : number)
        std:: cout << num << " " ;
    
}

