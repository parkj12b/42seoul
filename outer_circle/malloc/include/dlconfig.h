/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlconfig.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:43:31 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/06 22:42:03 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLCONFIG_H
# define DLCONFIG_H

# define PREV_INUSE         0x1
# define SIZE_MASK          (~(PREV_INUSE))

# define SMALL_BIN_STEP     16

# define SBIN_MIN           32
# define LBIN_START         14
# define NBIN               64
# define HPAGE_IDX    17

# define INIT_CHUNK_SIZE    2048

# define ALIGNMENT          16
# define HEADER_PAD         16

# define MUNMAP_LIMIT       128 * 1024 * 1024
// # define HEAP_SIZE          16 * 1024 * 1024
# define HEAP_SIZE          8 * 1024

#endif