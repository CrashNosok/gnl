/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahillary <ahillary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:51:44 by ahillary          #+#    #+#             */
/*   Updated: 2019/09/19 12:29:32 by ahillary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (num == 0)
		return (0);
	ptr1 = (unsigned char*)memptr1;
	ptr2 = (unsigned char*)memptr2;
	i = 0;
	while (ptr1[i] == ptr2[i] && i < num - 1)
		i++;
	return (ptr1[i] - ptr2[i]);
}
