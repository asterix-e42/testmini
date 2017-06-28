/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 03:00:42 by tdumouli          #+#    #+#             */
/*   Updated: 2017/03/05 17:11:13 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *src, int s)
{
	char	*d;

	d = (char *)src;
	while (*d != s && *d != '\0')
		d++;
	if (*d != s)
		return (NULL);
	return (d);
}
