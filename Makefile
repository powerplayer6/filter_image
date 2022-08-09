build: filterfunc.c filterfunc.h main.c
	mkdir build
	gcc -c filterfunc.c
	gcc -c main.c
	gcc filterfunc.o main.o -o mainExe
	mv filterfunc.o main.o mainExe ./build

clean:
	rm -r ./build

run:
	./build/mainExe