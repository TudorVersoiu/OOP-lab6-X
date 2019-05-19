CC = g++
CFLAGS = -Wall -g -c -I./headers/ -std=c17

LINK_FILES = bin/Car.o bin/Controller.o bin/CarValidator.o\
bin/Repository.o bin/TestCar.o bin/TestController.o bin/UI.o


# Main program rule
program: src/main.cpp $(LINK_FILES)
	$(CC) $^ -o $@ -Wall -g -I./headers/

# UI rule
bin/UI.o: src/UI.cpp headers/UI.h
	$(CC) $< -o $@ $(CFLAGS)

# Test Car rule
bin/TestCar.o: src/TestCar.cpp headers/TestCar.h
	$(CC) $< -o $@ $(CFLAGS)

# Test controller rule
bin/TestController.o: src/TestController.cpp headers/TestController.h
	$(CC) $< -o $@ $(CFLAGS)

# Controller rule
bin/Controller.o: src/Controller.cpp headers/Controller.h
	$(CC) $< -o $@ $(CFLAGS)

# Car rule
bin/Car.o: src/Car.cpp headers/Car.h
	$(CC) $< -o $@ $(CFLAGS)

# Car validator rule
bin/CarValidator.o: src/CarValidator.cpp headers/CarValidator.h
	$(CC) $< -o $@ $(CFLAGS)

# Repository rule
bin/Repository.o: src/Repository.cpp headers/Repository.h
	$(CC) $< -o $@ $(CFLAGS)



clean:
	rm bin/*.o -v
