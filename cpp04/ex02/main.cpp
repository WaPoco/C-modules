#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Animal *animal[100];
    for (int i = 0; i<100;i++)
    {
        if (i < 50)
            animal[i] = new Dog();
            
        else
            animal[i] = new Cat();
        animal[i]->makesound();
        delete animal[i];         
    }
    delete j;
    delete i;
    Dog dog1;
    Dog dog2 = dog1;
    dog1.getBrain()->setIdea(0, "Get some food!");
    dog2.getBrain()->setIdea(0, "Fuck me");
    std::cout << "____________________" << std::endl;
    std::cout << "dog 1 " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog 2 " << dog2.getBrain()->getIdea(0) << std::endl;
    return 0;
}
