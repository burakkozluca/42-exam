#include <unistd.h>

int repeat_alpha(char c)
{
    int repeat;

    if(c >= 'A' && c <= 'Z')
        repeat = c - 'A' + 1;
    else if(c >= 'a' && c <= 'z')
        repeat = c - 'a' + 1;
    else
        repeat = 1;
    return(repeat);
}

int main(int argc,char **argv)
{
    if(argc == 2)
    {
        int repeat = 0;
        int i = 0;
        while(argv[1][i])
        {
            repeat = repeat_alpha(argv[1][i]);
            while (repeat != 0)
            {
                write(1, &argv[1][i], 1);
                repeat--;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}
