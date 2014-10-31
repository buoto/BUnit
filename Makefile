CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=test.cpp BUnit.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=BUnit

all: $(SOURCES) $(EXECUTABLE)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *o $(EXECUTABLE)
