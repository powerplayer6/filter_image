build: filterfunc.c filterfunc.h main.c
	mkdir build
	gcc -c filterfunc.c
	gcc -c main.c
	gcc filterfunc.o main.o -o filter_image
	mv filterfunc.o main.o filter_image ./build

clean:
	rm -r ./build