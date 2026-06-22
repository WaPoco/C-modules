#include"Serializer.hpp"
#include <iostream>

int main()
{
    Data *test;
    // write the address of test to the console, then serialize it and deserialize it, and write the result to the console again. The two addresses should be the same.
    std::cout << "Address of test: " << test << std::endl;
    std::cout << "Address of test after serialization and deserialization: " << Serializer::deserialize(Serializer::serialize(test)) << std::endl;
    return (1);
}