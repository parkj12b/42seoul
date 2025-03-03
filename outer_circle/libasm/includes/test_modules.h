/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_modules.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:41:57 by minsepar          #+#    #+#             */
/*   Updated: 2025/03/03 17:31:42 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MODULES
# define TEST_MODULES

/* mandatory */

void    test_module_ft_strlen(void *arg);
void    test_module_ft_strcpy(void);
void    test_module_ft_strcmp(void);
void    test_module_ft_write(void);
void    test_module_ft_read(void);

/* bonus */
void    test_module_ft_atoi_base(void);
void    test_module_ft_list_push_front(void);
void    test_module_ft_list_size(void);
void    test_module_ft_list_sort(void);
void    test_module_ft_list_remove_if(void);

/* not required */

void    test_ft_isspace(void);
void    test_ft_create_elem(void);

#endif