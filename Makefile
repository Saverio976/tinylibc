##
## EPITECH PROJECT, 2023
## TinyLibC
## File description:
## make
##

##############################################################################
##                                                                          ##
##                              (my) Tiny Lib C                             ##
##                                                                          ##
##############################################################################

#######################################
#### VARS
#######################################

# The lib path
TARGET				:=		libtinylibc.a

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

# Lib for list (includes/tlcllists.h)
SRC_LLISTS			:=		append.c									\
							create.c									\
							delete.c									\
							duplicate.c									\
							find.c										\
							index.c										\
							insert.c									\
							remove.c
SRC_LLISTS			:=		$(addprefix llists/,$(SRC_LLISTS))

# Lib for math.h (includes/tlcmaths.h)
SRC_MATHS			:=		max.c										\
							min.c										\
							pow.c										\
							sqrt.c
SRC_MATHS			:=		$(addprefix maths/,$(SRC_MATHS))

SRC_STDIOS			:=		printf.c									\
							putc.c										\
							puts.c										\
							sprintf.c									\
							utils/chars_specifier.c						\
							utils/nb_specifier.c						\
							utils/ptr_specifier.c
SRC_STDIOS			:=		$(addprefix stdios/,$(SRC_STDIOS))

# Lib for stdlib.h (includes/tlcstdlibs.h)
SRC_STDLIBS			:=		atoi.c										\
							atoi_base.c									\
							calloc.c									\
							ccalloc.c									\
							itoa.c										\
							itoa_base.c
SRC_STDLIBS			:=		$(addprefix stdlibs/,$(SRC_STDLIBS))

# Lib for string.h (includes/tlcstrings.h)
SRC_STRINGS			:=		memcpy.c									\
							strchr.c									\
							strcmp.c									\
							strcpy.c									\
							strdup.c									\
							strlen.c									\
							strncpy.c									\
							strndup.c									\
							strrev.c									\
							strsplit.c									\
							strstr.c									\
							strstrip.c
SRC_STRINGS			:=		$(addprefix strings/,$(SRC_STRINGS))

# Lib for utils (includes/tlcutils.h)
SRC_UTILS			:=		free_ifnotnull.c							\
							return_void.c
SRC_UTILS			:=		$(addprefix utils/,$(SRC_UTILS))

# List of all .c
SRC					:=		$(SRC_LLISTS)								\
							$(SRC_MATHS)								\
							$(SRC_STDIOS)								\
							$(SRC_STDLIBS)								\
							$(SRC_STRINGS)								\
							$(SRC_UTILS)

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

CR_TEST_LDFLAGS		:=		-lcriterion -lgcov -lm

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
tests_run:					fclean $(OBJS) $(T_OBJ)
	@$(CC) $(OBJS) $(T_OBJ) -o $(TTARGET) $(LDFLAGS)
	./$(TTARGET) || exit 1
	gcovr --exclude tests || true
	gcovr --exclude tests --branch || true
	@$(RM) $(OBJS)
	true

release:					fclean
	rm -rf scripts/
	rm -rf tests/
	rm -rf examples/
	rm -rf man/
	rm -rf doxygen-awesome-css/
	rm -rf docs/
	rm -rf assets/
	rm -rf .github/

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
