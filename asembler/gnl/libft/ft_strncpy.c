/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:15:16 by ddodukal          #+#    #+#             */
/*   Updated: 2018/12/06 15:08:08 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t l)
{
	size_t		i;

	i = 0;
	while (s2[i] && i < l)
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < l)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}