#include "iter.hpp"
#include <iostream>

void print(int &x)
{
    int a=x*x;
    int b=2*x+2;
    x=a+b;
}

int main(void)
{
    int array[] = {1, 2, 3, 4, 5,6,7,8,9};
    iter<int>(array, 9, &print);
    for (size_t i = 0; i < 9; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}