/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 19:21:02 by tdumouli          #+#    #+#             */
/*   Updated: 2017/06/16 19:17:12 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "g.h"
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void pass(int fd_read, int fd_write);

int		new_process(char ***av, char *error, int stk, t_fd *fd, int sepG, int sepD)
{
	pid_t	pid;
	int		count;
	int		tmpfd;
	char ter[1024];

	if (stk)
		ft_putstr(**av);
	if (*av && !access(**av, X_OK))
	{
		if (fd->pos && sepD == 1)
		{
			fd->fd_stn2[0] = fd->fd_stn1[0];
			//fd->fd_stn2[1] = fd->fd_stn1[1];
		}
		//else
		//	++fd.pos;
		pipe(fd->fd_stn1);
		pid = fork();
		if (pid == 0)
		{
			//ft_putnbr(fd.pos);
		//write(1, "1", 1);
		//ft_putendl(**av);
/*			if (!fd.pos)
			{
					//write(1, "1a", 2);
					close (fd->fd_stn1[0]); //on ferme sortie
					dup2(fd->fd_stn1[1], 1); //redirec sortie stn
				//write(1, "1", 1);
					//write(0, "0", 1);
					//close(fd->fd_stn1[0]);
			}
			else
			{*/
		/*ft_putchar('i');
		ft_putchar('\n');
		ft_putnbr(fd->fd_stn1[0]);
		ft_putchar('\n');*/
		if (!fd->pos)
					close (fd->fd_stn1[0]); //on ferme sortie
					dup2(fd->fd_stn1[1], 1); //redirec sortie stn vers entrer
		if (fd->pos && sepD == 1)
		{
				close (fd->fd_stn2[1]); //on ferme entrer
				dup2(fd->fd_stn2[0], 0); // redirec entrer stn
		}
				//write(0, "ter ", 4);
				//read(0, ter, 1);
				//write(1, ter, 1);
				//read(fd->fd_stn1[0], ter, 1);
				//write(1, ter, 1);
			//}
		if (sepD == 1)
			execve(**av, *av, NULL);
		}
		else
		{
		/*ft_putchar('\n');
		ft_putnbr(fd->fd_stn1[0]);
		ft_putchar('\n');*/
			//fd->pos = 1;
		//	new_process(av + 1, error, stk, fd);
			//close(fd->fd_stn1[1]);
			wait(&count);

		//	write(1, "hg", 2);
		//ft_putendl(**av);
			close(fd->fd_stn1[1]);
			//pass(fd->fd_stn1[0], 1);
		if (!fd->pos && sepD == 1)
			++fd->pos;
			new_process(av + 1, error, stk, fd, sepG, sepD);
			//close(0);
		}
		return (WEXITSTATUS(count));
	}
	else if (fd->pos && sepD == 1)
	{
		/*ft_putchar('\n');
		ft_putnbr(fd->fd_stn2[0]);
		ft_putchar('\n');*/
		write(1, "1", 1);
			pass(fd->fd_stn1[0], 1);
		//read(fd->fd_stn2[0], ter, 50);
		//write(1, ter, 50);
		dup2(1, fd->fd_stn2[0]); // redirec entrer stn
		dup2(1, fd->fd_stn1[0]); // redirec entrer stn
		close(fd->fd_stn1[0]);
		close(fd->fd_stn2[0]);
	}
	return (1);
}

void pass(int fd_read, int fd_write)
{
	char str[BUFF_SIZE + 1];
	int		len_read;

	while ((len_read = read(fd_read, str, BUFF_SIZE)) > 0)
	{
		//write(2, str, strlen(str));
		*(str + len_read) = '\0';
		write(fd_write, str, strlen(str));
	}
	close (fd_write);
}

void end_pass(t_fd fd)
{
	int fd_st;

	fd_st = open("/dev/fd/1", O_WRONLY);
	pass(fd.fd_stn1[0], fd_st);
	close(fd.fd_stn1[0]);
	close(fd_st);
	//	fd = open("/dev/fd/2", O_WRONLY);
	//	pass(fd->fd_err);
	//	close(fd);
}

int		redirection_d(t_fd fd, int doubl, char *name)
{
	int		ecriture;
	char	t;

	if (!((ecriture = open(name, O_CREAT | O_WRONLY | doubl | S_IRUSR | S_IWUSR
						| S_IRGRP | S_IROTH)) > 0))
		return(1);
	t = ecriture + 'a';
	//write(2, &t, 1);
	//write(1, "1", 1);
	//write(1, "2", 1);
	pass(fd.fd_stn1[0], ecriture);
	//write(2, "1", 1);
	close(fd.fd_stn1[0]);
	close(ecriture);
	return (0);
}

int		ouverture_d(int ac, t_fd fd)
{
	char c;

	c = 4;
	if (ac == 1)
	{
		//dup2(0, fd->fd_stn1[1]);
		pass(0, 1);
		close(fd.fd_stn1[1]);
		close (1);
		//write(1, "\0", 1);
	}
	//else
	//dup2(1, fd_pipe[1]);
	//close(fd_pipe[1]);
	return (0);
}

int		ouverture_g(int doubl, char *av, int fd_pipe[2])
{
	int		fd;
	int		flag;
	char	*end;

	if (doubl == 2)
	{
		while((end = saisie()) && ft_strcmp(av, end) != -'\n')
		{
			write(fd_pipe[1], end, ft_strlen(end));
			free(end);
		}
	}
	else if ((fd = open(av, O_RDONLY)) > 0)
	{
		pass(fd, fd_pipe[1]);
	}
	else
	{
		write(2, "erreur\n", 7);
		return (1);
	}
	close(fd_pipe[1]);
	return(0);
}
/*
   int		main(int ac, char **av)
   {
   t_fd	fd;

   pipe(fd->fd_stn1);
//pipe(fd->fd_err);
dup2(fd->fd_stn1[1], 1);
//dup2(fd->fd_err[1], 2);
//ouverture_g(1, *(av + 1), fd_pipe);
//pass(*fd_pipe, 1);
if (!(av + 1) || !*(av + 1))
write(2, "missing name\n", 13);
else
{
//write(1, "3", 1);
ouverture_d(1, fd);
//write(1, "4", 1);
redirection_d(fd, O_TRUNC, *(av + 1));
}
end_pass(fd);
}*/

int main(int ac, char **av)
{
	t_fd	fd;
	char **avp[4];
	char *q;
	char *a[3];
	char *q1;
	char *a1[3];
	char *q2;
	char *a2[3];

	q = "/bin/ls";
	*a = q;
	*(a + 1) = "-l";
	*(a + 2) = 0;
	*(avp + 0) = a;

	q1 = "/bin/cat";
	*a1 = q1;
	*(a1 + 1) = "-e";
	*(a1 + 2) = 0;
	*(avp + 1) = a1;

	q2 = "/bin/cat";
	*a2 = q2;
	*(a2 + 1) = "-e";
	*(a2 + 2) = 0;
	*(avp + 0) = a2;

	*(avp + 1) = 0;

	//pipe(fd->fd_stn1);
	fd.pos = 0;
	new_process(avp, NULL, 0, &fd, 1, 1);
}

