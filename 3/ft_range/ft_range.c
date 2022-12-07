#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int* str;
    int i = 0;

    str = malloc(10000);
    if(start > end)
    {
        int len = start - end + 1;
        while (len)
        {
            str[len] = end;
            end++;
            len--;
        }
        
    }
    else if(end > start)
    {
        while (start != end)
        {
            str[i] = start;
            start++;
            i++;
        }
        if(start == end)
            str[i] = start;
    }
    return(str);
}