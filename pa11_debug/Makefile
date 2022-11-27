IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0 -std=c++11

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = DebugT-1.o
_OBJ2 = DebugT-2.o
_OBJ3 = DebugT-3.o
_OBJ4 = DebugT-4.o
_OBJ5 = DebugT-5.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: file1 file2 file3 file4 file5

	
file1: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

file2: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

file3: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

file4: $(_OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

file5: $(_OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f file*
	rm -f *.o
	rm -f *.txt

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 
