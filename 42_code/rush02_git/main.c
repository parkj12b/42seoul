/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 07:59:08 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/09 13:30:08 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

typedef struct s_entry
{
	int key;
	char *value;
}	t_entry;

typedef struct s_str_size
{
	int key;
	int size;
}	t_str_size;

typedef struct s_key
{
	char *cur;
	t_dup_check *next;
}	t_dup_check;

typedef struct s_dictionary
{
	t_entry *small_dictionary;
	t_entry *big_dictionary;
	t_str_size *small_size_arr;
	t_str_size *big_size_arr;
	t_dup_check *duplicate_checker;
}	t_dictionary;

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}


//return -1 on error
//
int dictionary_parser(char *file_name)
{
	t_str_size		*small_dictionary;
	t_str_size		*big_dictionary;
	int				fd;
	t_entry			*duplicate_check_arr;

	fd = open(file_name);
	if (fd == -1)
		return (-1);
	else
	{
		
	}
}

void	init_small_dictionary(t_entry *small_dictionary)
{
	int i;
	int j;

	j = 20;
	i = 0;
	while (i <= 20)
	{
		small_dictionary[i]->key = i;
		i++;
	}
	while (j <= 100)
	{
		small_dictionary[i]->key = j;
		j += 10;
	}
}

void	init_big_dictionary(t_entry *big_dictionary)
{
	int i;
	int j;

	i = 0;
	j = 3;
	while (i < 12)
	{
		big_dictionary[i] = j;
		i++;
		j += 3;
	}
}

//need free
//100 이하의 숫자들만 처리해주는 함수 add 하는게 들어와도 100이하만 처리해준다.
t_entry	*small_dictionary_parser(char *file_name,t_dup_check *duplicate_check)
{
	int num_entries;
	int fd;
	t_entry *dictionary_arr[30];

	fd = open(file_name);
	if (fd == -1)
		write(2, "Dict Error\n", 11);
	else
	{
	
	}
}

t_entry *big_dictionary_parser(char *file_name, t_dup_check *duplicate_check)
{
	int num_entries;
	int fd;
	t_entry *dictionary_arr[13];
}

int main()
{
	
}
