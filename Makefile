CC	=	gcc

CFLAGS	+=	-Wall -pedantic -g3

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

BIN	=	bpe

TEST_SRC	=	$(filter-out src/main.c, $(wildcard src/*.c))
TEST_OBJ	=	$(TEST_SRC:.c=.o)
TEST_BIN	=	tests/run_tests
TEST_FILES	=	$(wildcard tests/*.c)

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

$(TEST_BIN): $(TEST_OBJ) $(TEST_SRC)
	$(CC) $(TEST_OBJ) $(TEST_FILES) -o $(TEST_BIN) $(CFLAGS) -lcriterion

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -f $(OBJ) $(TEST_OBJ)

fclean: clean
	rm -f $(BIN) $(TEST_BIN)

re: fclean $(BIN)
