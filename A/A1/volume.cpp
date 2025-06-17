#include <iostream>

const double pi = 3.14159265358979323846;
double calculateSurfaceArea(double radius,double height){
    
    if(radius<= 0 || height <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
    }
    return 2*(pi)*(radius)*(radius+height);
}

double calculateVolume(double radius,double height){
    if(radius<= 0 || height <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 0;
    }
    return pi*radius*radius*height;
}

int main(){
    double radius, height;
    std::cout << "Enter the radius: ";
    std::cin >> radius;
    std::cout << "Enter the height: ";
    std::cin >> height;
    std::cout << "Surface Area: " << calculateSurfaceArea(radius, height)<<"\n" ;
    std::cout << "Volume: " << calculateVolume(radius, height) ;
} 
/*Time Complexity: (O(1)) for both calculateSurfaceArea and calculateVolume
Space Complexity: (O(1)) for both calculateSurfaceArea and calculateVolume*/