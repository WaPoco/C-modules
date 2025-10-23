#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
# include <iostream>

class   Zombie
{
    public:
        void    announce(void) const;
        Zombie(const std::string& name);
        ~Zombie();
    private:
        std::string _name;
};

Zombie  *newZombie(const std::string& name);
void    randomChump(const std::string& name);

#endif