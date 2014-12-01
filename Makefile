CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=-lbunit
SOURCES=BUnit.cpp
TEST=test.cpp
OBJECTS=$(TEST:.cpp=.o)
EXECUTABLE=BUnit
LIBRARY=libbunit.so

all:
	$(CC) $(CFLAGS) -fpic  $(SOURCES)
	$(CC) -shared -o $(LIBRARY) $(SOURCES:.cpp=.o)

install: all
	install BUnit.h -D /usr/include/bunit/
	install libbunit.so /usr/lib/

test: $(TEST) $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
clean:
	rm -rf *o $(EXECUTABLE)
