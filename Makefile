# Author: Eduardo Gobbo W.V.G
# Date 	: 10/2023

parametrosCompilacao=-Wall -I./includes#-Wshadow 
nomePrograma=main

.PHONY: tests clean

# Add a variable for the DNDBUG flag for build target
DNDBUG=-DNDBUG

SRCS = $(wildcard *.cpp src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(nomePrograma)

$(nomePrograma): $(OBJS)
	g++ -o $(nomePrograma) $(OBJS) $(parametrosCompilacao)

# %.o: %.cpp
$(OBJS): %.o : %.cpp
	g++ -c $< -o $@ $(parametrosCompilacao)

# build target compiles with the DNDBUG flag
build: $(OBJS)
	g++ -o $(nomePrograma) $(OBJS) $(parametrosCompilacao) $(DNDBUG)

run: $(nomePrograma)
	./$(nomePrograma)

DONT_TEST=tests/test_chalk.cpp tests/test_craft.cpp tests/test_material.cpp tests/test_warehouse.cpp tests/test_market.cpp
tests: $(OBJS)
	@for t in $(filter-out $(DONT_TEST), $(wildcard tests/test_*.cpp)); do \
		echo "Compiling & running $$t"; \
		g++ -c $$t -o test_program.o $(parametrosCompilacao); \
		g++ -o test_program test_program.o $(filter-out main.o, $(OBJS)) $(parametrosCompilacao);\
		valgrind --leak-check=full --show-leak-kinds=all ./test_program; \
	done
# ./test_program; 

	@rm -f test_program test_program.o

clean:
	rm -f *.o *.gch $(nomePrograma)
	@rm -f $(OBJS)
