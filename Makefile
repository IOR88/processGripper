CC := g++
CPPFLAGS += -std=c++14 -Wall
program_SOURCE := src
program_BIN := bin
program_NAME := pg
program_CXX_SRCS := $(wildcard src/**/*.cpp)
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_OBJS := $(program_CXX_OBJS)

all: $(program_NAME)

$(program_NAME): $(program_OBJS)
	$(LINK.cc) $(program_OBJS) src/main.cpp -o $(program_BIN)/$(program_NAME)
