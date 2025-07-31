###########
# ALIASES #
###########
CXX = c++

#########
# FLAGS #
#########
STD_FLAGS :=	-std=c++98
WARNINGS :=		-Wall -Werror -Wextra
CXXFLAGS :=		$(STD_FLAGS) $(WARNINGS)
CXXFLAGS_DB :=	$(STD_FLAGS) $(WARNINGS) -g3
CXXFLAGS_AS :=	$(STD_FLAGS) $(WARNINGS) -g3 \
				-fsanitize=address
CFLAGS_MUS :=	$(STD_FLAGS) $(WARNINGS) -g3 \
				-fsanitize=memory \
				-fsanitize=undefined
CXXFLAGS_NE :=	$(STD_FLAGS) -Wall -Wextra -g3
CXXFLAGS_REL :=	$(STD_FLAGS) $(WARNINGS) -O2
DEP_FLAGS := 	-MMD

#########
# FILES #
#########
NAME := hi_brainz

SRC :=	main.cpp

BUILD_DIR := build
OBJ := $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

DEP_FILES := $(OBJ:.o=.d)

###########
# TARGETS #
###########
all: $(BUILD_DIR) $(NAME)

dbg: CXXFLAGS = $(CXXFLAGS_DB)
dbg: all

noerr: CXXFLAGS = $(CXXFLAGS_NE)
noerr: all

asan: CXXFLAGS = $(CXXFLAGS_AS)
asan: CXX = clang++
asan: all

musan: CXXFLAGS = $(CXXFLAGS_MUS)
musan: CXX = clang++
musan: all

rel: CXXFLAGS = $(CXXFLAGS_REL)
rel: all

clean:
	rm -rf $(BUILD_DIR)

fclean:
	rm -rf $(BUILD_DIR)
	rm -f $(NAME)

re: fclean all

-include $(DEP_FILES)

#########
# RULES #
#########
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) $(DEP_FLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

.PHONY: all clean fclean re noerr dbg asan musan rel
