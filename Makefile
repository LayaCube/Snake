PLAYGROUND_PATH=include/playground

PROGRAM=snake

CFLAGS=-O0 -g -Werror=implicit-function-declaration
CPPFLAGS=-I$(PLAYGROUND_PATH) -I$(PLAYGROUND_PATH)/externals/include -MMD
LDFLAGS=-L$(PLAYGROUND_PATH) -L$(PLAYGROUND_PATH)/externals/x86_64-linux-gnu
LDLIBS=-lglfw3 -lm -ldl -lpthread -lpg 

OBJS=src/main.o src/game.o src/gui/gui.o

DEPS=$(OBJS:.o=.d)

.PHONY: all

all: $(PROGRAM)

-include $(DEPS)

%.o: %.c
	cc -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(PROGRAM): $(OBJS)
	cc $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	rm -f $(OBJS) $(DEPS) $(PROGRAM) config.bin

