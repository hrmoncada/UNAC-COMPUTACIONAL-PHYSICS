# Copy Makefile file
# cp Makefile_3 Makefile
# make -f Makefile_3
# *****************************************************
# Variables to control Makefile operation
CXX = g++
CXXFLAGS = -Wall -g -I.
DEPS = Point.h Rectangle.h
OBJ = main.o Point.o Rectangle.o

# ****************************************************
# The main.o target can be written more simply
%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) 

# Targets needed to bring the executable up to date
main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

run:
	./main

clean:
	rm -f *.o main .*
