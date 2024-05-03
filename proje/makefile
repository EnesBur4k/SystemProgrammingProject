hepsi:derle bagla
derle:
	gcc -c -I "./include" ./src/fields.c -o ./lib/fields.o
	gcc -c -I "./include" ./src/linkedlist.c -o ./lib/linkedlist.o
	gcc -c -I "./include" ./src/program.c -o ./lib/program.o

bagla:
	gcc ./lib/fields.o ./lib/linkedlist.o ./lib/program.o -o ./program

calistir:
	./bin/program
