CC = g++ 
TARGET = dequetool
CFLAGS = -c -Wall -Wextra 

all: $(TARGET)

$(TARGET): main.o
	$(CC) -o $(TARGET) main.o 

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~
