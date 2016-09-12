PROGRAM = scan-conf

SRCS = ReadScanner.cxx SerialPort/SerialPort.cxx
OBJS = $(SRCS:.cxx=.o)
LIBS = -lpthread

CCC    = g++
CFLAGS = -g -I.

.SUFFIXES: .cxx .o
.cxx.o:
	$(CCC) $(CFLAGS) -c $< 

$(PROGRAM): $(OBJS)
	$(CCC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	rm $(OBJS) $(PROGRAM)

install: $(PROGRAM)
	@echo "Installing $(PROGRAM)"
	@( diff $(PROGRAM) $(MISC_ROOT)/bin/$(PROGRAM) > /dev/null 2>& 1 && echo no difference $(PROGRAM) ) || ( cp $(PROGRAM) $(MISC_ROOT)/bin && echo copied $(PROGRAM))
