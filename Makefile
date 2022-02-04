CXX=g++
CXXFLAGS=-Wall -g

TESTS= test_enigmaI test_plugboard test_rotor test_reflector test_entrywheel
TARGETS= run_enigmaI

all: $(TARGETS) $(TESTS)

tests: $(TESTS)

run_enigmaI: run_enigmaI.o enigmaI.o plugboard.o rotor.o reflector.o entrywheel.o common.o
	$(CXX) $(CXXFLAGS) -o run_enigmaI run_enigmaI.o enigmaI.o plugboard.o rotor.o reflector.o entrywheel.o common.o

run_enigmaI.o: run_enigmaI.cpp enigma.h plugboard.h rotor.h reflector.h entrywheel.h common.h
	$(CXX) $(CXXFLAGS) -c run_enigmaI.cpp enigmaI.cpp plugboard.cpp rotor.cpp reflector.cpp entrywheel.cpp common.cpp

test_enigmaI: test_enigmaI.o enigmaI.o plugboard.o rotor.o reflector.o entrywheel.o common.o
	$(CXX) $(CXXFLAGS) -o test_enigmaI test_enigmaI.o enigmaI.o plugboard.o rotor.o reflector.o entrywheel.o common.o
test_plugboard: test_plugboard.o plugboard.o common.o
	$(CXX) $(CXXFLAGS) -o test_plugboard test_plugboard.o plugboard.o common.o
test_rotor: test_rotor.o rotor.o common.o
	$(CXX) $(CXXFLAGS) -o test_rotor test_rotor.o rotor.o common.o
test_reflector: test_reflector.o reflector.o common.o
	$(CXX) $(CXXFLAGS) -o test_reflector test_reflector.o reflector.o common.o
test_entrywheel: test_entrywheel.o entrywheel.o common.o
	$(CXX) $(CXXFLAGS) -o test_entrywheel test_entrywheel.o entrywheel.o common.o

test_enigmaI.o: test_enigmaI.cpp enigma.h plugboard.h rotor.h reflector.h entrywheel.h common.h
	$(CXX) $(CXXFLAGS) -c test_enigmaI.cpp enigmaI.cpp plugboard.cpp rotor.cpp reflector.cpp entrywheel.cpp common.cpp
test_plugboard.o: test_plugboard.cpp plugboard.h common.h
	$(CXX) $(CXXFLAGS) -c test_plugboard.cpp common.cpp
test_rotor.o: test_rotor.cpp rotor.h common.h
	$(CXX) $(CXXFLAGS) -c test_rotor.cpp common.cpp
test_reflector.o: test_reflector.cpp reflector.h common.h
	$(CXX) $(CXXFLAGS) -c test_reflector.cpp common.cpp
test_entrywheel.o: test_entrywheel.cpp entrywheel.h common.h
	$(CXX) $(CXXFLAGS) -c test_entrywheel.cpp common.cpp

enigmaI.o: enigmaI.cpp enigma.h plugboard.h rotor.h reflector.h entrywheel.h common.h
	$(CXX) $(CXXFLAGS) -c enigmaI.cpp plugboard.cpp rotor.cpp reflector.cpp entrywheel.cpp common.cpp
plugboard.o: plugboard.cpp plugboard.h common.h
	$(CXX) $(CXXFLAGS) -c plugboard.cpp common.cpp
rotor.o: rotor.cpp rotor.h common.h
	$(CXX) $(CXXFLAGS) -c rotor.cpp common.cpp
reflector.o: reflector.cpp reflector.h common.h
	$(CXX) $(CXXFLAGS) -c reflector.cpp common.cpp
entrywheel.o: entrywheel.cpp entrywheel.h common.h
	$(CXX) $(CXXFLAGS) -c entrywheel.cpp common.cpp
common.o: common.cpp common.h
	$(CXX) $(CXXFLAGS) -c common.cpp

clean:
	rm -r $(TARGETS) $(TESTS) *.exe *.o
