

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

void	checks(void)
{
	system("leaks a.out");
}

int main()
{
	atexit(checks);
	//ft_printf("", "hello", "it's", "me", "jacob");	
	/*
	printf("|%10cddd\n", 'a');
	ft_printf("|%10cddd\n", 'a');
	printf("|%-10caaa\n", 'a');
	ft_printf("|%-10caaa\n", 'a');
	printf("|%10cccc\n", 'a');
	ft_printf("|%10cccc\n", 'a');
	*/

	/*
	printf("printf: |%s|\n", "a");
	ft_printf("ft: |%s|\n", "a");
	printf("printf: |%s|\n", "abcde");
	ft_printf("ft: |%s|\n", "abcde");
	printf("printf: |%5.2s|\n", "abcde");
	ft_printf("ft: |%5.2s|\n", "abcde");
	printf("ft: |%-5.2s|\n", "abcde");
	ft_printf("ft: |%-5.2s|\n", "abcde");
	printf("%s\n", NULL);
	ft_printf("%s\n", NULL);
	printf("%p\n", "hello");
	ft_printf("%p\n", "hello");
	printf("%p\n", NULL);
	ft_printf("%p\n", NULL);
	printf("%0 10.3d\n", -1);
	ft_printf("%0 10.3d\n", -1);
	printf("%10.15d\n", -1);
	ft_printf("%10.15d\n", -1);

	printf("%0+.13d\n", 1);
	ft_printf("%0+.13d\n", 1);
	printf("%-23.14d]\n", (int)-2147483648);
	ft_printf("%-23.14d]\n", (int)-2147483648);

	printf("%-10.0d]\n", 0);
	ft_printf("%-10.0d]\n", 0);
	printf("%10d]\n", 0);
	ft_printf("%10d]\n", 0);
	printf("%+13.10d]\n", 0);
	ft_printf("%+13.10d]\n", 0);
	printf("%+3d]\n", 0);
	ft_printf("%+3d]\n", 0);
	*/
/*
	printf("%-10x\n", 256);
	ft_printf("%-10x\n", 256);
	printf("%x\n", 0);
	ft_printf("%x\n", 0);
	printf("%10.5x\n", 1);
	ft_printf("%10.5x\n", 1);
	printf("%-10.5x\n", 1);
	ft_printf("%-10.5x\n", 1);
	*/
	/*
	printf("%x\n", LONG_MAX);
	ft_printf("%x\n", LONG_MAX);
	printf("%x\n", LONG_MIN);
	ft_printf("%x\n", LONG_MIN);
	printf("%x\n", UINT_MAX);
	ft_printf("%x\n", UINT_MAX);
	*/
	/*
	printf("|%-10.p|\n", (void *)0);
	ft_printf("|%-10.p|\n", (void *)0);

	printf("|%-7p|\n", (void *)10124);
	ft_printf("|%-7p|\n", (void *)10124);
	pke
	rintf("|%13%%p|\n", (void *)10124);
	*/
	/*
	printf("%.2d\n", -1);
	ft_printf("%.2d\n", -1);
	printf("%10d\n", 1);
	ft_printf("%10d\n", 1);
	*/
//	printf("42%34d42\n", NULL);
//	ft_printf("!%46.42s!\n", NULL);
	/*
	printf("%04d\n", 9);
	ft_printf("%04d\n", 9);
	printf("%.4d\n", 9);
	ft_printf("%.4d\n", 9);
	printf("\\!/%42.2d\\!/\n", 0);
	ft_printf("\\!/%42.2d\\!/\n", 0);
	printf(">------------<%46d>------------<\n", -1064467384);
	ft_printf(">------------<%46d>------------<\n", -1064467384);
*/	
//	ft_printf("|%13%%p|\n", (void *)10124);
	//ft_printf("%.0d", 0);
	//ft_printf("%.0d\n", 5);
	//ft_printf("%p\n%p\n", LONG_MIN, LONG_MAX);
	//ft_printf("%5%");
//	ft_printf("%01.d\n", 0);
//	ft_printf("%.d\n", 0);

//	printf("%5%");	
//	ft_printf("%5%");
	char *s = malloc(UINT_MAX);
	for(size_t i = 0; i < UINT_MAX; i++)
	{
		s[i] = 'a';
	}
	s[UINT_MAX - 1] = 0;
	ft_printf("%s\n", s);
	ft_printf(">------------<%62.28d>------------<", 0);
}
