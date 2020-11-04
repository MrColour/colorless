NAME = colorless
VERI_NAME = verify_main
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/

SRC_DIR = srcs/
BIN_DIR = bin/

# List of all the source files.
SRC_NAMES = \
	main \
	utils \

# List of all the source files, folders are to be added by
# including a $(addprefix, DIR_NAME, $(DIR_FILES))
FILE_NAMES = \
	$(SRC_NAMES) \

SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILE_NAMES)))
# Object files will be built to BIN_DIR. They will build the
# structure/ path tree that the SRC_DIR has.
OBJS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(BIN_DIR) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# These are the target object file names given by path ($(OBJS)).
# We will create the required directories with mkdir -p.
$(BIN_DIR)%.o: %.c
	mkdir -p $(BIN_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)$(SRC_DIR)$(VERI_NAME).o
	rm -f $(OBJS)

fclean: clean
	rm -rf $(VERI_NAME)
	rm -rf $(NAME)

# Ensure that when git add is done the repo is cleaned out.
save: fclean
	git add .
	git commit -m "$(MSG)"
	git push

re: fclean all

run:
	rm -f $(NAME)
	make all
	clear
	@echo "\033[1m\033[32m$(NAME)\033[0m"
	@./$(NAME)


OBJS_VERIFY = $(filter-out $(BIN_DIR)$(SRC_DIR)main.o, $(OBJS))
OBJS_VERIFY += $(BIN_DIR)$(SRC_DIR)$(VERI_NAME).o

verify: $(BIN_DIR) $(OBJS_VERIFY)
	gcc $(FLAGS) $(INCLUDES) -o $(VERI_NAME) $(OBJS_VERIFY)
