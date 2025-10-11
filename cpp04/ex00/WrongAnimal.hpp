#ifndef WrongAnimal_HPP 
#define WrongAnimal_HPP
# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(const std::string type);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal operator=(const WrongAnimal& other);
        ~WrongAnimal();
        std::string getType();
        void makesound();
};
#endif