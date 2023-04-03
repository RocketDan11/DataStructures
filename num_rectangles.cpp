#include <iostream>
//calculate number of rectangles that can be found in an m x n square
int numSquares(int m, int n){
int rectangles= 0;
int n0 = (((n + 1)*n) / 2);
int m0 = (((m + 1)*m) / 2);
rectangles = m0*n0;
return rectangles;

};

int main(){
    int m;
    int n;
    std::cout << "enter m: " << std::endl;
    std::cin >> m;
    std::cout << "enter n: " << std::endl;
    std::cin >> n;
std::cout << numSquares(m,n) << std::endl;

    return 0;
}