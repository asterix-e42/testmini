/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:29:01 by tdumouli          #+#    #+#             */
/*   Updated: 2017/03/26 18:44:38 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(const char *s)
{
	int i;

	if (!s)
		return ;
	i = -1;
	while (*(s + ++i))
		write(1, s + i, 1);
	write(1, "\n", 1);
}
