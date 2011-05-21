all: mtoc postprocess

#RAGELOPTIM=-G1
RAGELOPTIM=-T0
#CXXFLAGS=-g -O0 -DDEBUG
CXXFLAGS=

install: all
	cp -dp ./mtoc ./postprocess ../../bin

mfilescanner.cc: mfilescanner.rl
	ragel $(RAGELOPTIM) -o mfilescanner.cc mfilescanner.rl

confscanner.cc: confscanner.rl
	ragel $(RAGELOPTIM) -o confscanner.cc confscanner.rl

confscanner.o: confscanner.cc confscanner.h
	g++ -Os -c -Wall $(CXXFLAGS) -o confscanner.o confscanner.cc

mfilescanner.o: mfilescanner.cc mfilescanner.h
	g++ -Os -c -Wall $(CXXFLAGS) -o mfilescanner.o mfilescanner.cc

mtoc: mtoc.cc mfilescanner.o confscanner.o
	g++ -Os -o mtoc $(CXXFLAGS) -Wall mtoc.cc mfilescanner.o confscanner.o

postprocess.cc: postprocess.rl
	ragel $(RAGELOPTIM) -o postprocess.cc postprocess.rl

postprocess: postprocess.cc
	g++ -Os -o postprocess $(CXXFLAGS) -Wall postprocess.cc

accesstest: access.cc confscanner.o mfilescanner.h
	g++ -Os -o accesstest $(CXXFLAGS) -Wall access.cc confscanner.o mfilescanner.o


clean:
	rm -rf *.o mfilescanner.cc confscanner.cc postprocess mtoc
