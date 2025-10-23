#include "Zombie.hpp"

Zombie  *zombieHorde(int N, const std::string& name)
{
    Zombie  *h = new Zombie[N];
    for (int i = 0; i < N; i++)
        h[i].setName(name);
    return (h);
}