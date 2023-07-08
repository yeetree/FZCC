CC=g++

all: bf bfz bfd

bf: ./src/bf/main.cpp
	$(CC) -o ./bin/bf ./src/bf/main.cpp -I.

bfz: ./src/bfz/main.cpp ./src/bfz/utils.cpp
	$(CC) -o ./bin/bfz ./src/bfz/main.cpp ./src/bfz/utils.cpp -I.

bfd: ./src/bfd/main.cpp ./src/bfd/utils.cpp
	$(CC) -o ./bin/bfd ./src/bfd/main.cpp ./src/bfd/utils.cpp -I.