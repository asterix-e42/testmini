/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 04:13:33 by tdumouli          #+#    #+#             */
/*   Updated: 2017/04/08 04:49:28 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poo.h"
#include <stdlib.h>

static t_class_test	*private_my_int()
{
	static t_class_test	*my_class = NULL;

	if (!my_class)
		my_class = malloc(sizeof(t_class_test));

	return (my_class);
}

int			get_my_int(void)
{
	return (private_my_int()->val);
}

void		set_my_int(int set)
{
	(private_my_int())->val = set;
}
