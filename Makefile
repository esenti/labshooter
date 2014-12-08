CXX=g++
RM=rm -f
CPPFLAGS=-g --std=c++11 -Isrc -Wall
LDFLAGS=-g
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system

SRCS=$(wildcard src/*.cpp src/**/*.cpp)
OBJS=$(subst .cpp,.o,$(SRCS))

all: game

game: $(OBJS)
	$(CXX) $(LDFLAGS) -o labshooter $(OBJS) $(LDLIBS)

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) tool
