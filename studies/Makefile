CC	:=	gcc

CFLAGS	:=	-g -Wall

BIN		:=	matrix

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

%: %.cpp
	$(CPP) $(CFLAGS) $< -o $@

clean:
	$(RM) -rf $(BIN) *.dSym