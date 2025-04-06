/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dldllist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:17:13 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/06 23:29:50 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLDLLIST_H
# define DLDLLIST_H

# include "dlmalloc.h"

void    init_bin(t_mchunk *bin);
void    unlink_chunk(t_mchunk *node);
void    insert_node(t_mchunk *prev, t_mchunk *node);
void    insert_sorted(t_mchunk *head, t_mchunk *node);

#endif