/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 19:21:02 by tdumouli          #+#    #+#             */
/*   Updated: 2017/05/25 16:21:20 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define BUFF_SIZE 1024

char *saisie(void);

int		redirection_d(int fd, int doubl)
{
	int		ecriture;
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if ((ecriture = open("test.txt", O_CREAT | O_WRONLY | doubl, 0644)) > 0)
		
		write(ecriture, str, strlen(str));
	free(str);
	if (ecriture)
		close(ecriture);
	return (0);
}

void	ouverture(int ac, char **av, int fdpipe[2])
{
	int		fd;

	if (ac == 1)
		fd = 0;
	else if ((fd = open(*(av + 1), O_RDONLY)) <= 0)
		fd = 0;
	dup2(fdpipe[1], fd);
}

int		main(int ac, char **av)
{
	int		fd[2];

	pipe(fd);
	ouverture(ac, av, fd);
	redirection_d(fd, O_APPEND);
}
