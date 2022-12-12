#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		int nbr1 = atoi(argv[1]);
		int nbr2 = atoi(argv[2]);

		if(nbr1 > 0 && nbr2 > 0)
		{
			while (nbr1 != nbr2)
			{
				if (nbr1 > nbr2)
					nbr1 -= nbr2;
				else
					nbr2 -= nbr1;
			}
			printf("%d",nbr1);
		}
	}
	printf("\n");
	return (0);
}
