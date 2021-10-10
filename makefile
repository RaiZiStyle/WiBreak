CC=gcc
CFLAGS=
LDFLAGS=-lcurl
SRCDIR=src
OBJDIR=Obj
EXEC=WiBreak.exe
SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))




all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	rm -rf Obj/*.o *.o $(EXEC) 

run: all
	./$(EXEC) -u to_query.com -w test.txt
	
print: # OBJ : "Obj/game_interface.o Obj/List.o Obj/game.o Obj/main.o"
	@echo 'OBJ : "$(OBJ)"' 

src: # SRC : "source/game_interface.c source/List.c source/game.c source/main.c"
	@echo 'SRC : "$(SRC)"'

# cible: dépendances
# 	commandes
# – $@ : nom de la cible ;
# – $< : nom de la première dépendance ;
# – $^ : liste des dépendances ;
# – $? : liste des dépendances plus récentes que la cible ;
# – $* : nom d'un fichier sans son suffixe.


#REDDIT
# LDFLAGS += $(shell sdl-config --libs) -lSDL_image
# # depend on the object files generated from every .c file
# OBJS = $(patsubst %.c,%.o,$(wildcard *.c))

# # to make 'game.exe' we need to make every object file
# game.exe: $(OBJS)
# 	gcc -o $@ $^ $(LDFLAGS)



#ME OWN
# https://ensiwiki.ensimag.fr/images/e/eb/Makefile.pdf
# CC=gcc
# CFLAGS=-W #-Wall -pedantic
# LDFLAGS=`sdl-config --libs` -lSDL_image 
# EXEC=Chess.exe

# all: $(EXEC)

# $(EXEC):  Obj/main.o Obj/fonction.o
# 	$(CC) -o $@ $^ $(LDFLAGS)

# Obj/fonction.o: List.c game.c game_interface.c  
# 	$(CC) -o $@ -c $< $(CFLAGS)

# Obj/main.o: main.c game.h constante.h List.h game_interface.h
# 	$(CC) -o $@ -c $< $(CFLAGS)

# clean:
# 	rm -rf Obj/*.o $(EXEC)

# run: $(EXEC)
# 	./$(EXEC)

# valgrind: $(EXEC)
# 	valgrind ./$(EXEC)

# main.c game.c game_interface.c List.c