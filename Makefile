CFLAGS = -Wall -g

main: main.o src/Image.o
	g++ $(CFLAGS) -o main main.o src/Image.o

main.o: src/image-processor.cpp src/Image.h
	g++ $(CFLAGS) -c src/main.cpp

Image.o: src/Image.h