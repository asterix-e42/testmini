
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "t.h"

#include "libft/include/libft.h"
#include <stdio.h>

void yolo(int dir, int y)
{
	char depl[4];

	*(depl) = 27;
	*(depl + 1) = 91;
	*(depl + 2) = dir;
	*(depl + 3) = 0;
	while(--y > -1)
		write(1, depl, 3);
}

void clean(t_data *blk)
{
	char c;
	int i;

	i = blk->len;
	c = 127;
//printf("%d\n", i);
	yolo(68, blk->pointeur);
	while(--i > -1)
		write(1, &c, 1);
	//printf("%d\n", blk->len);
	yolo(68, blk->len);
}

int ft_alloc(t_data *data, char *ajout)
{
	char *tmp;

	tmp = data->str;
		//++(data->pointeur);
	if (ajout)
		data->len += ft_strlen(ajout);
	else
	{
		if (data->pointeur > 0 && --(data->pointeur) + 42)
		--(data->len);
		else
			return(0);
	}
	if (!(data->str = (char *)ft_memalloc(sizeof(char) * (data->len + 1))))
		return(-1);
	ft_strncpy(data->str, tmp, data->pointeur);
	if (ajout)
	ft_strcat(data->str, ajout);
	ft_strcat(data->str, tmp + data->pointeur + !(ajout));
	(data->pointeur) += (ajout)?ft_strlen(ajout): 0;
	*(data->str + data->len) = 0;
	free(tmp);
	return(0);
}

t_data *init()
{
	t_data *ret;

	if (!(ret = malloc(sizeof(t_data))))
		return(NULL);
	if (!(ret->str = malloc(sizeof(char))))
	{
		free(ret);
		return(NULL);
	}
	*(ret->str) = 0;
	ret->len = 0;
	ret->pointeur = 0;
	return(ret);
}

void up(char *s, t_data *blk)
{
	if (*s == 27 && *(s + 1) == 91)
	{
		//write(1, s, 3);
		if (*(s + 2) == 65)
		write(1, s, 3);
			//write(1, "up", 2);
		else if (*(s + 2) == 66)
		write(1, s, 3);
			//write(1, "down", 4);
		else if (*(s + 2) == 67)
		{
		//	write(1, "droite", 6);
			if (blk->pointeur < blk->len)
			{
		write(1, s, 3);
				++blk->pointeur;
			}
		}
		else if (*(s + 2) == 68)
		{
		//	write(1, "gauche", 6);
			if (blk->pointeur > 0)
			{
		write(1, s, 3);
				--blk->pointeur;
			}
		}
	}
}

void lecture()
{
	char	c[5];
	int		lec;
	t_data	*my_block;

	if (!(my_block = init()))
		return ;
	*(c + 4) = 0;
	while((lec = read(0, c, 4)) > 0)
	{
		*(c + lec) = 0;
		if (lec == 3 && *c == 27)
			up(c, my_block);
		else
		{
		clean(my_block);
		if (31 < *c && *c < 127)
			ft_alloc(my_block, c);
		else if(*c == 127)
			ft_alloc(my_block, NULL);
		//printf("{%d}\n", my_block->len);
		//
		//yolo(68, my_bolock->pointeur - 1);
		write(1, my_block->str, my_block->len);
		yolo(68, my_block->len - my_block->pointeur);
		}
		//else
		//
		printf("	{%d %d}\n", *c, lec);
		if (*(c) == 3)
			return ;
	}
}

int pass_canonique()
{
	struct termios term;

	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	//term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return(0);
}

int main(int ac, char **av, char **env)
{
	char           *name_term;
	struct termios term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	printf("%s\n", name_term);
	write(1, "$>", 2);
	//if (tgetent(NULL, name_term) == ERR)
	//	return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	if (pass_canonique())
		return (-1);
	lecture();
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
}
