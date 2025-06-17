#include <iostream>

bool checkLeapYear(int year){
    return (year%4==0 && year%100!=0) || year%400==0;
}
void calc(int days){
    int year=days/365;
    int month=(days%365)/30;
    int day=(days%365)%30;
    if(year!=1) std::cout<<year<<" years, "<<month<<" months, "<<day<<" days";
    if(year==1) std::cout<<year<<" year, "<<month<<" months, "<<day<<" days";

}
int main(){
    int days;
    std::cout<<"Enter the number of days: ";
    std::cin>>days;
    calc(days);
} 
/*Time Complexity: (O(1)) for both checkLeapYear and calc
Space Complexity: (O(1)) for both checkLeapYear and calc*/