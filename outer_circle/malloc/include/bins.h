/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bins.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:41:29 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/06 15:44:31 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LBIN_H
# define LBIN_H

# include <stddef.h>

# define SBIN_MAX 256

int         get_bin_index(size_t size);
void        insert_chunk(t_mchunk *chunk);
t_mchunk    *get_first_chunk(int i);
t_mchunk    *get_bestfit_chunk(int i, size_t size);

#endif