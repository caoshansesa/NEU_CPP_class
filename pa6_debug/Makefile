IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0 -std=c++11

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = 3dmatrix.o
_OBJ2 = db_3d_dynamic.o
_OBJ3 = db_charptr.o
_OBJ4 = db_practice_1.o
_OBJ5 = db_practice_2.o
_OBJ6 = db_struct.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: 3dmatrix db_3d_dynamic db_charptr db_practice_1 db_practice_2 db_struct
	
3dmatrix: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

db_3d_dynamic: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

db_charptr: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

db_practice1: $(_OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

db_practice2: $(_OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

db_struct: $(_OBJ6)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f 3dmatrix
	rm *.o
	rm -f db_3d_dynamic
	rm -f db_charptr
	rm -f db_practice_1
	rm -f db_practice_2
	rm -f db_struct
