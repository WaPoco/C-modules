#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog& other);
        ~Dog();
        void makesound();
        Brain *getBrain();
    private:
        Brain* brain;
};
#endif