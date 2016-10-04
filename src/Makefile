PROGRAM = storage-management

SRCS = StorageManagement.cxx ConfigFactory.cxx ModuleEntity.cxx ../include/json.hpp
OBJS = $(SRCS:.cxx=.o)
LIBS = -lpthread

CCC    = g++
CFLAGS = -g -std=c++11 -I. -I ../include

.SUFFIXES: .cxx .o
.cxx.o:
	$(CCC) $(CFLAGS) -c $< 

$(PROGRAM): $(OBJS)
	$(CCC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	rm $(OBJS:.o) $(PROGRAM)
