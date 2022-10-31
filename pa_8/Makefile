IDIR =./
CC=g++
CFLAGS= -I$(IDIR) -g -O0 -std=c++11 

ODIR=.

LIBS=-lncurses

_DEPS =
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = pa8.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC)  -c -o $@ $< $(CFLAGS)

pa8: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~
	rm -f pa8
	rm -f *.o

