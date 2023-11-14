#include <iostream>

int main(int argc, char **argv)
{
    int  i;
    int y;

    y = 0;
    i = 1;
    if(argc  == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (argv[i])
        {
            while (argv[i][y])
            {
                std::cout << (char) toupper(argv[i][y]);
                y++;
            }
        y = 0;
        i++;
        if (argv[i])
            std::cout << ' ';
        }
    }
        
}
