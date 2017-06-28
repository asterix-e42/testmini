/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ajout.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 14:26:24 by tdumouli          #+#    #+#             */
/*   Updated: 2017/05/11 16:34:31 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tent.h"
#include "libft.h"
#include <stdlib.h>

static t_list	*new_private(char *name, char *value)
{
	t_private	ret;

	ret.name = ft_strdup(name);
	ret.value = value ? ft_strdup(value) : NULL;
	return (ft_lstnew(&ret, sizeof(t_private)));
}

static void		add_bout(char *nam, char *name, char *value)
{
	t_var		*priv;
	t_list		*exist;

	if (!name || !*name)
		return ;
	priv = ft_lstfind_var(nam);
	if (priv)
	{
		if (!value || !*value)
			value = "''";
		if ((exist = ft_lstfind_priv(name, priv->privat)))
			((t_private *)exist->content)->value = value;
		else if ((exist = new_private(name, value)))
			ft_lstaddend(&(priv->privat), exist);
	}
}

void			add(char *nam, char **ajout, unsigned int nb)
{
	char	*value;
	char	*tmp;

	while (nb-- && *ajout)
	{
		tmp = ft_strdup(*ajout);
		value = ft_strchr(tmp, '=');
		if (value)
		{
			*value = '\0';
			add_bout(nam, tmp, value + 1);
			free(tmp);
		}
		++ajout;
	}
}

t_list			*yolo(char *nam)
{
	t_list		*ret;
	t_var		var;

	ret = NULL;
	if (!ft_lstfind_var(nam))
	{
		ret = ft_lstnew(&var, sizeof(t_var));
		((t_var *)ret->content)->name = ft_strdup(nam);
		((t_var *)ret->content)->privat = NULL;
		ft_lstadd((t_list **)variable(2), ret);
	}
	return (ret);
}
