CXX = g++
CPPFLAGS = -g -std=c++14
TARGET = main.o

build: main.cc
	$(CXX) $(CPPFLAGS) $^ -o $(TARGET)

.PHONY: run
run:
	./$(TARGET) tests/input.in

.PHONY: clean
clean:
	rm -f *.o