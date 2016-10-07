CPP_FILES := $(wildcard src/*.c)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.c=.o)))
LD_FLAGS := -L/usr/lib/x86_64-linux-gnu -lSDL2 -lm -lGL -lGLU -lglut
CC_FLAGS := -I/usr/include/SDL2 -D_REENTRANT

#all: LD_FLAGS += -DOPT_NSGA2
#all: CC_FLAGS += -DOPT_NSGA2
all: add

add: debug main
#	git add makefile src/* include/* model/* sys/* state/* hv/* irace/*

debug: LD_FLAGS += -ggdb
debug: CC_FLAGS += -ggdb
debug: $(OBJ_FILES)
	gcc $(LD_FLAGS) -o $@ $^

main: LD_FLAGS += -Ofast -fopenmp 
main: CC_FLAGS += -fopenmp 
main: $(OBJ_FILES)
	gcc $(LD_FLAGS) -o $@ $^

clean:
	rm main debug obj/*


obj/%.o: src/%.c
	gcc $(CC_FLAGS) -c -o $@ $<

-include $(OBJFILES:.o=.d)
