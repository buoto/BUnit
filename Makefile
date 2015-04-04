CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=-lbunit
SOURCES=BUnit.cpp
TEST=test.cpp
OBJECTS=$(TEST:.cpp=.o)
EXECUTABLE=BUnit
LIBRARY=libbunit.so
STATIC_LIBRARY=libbunit.a

all: $(LIBRARY) $(STATIC_LIBRARY)

BUnit.o: BUnit.cpp BUnit.h
	$(CC) $(CFLAGS) -fpic  $(SOURCES)

$(LIBRARY): BUnit.o
	$(CC) -shared -o $(LIBRARY) $(SOURCES:.cpp=.o)

$(STATIC_LIBRARY): BUnit.o
	$(AR) r $(STATIC_LIBRARY) $(SOURCES:.cpp=.o)

install: all
	mkdir -p /usr/include/bunit
	install BUnit.h /usr/include/bunit/
	install libbunit.so /usr/lib/

test: $(TEST) $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(STATIC_LIBRARY)
	$(CC) $(OBJECTS) $(STATIC_LIBRARY) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
clean:
	rm -rf *.o $(LIBRARY) $(STATIC_LIBRARY) $(EXECUTABLE)
