# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 20:34:09 by aeid              #+#    #+#              #
#    Updated: 2024/01/19 16:20:46 by aeid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC			=	cc -g
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

HEADER_SRC	=	pipex.h pipex_bonus.h get_next_line.h
HEADER_DIR	=	Headers/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRC))

M_SRCS		=	child_processes.c errors.c free_process.c pipex.c
M_DIR		=	Mandatory/
M_PATH		=	$(addprefix $(M_DIR), $(M_SRCS))
M_OBJ		=	$(M_PATH:.c=.o)

B_SRCS		=	child_processes_bonus.c errors_bonus.c free_process_bonus.c\
				here_doc_bonus.c open_files_bonus.c pipex_bonus.c
B_DIR		=	Bonus/
B_PATH		=	$(addprefix $(B_DIR), $(B_SRCS))
B_OBJ		=	$(B_PATH:.c=.o)

U_SRCS		=	ft_split.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_substr.c
U_DIR		=	Utils/
U_PATH		=	$(addprefix $(U_DIR), $(U_SRCS))
U_OBJ		=	$(U_PATH:.c=.o)

G_SRCS		=	get_next_line.c get_next_line_utils.c
G_DIR		=	Get_next_line/
G_PATH		=	$(addprefix $(G_DIR), $(G_SRCS))
G_OBJ		=	$(G_PATH:.c=.o)

%.o: %.c $(HEADER) Makefile
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(U_OBJ) $(M_OBJ)
				@$(CC) $(M_OBJ) $(U_OBJ) -o $(NAME)

all: $(NAME)

bonus: $(U_OBJ) $(G_OBJ) $(B_OBJ)
				@$(CC) $(G_OBJ) $(U_OBJ) $(B_OBJ) -o $(NAME)

clean:
		$(RM) $(M_OBJ)
		$(RM) $(B_OBJ)
		$(RM) $(U_OBJ)
		$(RM) $(G_OBJ)

fclean: clean
		$(RM) $(NAME)
		
re: fclean all

.PHONY: all clean fclean re