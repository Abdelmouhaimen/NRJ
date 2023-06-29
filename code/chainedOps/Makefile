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


additionsZfp: additionsZfp.c $(ZFPDIR)/lib/$(LIBZFP)
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGSZFP) $(LIBSZFP)

additionsBlaz: $(OBJ) $(ODIR)/additionsBlaz.o
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGSBLAZ) $(LIBS)

additionsNoCompression: additionsNoCompression.c
	$(CC) -o $(BINDIR)/$@ $^ $(LIBS)

addmulBlaz: $(OBJ) $(ODIR)/addmulBlaz.o
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGSBLAZ) $(LIBS)

addmulNoCompression: addmulNoCompression.c
	$(CC) -o $(BINDIR)/$@ $^ $(LIBS)

addmulZfp: addmulZfp.c $(ZFPDIR)/lib/$(LIBZFP)
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGSZFP) $(LIBSZFP)


$(ODIR)/%.o: $(BLAZDIR)/src/%.c
	$(CC) $(CFLAGSBLAZ) -c $< -o $@


$(ODIR)/additionsBlaz.o: additionsBlaz.c
	$(CC) $(CFLAGSBLAZ) -c $< -o $@

$(ODIR)/addmulBlaz.o: addmulBlaz.c
	$(CC) $(CFLAGSBLAZ) -c $< -o $@


