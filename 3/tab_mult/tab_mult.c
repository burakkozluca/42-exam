#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if(n > 9)
		ft_putnbr(n/10);
	ft_putchar(n % 10 + '0');
}

int	ft_atoi(char *s)
{
	int res;

	res = 0;
	while(*s >= '0' && *s <= '9')
		res = res * 10 + *s++ - '0';
	return(res);
}

int main(int argc,char **argv)
{
	if(argc == 2)
	{
		int i = 1;
		while(i < 10)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(ft_atoi(argv[1]));
			write(1 ," = ", 3);
			ft_putnbr(i * ft_atoi(argv[1]));
			write(1, "\n", 1);
			i++;
		}
		return(0);
	}
	write(1,"\n", 1);
}
