.SUFFIXES : .cc
.SUFFIXES : .c
.SUFFIXES : .cpp

INCDIR =
LIBDIR =

CC = g++

CXXFLAGS = -g

LIBS = -lm

OBJS = main.o matrix.o matrix_functions.o

TARGET = matrix

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBDIR) $(LIBS)

.cc.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

.c.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

clean:
	rm -f $(OBJS) $(TARGET) core



