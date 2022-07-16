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
							strncpy.c									\
							strndup.c									\
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

# List of all .o
OBJS				:=		$(addprefix $(OBJ_DIR)/,\
								$(addsuffix .o,\
									$(basename $(patsubst %,%,$(SRC)))\
								)\
							)

SRC					:=		$(addprefix $(SRC_DIR)/,$(SRC))

###################
## Test
###################

TTARGET				:=		bin_test

T_DIR				:=		tests

T_SRC				:=		$(shell find $(T_DIR)/ -name '*.c' -type f)

T_OBJ				:=		$(T_SRC:.c=.o)

TFLAGS				:=		-fprofile-arcs -ftest-coverage

CR_TEST_LDFLAGS		:=		-lcriterion -lgcov

#######################################
#### Rules
#######################################

all:						$(TARGET)

$(TARGET):					$(OBJS)
	ar rc $(TARGET) $(OBJS)
	ranlib $(TARGET)

$(OUT_DIRS):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OUT_DIRS)

show:
	@$(ECHO) $(GREEN)"-> ECHO ->"$(RESET)
	@$(ECHO) $(ECHO)
	@$(ECHO) $(GREEN)"-> SRC ->"$(RESET)
	@$(ECHO) $(SRC)
	@$(ECHO) $(GREEN)"-> OBJS ->"$(RESET)
	@$(ECHO) $(OBJS)
	@$(ECHO) $(GREEN)"-> TSRC ->"$(RESET)
	@$(ECHO) $(T_SRC)
	@$(ECHO) $(GREEN)"-> TOBJ ->"$(RESET)
	@$(ECHO) $(T_OBJ)
	@$(ECHO) $(GREEN)"-> OUT_DIRS ->"$(RESET)
	@$(ECHO) $(OUT_DIRS)
	@$(ECHO) $(GREEN)"-> TO_CLEAN_EXT ->"$(RESET)
	@$(ECHO) $(TO_CLEAN_EXT)
	@$(ECHO) $(GREEN)"-> TO_CLEAN ->"$(RESET)
	@$(ECHO) $(TO_CLEAN)

clean:
	$(RM) $(OBJS) $(T_OBJ)
	$(RM) $(TO_CLEAN)

fclean:						clean
	$(RM) $(TARGET) $(TTARGET)

re:							fclean all

tests_run:					CFLAGS	+=	$(TFLAGS)
tests_run:					LDFLAGS	+=	$(CR_TEST_LDFLAGS)
tests_run:					$(OBJS) $(T_OBJ)
	@$(CC) $(OBJS) $(T_OBJ) -o $(TTARGET) $(LDFLAGS)
	./$(TTARGET)
	gcovr --exclude tests || true
	gcovr --exclude tests --branch || true
	@$(RM) $(OBJS)
	true

#######################################
#### Conversion Rules
#######################################

# .c -> .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OUT_DIRS)
	@$(CC) -c $< -o $@ $(CFLAGS)
	@$(ECHO) $(BLUE)'[compil]: '$(CYAN)'$< '$(RESET)'-> '$(CYAN)'$@'$(RESET)

$(T_DIR)/%.c: $(T_DIR)/%.o
	@$(CC) -c $< -o $@ $(CFLAGS)
	@$(ECHO) $(BLUE)'[compil]: '$(CYAN)'$< '$(RESET)'-> '$(CYAN)'$@'$(RESET)
