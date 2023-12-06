OBJS	= main.o card.o
SOURCE	= main.cpp card.cpp
HEADER	= 
OUT	= a.exe
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

card.o: card.cpp
	$(CC) $(FLAGS) card.cpp 


clean:
	rm -f $(OBJS) $(OUT)