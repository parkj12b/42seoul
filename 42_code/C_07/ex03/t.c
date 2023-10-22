#include <stdlib.h>
#include <stdio.h>
int ft_strlen(char *str)
{
    int len;
    len = 0;
    while (str[len])
        len++;
    return (len);
}
char   *ft_strcat(char *str1, char *str2)
{
    char   *start;
    start = str1;
    while (*str1)
        str1++;
    while (*str2)
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = 0;
    return (start);
}
int ft_get_total_length(int size, char **strs, char *sep)
{
    int i;
    int total;
    i = 0;
    total = 0;
    while (i < size)
    {
        total += ft_strlen(strs[i]);
        i++;
    }
    total += ft_strlen(sep) * (size - 1);
    return (total);
}
char   *ft_strjoin(int size, char **strs, char *sep)
{
    int    len;
    char   *res;
    int    i;
    if (size == 0)
    {
        res = (char *)malloc(1);
        res[0] = 0;
        return (res);
    }
    i = 0;
    len = ft_get_total_length(size, strs, sep);
    res = (char *)malloc(len + 1);
	printf("%d\n", len);
    if (res == 0)
        return (0);
    while (i < size)
    {
        ft_strcat(res, strs[i]);
        if (i < size -1)
            ft_strcat(res, sep);
        i++;
    }
    res[len] = 0;
    return (res);
}
int main()
{
	char *arr[] = {"abc", "def"};
	char *str = ft_strjoin(2, arr, "--");
	printf("%s\n", str);
}
