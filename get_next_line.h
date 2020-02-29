/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahillary <ahillary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:10:40 by ahillary          #+#    #+#             */
/*   Updated: 2019/10/18 21:12:04 by ahillary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 10
# define MAX_FD 4864

int					get_next_line(int fd, char **line);
typedef struct		s_gnl
{
	int				fd;
	char			*ream;
	struct s_gnl	*next;
}					t_gnl;

#endif
