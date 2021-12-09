CC = g++
CFLAGS = -Wall -Wextra -lGL -lGLEW -lglfw
TARGET = a.out
SRCS = src/*.cpp
OBJS = objs/*.o
OBJDIR = objs/
LIBDIR =
LIBS = -lGL -lGLEW -lglfw

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS) && mv *.o $(OBJDIR)

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d
