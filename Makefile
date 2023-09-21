NAME		= libftprintf.a

SRC_DIR		:= srcs
INC_DIR		:= includes
LIBFT_DIR	:= libft

MAIN_SRCS	= ft_flags_bonus.c \
			ft_flags_pad_utils.c \
			ft_format_addr.c \
			ft_format_char.c \
			ft_format_hex.c \
			ft_format_int.c \
			ft_format_string.c \
			ft_format_uint.c \
			ft_printf.c \
			ft_print_utils.c \
			ft_utils.c \
			ft_utoa.c \
			ft_utox.c
MAIN_OBJS	= ${MAIN_SRCS:.c=.o}
LIBFT_OBJS	:= $(LIBFT_DIR)/*.o	

# Define the compiler and related tools
CC			= cc
AR			= ar
RM			= rm -f

# Define flags
CFLAGS		= 
ARFLAGS		= -crs

CFLAGS		+= -I$(INC_DIR) -I$(LIBFT_DIR)

$(NAME):	$(MAIN_OBJS)
			@make -C $(LIBFT_DIR) bonus
			@cp $(LIBFT_DIR)/*.a $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(MAIN_OBJS) $(LIBFT_OBJS)

%.o: $(SRC_DIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

bonus:		all

clean:
			@make -C $(LIBFT_DIR) clean
			$(RM) $(BUILD_DIR)/*.o

fclean:		clean
			@make -C $(LIBFT_DIR) fclean
			$(RM) $(NAME)

re:			fclean all

# Define phony targets to avoid conflicts with file names
.PHONY:		all bonus clean fclean re