/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saisie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:08:19 by tdumouli          #+#    #+#             */
/*   Updated: 2017/05/24 20:50:45 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "g.h"
#include "libft.h"

int		ft_alloc(t_data *data, char *ajout)
{
	char	*tmp;

	tmp = data->str;
	if (ajout)
		data->len += ft_strlen(ajout);
	else
	{
		if (data->pointeur > 0 && --(data->pointeur) + 42)
			--(data->len);
		else
			return (0);
	}
	if (!(data->str = (char *)ft_memalloc(sizeof(char) * (data->len + 1))))
		return (-1);
	ft_strncpy(data->str, tmp, data->pointeur);
	if (ajout)
		ft_strcat(data->str, ajout);
	ft_strcat(data->str, tmp + data->pointeur + !(ajout));
	(data->pointeur) += (ajout) ? ft_strlen(ajout) : 0;
	*(data->str + data->len) = 0;
	free(tmp);
	return (0);
}

void	dep_up_sec(char *s, t_data *blk)
{
	if (*(s + 2) == 68)
	{
		if (blk->pointeur > 0)
			set_t_data_pointeur(blk, -1);
		while (blk->pointeur > 0 && *(blk->str + blk->pointeur) == ' ')
			set_t_data_pointeur(blk, -1);
		while (blk->pointeur > 0 && !ft_isspace(*(blk->str + blk->pointeur)))
			set_t_data_pointeur(blk, -1);
		return ;
	}
	if (*(s + 2) == 67)
	{
		if (blk->pointeur < blk->len)
			set_t_data_pointeur(blk, 1);
		while (blk->pointeur < blk->len && *(blk->str + blk->pointeur) == ' ')
			set_t_data_pointeur(blk, 1);
		while (blk->pointeur < blk->len &&
				!ft_isspace(*(blk->str + blk->pointeur)))
			set_t_data_pointeur(blk, 1);
	}
}

/*
** 67 -> rigth
** 68 -> left
** 65 -> up
** 66 -> down
*/

char *recule(t_data *blk)
{
	char tmp;
	char *ret;

	tmp = *(blk->str + blk->pointeur);
	*(blk->str + blk->pointeur) = 0;
	ret = ft_strrchr(blk->str, '\n');
	*(blk->str + blk->pointeur) = tmp;
	return (ret);
}

static int up_sec_move(t_data *blk, char *s, int start)
{
	char	*tmp;
	int		len;

	if (*(s + 2) == 65)
	{
		tmp = recule(blk);
		if (!tmp)
			return (0 - blk->pointeur);
		set_t_data_pointeur(blk, 0 - start);
		len = (recule(blk)) ? recule(blk) - tmp : blk->str - tmp - 1;
		len += MIN(0 - len, start);
		return (len);
	}
	if (*(s + 2) == 66)
	{
		tmp = ft_strchr(blk->str + blk->pointeur, '\n');
		if (!tmp)
			return (blk->len - blk->pointeur);
		len = (ft_strchr(tmp + 1, '\n')) ? 	MIN(ft_strchr(tmp + 1, '\n')
				- tmp, start) : MIN(start, ft_strlen(tmp));
		return (tmp - blk->str -  blk->pointeur + len);
	}
	return (0);
}

void	up_sec(char *s, t_data *blk)
{
	++s;
	if (*s == 27 && *(s + 1) == 91)
	{
		if (*(s + 2) == 67)
			dep_up_sec(s, blk);
		else if (*(s + 2) == 68)
			dep_up_sec(s, blk);
		else if (recule(blk))
			set_t_data_pointeur(blk,
					up_sec_move(blk, s, blk->str + blk->pointeur - recule(blk)));
		else
			set_t_data_pointeur(blk, up_sec_move(blk, s, blk->pointeur + 1));
	}
}

void	up(char *s, t_data *blk)
{
	if (*s == 27 && *(s + 1) == 91)
	{
		if (*(s + 2) == 72)
			set_t_data_pointeur(blk, 0 - blk->pointeur);
		if (*(s + 2) == 70)
			set_t_data_pointeur(blk, blk->len - blk->pointeur);
		if (*(s + 2) == 65)
			;
		else if (*(s + 2) == 66)
			;
		else if (*(s + 2) == 67)
		{
			if (blk->pointeur < blk->len)
			{
				//		if (*(blk->pointeur + blk->str) == '\n')
				//			write(1, "\n\r", 2);
				//		else
				//			yolo(67, 1);;
				set_t_data_pointeur(blk, 1);
			}
		}
		else if (*(s + 2) == 68)
		{
			if (blk->pointeur > 0)
			{
				//		if (*(blk->pointeur + blk->str) == '\n')
				//		{
				//			yolo(65, 1);
				//			yolo(67, blk->str - recule(blk) + blk->pointeur);
				//		}
				//		else
				//			yolo(68, 1);
				set_t_data_pointeur(blk, -1);
			}
		}
	}
}

void ft_write(int fd, char *str, int len)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while(++j != -1 && ++i < len)
	{
		if (*(str + i) == '\n')
		{
			write(fd, str + i - j, j + 1);
				/*ft_putstr("       ");
				ft_putnbr(i - j + tmp);
				ft_putchar(' ');
				ft_putnbr(j + 1 - tmp);
				ft_putchar(' ');
				ft_putnbr(tmp);*/
			j = -1;
			write(1, "\r", 1);
		}
	}
	//ft_putnbr(i);
	//ft_putnbr(j);
	//	if (*(str + i - j + 1) == '\n')
	//		write(1, "1", 1);
	write(fd, str + i - j + (*(str + i - j) == '\n'), j);
	//write(fd, str + i - j, j);
}

char	*lecture(t_data *my_block)
{
	char	c[11];
	int		lec;
	int yrt;

	*(c + 10) = 0;
	while ((lec = read(0, c, 10)) > 0)
	{
		*(c + lec) = 0;
		yrt = lec;
		/*ft_putnbr(lec);
			while (yrt)
			{
			ft_putstr("  ");
			ft_putnbr(*(c + lec - yrt));
			yrt--;
			}
			write(1, "\n\r", 2);
			*/
		if (*(c) == 3)
			return (NULL);
		if (*(c) == 13 || *c == 4)
			return (my_block->str);
		if (lec == 3 && *c == 27)
			up(c, my_block);
		if (lec == 4 && *c == 27)
			up_sec(c, my_block);
		if (31 < *c || *c == '\n')
		{

			clean(my_block);
			if (*c == 127)
				ft_alloc(my_block, NULL);
			else
				ft_alloc(my_block, c);
			//sleep(1);
			ft_write(1, my_block->str, my_block->len);
			//write(1, my_block->str, my_block->len);

			point(my_block, 1);

			//yolo(68, my_block->len - my_block->pointeur);
		}
		//point(my_block, (31 < *c || *c == '\n'));
	}
	return (my_block->str);
}

int		pass_canonique()
{
	struct termios term;

	term.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
			| INLCR | IGNCR | ICRNL | IXON);
	term.c_oflag &= ~OPOST;
	term.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	term.c_cflag &= ~(CSIZE | PARENB);
	term.c_cflag |= CS8;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

char	*saisie(void)
{
	t_data			*my_block;
	struct termios	term;
	char			*read;

	//tputs(clstr, 1, my_putchar);
	if (tcgetattr(0, &term) == -1)
		return (NULL);
	//	int success = tgetent(NULL, NULL);//getenv("TERM"));
	//ft_putstr(getenv("TERM"));
	/*	if (success < 0)
		ft_putstr("Could not access the termcap data base.\n");
		if (success == 0)
	//		ft_putstr("Terminal type  is not defined.\n");
	return (NULL);
	*/	if (!(my_block = t_dat_init()))
	return (NULL);
	if (pass_canonique())
		return (NULL);
	lecture(my_block);
	if (tcsetattr(0, 0, &term) == -1)
		return (NULL);
	read = my_block->str;
	free(my_block);
	return (read);
}
