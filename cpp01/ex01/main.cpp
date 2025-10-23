#include "Zombie.hpp"

int main()
{
    Zombie *horde;
    Zombie *nZombie;
    nZombie = newZombie("new Zombie");
    nZombie->announce();
    randomChump("random FOO");
    horde = zombieHorde(3, "Zombiehord dude");
    for (int i = 0; i < 3; i++)
        horde[i].announce();
    delete[] horde;
    delete nZombie;
    return (0);
}