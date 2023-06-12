CC = gcc

LIBZFP = libzfp.a

BINDIR = ../bin

BLAZDIR = ../libraries/blaz-master

ZFPDIR = ../libraries/zfp

LIBS = -L$(ZFPDIR)/lib -lzfp -lm

CFLAGS := -I$(ZFPDIR)/include -I$(BLAZDIR)/src -O3


test: test.c $(ZFPDIR)/lib/$(LIBZFP)
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS) $(LIBS)
