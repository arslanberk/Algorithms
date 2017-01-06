objects = main.o image.o noise.o
cc = g++
cflags = -c
executable = NoiseReduction.exe

NoiseReduction: $(objects)
	$(cc) $(objects) -o $(executable)
main.o:
	$(cc) $(cflags) main.cpp 
image.o: image.cpp image.h
	$(cc) $(cflags) image.cpp
noise.o: noise.cpp noise.h
	$(cc) $(cflags) noise.cpp
clean:
	rm *o $(executable)