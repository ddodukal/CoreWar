/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:40:51 by ddodukal          #+#    #+#             */
/*   Updated: 2018/11/07 18:43:53 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fact(int n)
{
	int r;
	int i;

	i = 1;
	r = 1;
	while (i <= n)
	{
		r = r * i;
		i++;
	}
	return (r);
}