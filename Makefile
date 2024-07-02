CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
SDL_LIBS = -lSDL2 -lSDL2_ttf -lSDL2_image

# Rutas de inclusión de archivos
INC_DIR = include

# Archivos de cabecera
HEADERS = 	$(INC_DIR)/sdl_libs.h \
			$(INC_DIR)/general_tools.h \
			$(INC_DIR)/start_windows.h \
			$(INC_DIR)/buttons.h \
			$(INC_DIR)/handle_scene.h \
        	$(INC_DIR)/menu.h \
        	$(INC_DIR)/texture.h 

# Archivos fuente
SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
	  $(SRC_DIR)/general_tools.c \
	  $(SRC_DIR)/start_windows.c \
	  $(SRC_DIR)/buttons.c \
	  $(SRC_DIR)/handle_scene.c \
      $(SRC_DIR)/menu.c \
      $(SRC_DIR)/texture.c

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
