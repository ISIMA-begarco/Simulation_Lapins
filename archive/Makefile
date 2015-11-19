# definition des cibles particulieres
.PHONY: clean

# definition des variables
CXX = g++-4.7
CXXFLAGS = -O2 -Wall -Wextra -pg -std=c++11
OBJ = main.o ClasseLapins.o LapinManager.o Student.o
OBJI = mainI.o ClasseLapinsI.o LapinManagerI.o Student.o

GameOfRabbits : $(OBJ)
	$(CXX) $^ -o ./$@ $(CXXFLAGS) -lm

main.o : main.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

ClasseLapins.o : ClasseLapins.cpp ClasseLapins.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)

LapinManager.o : LapinManager.cpp LapinManager.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)
	
Student.o : Student.cpp Student.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)
	
GameOfRabbitsI : $(OBJI)
	$(CXX) $^ -o ./$@ $(CXXFLAGS) -lm

mainI.o : mainI.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

ClasseLapinsI.o : ClasseLapinsI.cpp ClasseLapinsI.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)

LapinManagerI.o : LapinManagerI.cpp LapinManagerI.h
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean :
	rm -rf *.bak; rm -rf *.o
