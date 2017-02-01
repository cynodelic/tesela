CXX = g++
CXXFLAGS = -std=c++14 -fopenmp -g
LIBS = -ljpeg -lpng -lz -ltiff

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%,$(SRCS))

$(info Compiling examples)

all : $(OBJS)
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LIBS)

