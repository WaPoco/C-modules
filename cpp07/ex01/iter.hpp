#pragma once
#include <cstddef>

template <class T>
void iter (T *array, const size_t length, void (*f)(T &))
{
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}