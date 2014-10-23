MKDIR_P = mkdir -p

OUT_DIR = bin obj
SDIR=source
IDIR=include
ODIR=obj
BDIR=bin

LIBS= -lm -lGL -lglut -lGLU -lGLEW 

CC=g++

CFLAGS= -g -Wall -ansi -I$(IDIR)

_DEPS = *.h	##ADD .h's here
_OBJ = Car.o cube.o DynamicObject.o Frog.o Frogger.o GameObject.o LightSource.o side.o Terrain.o vsLogLib.o vsMathLib.o vsResourceLib.o vsResSurfRevLib.o vsShaderLib.o
##_OBJ = ls ${SDIR} | sed 's/\.cpp/\.o/g' | tr '/\n' ' '


DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: init frogger

init:
	${MKDIR_P} ${OUT_DIR}

build: frogger

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

frogger: $(OBJ)
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)
	
run: build
	./$(BDIR)/frogger

clean:
	rm -f *~ $(SDIR)/*~ $(IDIR)/*~
	rm -r ${OUT_DIR}
