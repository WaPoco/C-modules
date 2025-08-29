#include <iostream>
#include <string.h>
#include <string>

class   Zombie
{
    public:
        void    announce( void );
        Zombie  *newZombie( std::string name );
        void    randomChump( std::string name );
        Zombie();
        void    setName( std::string name ) {_name = name;};
        Zombie  *zombieHorde(int N, std::string name);
        Zombie(std::string);
        ~Zombie();
    private:
        std::string _name;
};

Zombie  *zombieHorde(int N, std::string name);
