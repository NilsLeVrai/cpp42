NAME = RPN
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

INCLUDES = -I ./includes/

SRC_DIR = .

SOURCES =  main.cpp \
			RPN.cpp
	
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean	
	rm -f $(NAME)

re: fclean all

nils: fclean
	cd ..
	git add .
	git commit -m "$(m)"
	git push

.PHONY: all clean fclean re nils