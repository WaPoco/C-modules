#ifndef AANIMAL_HPP 
#define AANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal();
        AAnimal(const std::string type);
        virtual ~AAnimal();
        std::string getType() const;
        virtual void makesound() const = 0;
};
#endif