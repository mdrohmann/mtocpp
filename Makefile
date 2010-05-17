all: mtoc postprocess

RAGELOPTIM=-G2

install: all
	cp -dp ./mtoc ./postprocess ../../bin

mfilescanner.cc: mfilescanner.rl
	ragel $(RAGELOPTIM) -o mfilescanner.cc mfilescanner.rl

confscanner.cc: confscanner.rl
	ragel $(RAGELOPTIM) -o confscanner.cc confscanner.rl

confscanner.o: confscanner.cc confscanner.h
	g++ -Os -c -Wall -o confscanner.o confscanner.cc

mtoc: mfilescanner.cc mfilescanner.h confscanner.o
	g++ -Os -o mtoc -Wall mfilescanner.cc confscanner.o

postprocess.cc: postprocess.rl
	ragel $(RAGELOPTIM) -o postprocess.cc postprocess.rl

postprocess: postprocess.cc
	g++ -Os -o postprocess -Wall postprocess.cc
