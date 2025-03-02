/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:13:48 by minsepar          #+#    #+#             */
/*   Updated: 2025/03/03 01:05:14 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <stdlib.h>
# include <sys/types.h>

typedef struct  s_list
{
    void            *data;
    struct s_list   *next;
}   t_list;

/* bonus */
int     ft_atoi_base(char *str, char *base);
void    ft_list_push_front(t_list **begin_list, void *data);
int     ft_list_size(t_list *begin_list);
void    ft_list_sort(t_list **begin_list, int (*cmp)());
void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

/* helper */
t_list  *ft_create_elem(void *data);
void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

#endif