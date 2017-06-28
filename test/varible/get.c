/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 14:31:11 by tdumouli          #+#    #+#             */
/*   Updated: 2017/04/17 17:10:03 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tent.h"
#include <stdlib.h>

char	*ft_strjoini(char const *s1, char const *s2, char c)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (i + j + 2))))
		return (NULL);
	*(ret + i + j + 1) = '\0';
	while (j--)
		*(ret + i + j + 1) = *(s2 + j);
	*(ret + i) = c;
	while (i--)
		*(ret + i) = *(s1 + i);
	return (ret);
}

char	*chop(char *nam_var, char *name_priv)
{
	t_var		*tmp;
	t_list		*exist;

	tmp = ft_lstfind_var(nam_var);
	if (tmp)
		if ((exist = ft_lstfind_priv(name_priv, tmp->privat)))
			return (((t_private *)exist->content)->value);
	return (NULL);
}

char	**chop_all(char *nam_var)
{
	t_var		*tmp;
	t_list		*exist;
	char		**ret;
	int			parcourt;
	int			p2;

	p2 = 0;
	tmp = ft_lstfind_var(nam_var);
	if (tmp)
	{
		parcourt = ft_lstcount(tmp->privat);
		exist = (tmp->privat);
		ret = (char **)malloc(sizeof(char *) * (1 + parcourt));
		*(ret + parcourt) = (void *)0;
		while (p2 < parcourt)
		{
			*(ret + p2) = ft_strjoini(((t_private *)exist->content)->name,
								((t_private *)exist->content)->value, '=');
			++p2;
			exist = exist->next;
		}
		return (ret);
	}
	return (NULL);
}
