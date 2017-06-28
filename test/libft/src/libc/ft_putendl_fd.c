/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:37:57 by tdumouli          #+#    #+#             */
/*   Updated: 2016/11/11 12:53:47 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(const char *s, int fd)
{
	int i;

	if (!s)
		return ;
	i = -1;
	while (*(s + ++i))
		write(fd, s + i, 1);
	write(fd, "\n", 1);
}
