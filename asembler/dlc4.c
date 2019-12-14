/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:31:58 by eamielin          #+#    #+#             */
/*   Updated: 2019/10/30 20:32:02 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				getcmplen(char *s, t_lab **lab)
{
	int			n;
	int			n1;
	int			n2;
	int			l;

	n1 = (ft_strlen(s));
	if (s[0] == '%' && s[1] == ':')
		l = 2;
	if (s[0] == ':')
		l = 1;
	n1 -= l;
	n2 = ft_strlen((*lab)->label) - 1;
	if (n1 > n2)
		n = n1;
	else
		n = n2;
	if (ft_strncmp((*lab)->label, &s[l], n) == 0)
		return (1);
	return (0);
}
