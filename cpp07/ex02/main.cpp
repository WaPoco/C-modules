#include <iostream>

template <class T>
class Array {
    private:
        T *_data;
        unsigned int _N;
    public:
        Array():_data(NULL), _N(0) {}
        Array(unsigned int N): _data(new T[N]), _N(N) {}
        Array(const Array& other) : _data(NULL), _N(0) {
            *this = other;
        }
        int size() const {
            return _N;
        }
        ~Array() {
            if (_data)
                delete[] _data;
        }
        Array& operator=(const Array& other) {
            if (this != &other) {
                if (_data)
                    delete[] _data;
                _N = other._N;
                _data = new T[_N];
                for (unsigned int i = 0; i < _N; i++)
                    _data[i] = other._data[i];
            }
            return *this;
        }
        T& operator[](int index) const {
            if (index < 0 || index >= static_cast<int>(_N)) {
                throw std::out_of_range("Index out of range");
            }
            return _data[index];
        }
};

int main()
{
    Array<int> a(2);
    a[0] = 1;
    a[1] = 2;
    std::cout << "a[0]=" << a[0] << "a[1]=" << a[1] << "a[2]= " << a[0];
    return (1);
}