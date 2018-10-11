IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stack_test: $(OBJ)
	$(CC) -std=c++11 -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(ODIR)/*.gcno *~ $(ODIR)/*.gcda *~
