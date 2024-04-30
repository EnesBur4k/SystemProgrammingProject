# Libraries for fields, doubly-linked lists and red-black trees.
# Copyright (C) 2018 James S. Plank

CFLAGS = -O3 -I include

all: clean lib/libfdr.a run

OBJS = obj/dllist.o obj/fields.o obj/jval.o obj/jrb.o obj/program.o

run:
	gcc -o program obj/program.o lib/libfdr.a

lib/libfdr.a: $(OBJS)
	ar ru lib/libfdr.a $(OBJS)
	ranlib lib/libfdr.a 

clean:
	rm -f obj/* lib/*

obj/fields.o: src/fields.c include/fields.h
	gcc $(CFLAGS) -c -o obj/fields.o src/fields.c

obj/jval.o: src/jval.c include/jval.h
	gcc $(CFLAGS) -c -o obj/jval.o src/jval.c

obj/dllist.o: src/dllist.c include/dllist.h include/jval.h
	gcc $(CFLAGS) -c -o obj/dllist.o src/dllist.c

obj/jrb.o: src/jrb.c include/jrb.h include/jval.h
	gcc $(CFLAGS) -c -o obj/jrb.o src/jrb.c
	
obj/program.o: src/program.c
	gcc $(CFLAGS) -c -o obj/program.o src/program.c
