# Name of the programs built
NAME				:=		so_long

# Paths
PATH_SRC			:=		src
PATH_BUILD			:=		build
PATH_LIBS			:=		libs
PATH_LIBFT			:=		$(PATH_LIBS)/libft
PATH_LIBMLX_MAC		:=		$(PATH_LIBS)/minilibx_opengl_20191021
PATH_LIBMLX_LINUX	:=		$(PATH_LIBS)/minilibx-linux

# Sources 
# SRCS:		Find all the C files inside 'src' to be compiled
# OBJS:		Convert C files into binary and store in the 'build' folder
# DEPS:		Convert binary into dependency files
# INC_DIRS:	Find all dependency files in 'src' 
SRCS				:=		$(shell find $(PATH_SRC) -name *.c)
OBJS				:=		$(SRCS:%.c=$(PATH_BUILD)/%.o)
DEPS				:=		$(OBJS:.o=.d)
INC_DIRS			:=		$(shell find $(PATH_SRC) -type d)

# Compiler
CC					:=		gcc

# Flags - compilation
FLAG_WARNING		:=		-Wall -Wextra -Werror
FLAG_INC			:=		$(addprefix -I, $(INC_DIRS))
FLAG_MAKEFILE		:=		-MMD -MP
FLAG_DEBUG			:=		-g
FLAGS_COMP			:=		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_MAKEFILE) $(FLAG_DEBUG)

# Flags - memory leak check
FLAG_MEM_LEAK		:=		fsanitize=address

# Flags - linking
FLAG_LIBFT			:=		-L$(PATH_LIBFT) -lft
FLAG_LIBMLX_MAC		:=		-L$(PATH_LIBMLX_MAC) -lmlx -framework OpenGL -framework AppKit -lz
#FLAG_LIBMLX_LINUX	:=		-L$(PATH_LIBMLX_LINUX) -lmlx -lX11 -lbsd -lXext
ifeq ($(OS),)
		FLAGS_LINKING	:=	-lm $(FLAG_LIBFT) $(FLAG_LIBMLX_MAC)
else
		FLAGS_LINKING	:=	-lm $(FLAG_LIBFT) $(FLAG_LIBMLX_LINUX)
		OS_DEFINE			:=			-D OS=$(OS)
endif

# Other Commands
RM				:=			rm -rf

# Color code and template code
_YELLOW			:=			\e[38;5;184m
_GREEN			:=			\e[38;5;46m
_RESET			:=			\e[0m
_INFO			:=			[$(_YELLOW)INFO$(_RESET)]
_SUCCESS		:=			[$(_GREEN)SUCCESS$(_RESET)]

# General functions
all:						init $(NAME)
							@ echo "$(_SUCCESS) Compilation done"

init:						
							@ echo "$(_INFO) Initialize $(NAME)"
							@ make -C $(PATH_LIBFT)
ifeq ($(OS),)
	@ make -C $(PATH_LIBMLX_MAC)
else
	@ make -C $(PATH_LIBMLX_LINUX)
endif

$(NAME):					$(OBJS)
							$(CC) $(FLAGS_COMP) -o $@ $(OBJS) $(FLAGS_LINKING)

$(PATH_BUILD)/%.o:	%.c
							mkdir -p $(dir $@)
							$(CC) $(FLAGS_COMP) -c $< -o $@ $(OS_DEFINE)

bonus:						all

clean:						
							@ $(RM) $(PATH_BUILD)
							@ make -C $(PATH_LIBFT) clean
							@ make -C $(PATH_LIBMLX_MAC) clean
							@ make -C $(PATH_LIBMLX_LINUX) clean
							@ echo "$(_INFO) Deleted files and directory"

fclean:						clean
							@ $(RM) $(NAME)
							@ make -C $(PATH_LIBFT) fclean

re:							fclean all

# Debugging functions

debug:						FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:						FLAGS_LINKING += $(FLAG_MEM_LEAK)
debug: 						re

# Format functions

normH:						norminette $(shell find $(PATH_SRC) -name *.h)
							@ make -C $(PATH_LIBFT) normH

normC:						norminette $(SRCS)
							@ make -C $(PATH_LIBFT) normC

norm:						normH normC

.PHONY:						all clean fclean re

-include $(DEPS)