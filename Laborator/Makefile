CC = g++
CFLAGS = -Wall -g -c -Iheaders/

LINK_FILES = Car.o Controller.o CarValidator.o Repository.o TestCar.o TestController.o UI.o


# Main program rule
program: main.cpp $(LINK_FILES)
	$(CC) $^ -o bin/$@ -Wall -g 

# UI rule
bin/UI.o: UI.cpp UI.h
	$(CC) $< -o bin/$@ $(CFLAGS)

# Test Car rule
bin/TestCar.o: TestCar.cpp TestCar.h
	$(CC) $< -o bin/$@ $(CFLAGS)

# Test controller rule
bin/TestController.o: TestController.cpp TestController.h
	$(CC) $< -o bin/$@ $(CFLAGS)

# Controller rule
bin/Controller.o: Controller.cpp Controller.h
	$(CC) $< -o bin/$@ $(CFLAGS)

# Car rule
bin/Car.o: Car.cpp Car.h
	$(CC) $< -o bin/$@ $(CFLAGS)

# Car validator rule
bin/CarValidator.o: CarValidator.cpp CarValidator.h
	$(CC) $< -o bin/$@ $(CFLAGS)

# Repository rule
bin/Repository.o: Repository.cpp Repository.h
	$(CC) $< -o bin/$@ $(CFLAGS)



clean:
	rm bin/*.o -v
