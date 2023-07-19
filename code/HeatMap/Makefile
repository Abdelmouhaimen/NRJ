CC = gcc

LIBZFP = libzfp.a

BINDIR = ./bin

BLAZDIR = ../../libraries/blaz-master

ZFPDIR = ../../libraries/zfp

LIBS = -lm

LIBSZFP = -L$(ZFPDIR)/lib -lzfp $(LIBS)

CFLAGSZFP := -I$(ZFPDIR)/include

CFLAGSBLAZ := -I$(BLAZDIR)/src -O3

ODIR = ./Obj
OBJ = $(ODIR)/block_delta.o $(ODIR)/block_slope.o $(ODIR)/dct.o $(ODIR)/io.o $(ODIR)/compress.o $(ODIR)/operations.o $(ODIR)/compressed_operations.o $(ODIR)/errors.o


zfp: zfp.c $(ZFPDIR)/lib/$(LIBZFP)
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGSZFP) $(LIBSZFP)

blaz: $(OBJ) $(ODIR)/blaz.o
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGSBLAZ) $(LIBS)

noCompression: noCompression.c
	$(CC) -o $(BINDIR)/$@ $^ $(LIBS)




$(ODIR)/%.o: $(BLAZDIR)/src/%.c
	$(CC) $(CFLAGSBLAZ) -c $< -o $@


$(ODIR)/blaz.o: blaz.c
	$(CC) $(CFLAGSBLAZ) -c $< -o $@




