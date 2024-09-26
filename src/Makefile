CFLAGS=-g -O3

all: tokenizer

uimain.o: tokenizer.h
tokenizer.o: tokenizer.h

tokenizer: tokenizer.o uimain.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tokenizer
