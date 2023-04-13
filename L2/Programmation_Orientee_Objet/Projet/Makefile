CC = g++
CFLAGS = -std=c++98 -pedantic -Wall -Werror -g `pkg-config pugixml --cflags`
LDFLAGS = `pkg-config pugixml --libs-only-L`
LDLIBS = `pkg-config pugixml --libs-only-l`
RM = rm -fv
.PHONY : all clean

all : edp.out

%.o : %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<

edp.out : edp.cpp address.o company.o envelope.o envelope-c4.o envelope-dl.o str2i-error.o str2l-error.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

clean :
	$(RM) *.o *.out
