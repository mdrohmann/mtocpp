all: mtoc postprocess

install: all
	cp -dp ./mtoc ./postprocess ../../bin

mfilescanner.cc: mfilescanner.rl
	ragel -G2 -o mfilescanner.cc mfilescanner.rl

confscanner.cc: confscanner.rl
	ragel -G2 -o confscanner.cc confscanner.rl

confscanner.o: confscanner.cc confscanner.h
	g++ -g -c -Wall -o confscanner.o confscanner.cc

mtoc: mfilescanner.cc mfilescanner.h confscanner.o
	g++ -g -o mtoc -Wall mfilescanner.cc confscanner.o

postprocess.cc: postprocess.rl
	ragel -G2 -o postprocess.cc postprocess.rl

postprocess: postprocess.cc
	g++ -g -o postprocess -Wall postprocess.cc
