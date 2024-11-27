# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 18:50:52 by ghambrec          #+#    #+#              #
#    Updated: 2024/11/27 15:02:23 by ghambrec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------- MAIN ---------- #
NAME = push_swap
CC = cc
INCLUDE_DIR = ./include
LIBFT_DIR = ./sources/myLibft
LIBFT_NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

# ---------- SOURCES ---------- #
VPATH = ./sources
SOURCES = main.c parsing.c list_operations.c psl_swap.c psl_push.c psl_rotate.c psl_reverse_rotate.c sort_max_3.c sort.c

# ---------- OBJECTS ---------- #
OBJECT_DIR = objects
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

$(NAME): $(LIBFT_NAME) $(OBJECTS)
	@echo "$(YELLOW)\nCompiling $(NAME)$(NC)"
	@cc $(CFLAGS) $(OBJECTS) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME)
	@if [ -f $(NAME) ]; then \
		echo "$(CYAN)--------------------------------------$(NC)"; \
		echo "$(GREEN)BUILD PROCESS COMPLETED SUCCESSFULLY!$(NC)"; \
		echo "$(CYAN)--------------------------------------$(NC)"; \
	else \
		echo "$(RED)failed to compile $(NAME)$(NC)"; \
		exit 1; \
	fi

# test rule for faster testing (without compiling myLibft again)
test: $(OBJECTS)
	@echo "$(YELLOW)\nCompiling $(NAME)$(NC)"
	@cc $(CFLAGS) $(OBJECTS) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME)
	@if [ -f $(NAME) ]; then \
		echo "$(CYAN)--------------------------------------$(NC)"; \
		echo "$(GREEN)BUILD PROCESS COMPLETED SUCCESSFULLY!$(NC)"; \
		echo "$(CYAN)--------------------------------------$(NC)"; \
	else \
		echo "$(RED)failed to compile $(NAME)$(NC)"; \
		exit 1; \
	fi

# exec test without flags
testnf: CFLAGS = -I $(INCLUDE_DIR)
testnf: test
	
$(LIBFT_NAME):
	@echo "$(YELLOW)Creating $(LIBFT_NAME)$(NC)"
	@make re -C $(LIBFT_DIR) > $(LIBFT_DIR)/make_log.txt
	@if [ -f $(LIBFT_DIR)/$(LIBFT_NAME) ]; then \
		echo "$(GREEN)$(LIBFT_NAME) successfully created$(NC)"; \
	else \
		echo "$(RED)failed to compile $(LIBFT_DIR)$(NC)"; \
		exit 1; \
	fi

$(OBJECT_DIR)/%.o: %.c | $(OBJECT_DIR)
	@$(eval CURRENT := $(shell echo $$(($(CURRENT) + 1))))
	@$(eval PERCENT := $(shell echo $$(($(CURRENT) * 100 / $(TOTAL_SRCS)))))
	@printf "$(CLEAR_LINE)$(YELLOW)Compiling $(PERCENT)%% [$(CURRENT)/$(TOTAL_SRCS)] $(CYAN)$<$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

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

.PHONY: all clean fclean re test testnf
