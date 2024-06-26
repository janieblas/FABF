CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
SDL_LIBS = -lSDL2 -lSDL2_ttf -lSDL2_image

# Rutas de inclusión de archivos
INC_DIR = include

# Archivos de cabecera
HEADERS = $(INC_DIR)/sdl_libs.h \
          $(INC_DIR)/esc_menu.h

# Archivos fuente
SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/esc_menu.c

# Nombre del ejecutable
EXE = build/main.exe

all: $(EXE)

$(EXE): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ $(SRC) $(SDL_LIBS)

clean:
	rm -f $(EXE)

run: $(EXE)
	./$(EXE)

launch: clean all run
