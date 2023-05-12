# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 09:39:09 by alde-fre          #+#    #+#              #
#    Updated: 2022/11/25 09:39:09 by alde-fre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 3D

# directories
SRCDIR	=	./src
INCDIR	=	-I ./inc
OBJDIR	=	./obj

# src / includes / obj files
SRC		= main.c drawing.c vec3.c vec3_rot.c

INC		=	

OBJ		=	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))

DEPENDS :=	$(patsubst %.o,%.d,$(OBJ))
-include $(DEPENDS)

# compiler
CC		= clang
CFLAGS	= -MMD -MP -Wall -Wextra -Werror

# engine library
ENGINE		= ./engine/
ENGINE_LIB	= $(addprefix $(ENGINE),libengine.a)
ENGINE_INC	= -I ./engine/inc
ENGINE_LNK	= -l Xext -l X11 -L ./engine -l engine

all: obj $(ENGINE_LIB) $(NAME)

raw: CFLAGS += -O0
raw: obj $(ENGINE_LIB) $(NAME)

fast: CFLAGS += -Ofast
fast: obj $(ENGINE_LIB) $(NAME)

debug: CFLAGS += -g3
debug: obj $(ENGINE_LIB) $(NAME)

obj:
	@rm -rf .print_rule
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	@echo "\e[1;35mLinking...\e[0m"
	$(CC) -o $(NAME) $+ $(ENGINE_LNK) -lm
	@echo "\e[1;32m➤" $@ "created succesfully !\e[0m"

.print_rule:
	@> $@
	@echo "\e[1;36mCompiling...\e[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c .print_rule
	@echo "\e[0;36m ↳\e[0;36m" $< "\e[0m"
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCDIR) $(ENGINE_INC) -c $< -o $@

$(ENGINE_LIB):
	@make -C $(ENGINE)

clean:
	rm -rf $(OBJDIR)
	make -C $(ENGINE) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(ENGINE) fclean

re: fclean all

.PHONY: all clean fclean re
