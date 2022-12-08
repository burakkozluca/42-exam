#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		int i = 0;
		int ascii[256] = {0};

		while (argv[2][i])
		{
			if(ascii[(int)argv[2][i]] == 0)
				ascii[(int)argv[2][i++]] = 1;
			else
				i++;
		}
		i = 0;
		while (argv[1][i])
		{
			if(ascii[(int)argv[1][i]] == 1)
			{
				ascii[(int)argv[1][i]] = 2;
				write(1 ,&argv[1][i++], 1);
			}
			else
				i++;
		}
	}
	write(1,"\n",1);
}
