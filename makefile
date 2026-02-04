#compiler & flags
CXX = g++
CXXFLAGS = -Wall -Wextra -lpthread

#target.. and target again? idk. makes it work well enough
TARGET = ./a.out
TARGET_DEL = a.out

#grabs all of the names of cpp files and then makes the names of the .o files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

#default rule to build executable. could make a run rule but that's probably a bad idea if you have input params
all: $(TARGET)

#run to run
run: $(TARGET)
	./a.out
	feh out.ppm

#rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

#Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#clean rule to remove generated files
clean:
	rm -f $(TARGET_DEL) $(OBJS) *.ppm callgrind.*
