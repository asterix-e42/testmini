


#ifndef LEXER_H
#define LEXER _H

# include "libft.h"

t_list *get_resv(void);

typedef enum			token_type
{
	TK_NEWLINE,
	TK_BLANK,
	TK_COMMENT,
	TK_SEPARATOR,
	TK_CMD,
	TK_NBR,
	TK_SCOTE,
	TK_DCOTE,
	TK_PARENT,
	TK_CROCHET,
	TK_ACOLAD,
	TK_IF,
	TK_THEN,
	TK_ELSE,
	TK_ELIF,
	TK_FI,
	TK_CASE,
	TK_IN,
	TK_ESAC,
	TK_FOR,
	TK_WHILE,
	TK_UNTIL,
	TK_DO,
	TK_DONE,
	TK_END
}						e_token_type;

typedef struct			s_token
{
	e_token_type		type;
	char				*start;
	int					len;
}						t_token;

typedef struct			s_res_name
{
	char 				*text;
	e_token_type		type;
}						t_res_name;

typedef struct 			s_lexer
{
	char				*input;
	t_list				*token;
}						t_lexer;

#endif
