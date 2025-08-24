ifdef CROSS_COMPILE
	compile_prefix := ${CROSS_COMPILE}
else
	compile_prefix := 
endif

all: writer
writer: writer.o 
	${compile_prefix}gcc -o writer writer.o
writer.o: writer.c
	${compile_prefix}gcc -c writer.c

clean:
	rm -f writer *.o
