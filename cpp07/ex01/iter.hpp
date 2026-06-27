#pragma once
#include <cstddef>
#include <iostream>


template <class T, class F>
void iter (T *array, const size_t length, F f)
{
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

template <class T>
void print(T &x)
{
    std::cout << x << " ";
}