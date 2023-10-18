CC = gcc
CCFLAGS = -g

SRCDIR = ../src
INCLUDES = -I../include
OBJDIR = ./obj
TGTDIR = ./target

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TARGET = $(TGTDIR)/interfaces.a

all: $(TARGET)

clean-all:
	rm -r $(OBJDIR) $(TGTDIR)

clean-objs:
	rm -r $(OBJDIR)

.PHONY: all clean-all clean-objs

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TGTDIR):
	mkdir -p $(TGTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): $(OBJDIR) $(TGTDIR) $(OBJECTS)
	ar rcs $(TARGET) $(OBJECTS)