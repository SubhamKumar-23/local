#include <iostream>
int dsum(long card);
int osum(long card);
bool valid(int os , int ds);
int main(){
    long card;
    std::cout << "Enter the card number :" << std::endl;
    std::cin >> card;
    std::cout << (valid(osum(card),dsum(card))? "Valid\n" : "Invalid\n");
}
int dsum(long card){
    card/=10;
    int sum=0;
    for(;card>0;card/=100){
        int d=card%10;
        d >=5 ? sum += (d*2)/10 + (d*2)%10 : sum += d*2 ;
    }
    return sum;
}
int osum(long card){
    if(card>9)
        return card%10 + osum(card/100);
    return 0;
}
bool valid(int os , int ds){
    if( (os+ds) %10 == 0)
        return 1;
    return 0;
}