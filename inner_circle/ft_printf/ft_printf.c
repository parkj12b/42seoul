/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:49:11 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/21 22:53:40 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_print_dto	*dto_init(t_print_dto *dto)
{
	dto->flag = 0;
	dto->format_idx = 0;
	dto->print_idx = 0;
	dto->nums[WIDTH] = -1;
	dto->nums[PRECISION] = -1;
	dto->nums[PRINT_STR_LEN] = 0;
	dto->print_str = (char *)malloc(11);
	if (!dto->print_str)
		return (0);
	dto->size = 10;
	return (dto);
}

void	dto_clear(t_print_dto *dto)
{
	dto->flag ^= dto->flag;
	dto->nums[WIDTH] = -1;
	dto->nums[PRECISION] = -1;
	dto->nums[PRINT_STR_LEN] = 0;
}



void	*append_str(t_print_dto *dto, const char *append_str, ssize_t len)
{
	ssize_t	temp_i;
	char	*temp_str;

	if (dto->print_idx + len > dto->size)
	{
		while (dto->print_idx + len > dto->size)
			dto->size *= 2;
		temp_str = (char *)malloc(dto->size + 1);
		if (!temp_str)
			return (0);
		temp_i = dto->print_idx;
		while (temp_i-- > 0)
			temp_str[temp_i] = dto->print_str[temp_i];
		free(dto->print_str);
		dto->print_str = temp_str;
	}
	temp_i = 0;
	while (temp_i < len)
	{
		dto->print_str[dto->print_idx] = append_str[temp_i];
		dto->print_idx++;
		temp_i++;
	}
	dto->print_str[dto->print_idx] = 0;
	return (dto->print_str);
}

void	print_temp(int n, int len)
{
	if (len > 0)
		print_temp(n / 2, len - 1);
	printf("%d", n % 2);
}

void	print_dto(t_print_dto *dto)
{
	int temp = dto->flag;

	printf("flag: "); 
	print_temp(temp, 5);
	printf("\n");
	printf("width: %zd\n", dto->nums[0]);
	printf("precision: %zd\n", dto->nums[1]);
	printf("type: %c\n", dto->print_type);
}

char	*print_format_c(t_print_dto *dto, ssize_t *return_len)
{
	char	*return_str;
	ssize_t	len;

	*return_len = 1;
	if (dto->nums[WIDTH] > *return_len)
		*return_len = dto->nums[WIDTH];
	return_str = (char *)malloc(*return_len + 1);
	if (!return_str)
		return (0);
	return_str[*return_len] = 0;
	len = 0;
	while (len < *return_len)
		return_str[len++] = ' ';
	if (dto->flag & MINUS_FLAG)
		return_str[0] = (char) va_arg(dto->ap, int);
	else
		return_str[*return_len - 1] = (char) va_arg(dto->ap, int);
	return (return_str);
}

char	*print_format_s(t_print_dto *dto, ssize_t *return_len)
{
	char	*return_str;
	char	*arg_str;
	ssize_t	len;
	
	*return_len = 1;
	if (dto->print_type == '%')
		arg_str = "%";
	else 
		arg_str = va_arg(dto->ap, char *);
	if (!arg_str)
		arg_str = "(null)";
	len = ft_strlen(arg_str);
	if (dto->nums[PRECISION] != -1 && dto->nums[PRECISION] < len)
		len = dto->nums[PRECISION];
	dto->nums[PRINT_STR_LEN] = len;
	*return_len = len;
	if (dto->nums[WIDTH] > len)
		*return_len = dto->nums[WIDTH];
	return_str = (char *)malloc(*return_len + 1);
	if (!return_str)
		return (0);
	return_str[*return_len] = 0;
	len = 0;
	while(len < *return_len)
		return_str[len++] = ' ';
	len = -1;
	if (dto->flag & MINUS_FLAG)
		while(len++ < dto->nums[PRINT_STR_LEN] - 1)
			return_str[len] = arg_str[len];
	else
		while(len++ < dto->nums[PRINT_STR_LEN] - 1)
			return_str[*return_len - dto->nums[PRINT_STR_LEN] + len] =
			   	arg_str[len];
	return(return_str);
}

void	numlen_p(t_print_dto *dto, unsigned long num, ssize_t *return_len,
		ssize_t *len)
{
	unsigned long temp;

	*len = 2;
	*return_len = 0;
	temp = num;
	//printf("precision: %zd\n", dto->nums[PRECISION]);
	if (temp == 0 && dto->nums[PRECISION] != 0)
		*len = 3;
	while (temp > 0)
	{
		temp /= 16;
		*len += 1;
	}
	*return_len += *len;
	if (dto->nums[WIDTH] > *return_len)
		*return_len = dto->nums[WIDTH];
	//printf("len: %zd\n", *len);
}

char	*print_format_p(t_print_dto *dto, ssize_t *return_len)
{
	char			*return_str;
	ssize_t			len;
	ssize_t			temp_i;
	unsigned long	address;

	address = va_arg(dto->ap, unsigned long);
	numlen_p(dto, address, return_len, &len);
	return_str = (char *)malloc(*return_len + 1);
	temp_i = 0;
	if (!return_str) 
		return (0);
	while (temp_i < *return_len)
		return_str[temp_i++] = ' ';
    if(dto->flag & MINUS_FLAG)
        temp_i = 0;
    else
        temp_i = *return_len - len;
	return_str[temp_i] = '0';
	return_str[temp_i + 1] = 'x';
	return_str[*return_len] = 0;
	//printf("temp: %zd\n", temp_i);
	if (dto->flag & MINUS_FLAG && dto->nums[PRECISION] != 0)
		recur_p(dto, return_str, len, address);
	else if (dto->nums[PRECISION] != 0)
		recur_p(dto, return_str, *return_len, address);
	return (return_str);
}

void numlen_d(t_print_dto *dto, long num, ssize_t *return_len, ssize_t *len)
{
	long temp;

	*return_len = 0;
	temp = num;
	*len = 0;
	if (num < 0)
		num *= -1;
	if(num == 0 && dto->nums[PRECISION] == 0)
		*len = 0;
	else if (num == 0)
		*len = 1;
	while (num > 0)
	{
		(*len)++;
		num /= 10;
	}
	if (dto->nums[PRECISION] != -1 && dto->nums[PRECISION] > *len)
		*len = dto->nums[PRECISION];
	if (temp < 0 || (dto->flag & PLUS_FLAG) || (dto->flag & SPACE_FLAG))
		*len += 1;
	*return_len += *len;
	if (dto->nums[WIDTH] > *return_len)
		*return_len = dto->nums[WIDTH];
/*	
	printf("tolen: %zd\n", *return_len);
	printf("len: %zd\n", *len);
	print_dto(dto);
	
*/	
}	
void	recur_p(t_print_dto *dto, char *return_str, ssize_t len,
		unsigned long num)
{
	char			*hex;

	hex = "0123456789abcdef";
	if (num > 15)
		recur_d(dto, return_str, len - 1, num / 16);
	return_str[len - 1] = hex[num % 16];
}

void	recur_d(t_print_dto *dto, char *return_str, ssize_t len, long num)
{
	char *hex;

	if (dto->print_type == 'x' || dto->print_type == 'p')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (num > 15 && (dto->print_type == 'x' || dto->print_type == 'X'
			|| dto->print_type == 'p'))
		recur_d(dto, return_str, len - 1, num / 16);
	else if (num > 9 && !(dto->print_type == 'x' || dto->print_type == 'X'
				|| dto->print_type == 'p'))
		recur_d(dto, return_str, len - 1, num / 10);
	if (dto->print_type == 'x' || dto->print_type == 'X'
			|| dto->print_type == 'p')
		return_str[len - 1] = hex[num % 16];
	else
		return_str[len - 1] = num % 10 + '0';
	//printf("%d\n", num);
}

char	*print_format_d(t_print_dto *dto, ssize_t *return_len)
{
	char	*return_str;
	ssize_t temp_i;
	ssize_t	len;
	long	num;

	if (dto->print_type == 'd' || dto->print_type == 'i')
		num = va_arg(dto->ap, int);
	else
		num = va_arg(dto->ap, unsigned int);
	numlen_d(dto, num, return_len, &len);
	return_str = (char *)malloc(*return_len + 1);
	if (!return_str)
		return (0);
	if ((dto->flag & DOT_FLAG) && dto->nums[PRECISION] == 0)
		dto->flag &= ~(ZERO_FLAG);
	temp_i = 0;
	while (temp_i < *return_len)
		return_str[temp_i++] = ' ';
	return_str[*return_len] = 0;
	if(!(dto->flag & MINUS_FLAG) && (!(dto->flag &ZERO_FLAG) || dto->nums[PRECISION] > 0))
		temp_i = *return_len - len;
	else
		temp_i = 0;
	//printf("temp_i %zd\n", temp_i);
	if (num < 0)
		return_str[temp_i++] = '-';
	else if(dto->flag & PLUS_FLAG)
		return_str[temp_i++] = '+';
	else if (dto->flag & SPACE_FLAG)
		return_str[temp_i++] = ' ';
	if ((dto->flag & ZERO_FLAG || dto->nums[PRECISION] > 0) && len > 0)
	{
		if (dto->flag & MINUS_FLAG)
		{
			while (temp_i < len && dto->nums[PRECISION] != 0)
				return_str[temp_i++] = '0';
		}
		else
		{
			while (temp_i < *return_len)
				return_str[temp_i++] = '0';
		}
	}
	//printf("|%s|\n", return_str);
	/*
	if (dto->flag & SPACE_FLAG)
		return_str[0] = ' ';
		*/
	temp_i = num;
	if (temp_i < 0)
		temp_i *= -1;
	//printf("%zd\n", temp_i);
	/*
	if (dto->flag & MINUS_FLAG && dto->nums[PRECISION] != 0)
		recur_d(dto, return_str, len, temp_i);
	else if (dto->nums[PRECISION] != 0)
		recur_d(dto, return_str, *return_len, temp_i);
	*/
	if (dto->flag & MINUS_FLAG && !(dto->nums[PRECISION] == 0 && num == 0))
		recur_d(dto, return_str, len, temp_i);
	else if (len > 0 && !(dto->nums[PRECISION] == 0 && num == 0))
		recur_d(dto, return_str, *return_len, temp_i);
	return (return_str);
}

void	numlen_x(t_print_dto *dto, unsigned long num, ssize_t *return_len, ssize_t *len)
{
	unsigned long temp;

	*return_len = 0;
	*len = 0;
	temp = num;
	if(num == 0 && dto->nums[PRECISION] == 0)
		*len = 0;
	else if (num == 0)
		*len = 1;
	while (num > 0)
	{
		(*len)++;
		num /= 16;
	}
	if (dto->nums[PRECISION] != -1 && dto->nums[PRECISION] > *len)
		*len = dto->nums[PRECISION];
	if (dto->flag & HASH_FLAG && temp != 0)
		*len += 2;
	*return_len += *len;
	if (dto->nums[WIDTH] > *return_len)
		*return_len = dto->nums[WIDTH];
	/*
	printf("%zd\n", *return_len);
	printf("%zd\n", *len);
	printf("%zd\n", dto->nums[PRECISION]);
	print_dto(dto);
	*/
}

char	*print_format_x(t_print_dto *dto, ssize_t *return_len)
{
	char	*return_str;
	ssize_t	len;
	ssize_t temp_i;
	unsigned long	num;

	num = va_arg(dto->ap, unsigned int);
	numlen_x(dto, num, return_len, &len);
	return_str = (char *)malloc(*return_len + 1);
	if (!return_str)
		return (0);
	if ((dto->flag & DOT_FLAG) && dto->nums[PRECISION] == 0)
		dto->flag &= ~(ZERO_FLAG);
	temp_i = 0;
	while (temp_i < *return_len)
		return_str[temp_i++] = ' ';
	return_str[*return_len] = 0;
	if(!(dto->flag & MINUS_FLAG) && (!(dto->flag &ZERO_FLAG) || dto->nums[PRECISION] > 0))
		temp_i = *return_len - len;
	else
		temp_i = 0;
	if (dto->flag & HASH_FLAG && num != 0)
		return_str[temp_i++] = '0';
	if (dto->flag & HASH_FLAG && num != 0 && dto->print_type == 'x')
		return_str[temp_i++] = 'x';
	else if(dto->flag & HASH_FLAG && num != 0)
		return_str[temp_i++] = 'X';
	if (dto->flag & ZERO_FLAG || dto->nums[PRECISION] != 0)
	{
		if (dto->flag & MINUS_FLAG)
		{
			while (temp_i < len && dto->nums[PRECISION] != 0)
				return_str[temp_i++] = '0';
		}
		else
		{
			while (temp_i < *return_len)
				return_str[temp_i++] = '0';
		}
	}
	if (dto->flag & MINUS_FLAG && !(dto->nums[PRECISION] == 0 && num == 0))
		recur_d(dto, return_str, len, num);
	else if (len > 0 && !(dto->nums[PRECISION] == 0 && num == 0))
		recur_d(dto, return_str, *return_len, num);
	return (return_str);
}

char	*format_result(t_print_dto *dto, ssize_t *return_len)
{
	if (dto->print_type == 'c')
		return (print_format_c(dto, return_len));
	else if (dto->print_type == 's')
		return (print_format_s(dto, return_len));
	else if (dto->print_type == 'p')
		return (print_format_p(dto, return_len));
	else if (dto->print_type == 'd')
		return (print_format_d(dto, return_len));
	else if (dto->print_type == 'i')
		return (print_format_d(dto, return_len));
	else if (dto->print_type == 'u')
		return (print_format_d(dto, return_len));
	else if (dto->print_type == 'x')
		return (print_format_x(dto, return_len));
	else if (dto->print_type == 'X')
		return (print_format_x(dto, return_len));
	else if (dto->print_type == '%')
		return (print_format_s(dto, return_len));
	return (0);
}

int	on_error(t_print_dto *dto, void *mem1)
{
	free(dto->print_str);
	free(mem1);
	return (-1);
}

int	ft_printf(const char *format_str, ...)
{
	char		*temp_str;
	ssize_t		len;
	t_print_dto dto;

	va_start(dto.ap, format_str);
	if(!dto_init(&dto))
		return (-1);
	while (format_str[dto.format_idx])
	{
		if (format_str[dto.format_idx] == '%')
		{
			parse_format(&dto, format_str);
			temp_str = format_result(&dto, &len);
			if (!temp_str)
				return (on_error(&dto, temp_str));
			if(!append_str(&dto, temp_str, len))
				return (on_error(&dto, temp_str));
			free(temp_str);
			//print_dto(&dto);
			dto_clear(&dto);
		}
		else
			if(!append_str(&dto, &format_str[dto.format_idx], 1))
				return (on_error(&dto, 0));
		dto.format_idx++;
	}
	if(write(1, dto.print_str, dto.print_idx) == -1)
		dto.print_idx = -1;
	free(dto.print_str);
	return (dto.print_idx);	
}

int	is_type(int c)
{
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
			|| c == 'X' || c == '%')
		return (1);
	return (0);
}

int	is_flag(int c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

int	is_num(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	set_flag(t_print_dto *dto, char c)
{
	if (c == '-')
		dto->flag |= MINUS_FLAG;
	else if(c == '+')
		dto->flag |= PLUS_FLAG;
	else if(c == ' ')
		dto->flag |= SPACE_FLAG;
	else if(c == '0')
		dto->flag |= ZERO_FLAG;
	else if(c == '#')
		dto->flag |= HASH_FLAG;
	else if(c == '.')
	{
		dto->flag |= DOT_FLAG;
		set_num(dto, '.', PRECISION);
	}
}

void	set_num(t_print_dto *dto, char c, int flag)
{
	if (dto->nums[flag] == -1)
		dto->nums[flag] = 0;
	if (c == '*')
		dto->nums[flag] = va_arg(dto->ap, int);
	else if(c != '.')
	{
		dto->nums[flag] *= 10;
		dto->nums[flag] += (c - '0');
	}
}

void	parse_format(t_print_dto *dto, const char *format_str)
{
	ssize_t	len;

	len = 0;
	dto->format_idx++;
	while (is_flag(format_str[dto->format_idx]))
		set_flag(dto, format_str[dto->format_idx++]);
	while (is_num(format_str[dto->format_idx]))
		set_num(dto, format_str[dto->format_idx++], WIDTH);
	if (format_str[dto->format_idx] == '.')
	{
		if (format_str[dto->format_idx] == '.')
			set_flag(dto, format_str[dto->format_idx++]);
		while (is_num(format_str[dto->format_idx]))
			set_num(dto, format_str[dto->format_idx++], PRECISION);
	}
	dto->print_type = format_str[dto->format_idx];
}

/*
void	parse(const char *str)
{
	
}
*/
