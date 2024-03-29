/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labelch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:37:15 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 21:27:20 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_wh1(char *file, int i)
{
	if (file[i] != '\n' && file[i] != COMMENT_CHAR
	&& file[i] != ALT_COMMENT_CHAR && file[i] != ' ' && file[i] != '	')
		return (1);
	return (0);
}

int		ft_skip(char *file, int i, int n, int k)
{
	int		j;

	if (n == 1)
	{
		j = i;
		if (k == 2)
			j += 2;
		while (file[j] != SEPARATOR_CHAR && file[j] != '\n'
		&& file[j] != ' ' && file[j] != '\t' && file[j] != COMMENT_CHAR)
			j++;
		return (j);
	}
	else
	{
		while (file[i] == ' ' || file[i] == '	')
			i++;
		return (i);
	}
}

int		argch(t_asm *asem, char *file, int i, t_lab *page)
{
	int		k;
	int		j;

	k = 0;
	j = 0;
	i = ft_skip(file, i, 2, page->art[k]);
	while (ft_wh1(file, i) == 1)
	{
		argch2(file, i, page, k);
		j = ft_skip(file, i, 1, page->art[k]);
		page->args[k] = ft_strnew(j - i + 1);
		ft_strncpy(page->args[k], &file[i], j - i);
		page->args[k][j - i] = '\0';
		extrarg(asem, page->args[k], page->art[k]);
		i = j;
		if (file[i] == SEPARATOR_CHAR)
		{
			k++;
			i++;
		}
		i = ft_skip(file, i, 2, page->art[k]);
	}
	return (i);
}

int		opercheck(char *file, int i, t_asm *asem, t_lab *page)
{
	int		j;

	j = 0;
	while (j < 16)
	{
		if (ft_strncmp(&file[i], asem->opers[j],
		ft_strlen(asem->opers[j])) == 0)
		{
			page->oper = asem->opers[j];
			break ;
		}
		j++;
	}
	if (page->oper == NULL)
		errors(15, asem->ln, asem);
	i += ft_strlen(page->oper);
	i = argch(asem, file, i, page);
	i = ft_comment(file, i);
	return (i);
}

int		labcheck(char *file, int i, t_asm *asem, t_lab *page)
{
	int		j;

	j = 0;
	while (file[i + j] != LABEL_CHAR)
		j++;
	j++;
	page->label = ft_strnew(j);
	ft_strncpy(page->label, &file[i], j);
	while (file[i] != LABEL_CHAR)
		i++;
	i++;
	while (file[i] == ' ' || file[i] == '	' || file[i] == '\n')
	{
		if (file[i] == '\n')
			asem->ln++;
		i++;
	}
	i = ft_comment(file, i);
	if (chifoper(asem, file, i) == 1)
		i = opercheck(file, i, asem, page);
	return (i);
}
