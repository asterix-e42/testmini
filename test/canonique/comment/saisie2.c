/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saisie2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:32:04 by tdumouli          #+#    #+#             */
/*   Updated: 2017/05/24 19:33:40 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "g.h"
#include "libft.h"

void			yolo(int dir, int y)
{
	char	depl[3];

	*(depl) = 27;
	*(depl + 1) = 91;
	*(depl + 2) = dir;
	while (--y > -1)
		write(1, depl, 3);
}

static void		sup(int fd, char *str, int len)
{
	int		i;

	i = -1;
	while(++i < len)
	{
		if (*(str + i) == '\n')
			write(1, "\n\r", 2);
		write(1, " ", 1);
	}
}

static void start_lec(int pos, t_data *blk)
{
//	ft_putnbr(-i);
//	sleep(1);
	write(1, "\r", 1);
	yolo(67, blk->pos_start);
	yolo(65, ft_strcpt(blk->str, '\n') - ft_strcpt(blk->str + pos, '\n'));
//	ft_putnbr(i);
//	sleep(1);
	//if (ft_strcpt(blk->str, '\n') > 1 && *(blk->str) == '\n' && i % 2 == 0)
	//	yolo(65, 1);
	//ft_putnbr(i);
	
/*	if (recule(blk))
		ft_putnbr(blk->pointeur - (int)(recule(blk) - blk->str));
	else
*///		ft_putnbr(blk->pointeur);
}

void point(t_data *blk, int fg)
{
	if (fg)
		start_lec(blk->len, blk);
	if (recule(blk))
	{
		//sleep(1);
		yolo(66, ft_strcpt(blk->str, '\n') - ft_strcpt(blk->str + blk->pointeur, '\n'));
		//ft_putnbr(ft_strcpt(blk->str, '\n'));
		write(1, "\r", 1);
		yolo(67, blk->pointeur + blk->str - recule(blk) - 1);
	}
	else
		yolo(67, blk->pointeur);
}

void set_t_data_pointeur(t_data *blk, int inc)
{
	start_lec(blk->pointeur, blk);
	blk->pointeur += inc;
	point(blk, 0);
}

void			clean(t_data *blk)
{
	start_lec(blk->pointeur, blk);
	sup(1, blk->str, blk->len);
	start_lec(blk->len, blk);
}

t_data			*t_dat_init(void)
{
	t_data	*ret;

	if (!(ret = malloc(sizeof(t_data))))
		return (NULL);
	if (!(ret->str = malloc(sizeof(char))))
	{
		free(ret);
		return (NULL);
	}
	*(ret->str) = 0;
	ret->len = 0;
	ret->pointeur = 0;
	ret->pos_start = 3;
	return (ret);
}
