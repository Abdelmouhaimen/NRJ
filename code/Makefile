CC = gcc

LIBZFP = libzfp.a

BINDIR = ../bin

BLAZDIR = ../lib/blaz-master

ZFPDIR = ../lib/zfp

LIBS = -L$(ZFPDIR)/lib -lzfp -lm

CFLAGS := -I$(ZFPDIR)/include -I$(BLAZDIR)/src -O3


test: test.c $(ZFPDIR)/lib/$(LIBZFP)
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS) $(LIBS)