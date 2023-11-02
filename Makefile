# Author: Eduardo Gobbo W.V.G
# Date 	: 10/2023

parametrosCompilacao=-Wall#-Wshadow 
nomePrograma=main

SRCS = $(wildcard *.cpp MVC/*.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(nomePrograma)

$(nomePrograma): $(OBJS)
	g++ -o $(nomePrograma) $(OBJS) $(parametrosCompilacao)

# %.o: %.cpp
$(OBJS): %.o : %.cpp
	g++ -c $< -o $@ $(parametrosCompilacao)

run: $(nomePrograma)
	./$(nomePrograma)

clean:
	rm -f *.o *.gch $(nomePrograma)
