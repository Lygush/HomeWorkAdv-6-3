#include <iostream>
#include "MyVector.h"

int main() {
    My_vector<int> vec;
    try {
        for (int i{}; i < 10; ++i) {
            std::cout << i << ": ";
            vec.push_back(3);
            vec.print_vec();
            std::cout << "\n";
        }
        std::cout << "size: " << vec.size() << "\n";
        for (int i{}; i < 10; ++i) {
            vec[i] = 5;
        }
        vec.print_vec(); 
        std::cout << "\n";
        std::cout << "pop" << "\n";
        for (int i{}; i < 10; ++i) {
            std::cout << i << ": ";
            vec.pop_back();
            vec.print_vec();
            std::cout << "\n";
        }
        vec.pop_back();
        std::cout << "size: " << vec.size() << "\n";
    }
    catch(std::range_error& ex) {
        std::cout << ex.what() << std::endl;
    }
}