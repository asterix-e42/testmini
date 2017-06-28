

#ifndef T_H
#define T_H

typedef struct s_data {
	char	*str;
	int		len;
	int		pointeur;
} t_data;

typedef struct s_termios {
	tcflag_t c_iflag;
	tcflag_t c_oflag;
	tcflag_t c_cflag;
	tcflag_t c_lflag;
	cc_t c_cc[NCCS];
	speed_t c_ispeed;
	speed_t c_ospeed;
} t_term;

#endif
