#include "Harl.hpp"

Harls::Harls()
{

}

void Harls::complain(std::string level)
{
    int k = -1;
    std::string l[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harls::*f[4])() = {&Harls::debug, &Harls::error, &Harls::info, &Harls::warning};

    for(int j = 0; j < 4; j++)
    {
        if (l[j] == level)
            k = j;
    }
    switch (k)
    {
        case 0:
            (Harls::*f[0])();
            break;
        case 1:
            (this->*f[1])();
            break;
        case 2:
            (this->*f[2])();
            break;
        case 3:
            (this->*f[3])();
            break;
        default:
            break;
    }
}

void    Harls::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void     Harls::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt putenough bacon in my burger! If you did, I wouldnt be asking for more!" <<  std::endl;
}

void     Harls::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. Ive been coming foryears, whereas you started working here just last month." << std::endl;
}

void     Harls::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
