CC = g++
CFLAGS = -Wall -Wextra -lGL -lGLEW -lglfw
TARGET = a.out
SRCS = ./*.cpp
OBJS = $(SRCS:.cpp=.o)
LIBDIR = 
LIBS = -lGL -lGLEW -lglfw

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d
