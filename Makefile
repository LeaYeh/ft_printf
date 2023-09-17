NAME		= libftprintf.a

SRC_DIR		:= srcs
INC_DIR		:= includes
LIBFT_DIR	:= libft
BUILD_DIR	:= build

MAIN_SRCS	:= $(wildcard $(SRC_DIR)/*.c)
BONUS_SRCS	:= $(wildcard $(SRC_DIR)/*_bonus.c)
MAIN_OBJS	:= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(MAIN_SRCS))
BONUS_OBJS	:= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(BONUS_SRCS))
LIBFT_OBJS	:= $(LIBFT_DIR)/*.o	

# Define the compiler and related tools
CC			= cc
AR			= ar
RM			= rm -f

# Define flags
CFLAGS		= -Wall -Wextra -Werror
ARFLAGS		= -crs

CFLAGS		+= -I$(INC_DIR) -I$(LIBFT_DIR)

$(NAME):	$(MAIN_OBJS)
			@make -C $(LIBFT_DIR) bonus
			@cp $(LIBFT_DIR)/*.a $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(MAIN_OBJS) $(LIBFT_OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

bonus:		all
			@if [ -n "$(BONUS_OBJS)" ]; then \
				echo "Bonus objects found: $(BONUS_OBJS)"; \
				$(AR) -rs $(NAME) $(BONUS_OBJS); \
			else \
				echo "No bonus objects found. Skipping."; \
			fi

clean:
			@make -C $(LIBFT_DIR) clean
			$(RM) $(BUILD_DIR)/*.o

fclean:		clean
			@make -C $(LIBFT_DIR) fclean
			$(RM) $(NAME)

re:			fclean all

test:		re
			$(CC) test.c -L . -lftprintf $(CFLAGS) -g -o runner.out
			@./runner.out

# Define phony targets to avoid conflicts with file names
.PHONY:		all bonus clean fclean re