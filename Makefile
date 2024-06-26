CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
LIBS = -lSDL2 -lSDL2_ttf -lSDL2_image

SRC = main.c
EXE = main

all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(EXE)