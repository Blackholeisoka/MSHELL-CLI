# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: blackholeisoka <marvin@d42.fr>             +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2026/09/03 19:47:27 by blackholeisok     #+#    #+#             #
#   Updated: 2026/09/03 19:47:27 by blackholeisok    ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

CC = cc
HEADERS = ./includes
FLAGS = -Wall -Wextra -Werror -g -I$(HEADERS)
SOURCES = $(wildcard ./srcs/*.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET = mshell

.DEFAULT: all

.PHONY: help all clean fclean re

all: $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

help:
	@echo ""
	@echo "  mshell — available targets"
	@echo ""
	@echo "  make         - build the project"
	@echo "  make help    - show this message"
	@echo "  make clean   - remove object files"
	@echo "  make fclean  - remove objects and binary"
	@echo "  make re      - rebuild from scratch"
	@echo ""

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all
