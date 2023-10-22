/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:47:42 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/03 12:46:29 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*long_to_hexchar(unsigned long n, int size, char *arr)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		arr[i] = '0';
		i++;
	}
	i = size - 1;
	while (n > 0)
	{
		arr[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	return (arr);
}

void	non_printable_to_dot(char *str, unsigned int size, void *addr_init)
{
	char	arr[50];
	int		i;

	i = 0;
	while (i < 16 && str < (char *)addr_init + size)
	{
		if (*str < 32 || *str == 127)
			arr[i] = '.';
		else
			arr[i] = *str;
		str++;
		i++;
	}
	write(1, arr, i);
}

void	print_str_to_hex(void *addr, void *start, void *addr_init,
		unsigned int size)
{
	char	arr[50];

	if ((addr - start) % 2 == 0)
		write(1, " ", 1);
	if (addr - addr_init < size)
		write(1, long_to_hexchar((unsigned long)*((char *)addr), 2, arr), 2);
	else if ((addr - start) < 16)
		write(1, "  ", 2);
	addr++;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	addr_hex;
	void			*start;
	char			arr[50];
	void			*addr_init;

	start = addr;
	addr_init = addr;
	while (addr - addr_init < size)
	{
		addr_hex = (unsigned long)addr;
		write(1, long_to_hexchar(addr_hex, 16, arr), 16);
		write(1, ":", 1);
		while (addr < start + 16)
		{
			print_str_to_hex(addr, start, addr_init, size);
			addr++;
		}
		write(1, " ", 1);
		non_printable_to_dot(start, size, addr_init);
		write(1, "\n", 1);
		start = addr;
	}
	return (addr);
}

int main()
{
	char *c = "shf;asdhf;ahsdkhasl;fgkhad;lghadlfkghklsahdg;akflhg";
	ft_print_memory(c, 100);
}
