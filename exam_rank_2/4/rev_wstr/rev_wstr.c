#include <unistd.h>

int is_space(char c)
{
	return(c == ' ' || c == '\t');
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return(i);
}

int main(int argc,char **argv)
{
	if(argc == 2)
	{
		int string_len = ft_strlen(argv[1]) - 1;
		int curr;
		int end;

		while (string_len >= 0)
		{
			end = string_len;
			curr = string_len;

			while (string_len >= 0 && !is_space(argv[1][string_len]))
				string_len--;
			string_len++;

			curr = string_len;
			while (curr <= end)
			{
				write(1,&argv[1][curr],1);
				curr++;
			}
			if (string_len > 0)
				write(1," ",1);
			string_len--;
			string_len--;
		}
	}
	write(1,"\n",1);
}
