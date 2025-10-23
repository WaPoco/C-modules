#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap a("Alice");
    ClapTrap b("Bob");
    ScavTrap c("Test");

    c.guardGate();
    ScavTrap d (c);
    a.attack("Bob");
    b.takeDamage(5);
    b.beRepaired(3);
    return (0);
}