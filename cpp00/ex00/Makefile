NAME = megaphone
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)

re: fclean all

nils: fclean
	cd ..
	git add .
	git commit -m "$(m)"
	git push

.PHONY: all clean fclean re nils