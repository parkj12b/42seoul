/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:13:48 by minsepar          #+#    #+#             */
/*   Updated: 2025/03/01 20:07:03 by minsepar         ###   ########.fr       */
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

/* helper */
t_list  *ft_create_elem(void *data);
void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

#endif