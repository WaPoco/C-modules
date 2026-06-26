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
    
    // ========== DEEP COPY TEST ==========
    std::cout << "\n========== Testing Deep Copy Constructor ==========\n" << std::endl;
    
    // Test 1: Dog Copy Constructor
    std::cout << "--- Dog Copy Constructor Test ---" << std::endl;
    Dog originalDog;
    
    std::cout << "\nSetting ideas in originalDog:" << std::endl;
    originalDog.getBrain()->setIdea(0, "Chase cats");
    originalDog.getBrain()->setIdea(1, "Fetch ball");
    originalDog.getBrain()->setIdea(2, "Guard house");
    originalDog.getBrain()->setIdea(50, "Middle idea");
    originalDog.getBrain()->setIdea(99, "Last idea");
    
    std::cout << "originalDog Brain address: " << originalDog.getBrain() << std::endl;
    
    std::cout << "\nCreating copiedDog using copy constructor..." << std::endl;
    Dog copiedDog = originalDog;
    
    std::cout << "copiedDog Brain address: " << copiedDog.getBrain() << std::endl;
    
    // Verify addresses are different (deep copy)
    if (originalDog.getBrain() != copiedDog.getBrain())
        std::cout << "✓ Brain addresses are DIFFERENT (deep copy confirmed)" << std::endl;
    else
        std::cout << "✗ Brain addresses are SAME (shallow copy - BAD!)" << std::endl;
    
    std::cout << "\nVerifying copied ideas:" << std::endl;
    std::cout << "originalDog idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "copiedDog   idea[0]: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "originalDog idea[1]: " << originalDog.getBrain()->getIdea(1) << std::endl;
    std::cout << "copiedDog   idea[1]: " << copiedDog.getBrain()->getIdea(1) << std::endl;
    std::cout << "originalDog idea[99]: " << originalDog.getBrain()->getIdea(99) << std::endl;
    std::cout << "copiedDog   idea[99]: " << copiedDog.getBrain()->getIdea(99) << std::endl;
    
    std::cout << "\nModifying originalDog ideas AFTER copy:" << std::endl;
    originalDog.getBrain()->setIdea(0, "MODIFIED: Take a nap");
    originalDog.getBrain()->setIdea(1, "MODIFIED: Eat food");
    originalDog.getBrain()->setIdea(99, "MODIFIED: Last thought");
    
    std::cout << "\nAfter modification:" << std::endl;
    std::cout << "originalDog idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "copiedDog   idea[0]: " << copiedDog.getBrain()->getIdea(0) << " (should be unchanged)" << std::endl;
    std::cout << "originalDog idea[1]: " << originalDog.getBrain()->getIdea(1) << std::endl;
    std::cout << "copiedDog   idea[1]: " << copiedDog.getBrain()->getIdea(1) << " (should be unchanged)" << std::endl;
    std::cout << "originalDog idea[99]: " << originalDog.getBrain()->getIdea(99) << std::endl;
    std::cout << "copiedDog   idea[99]: " << copiedDog.getBrain()->getIdea(99) << " (should be unchanged)" << std::endl;
    
    // Test 2: Cat Copy Constructor
    std::cout << "\n--- Cat Copy Constructor Test ---" << std::endl;
    Cat originalCat;
    
    std::cout << "\nSetting ideas in originalCat:" << std::endl;
    originalCat.getBrain()->setIdea(0, "Climb tree");
    originalCat.getBrain()->setIdea(1, "Hunt mice");
    originalCat.getBrain()->setIdea(2, "Sleep on couch");
    
    std::cout << "originalCat Brain address: " << originalCat.getBrain() << std::endl;
    
    std::cout << "\nCreating copiedCat using copy constructor..." << std::endl;
    Cat copiedCat = originalCat;
    
    std::cout << "copiedCat Brain address: " << copiedCat.getBrain() << std::endl;
    
    if (originalCat.getBrain() != copiedCat.getBrain())
        std::cout << "✓ Brain addresses are DIFFERENT (deep copy confirmed)" << std::endl;
    else
        std::cout << "✗ Brain addresses are SAME (shallow copy - BAD!)" << std::endl;
    
    std::cout << "\nVerifying copied ideas:" << std::endl;
    std::cout << "originalCat idea[0]: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "copiedCat   idea[0]: " << copiedCat.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\nModifying copiedCat ideas:" << std::endl;
    copiedCat.getBrain()->setIdea(0, "MODIFIED: Meow loudly");
    copiedCat.getBrain()->setIdea(1, "MODIFIED: Knock things off table");
    
    std::cout << "\nAfter modification:" << std::endl;
    std::cout << "originalCat idea[0]: " << originalCat.getBrain()->getIdea(0) << " (should be unchanged)" << std::endl;
    std::cout << "copiedCat   idea[0]: " << copiedCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "originalCat idea[1]: " << originalCat.getBrain()->getIdea(1) << " (should be unchanged)" << std::endl;
    std::cout << "copiedCat   idea[1]: " << copiedCat.getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\n========== Deep Copy Test Complete ==========\n" << std::endl;
    
    return 0;
}
