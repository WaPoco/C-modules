#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Cannot instantiate abstract class ===" << std::endl;
    // const AAnimal* k = new AAnimal(); // This should NOT compile!
    std::cout << "AAnimal is abstract - cannot be instantiated\n" << std::endl;
    
    std::cout << "=== Test 2: Basic creation and sounds ===" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    std::cout << "Type: " << j->getType() << " - ";
    j->makesound();
    std::cout << "Type: " << i->getType() << " - ";
    i->makesound();
    
    delete j;
    delete i;
    
    std::cout << "\n=== Test 3: Array of animals ===" << std::endl;
    AAnimal *animal[10];
    int t = 0;
    while (t < 10)
    {
        if (t < 5)
            animal[t] = new Dog();
        else
            animal[t] = new Cat();
        animal[t]->makesound();
        t++;
    }
    
    std::cout << "Deleting animals..." << std::endl;
    int k = 0;
    while (k < 10)
    {
        delete animal[k];
        k++;
    }
    
    std::cout << "\n=== Test 4: Deep copy ===" << std::endl;
    Dog original;
    original.getBrain()->setIdea(0, "Original idea");
    Dog copy = original;
    std::cout << "Brain addresses - original: " << original.getBrain() 
              << ", copy: " << copy.getBrain() << std::endl;
    
    if (original.getBrain() != copy.getBrain())
        std::cout << "✓ Deep copy successful" << std::endl;
    else
        std::cout << "✗ Shallow copy detected!" << std::endl;
    
    original.getBrain()->setIdea(0, "Modified");
    std::cout << "Original: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy: " << copy.getBrain()->getIdea(0) << std::endl;
    
    return 0;
}
