CC=gcc
SOURCES=main.c tone.c
EXECUTABLE=pwmSong

all:
	$(CC) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm pwmSong
