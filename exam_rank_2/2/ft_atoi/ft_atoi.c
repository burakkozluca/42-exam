int	ft_atoi(char *s)
{
	int	sign = 1;
	int	r = 0;

	while (*s == ' ' || (*s <= 13 && *s >= 9))
		s++;
	if (*s == '-')
		sign = -1;
	if(*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + *s - '0';
		s++;
	}
	return (sign * (int)r);
}
