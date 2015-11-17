# definition des cibles particulieres
.PHONY: clean

# definition des variables
CXX = g++
CXXFLAGS = -O2 -Wall -Wextra -g -std=c++11
OBJ = main.o ClasseLapins.o LapinManager.o

GameOfRabbits : $(OBJ)
	$(CXX) $^ -o ./$@ $(CXXFLAGS)

main.o : main.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

ClasseLapins.o : ClasseLapins.cpp ClasseLapins.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)

LapinManager.o : LapinManager.cpp LapinManager.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean :
	rm -rf *.bak; rm -rf *.o
