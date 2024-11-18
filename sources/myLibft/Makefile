# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 15:19:22 by ghambrec          #+#    #+#              #
#    Updated: 2024/11/18 17:42:00 by ghambrec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------- MAIN ---------- #
NAME = libft.a
CC = cc
AR = ar
INCLUDE_DIR = ./include
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

# ---------- SOURCES ---------- #
VPATH = ./libft ./printf ./gnl
SOURCE_LIBFT = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SOURCE_PRINTF = ft_libft_utils.c ft_print_hex_nbr.c ft_print_nbr.c ft_print_str.c ft_print_unsigned_nbr.c ft_print_voidptr.c ft_printf.c
SOURCE_GNL = get_next_line.c get_next_line_utils.c

# ---------- OBJECTS ---------- #
OBJECT_DIR = objects
SOURCES = $(SOURCE_LIBFT) $(SOURCE_PRINTF) $(SOURCE_GNL)
OBJECTS = $(addprefix $(OBJECT_DIR)/, $(SOURCES:.c=.o))

# ---------- COLORS AND STUFF ---------- #
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
CYAN = \033[0;36m
NC = \033[0m
CLEAR_LINE = \033[2K\r

TOTAL_SRCS = $(words $(SOURCES))
CURRENT = 0

# ---------- RULES ---------- #

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)\nArchiving $(NAME)$(NC)"
	@$(AR) rcs $(NAME) $(OBJECTS)
	@if [ -f $(NAME) ]; then \
		echo "$(CYAN)--------------------------------------$(NC)"; \
		echo "$(GREEN)BUILD PROCESS COMPLETED SUCCESSFULLY!$(NC)"; \
		echo "$(CYAN)--------------------------------------$(NC)"; \
	else \
		echo "$(RED)$(NAME) failed to compile$(NC)"; \
	fi

$(OBJECT_DIR)/%.o: %.c | $(OBJECT_DIR)
	@$(eval CURRENT := $(shell echo $$(($(CURRENT) + 1))))
	@$(eval PERCENT := $(shell echo $$(($(CURRENT) * 100 / $(TOTAL_SRCS)))))
	@printf "$(CLEAR_LINE)$(YELLOW)Compiling $(PERCENT)%% [$(CURRENT)/$(TOTAL_SRCS)] $(CYAN)$<$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJECT_DIR):
	@echo "$(YELLOW)Creating $(OBJECT_DIR) directory$(NC)"
	@mkdir -p $(OBJECT_DIR)

clean:
	@echo "$(RED)Cleaning object files$(NC)"
	@rm -rf $(OBJECT_DIR)

fclean: clean
	@echo "$(RED)Removing $(NAME)$(NC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
