PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

WX_CONFIG_CMD = $(WX_CONFIG)

EXEEXT =
LIBS = -lz -ldl -lm
LDFLAGS_GUI = 
CXX = g++
CXXFLAGS += $(shell $(WX_CONFIG_CMD) --cxxflags) -g
LDFLAGS += $(shell $(WX_CONFIG_CMD) --libs)

OBJS = src/minimal.o

all: minimal$(EXEEXT)

minimal$(EXEEXT): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr minimal$(EXEEXT) $(OBJS)
