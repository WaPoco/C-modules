#include "iter.hpp"
#include <iostream>

int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    iter<int>(array, sizeof(array) / sizeof(int), print<int>);
    for (size_t i = 0; i < sizeof(array) / sizeof(int); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}