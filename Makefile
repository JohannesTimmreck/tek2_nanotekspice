##
## EPITECH PROJECT, 2019
## bootstrap_NanoTekSpice
## File description:
## Makefile
##

SRC =   src/Components/AndGate.cpp	\
		src/Components/Clock.cpp	\
		src/Components/Component.cpp	\
		src/Components/False.cpp	\
		src/Components/Input.cpp	\
		src/Components/OrGate.cpp	\
		src/Components/Output.cpp	\
		src/Components/True.cpp	\
		src/Components/NandGate.cpp	\
		src/Components/NorGate.cpp	\
		src/Components/NotGate.cpp	\
		src/Components/XnorGate.cpp	\
		src/Components/XorGate.cpp	\
		src/Circuits/Circuit.cpp	\
		src/Circuits/C4071.cpp	\
		src/Circuits/C4001.cpp	\
		src/Circuits/C4011.cpp	\
		src/Circuits/C4081.cpp	\
		src/Circuits/C4030.cpp	\
		src/Circuits/C4069.cpp	\
		src/Parser.cpp	\
		src/main.cpp	\

OBJ =   $(SRC:.cpp=.o)

NAME    =	nanotekspice

CXX =   g++

CXXFLAGS    =   -W -Wall -Werror -Wextra -g

all:    $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
