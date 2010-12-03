all: mtoc postprocess

#RAGELOPTIM=-G1
RAGELOPTIM=-T0
#CXXFLAGS=-g -DDEBUG
CXXFLAGS=

install: all
	cp -dp ./mtoc ./postprocess ../../bin

mfilescanner.cc: mfilescanner.rl
	ragel $(RAGELOPTIM) -o mfilescanner.cc mfilescanner.rl

confscanner.cc: confscanner.rl
	ragel $(RAGELOPTIM) -o confscanner.cc confscanner.rl

confscanner.o: confscanner.cc confscanner.h
	g++ -Os -c -Wall $(CXXFLAGS) -o confscanner.o confscanner.cc

mtoc: mfilescanner.cc mfilescanner.h confscanner.o
	g++ -Os -o mtoc $(CXXFLAGS) -Wall mfilescanner.cc confscanner.o

postprocess.cc: postprocess.rl
	ragel $(RAGELOPTIM) -o postprocess.cc postprocess.rl

postprocess: postprocess.cc
	g++ -Os -o postprocess $(CXXFLAGS) -Wall postprocess.cc

clean:
	rm -rf *.o mfilescanner.cc confscanner.cc postprocess mtoc
