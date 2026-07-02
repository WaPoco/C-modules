#pragma once


template <class T, class F>
void iter (T *array, const size_t length, F f)
{
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}
