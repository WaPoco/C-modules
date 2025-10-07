#include "ClapTrap.hpp" 

int main(void)
{
    ClapTrap a("Alice");
    ClapTrap b("Bob");

    a.attack("Bob");
    b.takeDamage(5);
    b.beRepaired(3);
    return (0);
}