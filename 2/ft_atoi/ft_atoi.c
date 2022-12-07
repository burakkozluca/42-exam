#include <unistd.h>

int	ft_atoi(char *s)
{
	int	sign;
	int	r;

	while (*s <= ' ' || (*s <= 13 && *s >= 9))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' || *s <= '9')
	{
		r = r * 10 + *s - '0';
		s++;
	}
	return (sign * (int)r);
}
