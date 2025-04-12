/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:43:16 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/13 03:09:55 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

void    print_size_t(size_t num);
void	print_heap();
void	print_chunk(void *chunk);
void	log_ptr(void *ptr);
void	print_free_list();

// #define DEBUG

# ifdef DEBUG
#  define DLOG(x) x
# else
#  define DLOG(x)
# endif

#endif