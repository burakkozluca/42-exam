#include <stdlib.h>

char    *ft_strdup(char *src)
{
    char *result;
    int i = 0;

    result = malloc(10000);
    while (src[i] != '\0')
    {
        result[i] = src[i];
        i++;
    }
    result[i] = '\0';
    return(result);
}