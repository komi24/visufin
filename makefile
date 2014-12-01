CC = g++

ARCH = $(shell getconf LONG_BIT)
ifeq ($(ARCH), 32)
  LIBPATH = ./libxl/lib
else
  LIBPATH = ./libxl/lib64
endif


CFLAGS = -I ./libxl/include_cpp -L $(LIBPATH) -lxl -Wl,-rpath,$(LIBPATH)

all: main

main: main.cpp
	$(CC) -o main Segment.cpp isocontour.cpp writeKML.cpp lodepng.cpp makepng.cpp shepard.cpp Parser.cpp Point.cpp Station.cpp KmlFactory.cpp main.cpp $(CFLAGS)

clean:
	rm main

