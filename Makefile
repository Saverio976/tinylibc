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

CFLAGS				:=		-Wall \
							-Wextra \
							-Wpedantic \
							-Wdouble-promotion \
							-Wformat=2 \
							-Wformat-overflow=2 \
							-Wformat-truncation=2 \
							-Wnull-dereference \
							-ftabstop=4 \
							-Wmissing-include-dirs \
							-Wreturn-local-addr \
							-Wunused \
							-Wunused-const-variable=2 \
							-Wsuggest-attribute=noreturn \
							-Wsuggest-attribute=const \
							-Wduplicated-branches \
							-Wduplicated-cond \
							-Warray-bounds \
							-Wtrampolines \
							-Wshadow \
							-Wunsafe-loop-optimizations \
							-Wabsolute-value \
							-Wundef \
							-Wunused-macros \
							-Wbad-function-cast \
							-Wcast-align \
							-Wconversion \
							-Wdangling-else \
							-Wjump-misses-init \
							-Wmissing-prototypes \
							-Wnormalized=id \
							-Wredundant-decls \
							-Wnested-externs \
							-Wint-in-bool-context \
							-Wvla \
							-Wdisabled-optimization \
							-Wstack-protector \
							-fanalyzer \
							-O2 \
							-march=native \
							-mtune=native \
							-fdelete-null-pointer-checks \
							-I./includes/

###################
## SRC
###################

# Where .c file are
SRC_DIR				:=		src

SRC_CIRC_BUF_INF	:=		create.c									\
							destroy.c									\
							empty.c										\
							read.c										\
							read_multiple.c								\
							write.c
SRC_CIRC_BUF_INF	:=		$(addprefix circ_buf_inf/,$(SRC_CIRC_BUF_INF))

SRC_DICO			:=		add.c										\
							create.c									\
							delete.c									\
							get.c										\
							pop.c										\
							rem.c
SRC_DICO			:=		$(addprefix dico/,$(SRC_DICO))

SRC_FILESYSTEM		:=		fs_get_content.c							\
							fs_get_size.c								\
							fs_open_ronly.c
SRC_FILESYSTEM		:=		$(addprefix filesystem/,$(SRC_FILESYSTEM))

SRC_JSONC			:=		creator/create_empty_json.c					\
							creator/creator_add_any.c					\
							creator/creator_add_list.c					\
							creator/creator_add_number.c				\
							creator/creator_add_string.c				\
							get/get.c									\
							get/get_from_array.c						\
							parser/destroy_any.c						\
							parser/parse.c								\
							parser/parse_array.c						\
							parser/parse_array_is_empty.c				\
							parser/parse_dico.c							\
							parser/parse_dico_is_empty.c				\
							parser/parse_number.c						\
							parser/parse_string.c						\
							parser/parse_unknow.c						\
							printer/prety_print.c						\
							printer/print_dico.c						\
							printer/print_array.c						\
							printer/print_string.c						\
							printer/print_number.c						\
							writer/write_json.c
SRC_JSONC			:=		$(addprefix jsonc/,$(SRC_JSONC))

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
SRC_STDLIBS			:=		atod.c										\
							atod_err.c									\
							atof.c										\
							atof_err.c									\
							atoi.c										\
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
							strcontainc.c								\
							strcpy.c									\
							strdup.c									\
							strendswith.c								\
							strlen.c									\
							strncpy.c									\
							strndup.c									\
							strrev.c									\
							strsplit.c									\
							strstartswith.c								\
							strstr.c									\
							strstrip.c
SRC_STRINGS			:=		$(addprefix strings/,$(SRC_STRINGS))

# Lib for utils (includes/tlcutils.h)
SRC_UTILS			:=		free_char_2d.c								\
							free_ifnotnull.c							\
							return_void.c
SRC_UTILS			:=		$(addprefix utils/,$(SRC_UTILS))

# List of all .c
SRC					:=		$(SRC_CIRC_BUF_INF)							\
							$(SRC_DICO)									\
							$(SRC_FILESYSTEM)							\
							$(SRC_JSONC)								\
							$(SRC_LLISTS)								\
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
	$(RM) -r scripts/
	$(RM) -r tests/
	$(RM) -r examples/
	$(RM) -r man/
	$(RM) -r doxygen-awesome-css/
	$(RM) -r docs/
	$(RM) -r assets/
	$(RM) -r .github/
	$(RM) .gitmodules

doxygen:
	doxygen Doxyfile

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
