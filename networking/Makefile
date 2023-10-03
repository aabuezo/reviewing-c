CC=clang
CFLAGS=-g -Wall

BIN=easy_networking

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lcurl


clean:
	$(RM) -rf $(BIN) *.dSYM