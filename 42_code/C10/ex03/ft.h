/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:07:58 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/11 13:15:50 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct s_file_dto
{
	int				i;
	char			buf[16];
	long			address;
	int				byte_type;
	int				flag;
	int				flag_star;
	int				ret;
	int				fd;
	int				c;
	int				success;
}	t_file_dto;
#endif
