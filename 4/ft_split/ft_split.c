#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ft_isspace(char c)
{
	return(c == ' ' || c == '\n' || c == '\t');
}

char *mallocword(char *str)
{
	char *word;
	int i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char **ret = (char **)malloc(100000);

	int reti = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if(*str && !ft_isspace(*str))
		{
			ret[reti] = mallocword(str);
			reti++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	ret[reti] = NULL;
	return (ret);
}
int		main()
{
	char **arr;

	char *phrase = " Burak baby \t akklınını \n yokeder ";
	arr = ft_split(phrase);
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
	printf("%s\n", arr[2]);
	printf("%s\n", arr[3]);
}
