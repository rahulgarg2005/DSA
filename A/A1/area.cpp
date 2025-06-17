#include <iostream>
using namespace std;
double calculateArea(double length, double width) { 
    if(length <= 0 || width <= 0) {
         cout << "Please enter a positive integer." <<  endl;
        return 0;
    }
    return length * width;
}
double calculatePerimeter(double length, double width) {
    if(length <= 0 || width <= 0) {
         cout << "Please enter a positive integer." <<  endl;
        return 0;
    }
    return 2 * (length + width);
}

int main(){
    double length, width;
     cout << "Enter the length: ";
     cin >> length;
     cout << "Enter the width: ";
     cin >> width; 
     cout << "Area: " << calculateArea(length, width)<<"\n" ;
     cout << "Perimeter: " << calculatePerimeter(length, width) ;
} 
/*Time Complexity: (O(1)) for both calculateArea and calculatePerimeter
Space Complexity: (O(1)) for both calculateArea and calculatePerimeter*/