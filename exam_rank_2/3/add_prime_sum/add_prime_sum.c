#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_atoi(char *s)
{
	int	r;

	r = 0;
	while (*s >= '0' && *s <= '9')
		r = r * 10 + *s++ - '0';
	return (r);
}

int	is_prime(int n)
{
	int i = 2;

	while(i < n)
		if(!(n % i++))
			return(0);
	return(1);
}

void add_prime_sum(int n)
{
	int i = 1;
	int count = 0;

	if(n == 1)
		count = 1;
	while(++i <= n)
		if(is_prime(i))
			count += i;
	ft_putnbr(count);
}

int main(int argc,char **argv)
{
	if(argc == 2 && ft_atoi(argv[1]) > 0)
	{
		add_prime_sum(ft_atoi(argv[1]));
	}
	write(1, "\n", 1);
}
