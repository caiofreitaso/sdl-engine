
SOURCEDIR := src/
BUILDDIR  := obj/
TESTDIR   := test/

TST_FILES := $(shell find $(SOURCEDIR) -name '*.t.cc')
CPP_FILES := $(filter-out $(TST_FILES), $(shell find $(SOURCEDIR) -name '*.cc'))
OBJ_FILES := $(subst $(SOURCEDIR), $(BUILDDIR), $(CPP_FILES:.cc=.o))
TSO_FILES := $(subst $(SOURCEDIR), $(TESTDIR), $(TST_FILES:.cc=))

FLAGS := -fopenmp -msse4.2 -mavx2 -march=x86-64 -malign-double \
-ftree-vectorize -ftree-vectorizer-verbose=2 -DGL_GLEXT_PROTOTYPES

LD_FLAGS := -std=c++14 -Linclude -L/usr/ -L/usr/lib/x86_64-linux-gnu -lSDL2 -lstdc++ -lm -lGL -lGLU -lglut -lboost_program_options $(FLAGS)
CC_FLAGS := -std=c++14 -Iinclude -I/usr/include/SDL2 -D_REENTRANT $(FLAGS)
TT_FLAGS := -std=c++14 -Iinclude -I/usr/include/SDL2 -D_REENTRANT $(FLAGS) -Linclude -L/usr/lib/x86_64-linux-gnu -lSDL2 -lstdc++ -lm -lGL -lGLU -lglut -ggdb

#all: LD_FLAGS += -DOPT_NSGA2
#all: CC_FLAGS += -DOPT_NSGA2
all: add
# cat "$(CPP_FILES)" | cat "$(OBJ_FILES)"

add: debug main test
#	git add makefile src/* include/* model/* sys/* state/* hv/* irace/*

debug: LD_FLAGS += -ggdb
debug: CC_FLAGS += -ggdb
debug: $(OBJ_FILES)
	gcc $(LD_FLAGS) -o $@ $^

main: LD_FLAGS += -O3
main: $(OBJ_FILES)
	gcc $(LD_FLAGS) -o $@ $^

test: $(TSO_FILES)
#	gcc $(LD_FLAGS) -o $@ $^

clean:
	rm main debug & find obj/ -name "*.o" -type f -delete & find test/ -name "*.t" -type f -delete


$(OBJ_FILES): $(BUILDDIR)%.o: $(SOURCEDIR)%.cc
	gcc $(CC_FLAGS) -c -o $@ $<

$(TSO_FILES): $(TESTDIR)%.t: $(SOURCEDIR)%.t.cc $(SOURCEDIR)%.cc
	gcc $(TT_FLAGS) -o $@ $^

-include $(OBJ_FILES:.o=.d)
