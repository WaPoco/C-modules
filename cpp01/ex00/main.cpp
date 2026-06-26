#include "Zombie.hpp"

int main()
{
    Zombie A ("Peter");
    A.announce();
    Zombie *B = newZombie("new Peter" );
    B->announce();
    randomChump("Random FOO");
    delete B;
    return (0);
}