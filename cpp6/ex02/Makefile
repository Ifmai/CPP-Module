NAME = Type
SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp identify.cpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): Base.hpp A.hpp B.hpp C.hpp
	c++ $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all