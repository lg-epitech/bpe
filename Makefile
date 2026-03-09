CC	=	gcc

CFLAGS	+=	-Wall -pedantic -g3

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

BIN	=	bpe

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BIN)

re: fclean $(BIN)
