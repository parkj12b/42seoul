/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:28:19 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/11 10:36:34 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct s_dto
{
	int				byte_type;
	unsigned int	i;
	char			**argv;
	int				first_print;
	int				is_zero;
	long			num_bytes;
}	t_dto;
#endif
