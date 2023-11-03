# Author: Eduardo Gobbo W.V.G
# Date 	: 10/2023

parametrosCompilacao=-Wall -I./includes#-Wshadow 
nomePrograma=main

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

test: $(OBJS)
	g++ -c tests/chalk_test.cpp -o chalk_test.o $(parametrosCompilacao)
	g++ -o test chalk_test.o src/Chalk.o $(parametrosCompilacao)
	./test
	@rm test

clean:
	rm -f *.o *.gch $(nomePrograma)
	@rm -f $(OBJS)
