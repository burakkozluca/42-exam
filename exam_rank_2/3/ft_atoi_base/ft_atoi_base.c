int ft_atoi_base(const char *nbr, unsigned int base)
{
	int i = 0;
	int n = 1;
	int res = 0;

	if(nbr[i] == '-')
	{
		n = -1;
		i++;
	}
	while (nbr[i])
	{
		res *= base;
		if(nbr[i] >= '0' && nbr[i] <= '9')
			res += nbr[i] - 48;
		else if(nbr[i] >= 'A' && nbr[i] <= 'Z')
			res += nbr[i] - 55;
		else if(nbr[i] >= 'a' && nbr[i] <= 'z')
			res += nbr[i] - 87;
		i++;
	}
	return (res * n);
}
