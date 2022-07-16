##############################################################################
##                                                                          ##
##                              (my) Tiny Lib C                             ##
##                                                                          ##
##############################################################################

#######################################
#### VARS
#######################################

# The lib path
TARGET				:=		tinylibc.a

# Command used to print ()
ECHO				:=		echo -e

# Dirty files
TO_CLEAN_EXT		:=		*.gcno *.gcda *~ *.swp
TO_CLEAN			:=		$(foreach EXT,$(TO_CLEAN_EXT),\
								$(shell find . -name "$(EXT)")\
							)

###################
## Colors
###################

CYAN				:=		'\033[1;36m'
BLUE				:=		'\033[1;34m'
GREEN				:=		'\033[1;32m'
RESET				:=		'\033[0m'

###################
## Flags
###################

CFLAGS				:=		-Wall -Wextra -Wpedantic -I./includes/

###################
## SRC
###################

# Where .c file are
SRC_DIR				:=		src

# Lib for string.h (includes/tlcstrings.h)
SRC_STRINGS			:=		strchr.c									\
							strcmp.c									\
							strcpy.c									\
							strdup.c									\
							strlen.c									\
							strsplit.c									\
							strstr.c									\
							strstrip.c
SRC_STRINGS			:=		$(addprefix strings/,$(SRC_STRINGS))

# Lib for stdlib.h (includes/tlcstdlibs.h)
SRC_STDLIBS			:=		calloc.c									\
							ccalloc.c
SRC_STDLIBS			:=		$(addprefix stdlibs/,$(SRC_STDLIBS))

# List of all .c
SRC					:=		$(SRC_STDLIBS)								\
							$(SRC_STRINGS)

###################
## OBJ
###################

# Where .o goes
OBJ_DIR				:=		obj

# Get all directorie
OUT_DIRS			:=		$(sort $(dir $(SRC)))
OUT_DIRS			:=		$(addprefix $(OBJ_DIR)/,$(OUT_DIRS))

# List of as:ll .o
OBJS				:=		$(addprefix $(OBJ_DIR)/,\
								$(addsuffix .o,\
									$(basename $(patsubst %,%,$(SRC)))\
								)\
							)

SRC					:=		$(addprefix $(SRC_DIR)/,$(SRC))

#######################################
#### Rules
#######################################

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rc $(TARGET) $(OBJS)
	ranlib $(TARGET)

$(OUT_DIRS):
	mkdir -p $(OUT_DIRS)

show:
	@$(ECHO) $(GREEN)"-> ECHO ->"$(RESET)
	@$(ECHO) $(ECHO)
	@$(ECHO) $(GREEN)"-> SRC ->"$(RESET)
	@$(ECHO) $(SRC)
	@$(ECHO) $(GREEN)"-> OBJS ->"$(RESET)
	@$(ECHO) $(OBJS)
	@$(ECHO) $(GREEN)"-> OUT_DIRS ->"$(RESET)
	@$(ECHO) $(OUT_DIRS)
	@$(ECHO) $(GREEN)"-> TO_CLEAN_EXT ->"$(RESET)
	@$(ECHO) $(TO_CLEAN_EXT)
	@$(ECHO) $(GREEN)"-> TO_CLEAN ->"$(RESET)
	@$(ECHO) $(TO_CLEAN)

clean:
	$(RM) $(OBJS)
	$(RM) $(TO_CLEAN)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

#######################################
#### Conversion Rules
#######################################

# .c -> .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OUT_DIRS)
	@$(CC) -c $< -o $@ $(CFLAGS)
	@$(ECHO) $(BLUE)'[compil]: '$(CYAN)'$< '$(RESET)'-> '$(CYAN)'$@'$(RESET)
