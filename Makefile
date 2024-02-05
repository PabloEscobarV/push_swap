# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 12:43:58 by polenyc           #+#    #+#              #
#    Updated: 2024/02/05 14:29:13 by polenyc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FILES = arr_sort.c dlist.c element_sort.c push_swap.c push.c rotate.c rrotate.c \
	swap.c sandytimes.c scatter.c trivial_sort.c \
	
TEST = test_onedata.c

SRCDIR = src
OBJDIR = $(SRCDIR)/objs

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(SRC:$(SRCDIR)%.c=$(OBJDIR)/%.o)

FTPOWDIR = ft_pow
FTPRINTFDIR = ft_printf
GNLDIR = get_next_line
SORTADIR = sorts_alg

FTPOW = ftpow
FTPRINTF = ftprintf
GNL = get_next_line
SORTA = sortsalg

CC = gcc
CFLAGSO = -c -Wall -Wextra -Werror
LFTPRINTF = -L$(FTPRINTFDIR) -l$(FTPRINTF)
LFTPOW = -L$(FTPOWDIR) -l$(FTPOW)
LGNL = -L$(GNLDIR) -l$(GNL)
LSORTA = -L$(SORTADIR) -l$(SORTA)

.PHONY: all clean fclean re re_bonus

all: $(NAME)
  
$(NAME): $(OBJ) $(FTPOW) $(FTPRINTF) $(GNL) $(SORTA)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGSO) $< -o $@

$(FTPOW):
	$(MAKE) -C $(FTPOWDIR)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTFDIR) bonus

$(GNL):
	$(MAKE) -C $(GNLDIR) bonus

$(SORTA):
	$(MAKE) -C $(SORTADIR)

clean:
	$(MAKE) -C $(FTPOWDIR) clean
	$(MAKE) -C $(FTPRINTFDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(MAKE) -C $(SORTADIR) clean
	rm -rf $(OBJDIR)

fclean: re
	$(MAKE) -C $(FTPOWDIR) fclean
	$(MAKE) -C $(FTPRINTFDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(SORTADIR) fclean
	rm -f $(NAME)

re: fclean all



	