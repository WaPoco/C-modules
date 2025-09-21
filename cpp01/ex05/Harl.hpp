#include <string>
#include <iostream>

class Harls
{
    public:
        Harls();
        void    complain(std::string  level);
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
};