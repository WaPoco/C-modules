#include "Harl.hpp"

Harls::Harls()
{
}

void Harls::complain(std::string level)
{
    std::string l[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harls::*f[4])() = {&Harls::debug, &Harls::info, &Harls::warning, &Harls::error};

    for(int j = 0; j < 4; j++)
    {
        if (l[j] == level)
        {
            (this->*f[j])();
            return ;
        }
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

void     Harls::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
