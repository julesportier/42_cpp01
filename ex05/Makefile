###########
# ALIASES #
###########
MAKE := make
CXX := c++

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
DEP_FLAGS := 	-MMD

#########
# FILES #
#########
NAME := harl

SRC_DIR := src
vpath %.cpp $(SRC_DIR)
SRC :=	main.cpp \
		Harl.cpp

BUILD_DIR := build
OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)

DEP_FILES := $(OBJ:.o=.d)

###########
# TARGETS #
###########
.PHONY: all clean fclean re dbg asan musan

all: $(BUILD_DIR) $(NAME)

dbg: CXXFLAGS = $(CXXFLAGS_DB)
dbg: all

asan: CXXFLAGS = $(CXXFLAGS_AS)
asan: CXX = clang++
asan: all
musan: CXXFLAGS = $(CXXFLAGS_MUS)
musan: CXX = clang++
musan: all

# Only print a message if actually removing files/folders
rm_wrapper = rm -r $(1) 2>/dev/null && echo $(2) || true
clean:
	@$(call rm_wrapper,$(BUILD_DIR),"remove $(BUILD_DIR)/")
fclean: clean
	@$(call rm_wrapper,$(NAME),"remove $(NAME)")

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
