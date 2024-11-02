SRCDIR += ./common
SRCDIR += ./lowerRetrival
SRCDIR += ./retrival
SRCDIR += ./target

NAME = IandQ
BIN_DIR ?= ./bin
OBJDIR ?= ./obj
BINARY ?= $(BIN_DIR)/$(NAME)

.DEFAULT_GOAL = IandQ

CC = clang++
LD = clang++
INCLUDES = $(addprefix -I, $(SRCDIR))
CFLAGS += -O2 -g -MMD -std=c++20 $(INCLUDES)

SRCS := $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.cpp))
OBJS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

$(OBJDIR)/%.o : %.cpp
	@echo + CC $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS)  -c -o $@ $<

-include $(OBJS:.o=.d)

.PHONY : IandQ clean-obj clean-all

IandQ : $(BINARY)

$(BINARY): $(OBJS)
	@echo + LD $@
	@$(LD) $(OBJS) -o bin/IandQ -O2 -std=c++17

clean-obj:
	rm -r ${OBJDIR}/*

clean-all:
	rm -r ${OBJDIR}/*
	rm -r bin/*
