# ****************************************************************************#
#                                                                             #
#                                                #   # #### #### ####         #
#    Makefile                                    #   # #  # #    #            #
#                                                #   # #### ###  #            #
#    By: Z. Safiy Errahmane                      #   # #    #    #            #
#                                                 ###  #    #### ####         #
#    Created: 2017/13/03 11:05:30 by Z.Safiy                                  #
#    Updated: 2017/14/03 09:27:30 by Z.Safiy                                  #
#                                                                             #
#*****************************************************************************#


NAME := game

TERMINAL_FT_PATH := terminal_ft/
TERMINAL_FT_SRC := changemode kbhit 

MAP_FT_PATH := map_ft/
MAP_FT_SRC := map_xy map_init

LOADING_FT_PATH := loading_ft/
LOADING_FT_SRC := 

FILES = game

#----------------MODIF--------------------#

#----------------STD--------------------#
COMPILER := gcc

SRC_PATH := src/

HDR_PATH := includes/

CACHE_PATH := cache/

INCF = -I $(HDR_PATH)

CFLAGS = -g -W -Wall -Werror -Wextra  $(INCF)

#----------------STD--------------------#

#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#
FILES+=$(addprefix $(TERMINAL_FT_PATH),$(TERMINAL_FT_SRC))
FILES+=$(addprefix $(MAP_FT_PATH),$(MAP_FT_SRC))
FILES+=$(addprefix $(LOADING_FT_PATH),$(LOADING_FT_SRC))

SRC = $(addprefix $(SRC_PATH),$(addsuffix .c,$(FILES)))
OBJ = $(addprefix $(CACHE_PATH),$(addsuffix .o,$(FILES)))
#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#

#-----------------COLORS------------------#
#-------B = Bold---------#
#-------I = Intense------#
#-------U = Underline----#
Green	:= "\033[0;32m"
Red		:= "\033[1;91m"
Yellow	:= "\033[0;33m"
CYAN	:= "\033[1;36m"
YELLOW	:= "\033[1;33m"
END 	:= "\033[0m"
#-----------------COLORS------------------#

CACHE:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ) $(LIB_PATH)
		@echo $(Yellow)" Compiling -->"$(CYAN)"SPACE INVADERS"$(END)$(Yellow)"<-- with $(CFLAGS) " $(END)
		@$(COMPILER) $(OBJ) -o $@ $(INCF)
		@echo $(Green) " !!! Ready !!! EXECUTE WITH :"$(END) $(YELLOW)" ./go" $(END)

$(CACHE_PATH)%.o:$(SRC_PATH)%.c | $(CACHE)
		@echo $(Green) "Creating "$(Red)"the $(NAME)"$(END) $(Green)" : $@ with $< " $(END);
		@$(COMPILER) $(CFLAGS) -o $@ -c $<

%.c:
	@echo $(Red) "Missing file : $@" $(END)

$(CACHE):
	@mkdir -p $(CACHE_PATH)
	@mkdir -p $(CACHE_PATH)$(TERMINAL_FT_PATH)
	@mkdir -p $(CACHE_PATH)$(MAP_FT_PATH)
	@mkdir -p $(CACHE_PATH)$(LOADING_FT_PATH)

clean:
		@/bin/rm -rf $(CACHE_PATH)
		@/bin/rm -rf $(CACHE)
		@echo $(Red) "Deleting ---->>>> $(CACHE_PATH)" $(END)
fclean: clean
		@/bin/rm -rf $(NAME)
		@echo $(Red) "Deleting ---->>>> $(NAME)" $(END)
re: fclean all

norm:
		@echo $(Red)
		@norminette $(SRC) $(HDR_PATH) | grep -v Norme -B1 || true
		@echo $(END)

libft/libft.a:
		@echo $(CYAN) "Making $@" $(EOC)
		@make -C libft/
		@make -C libft clean
test:
		@echo $(YELLOW)"Files :\n\033[0;33m"$(HDR_PATH)
		@echo $(BLUE)"Objects :\n\033[0;34m"$(OBJ)
		@echo $(CYAN)"Sources :\n\033[0;36m"$(SRC)

.PHONY: all clean fclean re