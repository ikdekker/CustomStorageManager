PROGRAM = storage-management

SRCS = src/StorageManagement.cxx
OBJS = $(SRCS:.cxx=.o)
LIBS = -lpthread

CCC    = g++
CFLAGS = -g -I. -I

.SUFFIXES: .cxx .o
.cxx.o:
	$(CCC) $(CFLAGS) -c $< 

$(PROGRAM): $(OBJS)
	$(CCC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	rm $(OBJS) $(PROGRAM)
