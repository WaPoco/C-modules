#include "Zombie.hpp"

int main()
{
    Zombie helper;
    Zombie *first;
    Zombie *sec;
    sec = helper.newZombie("B");
    helper.randomChump("FOO");
    first = zombieHorde(3, "Zombie");
    delete[] first;
    delete sec;
    return (0);
}