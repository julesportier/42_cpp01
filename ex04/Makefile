###########
# ALIASES #
###########
MAKE := make
CXX := c++

#########
# FLAGS #
#########
STDFLAGS := -std=c++98
WARNINGS := -Wall -Werror -Wextra
CXXFLAGS := $(STD_FLAGS) $(WARNINGS)
DEPFLAGS := -MMD

#########
# FILES #
#########
SRC_DIR := src
TEST_DIR := test
vpath %.cpp $(SRC_DIR):$(TEST_DIR)
BUILD_DIR := build

NAME := sed++
SRC := FileBuf.cpp \
	   main.cpp
OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)

NAME_TEST := test-$(NAME)
SRC_TEST := test.cpp $(filter-out main.cpp,$(SRC))
OBJ_TEST := $(SRC_TEST:%.cpp=$(BUILD_DIR)/%.o)

DEP_FILES := $(OBJ:.o=.d) $(OBJ_TEST:.o=.d)

###########
# TARGETS #
###########
.PHONY: all test clean fclean re

all: $(BUILD_DIR) $(NAME)
test: $(BUILD_DIR) $(NAME_TEST)

# Only print a message if actually removing files/folders
rm_wrapper = rm -r $(1) 2>/dev/null && echo $(2) || true
clean:
	@$(call rm_wrapper,$(BUILD_DIR),"remove $(BUILD_DIR)/")
fclean: clean
	@$(call rm_wrapper,$(NAME),"remove $(NAME)")
	@$(call rm_wrapper,$(NAME_TEST),"remove $(NAME_TEST)")

re: fclean all

-include $(DEP_FILES)

#########
# RULES #
#########
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(NAME_TEST): $(OBJ_TEST)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir $@
