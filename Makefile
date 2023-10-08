# Author: Eduardo Gobbo W.V.G
# Date 	: 2023/09

mainProgram='ember'

CompilerParams=-Wall --std=c++17 
Compiler=g++

SRCS=$(wildcard src/*.cpp)
OBJS=$(SRCS:.cpp=.o)

# compile every cpp file under src/
$(OBJS): %.o : %.cpp
	$(Compiler) -c $< -o $@

$(mainProgram): $(OBJS)
	$(Compiler) -o $(mainProgram) $(OBJS) $(CompilerParams)

clean: 
	rm -f $(OBJS) $(mainProgram) *.ghc
