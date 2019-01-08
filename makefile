# This will be a makefile script for my main.cpp


main: main.cpp
	g++ main.cpp -o main

edit:
	vim main.cpp

run:
	./main
clean:
	rm main

debug:
	gdb ./main
