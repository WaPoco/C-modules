#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    Weapon club = Weapon("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    return (0);
}