
CFLAGS  = -Wall -g $(shell sdl2-config --cflags)
LDFLAGS = 
LDLIBS  = $(shell sdl2-config --libs)

SRCDIR = src
OBJDIR = obj

SRC = $(shell find $(SRCDIR) -type f -name '*.c')
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
OUT = test

$(shell mkdir -p $(SRCDIR) $(OBJDIR))

all: $(OUT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(OUT): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $< $(LDLIBS)

run: 
	./$(OUT)
	
