#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
# include <iostream>

class   Zombie
{
    public:
        Zombie();
        void    announce(void) const;
        void    setName(const std::string& name);
        Zombie(const std::string& name);
        ~Zombie();
    private:
        std::string _name;
};

Zombie  *zombieHorde(int N, const std::string& name);
Zombie  *newZombie(const std::string& name);
void    randomChump(const std::string& name);

#endif