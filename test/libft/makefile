# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:51:40 by tdumouli          #+#    #+#              #
#    Updated: 2017/05/19 15:31:54 by tdumouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SPEUDO = "tdumouli"
NAME = libft.a
OBJDIR = ./objet
SRCDIR = ./src
INCDIR = ./include
SRCS =	memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy \
		strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp \
		strncmp atoi isalpha isdigit isalnum isascii isprint toupper tolower \
		memalloc memdel strnew strdel strclr striter striteri strmap strmapi \
		strequ strnequ strsub strjoin strtrim strsplit itoa putchar putstr \
		putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd isspace \
		intlen power atoibase unsignedintlen erreur itoabaseint strcpt

LST =	lstadd.o lstnew.o lstdel.o lstdelone.o lstiter.o lstmap.o lstfind.o \
		lstaddend.o	lstfindsize.o lstothernew.o lstcount.o 

OBJ=	$(addsuffix .o, $(addprefix $(OBJDIR)/libc/ft_, $(SRCS))) \
		$(addprefix $(OBJDIR)/liste/ft_, $(LST))

LSTDIRI = libc liste

############################## normaly no change ###############################

NO_COLOR="\x1b[39m"
RED="\x1b[31m"
GREEN="\x1b[32m"
YELLOW="\x1b[33m"
CC = gcc
CFLAGS = -I$(INCDIR) -Wall -Werror -Wextra
MAKE = /usr/bin/make
LSTDIR= $(addprefix $(OBJDIR)/, $(LSTDIRI)) \

ifneq ($(NAME), )
all: objdir $(NAME)
	@echo $(GREEN)"compilation reussi"$(NO_COLOR)
else
all: objdir $(OBJ)
	@echo $(GREEN)"compilation reussi"$(NO_COLOR)
endif

objdir:
	@if ! [ -d $(OBJDIR) ]; then\
		mkdir $(OBJDIR) $(LSTDIR);\
		fi

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN)"objets compile"$(NO_COLOR)

$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN)"library compile"$(NO_COLOR)

$(NAME)2: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	@echo $(GREEN)$(NAME)" a ete cree"$(NO_COLOR)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) cleanv

ifeq ($(shell find . -type f | grep "\.o"), )
cleanv:
	@echo $(GREEN)"les objets sont clean"$(NO_COLOR)
else
cleanv:
	@echo $(RED)"il ya probleme"
	@echo $(YELLOW)$(shell echo | find . -typr f | grep "\.o" | cat -e)
	make -d
endif

cl:
	@if [ "test" = "test" ]; then\
		echo "Hello world";\
		fi

auteur:
	@echo $(SPEUDO) > auteur
	@echo $(GREEN)"le fichier auteur a bien ete cree"$(NO_COLOR)

fclean: clean
	@rm -f $(NAME)
	@echo $(GREEN)"tout est clean"$(NO_COLOR)

re: fclean all

.PHONY: all clean fclean re cleanv anc
