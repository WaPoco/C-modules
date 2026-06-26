#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap a("Alice");
    ClapTrap b("Bob");
    ScavTrap c("Test");
    FragTrap e("S");

    c.guardGate();
    c.attack("S");
    e.attack("Bob");
    ScavTrap d (c);
    a.attack("Bob");
    b.takeDamage(5);
    b.beRepaired(3);
    e.attack("Bob");
    return (0);
}