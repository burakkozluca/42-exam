#include <unistd.h>

int main(int argc, char **argv)
{
	int ascii[256] = {0};

	if(argc == 3)
	{
		int i = 0;

		while (argv[1][i])
		{
			if(ascii[(int)argv[1][i]] == 0)
			{
				ascii[(int)argv[1][i]] = 1;
				write(1,&argv[1][i++],1);
			}
			else
				i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if(ascii[(int)argv[2][i]] == 0)
			{
				ascii[(int)argv[2][i]] = 1;
				write(1, &argv[2][i++], 1);
			}
			else
				i++;
		}
	}
	write(1, "\n", 1);
}
