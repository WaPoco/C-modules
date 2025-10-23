#ifndef ANIMAL_HPP 
#define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const std::string type);
        //Animal operator=(const Animal& other);
        virtual ~Animal();
        std::string getType();
        virtual void makesound() = 0;
};
#endif