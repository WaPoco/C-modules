#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception& e)
    {
        try
        {
            dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}

Base*   generate(void)
{
    int random = std::rand() % 3;
    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return nullptr;
}   

int main()
{
    Base *base = new Base();
    Base *a = new A();
    Base *b = new B();
    Base *c = new C();

    identify(base);
    identify(a);
    identify(b);
    identify(c);

    delete base;
    delete a;
    delete b;
    delete c;

    return 0;
}