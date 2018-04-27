
.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = lem-in

D_SRC = Srcs/

D_OBJ = Objets/

DIR_LIBFT = Libft/Sources/

DIR_PRINTF = Libft/Sources/Ft_printf/

SRC_AU = aurollan_algo.c \
		aurollan_loop.c \
		aurollan_refresh_hive.c \
		aurollan_sort_path.c \
        check_error.c \
        check_room.c \
        check_tube.c \
        clear_roaming.c \
        create_room.c \
		create_structure.c \
		create_tube.c \
		free_init.c \
		hive.c \
		main.c

LIBFT = ft_atoi.c \
	    ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strjoin_free.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strrev.c \
		ft_itoa_base.c \
		ft_strrev_free.c \
		get_next_line.c \
		ft_atoi_maxint.c \
		ft_swap.c

PRINTF = path_i_d.c \
		path_i_d2.c \
	    path_i_d3.c \
		path_i_d4.c \
		path_i_d5.c \
		path_c.c \
		path_c2.c \
		path_c3.c \
		path_o.c \
		path_o2.c \
		path_o3.c \
		path_o4.c \
		path_o5.c \
		path_p.c \
		path_s.c \
		path_s2.c \
		path_u.c \
		path_x.c \
		path_x2.c \
		path_x3.c \
		path_x4.c \
		path_e.c \
		char.c \
		hexa.c \
		octal.c \
		putnbr.c \
		wchar.c \
		wchar2.c \
		printf.c \
		printf2.c \
		printf3.c \
		struct.c \
		struct2.c



OBJ = $(addprefix $(D_OBJ), $(SRC_AU:.c=.o)) $(addprefix $(D_OBJ), $(LIBFT:.c=.o)) $(addprefix $(D_OBJ), $(PRINTF:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
			@echo "\033[33;32m=== Compilation de lem-in...\t\t\tDONE"

$(D_OBJ)%.o: $(D_SRC)%.c Includes/lem_in.h
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	@mkdir -p $(D_OBJ)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(D_OBJ)%.o: $(DIR_LIBFT)%.c Libft/Includes/libft.h
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	@mkdir -p $(D_OBJ)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(D_OBJ)%.o: $(DIR_PRINTF)%.c Libft/Includes/libft.h
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	@mkdir -p $(D_OBJ)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
			@rm -rf $(D_OBJ)

fclean: clean
			@rm -f $(NAME)

re: fclean all
