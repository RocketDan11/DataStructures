#include <iostream>
#include <vector>
#include <chrono>

#define N 1000


std::vector<double> createTestVector(double n) {
    std::vector<double> vec;
    // Add test values to the vector
    for (int i = 1; i <= n; i++) {
        vec.push_back(i * 10);
    }
    return vec;
}


std::vector<double> elementWiseMultiply(const std::vector<double>& vec1, const std::vector<double>& vec2) {
    std::vector<double> result;
    size_t size = std::min(vec1.size(), vec2.size());

    for (size_t i = 0; i < size; i++) {
        result.push_back(vec1[i] * vec2[i]);
    }

    return result;
}



int main(){

std::vector<double> vec1 = createTestVector(N) ;
std::vector<double> vec2 = createTestVector(N) ;


auto startTime = std::chrono::high_resolution_clock::now();
std::vector<double> result = elementWiseMultiply(vec1, vec2);
auto endTime = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
std::cout << "Execution time: " << duration.count() << " nanoseconds" << std::endl;




/*for (const auto& value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
*/
    return 0;
}