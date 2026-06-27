#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Polymorphic section ===\n";
    Animal* meta = new Animal();
    Animal* dog  = new Dog();
    Animal* cat  = new Cat();

    std::cout << dog->getType() << " says: ";
    dog->makesound();
    std::cout << cat->getType() << " says: ";
    cat->makesound();
    std::cout << meta->getType() << " says: ";
    meta->makesound();

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n=== Wrong polymorphism section ===\n";
    WrongAnimal* wmeta = new WrongAnimal();
    WrongAnimal* wcat  = new WrongCat();

    std::cout << wmeta->getType() << " says: ";
    wmeta->makesound();
    std::cout << wcat->getType() << " says: ";
    wcat->makesound(); 
    delete wmeta;
    delete wcat;
    return 0;
}
