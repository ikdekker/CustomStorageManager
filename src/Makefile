PROGRAM = storage-management

SRCS = StorageManagement.cxx ScannerReader.cxx ConfigFactory.cxx ModuleEntity.cxx ../include/json.hpp
OBJS = $(SRCS:.cxx=.o)
LIBS = -lpthread -lhidapi-hidraw

CCC    = g++
CFLAGS = -g -std=c++11 -I. -I../lib/hidapi/hidapi -I ../include

.SUFFIXES: .cxx .o
.cxx.o:
	$(CCC) $(CFLAGS) -c $< 

$(PROGRAM): $(OBJS)
	$(CCC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	rm $(OBJS:.o) $(PROGRAM)
